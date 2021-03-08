#pragma once
#include <iostream>

using namespace std;

class cCircleShootor;

class cGameEnd {
private:
	string mGameScore;
	string mStart;

	bool mDisyplay = true;

	float mBlinkTime = 0.0f;

public:
	void CreateTitle(cCircleShootor* tpCircle, int tScore);
	void UpdateTitle(float fElapsedTime, cCircleShootor* tpCircle);
	void DisplayTitle(cCircleShootor* tpCircle);
	void DestroyTitle();
};

