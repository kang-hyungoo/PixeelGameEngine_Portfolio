#include "CircleShootor.h"

DoFireAim* DoFireAim::mpInstance = NULL;
DoFireCircle* DoFireCircle::mpInstance = NULL;

void cGamePlay::CreatePlayGame(cCircleShootor* tpCircle) {
	mScore = 0;
	mUnitVec.reserve(256);

	tActor = new cUser;

	tActorBullet = new cBullet[BULLET_MAX];

	tEnemyBullet = new cBullet*[ENEMY_MAX];

	mScroll = new cScroll;

	mMap = new cMap;

	mLevel = new cLevel;

	mGameOver = false;

	for (int ti = 0; ti < ENEMY_MAX; ti++) {
		tEnemyBullet[ti] = new cBullet[BULLET_MAX];
	}

	mScroll->CreateScroll();
	mScroll->SetPGE(tpCircle);

	mMap->CreateMap();
	mMap->SetPGE(tpCircle);
	mMap->SetMap();

	//주인공 기체의 설정
	tActor->SetUnitSize(UNIT_SIZE);
	tActor->SetUnitPosition(tpCircle->ScreenWidth() / 2, tpCircle->ScreenHeight() / 2);
	tActor->SetVelocity(50.0f);
	tActor->SetUnitClolor(olc::BLUE);
	tActor->SetHP(10);
	tActor->SetIsAlive(true);

	//적 기체의 설정
	for (int ti = 0; ti < ENEMY_MAX; ti++) {
		tEnemy[ti] = new cEnemy();

		if (rand() % 100 > 70) {
			mEnemyState[ti] = DoFireCircle::CreateInstance();
			tEnemy[ti]->SetState(mEnemyState[ti]);
			tEnemy[ti]->SetUnitClolor(olc::GREEN);
		}
		else {
			mEnemyState[ti] = DoFireAim::CreateInstance();
			tEnemy[ti]->SetState(mEnemyState[ti]);
			tEnemy[ti]->SetUnitClolor(olc::RED);
		}

		tEnemy[ti]->SetUnitSize(UNIT_SIZE);
		tEnemy[ti]->SetUnitPosition(rand() % (tpCircle->ScreenWidth() - 2 * UNIT_SIZE) + UNIT_SIZE, rand() % (tpCircle->ScreenHeight() - 2 * UNIT_SIZE) + UNIT_SIZE);
		tEnemy[ti]->SetVelocity(50.0f);
		tEnemy[ti]->SetTimeTick(0.0f);
		tEnemy[ti]->SetTimeTickAI(0.0f);
		tEnemy[ti]->SetHP(3);

		if (ti < mLevel->GetUnitCount()) {
			tEnemy[ti]->SetIsAlive(true);
		}
	}

	//주인공 기체의 탄환 설정
	for (int ti = 0; ti < BULLET_MAX; ti++)
	{
		tActorBullet[ti].SetBulletSize(BULLET_SIZE);
		tActorBullet[ti].SetVelocity(150.0f);
		tActorBullet[ti].SetBulletClolor(olc::DARK_BLUE);
	}

	//적 기체의 탄환 설정
	for (int ti = 0; ti < ENEMY_MAX; ti++)
	{
		for (int tj = 0; tj < BULLET_MAX; tj++)
		{
			tEnemyBullet[ti][tj].SetBulletSize(BULLET_SIZE);
			tEnemyBullet[ti][tj].SetVelocity(150.0f);
			tEnemyBullet[ti][tj].SetBulletClolor(olc::DARK_RED);
		}
	}
}


void cGamePlay::UpdatePlayGame(float fElapsedTime, cCircleShootor* tpCircle) {
	//Update
	for (int ti = 0; ti < mLevel->GetUnitCount(); ti++) {
		if (tEnemy[ti]->GetIsAlive()) {
			for (int tj = ti + 1; tj < mLevel->GetUnitCount(); tj++) {
				if (tEnemy[tj]->GetIsAlive()) {
					if (powf(tEnemy[ti]->GetX() - tEnemy[tj]->GetX(), 2) + powf(tEnemy[ti]->GetY() - tEnemy[tj]->GetY(), 2) <= powf(tEnemy[ti]->GetSize() + tEnemy[tj]->GetSize(), 2)) {
						tEnemy[ti]->ChangeAI(tEnemy[tj]);
					}
				}
			}
			if (tEnemy[ti]->GetTimeTick() >= mLevel->GetBulletFireTime())
			{
				tEnemy[ti]->DoFire(tEnemyBullet[ti], tActor, mLevel->GetAccuracy());
				tEnemy[ti]->SetTimeTick(0.0f);
			}
			else {
				tEnemy[ti]->SetTimeTick(tEnemy[ti]->GetTimeTick() + fElapsedTime);
			}
			tEnemy[ti]->UpdateAI(fElapsedTime, tpCircle);
		}
		else {
			if (tEnemy[ti]->GetTimeTick() >= mLevel->GetResponeTime())
			{
				if (rand() % 100 > 70) {
					mEnemyState[ti] = DoFireCircle::CreateInstance();
					tEnemy[ti]->SetState(mEnemyState[ti]);
					tEnemy[ti]->SetUnitClolor(olc::GREEN);
				}
				else {
					mEnemyState[ti] = DoFireAim::CreateInstance();
					tEnemy[ti]->SetState(mEnemyState[ti]);
					tEnemy[ti]->SetUnitClolor(olc::RED);
				}

				tEnemy[ti]->SetUnitSize(UNIT_SIZE);
				tEnemy[ti]->SetUnitPosition(rand() % (tpCircle->ScreenWidth() - 2 * UNIT_SIZE) + UNIT_SIZE, rand() % (tpCircle->ScreenHeight() - 2 * UNIT_SIZE) + UNIT_SIZE);
				tEnemy[ti]->SetVelocity(50.0f);
				tEnemy[ti]->SetHP(3);

				tEnemy[ti]->SetIsAlive(true);

				tEnemy[ti]->SetTimeTick(0.0f);
			}
			else {
				tEnemy[ti]->SetTimeTick(tEnemy[ti]->GetTimeTick() + fElapsedTime);
			}
		}
	}

	mScroll->UpdateScroll(fElapsedTime);

	mLevel->UpdateLevel(fElapsedTime, tEnemy);

	//Input
	if (tpCircle->GetKey(olc::Key::A).bHeld) {
		if (tActor->GetUnitLeft() > 1)
		{
			// 프래임 기반 진행
			// mActorX -= mCircleMoveX;

			// 시간 기반 진행
			tActor->UpdateMoveLeft(fElapsedTime);
		}
	}

	if (tpCircle->GetKey(olc::Key::D).bHeld) {
		if (tActor->GetUnitRight() < tpCircle->ScreenWidth() - 1)
		{
			tActor->UpdateMoveRight(fElapsedTime);
		}
	}

	if (tpCircle->GetKey(olc::Key::W).bHeld) {
		if (tActor->GetUnitUp() > 1)
		{
			tActor->UpdateMoveUp(fElapsedTime);
		}
	}

	if (tpCircle->GetKey(olc::Key::S).bHeld) {
		if (tActor->GetUnitDown() < tpCircle->ScreenHeight() - 1)
		{
			tActor->UpdateMoveDown(fElapsedTime);
		}
	}

	if (tpCircle->GetMouse(LEFT_BUTTON).bPressed) {
		tMouse_Point.tX = tpCircle->GetMouseX();
		tMouse_Point.tY = tpCircle->GetMouseY();
		tActor->DoFire(tActorBullet, tMouse_Point);
		mShotDelay = 0.0f;
	}
	else if (tpCircle->GetMouse(LEFT_BUTTON).bHeld) {
		mShotDelay += fElapsedTime;
		if (mShotDelay > 0.1) {
			tMouse_Point.tX = tpCircle->GetMouseX();
			tMouse_Point.tY = tpCircle->GetMouseY();
			tActor->DoFire(tActorBullet, tMouse_Point);
			mShotDelay -= 0.1;
		}
	}

	for (int ti = 0; ti < BULLET_MAX; ti++) {
		tActorBullet[ti].UpdateMove(fElapsedTime);
	}
	for (int ti = 0; ti < mLevel->GetUnitCount(); ti++) {
		for (int tj = 0; tj < BULLET_MAX; tj++) {
			tEnemyBullet[ti][tj].UpdateMove(fElapsedTime);
		}
	}

	mUnitVec.push_back(tActor);

	for (int ti = 0; ti < mLevel->GetUnitCount(); ti++) {
		if (tEnemy[ti]->GetIsAlive()) {
			mUnitVec.push_back(tEnemy[ti]);
		}
	}

	sort(mUnitVec.begin(), mUnitVec.end(), DoCompared);
}

void cGamePlay::DisplayPlayGame(cCircleShootor* tpCircle) {
	tpCircle->SetPixelMode(olc::Pixel::MASK);

	mMap->DisplayMap();
	mScroll->DisplayScroll();

	for (int ti = 0; ti < mUnitVec.size() ;  ti++) {
		if (mUnitVec[ti]->GetIsAlive()) {
			mUnitVec[ti]->Display(tpCircle);
		}
	}

	for (int ti = 0; ti < BULLET_MAX; ti++) {
		tActorBullet[ti].Display(tpCircle);
	}

	for (int ti = 0; ti < mLevel->GetUnitCount(); ti++) {
		for (int tj = 0; tj < BULLET_MAX; tj++) {
			tEnemyBullet[ti][tj].Display(tpCircle);
		}
	}

	for (int ti = 0; ti < BULLET_MAX; ti++) {
		if (tActorBullet[ti].GetIsAlive() == true) {
			for (int tj = 0; tj < mLevel->GetUnitCount(); tj++) {
				if (powf(tActorBullet[ti].GetX() - tEnemy[tj]->GetX(), 2) + powf(tActorBullet[ti].GetY() - tEnemy[tj]->GetY(), 2) <= powf(tActorBullet[ti].GetSize() + tEnemy[tj]->GetSize(), 2))
				{
					if (tEnemy[tj]->GetIsAlive()) {
						tEnemy[tj]->Hit(mScore);
						tActorBullet[ti].SetIsAlive(false);
					}
				}
			}
		}
	}

	for (int ti = 0; ti < mLevel->GetUnitCount(); ti++) {
		for (int tj = 0; tj < BULLET_MAX; tj++) {
			if (tEnemyBullet[ti][tj].GetIsAlive()) {
				if (powf(tEnemyBullet[ti][tj].GetX() - tActor->GetX(), 2) + powf(tEnemyBullet[ti][tj].GetY() - tActor->GetY(), 2) <= powf(tEnemyBullet[ti][tj].GetSize() + tActor->GetSize(), 2))
				{
					tEnemyBullet[ti][tj].SetIsAlive(false);
					tActor->SetHP(tActor->GetHP() - 1);
					if (tActor->GetHP() <= 0) {
						tActor->SetIsAlive(false);
						mGameOver = true;
					}
				}
			}
		}
	}

	tpCircle->DrawString(tpCircle->ScreenWidth() - (tpCircle->GetTextSize("Score : " + to_string(mScore)).x * 3), 0, "Score : " + to_string(mScore), olc::BLACK, 3);

	tpCircle->DrawString(tpCircle->ScreenWidth() - (tpCircle->GetTextSize("HP : " + to_string(tActor->GetHP())).x * 3), tpCircle->GetTextSize("Score : " + to_string(mScore)).y * 3, "HP : " + to_string(tActor->GetHP()), olc::BLACK, 3);
	tpCircle->SetPixelMode(olc::Pixel::NORMAL);
}

void cGamePlay::DestroyPlayGame() {
	mMap->DestroyMap();

	if (mMap != nullptr) {
		delete mMap;
		mMap = nullptr;
	}

	if (tActor != nullptr) {
		delete tActor;
		tActor = nullptr;
		cout << "tAcotr Clear" << endl;
	}

	if (tEnemy != nullptr) {
		for (int ti = 0; ti < ENEMY_MAX; ++ti) {
			delete tEnemy[ti];
			tEnemy[ti] = nullptr;
		}
		cout << "tEnemy Clear" << endl;
	}


	if (tActorBullet != nullptr) {
		delete[] tActorBullet;
		tActorBullet = nullptr;
		cout << "tActorBullet Clear" << endl;
	}


	for (int ti = 0; ti < ENEMY_MAX; ++ti) {
		if (tEnemyBullet[ti] != nullptr) {
			delete[] tEnemyBullet[ti];
			tEnemyBullet[ti] = nullptr;
			cout << "tEnemyBullet" << ti << " Clear" << endl;
		}
	}

	if (tEnemyBullet != nullptr) {
		delete[] tEnemyBullet;
		tEnemyBullet = nullptr;
	}

	mScroll->DestroyScroll();

	if (mScroll != nullptr) {
		delete mScroll;
		mScroll = nullptr;
	}

	if (mLevel != nullptr) {
		delete mLevel;
		mLevel = nullptr;
	}
}

bool cGamePlay::GetGameOver() {
	return mGameOver;
}

int cGamePlay::GetScore() {
	return mScore;
}

bool DoCompared(cUnit* tpA, cUnit* tpB)
{
	if (tpA->GetY() < tpB->GetY()) {
		return true;
	}
	else {
		return false;
	}
}