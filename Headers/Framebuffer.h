#pragma once
#include <vector>
#include "Vectors.h"
#include "Settings.h"

class Framebuffer
{
public:
	int width = 0;
	int height = 0;
	std::vector<RGB> colors;
	Framebuffer(int width, int height);
	void setRegionColor(int xStart, int yStart, int width, int height, RGB color);
	RGB returnColor(int x, int y);
};