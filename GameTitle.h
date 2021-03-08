#pragma once
#include <iostream>

using namespace std;

class cCircleShootor;

class cGameTitle {
private:
	string mGameTitle;
	string mStart;

	bool mDisyplay = true;

	float mBlinkTime = 0.0f;

public:
	void CreateTitle(cCircleShootor* tpCircle);
	void UpdateTitle(float fElapsedTime, cCircleShootor* tpCircle);
	void DisplayTitle(cCircleShootor* tpCircle);
	void DestroyTitle();
};

