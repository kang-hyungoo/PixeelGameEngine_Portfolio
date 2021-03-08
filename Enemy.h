#pragma once
#include "Unit.h"
#include "Define.h"
#include "State.h"

class cBullet;
class cCircleShootor;
class DoFireAim;
class DoFireCircle;
class cState;

class cEnemy : public cUnit {
private:
	float mTimeTick = 0.0f;
	float mTimeTickAI = 0.0f;

	float mDirX = 0.0f;
	float mDirY = 0.0f;

	int mAI = AIMODE::STOP;
	int mTheta = 0;

	cState* mpState = NULL;

public:

	float GetTimeTick() const;

	void UpdateAI(float fElapsedTime, cCircleShootor* tpCircle);
	void SetTimeTick(float tTimeTick);
	void SetTimeTickAI(float tTimeTickAI);
	void ChangeAI(cEnemy* tEnemyB);
	void Hit(int& tScore);
	void SetTheta();

	cEnemy() { mpState = DoFireAim::CreateInstance(); }

	void SetState(cState* tpState)
	{
		mpState = tpState;
	}

	void DoFire(cBullet tpBullet[], cUnit* tpTarget, int tAccuracy) { 
		mpState->SetEnemy(this);
		mpState->DoFire(tpBullet, tpTarget, tAccuracy); 
	}
};
