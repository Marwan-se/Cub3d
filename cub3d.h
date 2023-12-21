
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 512
#define TRUE 1
#define FALSE 0
#define TILE_SIZE 64
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define FOV_ANGLE (60 * M_PI / 180)
#define NUM_RAYS WINDOW_WIDTH
#define MINI_MAP_SACALE_FACTOR 0.5

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct info
{
    int		facingDown;
	int		facingRight;
	float	xIntercept;
	float	yIntercept;
	float	xStep;
	float	yStep;
	float	wallHitX;
	float	wallHitY;
	int		wallContent;
	float	nextX;
	float	nextY;
	float	xCheck;
	float	yCheck;
	int		foundWallHit;
} info;

typedef struct Ray
{
    float   rayAngle;
    float   wallHitX;
    float   wallHitY;
    float   distance;
    int     HitVertical;
    int     isFacingUp;
    int     isFacingDown;
    int     isFacingLeft;
    int     isFacingRight;
    int     Content;
} rays[NUM_RAYS];

typedef struct Player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
} Player;