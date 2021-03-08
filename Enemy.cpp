#include "CircleShootor.h"

float cEnemy::GetTimeTick() const {
	return mTimeTick;
}

void cEnemy::UpdateAI(float fElapsedTime, cCircleShootor* tpCircle) {
	if (mIsAlive) {
		if (mAI == AIMODE::STOP) {
			mAI = AIMODE::XX;
			SetTheta();
			mTimeTickAI = 0.0f;
		}

		if (mTimeTickAI < 1.0f) {
			mTimeTickAI += fElapsedTime;
		}
		else {
			mAI = AIMODE::XX;
			SetTheta();
			mTimeTickAI = 0.0f;
		}

		if (this->GetY() <= this->GetSize()) {
			if (this->GetX() <= this->GetSize() && mAI != AIMODE::UL) {
				mAI = AIMODE::UL; 
				SetTheta();
				mTimeTickAI = 0.0f;
			} 
			else if (this->GetX() >= tpCircle->ScreenWidth() - this->GetSize() && mAI != AIMODE::UR) {
				mAI = AIMODE::UR;
				SetTheta();
				mTimeTickAI = 0.0f;
			}
			else if (this->GetX() < tpCircle->ScreenWidth() - this->GetSize() && GetX() > this->GetSize() && mAI != AIMODE::UX) {
				mAI = AIMODE::UX;
				SetTheta();
				mTimeTickAI = 0.0f;
			}
		}
		else if (this->GetY() >= tpCircle->ScreenHeight() - this->GetSize() && mAI != AIMODE::DL) {
			if (this->GetX() <= this->GetSize()) {
				mAI = AIMODE::DL;
				SetTheta();
				mTimeTickAI = 0.0f;
			}
			else if (this->GetX() >= tpCircle->ScreenWidth() - this->GetSize() && mAI != AIMODE::DR) {
				mAI = AIMODE::DR;
				SetTheta();
				mTimeTickAI = 0.0f;
			}
			else if (this->GetX() < tpCircle->ScreenWidth() - this->GetSize() && this->GetX() > this->GetSize() && mAI != AIMODE::DX) {
				mAI = AIMODE::DX;
				SetTheta();
				mTimeTickAI = 0.0f;
			}
		}
		else if (this->GetY() < tpCircle->ScreenHeight() - this->GetSize() && this->GetY() > this->GetSize() ){
			if (this->GetX() <= this->GetSize() && mAI != AIMODE::XL) {
				mAI = AIMODE::XL;
				SetTheta();
				mTimeTickAI = 0.0f;
			}
			else if (this->GetX() >= tpCircle->ScreenWidth() - this->GetSize() && mAI != AIMODE::XR) {
				mAI = AIMODE::XR;
				SetTheta();
				mTimeTickAI = 0.0f;
			}
			else if (this->GetX() < tpCircle->ScreenWidth() - this->GetSize() && GetX() > this->GetSize() && mAI != AIMODE::XX) {

			}
		}

		this->UpdateMoveRight(fElapsedTime * cosf(PI * mTheta / 180.0f));
		this->UpdateMoveDown(fElapsedTime * sinf(PI * mTheta / 180.0f));
	}
}

void cEnemy::SetTimeTick(float tTimeTick) {
	mTimeTick = tTimeTick;
}

void cEnemy::SetTimeTickAI(float tTimeTickAI) {
	mTimeTickAI = tTimeTickAI;
}

void cEnemy::ChangeAI(cEnemy* tEnemyB) {
	int tHorizontal_A;
	int tVertical_A;
	int tHorizontal_B;
	int tVertical_B;


	int tTable[3][3] = {	{AIMODE::UL, AIMODE::UX, AIMODE::UR},
							{AIMODE::XL, AIMODE::XX, AIMODE::XR},
							{AIMODE::DL, AIMODE::DX, AIMODE::DR} };

	if (this->mX - tEnemyB->mX == 0) {		//A와 B의 X 좌표가 동일
		tHorizontal_A = 1;
		tHorizontal_B = 1;
	}
	else if (this->mX - tEnemyB->mX > 0)	{	//A와 B의 X 좌표가 A가 B보다 크다.
		tHorizontal_A = 2;
		tHorizontal_B = 0;
	}
	else {
		tHorizontal_A = 0;						//A와 B의 X 좌표가 A가 B보다 작다.
		tHorizontal_B = 2;
	}

	if (this->mY - tEnemyB->mY == 0) {		//A와 B의 Y 좌표가 동일
		tVertical_A = 1;
		tVertical_B = 1;
	}
	else if (this->mY - tEnemyB->mY > 0) {	//A와 B의 Y 좌표가 A가 B보다 크다.
		tVertical_A = 2;
		tVertical_B = 0;
	}
	else {
		tVertical_A = 0;						//A와 B의 Y 좌표가 A가 B보다 작다.
		tVertical_B = 2;
	}

	if (tHorizontal_A == 1 && tVertical_A == 1) {
		tHorizontal_A = rand() % 3;
		tVertical_A = rand() % 3;

		tHorizontal_B = rand() % 3;
		tVertical_B = rand() % 3;

		this->mAI = tTable[tHorizontal_A][tVertical_A];
		this->SetTheta();
		tEnemyB->mAI = tTable[tHorizontal_B][tVertical_B];
		tEnemyB->SetTheta();
	}
	else {
		this->mAI = tTable[tHorizontal_A][tVertical_A];
		this->SetTheta();
		tEnemyB->mAI = tTable[tHorizontal_B][tVertical_B];
		tEnemyB->SetTheta();
	}

	this->mTimeTickAI = 0.0f;
	tEnemyB->mTimeTickAI = 0.0f;
}

void cEnemy::Hit(int& tScore) {
	if (mHP == 1) {
		mIsAlive = false;
		mTimeTick = 0.0f;
		mTimeTickAI = 0.0f;
		mHP -= 1;
		tScore += 200;
	}
	else {
		mHP -= 1;
	}
}

void cEnemy::SetTheta() {

	switch (mAI) {
	case AIMODE::UL:
	{
		mTheta = rand() % 90;
	}
	break;
	case AIMODE::UX:
	{
		mTheta = rand() % 180;
	}
	break;
	case AIMODE::UR:
	{
		mTheta = rand() % 90 + 90;

	}
	break;
	case AIMODE::XL:
	{
		mTheta = rand() % 180 - 90;
	}
	break;
	case AIMODE::XX:
	{
		mTheta = rand() % 360;
	}
	break;
	case AIMODE::XR:
	{
		mTheta = rand() % 180 + 90;
	}
	break;
	case AIMODE::DL:
	{
		mTheta = rand() % 90 + 270;
	}
	break;
	case AIMODE::DX:
	{
		mTheta = rand() % 180 + 180;
	}
	break;
	case AIMODE::DR:
	{
		mTheta = rand() % 90 + 180;
	}
	break;
	case AIMODE::STOP:
	{

	}
	break;
	}
}
