#include <SFML/Graphics.hpp>
#include "engine.h"
#include <cstdlib>

int main()
{
	srand(time(0));

	Engine engine;
	engine.start();

	return 0;
}