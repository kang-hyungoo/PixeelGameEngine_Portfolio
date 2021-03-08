#pragma once

#define OLC_PGE_APPLICATION
#define PI 3.141592f
#define ENEMY_MAX 10
#define BULLET_MAX 80
#define LEFT_BUTTON false
#define RIGHT_BUTTON true
#define THETA 180
#define GAME_SIZE_WIDTH 480
#define GAME_SIZE_HEIGHT 800
#define MAP_SIZE_WIDTH 32
#define MAP_SIZE_HEIGHT 32
#define UNIT_SIZE 15
#define BULLET_SIZE 6

#define LEVEL_UPDATE_TIME 10.0f

#define MAP_WIDTH GAME_SIZE_WIDTH / MAP_SIZE_WIDTH
#define MAP_HEIGHT GAME_SIZE_HEIGHT / MAP_SIZE_HEIGHT

enum BULLETMODE {

	AIM = 0,
	CIRCLE = 1
};

enum AIMODE {
	UL = 0,	//UP + LEFT
	UX = 1,	//UP + X
	UR = 2,	//UP + RIGHT


	XL = 3,	//X + LEFT
	XX = 4,	//X + X
	XR = 5,	//X + RIGHT
	

	DL = 6,	//DOWN + LEFT
	DX = 7,	//DOWN + X
	DR = 8,	//DOWN + RIGHT
	STOP = 9
};

struct sMouse_Point {
	int tX;
	int tY;
};

enum SCENE
{
	TITLE = 0,
	READY_PLAYGAME = 1,
	PLAYGAME = 2,
	ENDGAME = 3
};