#include "Renderer.h"
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	Renderer renderer;
	renderer.init();
	renderer.render(RGB(0,0,0));
	return 0;
}
