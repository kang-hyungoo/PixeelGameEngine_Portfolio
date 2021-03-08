#include "CircleShootor.h"

void cTile::CreateTile(int tX, int tY, int tWidth, int tHeight) {
	mpSpriteA = new olc::Sprite("resources/tile_earth.png");
	mpSpriteB = new olc::Sprite("resources/tile_water.png");

	mX = tX;
	mY = tY;
	mWidth = tWidth;
	mHeight = tHeight;
}

void cTile::DestroyTile() {
	if (mpSpriteA != nullptr) {
		delete mpSpriteA;
		mpSpriteA = nullptr;
	}

	if (mpSpriteB != nullptr) {
		delete mpSpriteB;
		mpSpriteB = nullptr;
	}
}

void cTile::UpdateTile() {

}

olc::Sprite* cTile::SetTile(int *tGrid[MAP_HEIGHT][MAP_WIDTH], int tX, int tY) {
	int tRow = 0;
	int tCol = 0;

	int tCarmeraXWorld = tX * 32;
	const int CAMERA_X_SCREEN = 1 * 32;
	int tDiffScreenX = mX - CAMERA_X_SCREEN;
	int tBlockXWorld = tCarmeraXWorld + tDiffScreenX;

	int tCarmeraYWorld = tY * 32;
	const int CAMERA_Y_SCREEN = 1 * 32;
	int tDiffScreenY = mY - CAMERA_Y_SCREEN;
	int tBlockYWorld = tCarmeraYWorld + tDiffScreenY;

	tCol = tBlockXWorld / 32;
	tRow = tBlockYWorld / 32;

	int tAttribute = *tGrid[tRow][tCol];


	switch (tAttribute)
	{
	case 0:
	{
		return mpSpriteA;
	}
	break;
	case 1:
	{
		return mpSpriteB;
	}
	break;
	}
}
