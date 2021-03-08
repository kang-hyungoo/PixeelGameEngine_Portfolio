#include "CircleShootor.h"

void cUser::DoFire(cBullet tpBullet[], sMouse_Point tMouse_Point) {
	float tX_Size = mX - tMouse_Point.tX;
	float tY_Size = mY - tMouse_Point.tY;
	float tH_Size = sqrtf(powf(tX_Size, 2) + powf(tY_Size, 2));

	//시작점
	tpBullet[mCurIndexBullet].SetBulletPosition(mX - (mSize + tpBullet[mCurIndexBullet].GetSize()) * (tX_Size / tH_Size),
												mY - (mSize + tpBullet[mCurIndexBullet].GetSize()) * (tY_Size / tH_Size));


	//방향
	tpBullet[mCurIndexBullet].SetDirX(tMouse_Point.tX - this->mX);
	tpBullet[mCurIndexBullet].SetDirY(tMouse_Point.tY - this->mY);


	float tMagnitude = sqrtf(powf(tpBullet[mCurIndexBullet].GetDirX(), 2) + powf(tpBullet[mCurIndexBullet].GetDirY(), 2));


	tpBullet[mCurIndexBullet].SetDirX(tpBullet[mCurIndexBullet].GetDirX() / tMagnitude);
	tpBullet[mCurIndexBullet].SetDirY(tpBullet[mCurIndexBullet].GetDirY() / tMagnitude);

	tpBullet[mCurIndexBullet].ShootFire();

	if (mCurIndexBullet < BULLET_MAX - 1)
	{
		mCurIndexBullet++;
	}
	else {
		mCurIndexBullet = 0;
	}
}