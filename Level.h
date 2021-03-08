#pragma once
class cLevel
{
private:
	int mAccuracy = 100;
	int mUnit_Count = 1;

	float mGame_Play_Time = 0.0f;

	float mRespone_Time = 20.0f;
	float mBullet_Fire_Time = 4.0f;

public:
	int GetUnitCount();
	int GetAccuracy();

	void UpdateLevel(float fElapsedTime, cEnemy** tEnemy);

	float GetResponeTime();
	float GetBulletFireTime();
};

