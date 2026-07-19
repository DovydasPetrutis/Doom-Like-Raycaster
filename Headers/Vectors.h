#pragma once
#include <iostream>

struct RGB
{
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
	RGB(uint8_t r, uint8_t g, uint8_t b) :
		r(r), g(g), b(b){};
};

struct Wall
{
	uint16_t id = 0;
	uint16_t x = 0;
	uint16_t y = 0;
	uint16_t width = 0;
	uint16_t height = 0;
	Wall(uint16_t id, uint16_t x, uint16_t y,uint16_t width,uint16_t height) :
		id(id), x(x), y(y), width(width), height(height) {};
};