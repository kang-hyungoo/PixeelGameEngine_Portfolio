#pragma once
// Override base class with your custom functionality
#include "olcPixelGameEngine.h"
#include "Unit.h"
#include "Enemy.h"
#include "Define.h"
#include "Bullet.h"
#include "User.h"
#include "GamePlay.h"
#include "GameTitle.h"
#include "GameEnd.h"
#include "Tile.h"
#include "Scroll.h"
#include "Level.h"
#include "Map.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class cCircleShootor : public olc::PixelGameEngine
{
private:
	cGamePlay mGamePlay;
	cGameTitle mGameTitle;
	cGameEnd mGameEnd;
	SCENE mSceneState;
public:
	cCircleShootor()
	{
		// Name you application
		srand(time(nullptr));
		sAppName = "cCircleShootor";
	}

public:
	bool OnUserCreate() override
	{
		srand(time(nullptr));
		mSceneState = SCENE::TITLE;
		mGameTitle.CreateTitle(this);
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		switch (mSceneState) {
			case SCENE::TITLE:
			{
				mGameTitle.UpdateTitle(fElapsedTime, this);
				mGameTitle.DisplayTitle(this);

				if (GetKey(olc::Key::SPACE).bReleased) {
					mSceneState = SCENE::READY_PLAYGAME;
				}
			}
			break;
			case SCENE::READY_PLAYGAME:
			{
				mGamePlay.CreatePlayGame(this);
				mGameTitle.DestroyTitle();
				mSceneState = SCENE::PLAYGAME;
			}
			break;
			case SCENE::PLAYGAME:
			{
				if (GetKey(olc::Key::ESCAPE).bReleased) {
					mSceneState = SCENE::TITLE;
					mGamePlay.DestroyPlayGame();
					mGameTitle.CreateTitle(this);
				}
				else if (GetKey(olc::Key::R).bReleased) {
					mGamePlay.DestroyPlayGame();

					mGamePlay.CreatePlayGame(this);
				}
				else {
					mGamePlay.UpdatePlayGame(fElapsedTime, this);
					mGamePlay.DisplayPlayGame(this);
				}

				if (mGamePlay.GetGameOver()) {
					mGameEnd.CreateTitle(this, mGamePlay.GetScore());
					mGamePlay.DestroyPlayGame();
					mSceneState = SCENE::ENDGAME;
				}
			}
			break;
			case SCENE::ENDGAME:
			{
				mGameEnd.UpdateTitle(fElapsedTime, this);
				mGameEnd.DisplayTitle(this);
				if (GetKey(olc::Key::SPACE).bReleased) {
					mSceneState = SCENE::TITLE;
					mGameEnd.DestroyTitle();
				}
			}
			break;
		}


		return true;
	}

	bool OnUserDestroy() override
	{
		return true;
	}
};
