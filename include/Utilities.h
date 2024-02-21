#pragma once

struct Vertex {
	float m_x;
	float m_y;
};

struct Size {
	float m_x;
	float m_y;
};

const int OBJ_AMOUNT = 7;


#define windowHeight 890
#define WindowWidth 950

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
}
