#pragma once

class cBullet
{
private:
	float mX = 0.0f;
	float mY = 0.0f;
	float mVelocity = 0.0f;
	float mDirX = 0.0f;
	float mDirY = 0.0f;

	int mSize = 0;

	bool mIsAlive = false;
	olc::Pixel mBulletColor = olc::WHITE;
public:
	float GetX() const;
	float GetY() const;
	float GetVelocity() const;

	void SetBulletPosition(float tX, float tY);
	void ShootFire();
	void SetBulletSize(int tSize);
	void SetIsAlive(bool tIsAlive);
	void SetVelocity(float tVelocity);
	void SetDirX(float tDirX);
	void SetDirY(float tDirY);
	void SetBulletClolor(olc::Pixel tBulletColor);

	void UpdateMove(float fElapsedTime);
	void Display(cCircleShootor* tpCircle);

	int GetSize() const;
	int GetDirX() const;
	int GetDirY() const;


	bool GetIsAlive() const;
};