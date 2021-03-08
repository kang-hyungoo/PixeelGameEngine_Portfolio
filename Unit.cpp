#include "CircleShootor.h"

float cUnit::GetX() const {
	return mX;
}

float cUnit::GetY() const {
	return mY;
}

float cUnit::GetAngleDegee() const {
	return mAngleDegee;
}

void cUnit::UpdateMoveLeft(float fElapsedTime) {
	mX -= mVelocity * fElapsedTime;
}

void cUnit::UpdateMoveRight(float fElapsedTime) {
	mX += mVelocity * fElapsedTime;
}

void cUnit::UpdateMoveUp(float fElapsedTime) {
	mY -= mVelocity * fElapsedTime;
}

void cUnit::UpdateMoveDown(float fElapsedTime) {
	mY += mVelocity * fElapsedTime;
}

int cUnit::GetUnitLeft() const {
	return mX - mSize;
}

int cUnit::GetUnitRight() const {
	return mX + mSize;
}

int cUnit::GetUnitUp() const {
	return mY - mSize;
}

int cUnit::GetUnitDown() const {
	return mY + mSize;
}

int cUnit::GetSize() const {
	return mSize;
}

int  cUnit::GetHP() const {
	return mHP;
}

int cUnit::GetCurIndexBullet() const {
	return mCurIndexBullet;
}

void cUnit::SetUnitSize(int tSize) {
	mSize = tSize;
}

void cUnit::SetHP(int tHP) {
	mHP = tHP;
}

void cUnit::SetUnitPosition(float tX, float tY) {
	mX = tX;
	mY = tY;
}

void cUnit::SetVelocity(float tVelocity) {
	mVelocity = tVelocity;
}

void cUnit::SetUnitClolor(olc::Pixel tUnitColor) {
	mUnitColor = tUnitColor;
}

void cUnit::SetIsAlive(bool tIsAlive) {
	mIsAlive = tIsAlive;
}

void cUnit::SetCurIndexBullet(int tCurIndexBullet) {
	mCurIndexBullet = tCurIndexBullet;
}

void cUnit::SetAngleDegee(float tAngleDegee) {
	mAngleDegee = tAngleDegee;
}
void cUnit::Display(cCircleShootor* tpCircle) {
	tpCircle->FillCircle(mX, mY, mSize, mUnitColor);
}

bool cUnit::GetIsAlive() const {
	return mIsAlive;
}