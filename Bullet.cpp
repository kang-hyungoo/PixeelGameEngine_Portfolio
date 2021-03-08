#include "CircleShootor.h"


float cBullet::GetX() const {
	return mX;
}

float cBullet::GetY() const {
	return mY;
}

float cBullet::GetVelocity() const {
	return mVelocity;
}

void cBullet::UpdateMove(float fElapsedTime) {
	if (true == mIsAlive)
	{
		this->mX = this->mX + mDirX * mVelocity * fElapsedTime;
		this->mY = this->mY + mDirY * mVelocity * fElapsedTime;

		if (this->mY <= -3.0f) {
			this->mIsAlive = false;
		}
	}
}

void cBullet::Display(cCircleShootor* tpCircle) {
	if (true == mIsAlive)
	{
		tpCircle->FillCircle(mX, mY, mSize, mBulletColor);
		
		if (mY <= -mSize) {
			mIsAlive = false;
		}
		else if (mY >= tpCircle->ScreenHeight() + mSize) {
			mIsAlive = false;
		}

	}
}

void cBullet::ShootFire() {
	mIsAlive = true;
}

void cBullet::SetIsAlive(bool tIsAlive) {
	mIsAlive = tIsAlive;
}

void cBullet::SetBulletSize(int tSize) {
	mSize = tSize;
}

void cBullet::SetBulletPosition(float tX, float tY) {
	mX = tX;
	mY = tY;
}

void cBullet::SetVelocity(float tVelocity) {
	mVelocity = tVelocity;
}

void cBullet::SetDirX(float tDirX) {
	mDirX = tDirX;
}

void cBullet::SetDirY(float tDirY) {
	mDirY = tDirY;
}

void cBullet::SetBulletClolor(olc::Pixel tBulletColor) {
	mBulletColor = tBulletColor;
}

bool cBullet::GetIsAlive() const {
	return mIsAlive;
}

int cBullet::GetSize() const {
	return mSize;
}

int cBullet::GetDirX() const {
	return mDirX;
}

int cBullet::GetDirY() const {
	return mDirY;
}
