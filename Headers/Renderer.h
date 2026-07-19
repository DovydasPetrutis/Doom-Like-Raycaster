#pragma once
#include <fstream>
#include "Utils.h"
#include "Framebuffer.h"
#include "Vectors.h"
#include "Settings.h"

class Renderer
{
public:
	Framebuffer mapFbo{ Settings::RESOLUTION_WIDTH, Settings::RESOLUTION_HEIGHT };
	std::vector<Wall> walls;

	void init_read_wall_file();
	void init();
	void fill_map_background_color(RGB color);
	void render_to_ppm_map();
	void draw_walls_map();
	void draw_walls(Framebuffer& fbo);
	void render(RGB backgroundColorFill);
};