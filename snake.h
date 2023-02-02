#ifndef SNAKE_H_
#define SNAKE_H_

#include <SFML/Graphics.hpp>
#include <vector>

enum Direction {
	Up = 0,
	Down = 1,
	Left = 2,
	Right = 3
};

class Snake {
private:
	//Vector of points (Vector2i has x and y int values), that stores position of all squares of snake
	std::vector<sf::Vector2i> body;

	//Current movement direction of snake
	Direction direction;

	//Snake movement speed
	float speed;

	//Delay between each snake move
	float delay;

	//Summ of elapsed times of frames that passed from engine
	float elapsedTimeSumm;

	//If value is true, makeMove() function will add new point to snake
	bool needAddPoint;

	/*If value is true, makeMove() function will turn snakes head
	 *and snake will not change direction until next move if it set once */
	bool needToTurn;

public:
	//Default constructor
	Snake();
	//Parametric constructors
	Snake(sf::Vector2i pos, Direction dir, int length, float speed);
	//Copy constructor
	Snake(const Snake& s);
	//Destructor
	~Snake();
	//Equality operator overloading
	Snake& operator=(const Snake& s);

	//Get point of snake by index
	sf::Vector2i getPosition();
	//Get point of snake by index
	sf::Vector2i& getPoint(int index);
	//Set new direction
	void setDirection(Direction dir);
	//Set new length for the snake
	int getLength();
	//Set new speed for the snake
	void setSpeed(int s);
	//Get speed
	int getSpeed();
	//Add one more point to snake
	void addPoint();
	//Move every point to the position of previous point (make snake move)
	void makeMove();
	//Function called by engine every frame, check ability snake to move at this moment
	void update(float elapsedTime);
	//Overloaded index operator to get specific point
	sf::Vector2i& operator[](int i);
};

#endif
