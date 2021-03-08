#pragma once

class cTile {
private:
	olc::Sprite* mpSpriteA = nullptr;
	olc::Sprite* mpSpriteB = nullptr;

	int mX = 0;			//Ÿ�� ���� �����ġ X
	int mY = 0;			//Ÿ�� ���� �����ġ Y

	int mWidth = 0;		//Ÿ�� ���� �ʺ�
	int mHeight = 0;	//Ÿ�� ���� ����
public:
	void CreateTile(int tX, int tY, int tWidth = MAP_SIZE_WIDTH, int tHeight = MAP_SIZE_HEIGHT);
	void DestroyTile();
	void UpdateTile();

	olc::Sprite* SetTile(int *tGrid[MAP_HEIGHT][MAP_WIDTH], int tX, int tY);
};