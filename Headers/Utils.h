#pragma once
#include <iostream>
#include <string>
#include "Framebuffer.h"
#include "Settings.h"

class Utils
{
public:
	static void drawBoundaries(Framebuffer &fbo);
	static Wall read_id_x_y_wall(std::string line);
};