#include "CircleShootor.h"

void DoFireAim::DoFire(cBullet tpBullet[], cUnit* tpTarget, int tAccuracy) {
	float tTheta = (rand() % 90) - 45;
	tTheta = tTheta * (PI / 180.0f) * ((float)tAccuracy / 100.0f);

	float tX_Size = mEnemy->GetX() - tpTarget->GetX();
	float tY_Size = mEnemy->GetY() - tpTarget->GetY();

	//시작점
	tpBullet[mEnemy->GetCurIndexBullet()].SetBulletPosition(mEnemy->GetX() - (mEnemy->GetSize() + tpBullet[mEnemy->GetCurIndexBullet()].GetSize()) * cosf(atan2f(tY_Size, tX_Size) + tTheta), mEnemy->GetY() - (mEnemy->GetSize() + tpBullet[mEnemy->GetCurIndexBullet()].GetSize()) * sinf(atan2f(tY_Size, tX_Size) + tTheta));

	//방향
	tpBullet[mEnemy->GetCurIndexBullet()].SetDirX(cosf(atan2f(-tY_Size, -tX_Size) + tTheta));
	tpBullet[mEnemy->GetCurIndexBullet()].SetDirY(sinf(atan2f(-tY_Size, -tX_Size) + tTheta));

	tpBullet[mEnemy->GetCurIndexBullet()].ShootFire();

	if (mEnemy->GetCurIndexBullet() < BULLET_MAX - 1)
	{
		mEnemy->SetCurIndexBullet(mEnemy->GetCurIndexBullet() + 1);
	}
	else {
		mEnemy->SetCurIndexBullet(0);
	}
}

void DoFireCircle::DoFire(cBullet tpBullet[], cUnit* tpTarget, int tAccuracy) {
	for (int ti = 0; ti < 8; ti++) {
		if (tpBullet[mEnemy->GetCurIndexBullet()].GetVelocity() > 0) {
			tpBullet[mEnemy->GetCurIndexBullet()].SetBulletPosition(mEnemy->GetX() - (mEnemy->GetSize() + tpBullet[mEnemy->GetCurIndexBullet()].GetSize()) * cosf(PI * (mEnemy->GetAngleDegee() + 180.0f) / 180.0f), mEnemy->GetY() - (mEnemy->GetSize() + tpBullet[mEnemy->GetCurIndexBullet()].GetSize()) * sinf(PI * (mEnemy->GetAngleDegee() + 180.0f) / 180.0f));
		}
		else {
			tpBullet[mEnemy->GetCurIndexBullet()].SetBulletPosition(mEnemy->GetX() + (mEnemy->GetSize() + tpBullet[mEnemy->GetCurIndexBullet()].GetSize()) * cosf(PI * (mEnemy->GetAngleDegee() + 180.0f) / 180.0f), mEnemy->GetY() + (mEnemy->GetSize() + tpBullet[mEnemy->GetCurIndexBullet()].GetSize()) * sinf(PI * (mEnemy->GetAngleDegee() + 180.0f) / 180.0f));
		}

		tpBullet[mEnemy->GetCurIndexBullet()].SetDirX(cosf(PI * mEnemy->GetAngleDegee() / 180.0f));
		tpBullet[mEnemy->GetCurIndexBullet()].SetDirY(sinf(PI * mEnemy->GetAngleDegee() / 180.0f));

		tpBullet[mEnemy->GetCurIndexBullet()].ShootFire();

		mEnemy->SetAngleDegee(mEnemy->GetAngleDegee() + 45.0f);

		if (mEnemy->GetAngleDegee() == 360.0f) {
			mEnemy->SetAngleDegee(0.0f);
		}

		if (mEnemy->GetCurIndexBullet() < BULLET_MAX - 1)
		{
			mEnemy->SetCurIndexBullet(mEnemy->GetCurIndexBullet() + 1);
		}
		else {
			mEnemy->SetCurIndexBullet(0);
		}
	}
}