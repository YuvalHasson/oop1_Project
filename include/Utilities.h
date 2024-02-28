#pragma once

struct Vertex {
	float m_x;
	float m_y;
};

struct Size {
	float m_x;
	float m_y;
};

const int OBJ_AMOUNT = 14;
const int SOUND_AMOUNT = 13;
const int BACK_SOUND_AMNT = 2;

enum GAME_STATE { MAIN_MENU, NEW_GAME, HELP, EXIT };

#define windowHeight 890
#define WindowWidth 950

#define statusBarHeight 60
#define statusBarWidth 950

#define ADDTIME 5

#define MouseSpeed 165.f
#define CatSpeed 100.f

#define FREEZETIME 3

#define LVLCMPLT 25
#define CHEESEPOINTS 10
#define PRESENTPOINTS 5
#define DOORPOINTS 2

namespace TEXTURE
{
	constexpr int mouse = 0;
	constexpr int cat = 1;
	constexpr int cheese = 2;
	constexpr int door = 3;
	constexpr int key = 4;
	constexpr int present = 5;
	constexpr int wall = 6;
	constexpr int background = 7;
	constexpr int menu = 8;
	constexpr int button = 9;
	constexpr int help = 10;
	constexpr int heart = 11;
	constexpr int score = 12;
	constexpr int clock = 13;
}

namespace SOUND
{
	constexpr int key_pickup = 0;
	constexpr int door_open = 1;
	constexpr int eating = 2;
	constexpr int scream = 3;
	constexpr int present = 4;
	constexpr int time_over = 5;
	constexpr int level_up = 6;
	constexpr int win = 7;
	constexpr int lose = 8;
	constexpr int freeze = 9;
	constexpr int unfreeze = 10;
	constexpr int life = 11;
	constexpr int add_time = 12;
}

namespace BACKGROUND
{
	constexpr int background = 0;
	constexpr int menu = 1;
}