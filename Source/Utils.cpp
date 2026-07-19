#include "Utils.h"


void Utils::drawBoundaries(Framebuffer& fbo)
{
	for (int y = 0; y < Settings::RESOLUTION_HEIGHT;y = y + Settings::WALL_SIZE)
	{
		fbo.setRegionColor(0, y, Settings::WALL_SIZE, Settings::WALL_SIZE, Settings::WALL_COLOR); // Left
	}
	for (int y = 0; y < Settings::RESOLUTION_HEIGHT;y = y + Settings::WALL_SIZE)
	{
		fbo.setRegionColor(Settings::RESOLUTION_WIDTH - Settings::WALL_SIZE, y, Settings::WALL_SIZE, Settings::WALL_SIZE, Settings::WALL_COLOR); // Right
	}
	for (int x = 0; x < Settings::RESOLUTION_WIDTH;x = x + Settings::WALL_SIZE)
	{
		fbo.setRegionColor(x, 0, Settings::WALL_SIZE, Settings::WALL_SIZE, Settings::WALL_COLOR); // Top
	}
	for (int x = 0; x < Settings::RESOLUTION_WIDTH;x = x + Settings::WALL_SIZE)
	{
		fbo.setRegionColor(x, Settings::RESOLUTION_HEIGHT - Settings::WALL_SIZE, Settings::WALL_SIZE, Settings::WALL_SIZE, Settings::WALL_COLOR); // Bottom
	}
}

Wall Utils::read_id_x_y_wall(std::string line)
{
	Wall wall(0, 0, 0, 0, 0);
	uint8_t commaLocation = 0;
	for (int i = 0; i < 5;i++)
	{
		commaLocation = line.find(',');
		if     (i == 0) wall.id     = stoi(line.substr(0, commaLocation));
		else if(i == 1) wall.x      = stoi(line.substr(0, commaLocation));
		else if(i == 2) wall.y      = stoi(line.substr(0, commaLocation));
		else if(i == 3) wall.width  = stoi(line.substr(0, commaLocation));
		else if(i == 4) wall.height = stoi(line.substr(0, commaLocation));
		if(i != 4) line = line.substr(commaLocation + 1, line.length());
	}
	return wall;
}
