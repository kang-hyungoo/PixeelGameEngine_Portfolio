#include "CircleShootor.h"


void cGameTitle::CreateTitle(cCircleShootor* tpCircle) {
	mGameTitle = "Circle Shootor";
	mStart = "Press Space Bar.";

	mDisyplay = true;
	mBlinkTime = 0.0f;
}
void cGameTitle::UpdateTitle(float fElapsedTime, cCircleShootor* tpCircle) {
	mBlinkTime += fElapsedTime;

	if (mBlinkTime > 0.5f) {

		mDisyplay = !mDisyplay;
		mBlinkTime = 0.0f;
	}
}

void cGameTitle::DisplayTitle(cCircleShootor* tpCircle) {
	tpCircle->Clear(olc::BLUE);

	tpCircle->DrawString((tpCircle->ScreenWidth() / 2) - (tpCircle->GetTextSize(mGameTitle).x / 2 * (3)), (tpCircle->ScreenHeight() / 2) - 15 * (tpCircle->GetTextSize(mGameTitle).y / 2 * (3)), mGameTitle, olc::WHITE, 3);

	if (mDisyplay) {
		tpCircle->DrawString((tpCircle->ScreenWidth() / 2) - (tpCircle->GetTextSize(mStart).x / 2 * (2)), (tpCircle->ScreenHeight() / 2) - (tpCircle->GetTextSize(mStart).y / 2 * (2)), mStart, olc::WHITE, (2));
	}
}

void cGameTitle::DestroyTitle() {

}