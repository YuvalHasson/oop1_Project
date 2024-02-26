#pragma once

struct Vertex {
	float m_x;
	float m_y;
};

struct Size {
	float m_x;
	float m_y;
};

const int OBJ_AMOUNT = 11;
const int SOUND_AMOUNT = 11;

enum GAME_STATE { MAIN_MENU, NEW_GAME, HELP, EXIT };

#define windowHeight 890
#define WindowWidth 950

#define statusBarHeight 60
#define statusBarWidth 950

#define MouseSpeed 150.f
#define CatSpeed 100.f

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
}

namespace SOUND
{
	constexpr int key_pickup = 0;
	constexpr int door_open = 1;
	constexpr int eating = 2;
	constexpr int scream = 3;
	constexpr int present = 4;
}