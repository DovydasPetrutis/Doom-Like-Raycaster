#include "Framebuffer.h"

Framebuffer::Framebuffer(int width, int height)
{
	this->height = height;
	this->width = width;
	colors.reserve(width * height);
	for (int i = 0; i < width * height; i++)
	{
		colors.push_back(RGB(0, 0, 0));
	}
}

void Framebuffer::setRegionColor(int xStart, int yStart,int width, int height, RGB color)
{
	for (int y = yStart; y < yStart + height; y++)
	{
		for (int x = xStart; x < xStart + width;x++)
		{
			int idx = x + this->width * y;
			if (idx >= Settings::RESOLUTION_HEIGHT * Settings::RESOLUTION_WIDTH || idx < 0)
			{
				std::cout << "You are drawing outside Boundaries: " << "X: " << x << " Y: " << y << '\n';
			}
			else
			{
				colors[x + this->width * y] = color;
			}
		}
	}
}

RGB Framebuffer::returnColor(int x, int y)
{
	return colors[x + width * y];
}
