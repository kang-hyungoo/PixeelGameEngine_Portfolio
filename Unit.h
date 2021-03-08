#pragma once

class cCircleShootor;

class cUnit
{
protected:
	float mX = 0.0f;
	float mY = 0.0f;
	float mVelocity = 0.0f;
	float mAngleDegee = 270.0f;

	int mSize = 0;
	int mCurIndexBullet = 0;

	int mHP = 0;

	bool mIsAlive = false;

	olc::Pixel mUnitColor = olc::WHITE;
public:
	float GetX() const;
	float GetY() const;
	float GetAngleDegee() const;

	void UpdateMoveLeft(float fElapsedTime);
	void UpdateMoveRight(float fElapsedTime);
	void UpdateMoveUp(float fElapsedTime);
	void UpdateMoveDown(float fElapsedTime);

	int GetUnitLeft() const;
	int GetUnitRight() const;
	int GetUnitUp() const;
	int GetUnitDown() const;
	int GetSize() const;
	int GetHP() const;
	int GetCurIndexBullet() const;

	void SetUnitSize(int tSize);
	void SetHP(int tHP);
	void SetUnitPosition(float tX, float tY);
	void SetVelocity(float tVelocity);
	void SetUnitClolor(olc::Pixel tUnitColor);
	void SetIsAlive(bool tIsAlive);
	void SetCurIndexBullet(int tCurIndexBullet);
	void SetAngleDegee(float tAngleDegee);

	void Display(cCircleShootor* tpCircle);

	bool GetIsAlive() const;
};
