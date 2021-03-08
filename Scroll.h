#pragma once

class cScroll {
private:
	olc::Sprite* mpSpriteA = nullptr;
	olc::Sprite* mpSpriteB = nullptr;

	float mA_Y = 0.0f;
	float mB_Y = 0.0f;

	float mHeight = 0.0f;

	olc::PixelGameEngine* mpPGE = nullptr;
public:
	void CreateScroll();
	void DestroyScroll();
	void UpdateScroll(float fElapsedTime);

	void DisplayScroll();
	void SetPGE(olc::PixelGameEngine* tpPGE);
};