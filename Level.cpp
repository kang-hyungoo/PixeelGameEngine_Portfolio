#include "CircleShootor.h"

int cLevel::GetUnitCount() {
	return mUnit_Count;
}

int cLevel::GetAccuracy() {
	return mAccuracy;
}

void cLevel::UpdateLevel(float fElapsedTime, cEnemy** tEnemy) {
	mGame_Play_Time += fElapsedTime;

	if (mGame_Play_Time > LEVEL_UPDATE_TIME) {

		if (mUnit_Count < ENEMY_MAX) {
			tEnemy[mUnit_Count]->SetIsAlive(true);

			mUnit_Count++;
		}
	
		if (mRespone_Time > 10.0f) {
			mRespone_Time -= 0.5f;
		}

		if (mBullet_Fire_Time > 2.0f) {
			mBullet_Fire_Time -= 0.25f;
		}

		if (mAccuracy > 0) {
			mAccuracy -= 5;
		}

		mGame_Play_Time -= LEVEL_UPDATE_TIME;
	}
}


float cLevel::GetResponeTime() {
	return mRespone_Time;
}

float cLevel::GetBulletFireTime() {
	return mBullet_Fire_Time;
}