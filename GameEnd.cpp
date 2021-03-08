#include "CircleShootor.h"


void cGameEnd::CreateTitle(cCircleShootor* tpCircle, int tScore) {
	mGameScore = "Score : " + to_string(tScore);
	mStart = "Press Space Bar.";

	mDisyplay = true;
	mBlinkTime = 0.0f;
}
void cGameEnd::UpdateTitle(float fElapsedTime, cCircleShootor* tpCircle) {
	mBlinkTime += fElapsedTime;

	if (mBlinkTime > 0.5f) {

		mDisyplay = !mDisyplay;
		mBlinkTime = 0.0f;
	}
}

void cGameEnd::DisplayTitle(cCircleShootor* tpCircle) {
	tpCircle->Clear(olc::BLUE);

	tpCircle->DrawString((tpCircle->ScreenWidth() / 2) - (tpCircle->GetTextSize("GAME OVER").x / 2 * (4)), (1 * tpCircle->ScreenHeight() / 3) - (tpCircle->GetTextSize("GAME OVER").y / 2 * (4)), "GAME OVER", olc::WHITE, (4));

	tpCircle->DrawString((tpCircle->ScreenWidth() / 2) - (tpCircle->GetTextSize(mGameScore).x / 2 * (3)), (tpCircle->ScreenHeight() / 2) - (tpCircle->GetTextSize(mGameScore).y / 2 * (3)), mGameScore, olc::WHITE, 3);

	if (mDisyplay) {
		tpCircle->DrawString((tpCircle->ScreenWidth() / 2) - (tpCircle->GetTextSize(mStart).x / 2 * (2)), (2 * tpCircle->ScreenHeight() / 3) - (tpCircle->GetTextSize(mStart).y / 2 * (2) ), mStart, olc::WHITE, (2));
	}
}

void cGameEnd::DestroyTitle() {

}