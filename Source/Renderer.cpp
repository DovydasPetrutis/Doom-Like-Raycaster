#include "Renderer.h"


void Renderer::init_read_wall_file()
{
	std::ifstream file("Walls.txt");
	std::string line = "";
	std::getline(file, line); // Comment text remove
	while (std::getline(file, line))
	{
		walls.push_back(Utils::read_id_x_y_wall(line));
	}
}

void Renderer::init()
{
	Renderer::init_read_wall_file();
}

void Renderer::fill_map_background_color(RGB color)
{
	mapFbo.setRegionColor(0, 0, Settings::RESOLUTION_WIDTH, Settings::RESOLUTION_HEIGHT, color);
}

void Renderer::render_to_ppm_map()
{
	std::ofstream output("output.ppm");

	output << "P6\n";
	output << mapFbo.width << " " << mapFbo.height << "\n";
	output << "255" << "\n";

	for (int y = 0; y < mapFbo.height; y++)
	{
		for (int x = 0; x < mapFbo.width;x++)
		{
			RGB color = mapFbo.returnColor(x, y);
			output << color.r << color.g << color.b;
		}
	}
	output.close();
}

void Renderer::draw_walls_map()
{
	for (Wall &wall : walls)
	{
		uint16_t wallX = Settings::WALL_SIZE + wall.x * Settings::WALL_SIZE;
		uint16_t wallY = Settings::WALL_SIZE + wall.y * Settings::WALL_SIZE;
		if (wall.id == 1)
		{
			mapFbo.setRegionColor(wallX,wallY, Settings::WALL_SIZE * wall.width, Settings::WALL_SIZE * wall.height, Settings::WALL_COLOR);
		}
	}
}

void Renderer::draw_walls(Framebuffer &fbo)
{
	Utils::drawBoundaries(fbo);
	Renderer::draw_walls_map();
}

void Renderer::render(RGB backgroundColorFill)
{
	fill_map_background_color(backgroundColorFill);
	draw_walls(mapFbo);
	render_to_ppm_map();
}
