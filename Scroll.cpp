#include "CircleShootor.h"

void cScroll::CreateScroll() {
	mpSpriteA = new olc::Sprite("resources/bg.png");
	mpSpriteB = new olc::Sprite("resources/bg.png");


	mA_Y = 0.0f;
	mB_Y = -800.0f;

	mHeight = 800.0f;
}

void cScroll::DestroyScroll() {
	if (mpSpriteA != nullptr) {
		delete mpSpriteA;
		mpSpriteA = nullptr;
	}

	if (mpSpriteB != nullptr) {
		delete mpSpriteB;
		mpSpriteB = nullptr;
	}
}

void cScroll::UpdateScroll(float fElapsedTime) {
	mA_Y += 200.0f * fElapsedTime;
	mB_Y += 200.0f * fElapsedTime;

	if (mA_Y >= mHeight) {
		mA_Y = -mHeight;
	}

	if (mB_Y >= mHeight) {
		mB_Y = -mHeight;
	}
}

void cScroll::DisplayScroll() {
	mpPGE->DrawSprite(0, mA_Y, mpSpriteA);
	mpPGE->DrawSprite(0, mB_Y, mpSpriteB);

}

void cScroll::SetPGE(olc::PixelGameEngine* tpPGE) {
	mpPGE = tpPGE;
}