#pragma once

class cTile {
private:
	olc::Sprite* mpSpriteA = nullptr;
	olc::Sprite* mpSpriteB = nullptr;

	int mX = 0;			//타임 블럭의 출력위치 X
	int mY = 0;			//타임 블럭의 출력위치 Y

	int mWidth = 0;		//타일 블럭의 너비
	int mHeight = 0;	//타일 블럭의 높이
public:
	void CreateTile(int tX, int tY, int tWidth = MAP_SIZE_WIDTH, int tHeight = MAP_SIZE_HEIGHT);
	void DestroyTile();
	void UpdateTile();

	olc::Sprite* SetTile(int *tGrid[MAP_HEIGHT][MAP_WIDTH], int tX, int tY);
};