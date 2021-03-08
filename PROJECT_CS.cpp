#define OLC_PGE_APPLICATION
#include "CircleShootor.h"

int main()
{
	cCircleShootor tCircleShootor;
	if (tCircleShootor.Construct(GAME_SIZE_WIDTH, GAME_SIZE_HEIGHT, 1, 1))
		tCircleShootor.Start();
	return 0;
}
