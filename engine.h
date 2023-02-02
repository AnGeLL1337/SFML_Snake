//engine.h -- class of snake game engine
#ifndef ENGINE_H_
#define ENGINE_H_

#include<SFML/Graphics.hpp>
//#include <time>
#include "snake.h"
#include "fruit.h"
#include "snakeui.h"
using namespace sf;

class Engine
{
private:
	//Window to render all the stuff
	RenderWindow window;

	Texture whiteTile, redTile, greenTile;
	Sprite whiteSprite, redSprite, greenSprite;

	//Main snake object
	Snake snake;

	//Fruit object
	Fruit fruit;

	//Game interface
	SnakeUI snakeUI;

	//Flag indicating the status of the game, lost or not lost
	bool gameFailed;

	//Game score
	int score;

	//Current level, affects to speed
	int level;

	//Amount of tiles by x coordinate
	int fieldWidth;
	//Amount of tiles by y coordinate
	int fieldHeight;

	//Size of tile in pixels
	int tileSize;

	//This function will draw all the objects
	void draw();

	//This function will scan user's input every frame
	void input();

	//This function will be called every frame to update objects state
	void update(float dtAsSeconds);
public:
	//Default constructor
	Engine();

	//Start will call all the private methods
	void start();

	//Restart will reset all the values to default
	void restart();
};

#endif
