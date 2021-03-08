#pragma once

class cMap
{
private:
	int* mGrid[MAP_HEIGHT][MAP_WIDTH] = { nullptr };
	cTile** mTiles = { nullptr };
	olc::Sprite* mpSpriteBG = nullptr;

	olc::PixelGameEngine* mpPGE = nullptr;


	int mCameraCol = 1;
	int mCameraRow = 1;

	int mDisplayStartX = 0;
	int mDisplayStartY = 0;
public:
	void CreateMap();
	void DestroyMap();

	void SetMap();
	void SetPGE(olc::PixelGameEngine* tpPGE);

	void DisplayMap();
};

