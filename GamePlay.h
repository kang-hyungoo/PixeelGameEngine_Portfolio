#pragma once
#include <vector>
#include <algorithm>

class cUser;
class cEnemy;
class cBullet;
class cCircleShootor;
class cTile;
class cScroll;
class cLevel;
class cState;
class cMap;

class cGamePlay
{
private:
	int Bullet_Number = 0;

	int mScore = 0;

	bool mGameOver = false;

	float mShotDelay = 0.0f;

	std::vector<cUnit*> mUnitVec;

	sMouse_Point tMouse_Point;
	cUser* tActor = nullptr;
	cEnemy* tEnemy[ENEMY_MAX] = { nullptr };
	cState* mEnemyState[ENEMY_MAX] = { NULL };
	cBullet* tActorBullet = { nullptr };
	cBullet** tEnemyBullet = { nullptr };

	cScroll* mScroll;

	cLevel* mLevel;
	cMap* mMap = nullptr;
public:
	void CreatePlayGame(cCircleShootor* tpCircle);
	void UpdatePlayGame(float fElapsedTime, cCircleShootor* tpCircle);
	void DisplayPlayGame(cCircleShootor* tpCircle);
	void DestroyPlayGame();

	bool GetGameOver();

	int GetScore();
};

bool DoCompared(cUnit* tpA, cUnit* tpB);
