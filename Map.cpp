#include "CircleShootor.h"



void cMap::CreateMap() {
	mTiles = new cTile * [MAP_HEIGHT];

	for (int ti = 0; ti < MAP_HEIGHT; ti++) {
		mTiles[ti] = new cTile[MAP_WIDTH];
	}

	for (int tRow = 0; tRow < MAP_HEIGHT; tRow++) {
		for (int tCol = 0; tCol < MAP_WIDTH; tCol++) {
			mGrid[tRow][tCol] = new int();
			*mGrid[tRow][tCol] = rand() % 2;
		}
	}

	for (int tRow = 0; tRow < MAP_HEIGHT; tRow++) {
		for (int tCol = 0; tCol < MAP_WIDTH; tCol++) {
			int tX = mDisplayStartX + tCol * 32;
			int tY = mDisplayStartY + tRow * 32;

			mTiles[tRow][tCol].CreateTile(tX, tY);
		}
	}

	mpSpriteBG = new olc::Sprite(GAME_SIZE_WIDTH, GAME_SIZE_HEIGHT);
}

void cMap::DestroyMap() {
	for (int tRow = 0; tRow < MAP_HEIGHT; tRow++) {
		for (int tCol = 0; tCol < MAP_WIDTH; tCol++) {
			mTiles[tRow][tCol].DestroyTile();
		}
	}

	for (int ti = 0; ti < MAP_HEIGHT; ++ti) {
		if (mTiles[ti] != nullptr) {
			delete[] mTiles[ti];
			mTiles[ti] = nullptr;
		}
	}

	if (mTiles != nullptr) {
		delete[] mTiles;
		mTiles = nullptr;
	}


	if (mpSpriteBG != nullptr) {
		delete mpSpriteBG;
		mpSpriteBG = nullptr;
	}
}

void cMap::SetMap() {
	olc::Sprite* tTempSprite;
	for (int tRow = 0; tRow < MAP_HEIGHT; tRow++) {
		for (int tCol = 0; tCol < MAP_WIDTH; tCol++) {
			tTempSprite = mTiles[tRow][tCol].SetTile(mGrid, mCameraCol, mCameraRow);
			for (int y = 0; y < 32; y++) {
				for (int x = 0; x < 32; x++) {
					mpSpriteBG->SetPixel(tCol * 32 + x, tRow * 32 + y, tTempSprite->GetPixel(x, y));
				}
			}
		}
	}
}


void cMap::DisplayMap() {
	mpPGE->DrawSprite(0, 0, mpSpriteBG);
}


void cMap::SetPGE(olc::PixelGameEngine* tpPGE) {
	mpPGE = tpPGE;
}