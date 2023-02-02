#include "snake.h"
#include "constants.h"
#include <iostream>

Snake::Snake()
	:direction(Direction::Down),
	body(std::vector<sf::Vector2i>(snakeLength)), speed(snakeSpeed),
	delay(maxDelay - snakeSpeed * 0.01)
{
}

//Parametric constructor
Snake::Snake(sf::Vector2i pos, Direction dir, int len, float speed)
	:direction(Direction::Down),
	body(std::vector<sf::Vector2i>(len)), speed(speed),
	delay(maxDelay - speed * 0.01F)
{
	body[0].x = pos.x;
	body[0].y = pos.y;
}

//Copy constructor
Snake::Snake(const Snake& s)
	:direction(Direction::Down),
	body(std::vector<sf::Vector2i>(s.body.size())), speed(speed),
	delay(maxDelay - speed * 0.01F)
{
}

//Desctructor
Snake::~Snake()
{
}

//Operator overloading
Snake& Snake::operator=(const Snake& s)
{
	if (this == &s) return *this;
	else
	{
		body = s.body;
		direction = s.direction;
		speed = s.speed;
		return *this;
	}
}

//Return current position 
sf::Vector2i Snake::getPosition()
{
	return body[0];
}

//Get point of snake by index
sf::Vector2i& Snake::getPoint(int index)
{
	return body[index];
}

//prevent changing snake in opposite direction
void Snake::setDirection(Direction dir)
{
	if (dir == Direction::Left)
	{
		if (direction != Direction::Right)
			direction = dir;
	}
	else if (dir == Direction::Right)
	{
		if (direction != Direction::Left)
			direction = dir;
	}
	else if (dir == Direction::Up)
	{
		if (direction != Direction::Down)
			direction = dir;
	}
	else if (dir == Direction::Down)
	{
		if (direction != Direction::Up)
			direction = dir;
	}
}

//Set new length for the snake
int Snake::getLength()
{
	return body.size();
}


//Add one more point to snake, used when snake eats fruit
void Snake::addPoint()
{
	needAddPoint = true;
}

//Move every point to the position of previous point (make snake move)
void Snake::makeMove()
{
	int snakeLength = body.size();

	sf::Vector2i tailPoint = body[getLength() - 1];

	for (int i = snakeLength - 1; i > 0; --i)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}

	if (needAddPoint)
	{
		needAddPoint = false;
		body.push_back(tailPoint);
	}

	//Move head, corresponding to direction
	switch (direction)
	{
	case Up:
		body[0].y -= 1;
		break;
	case Down:
		body[0].y += 1;
		break;
	case Left:
		body[0].x -= 1;
		break;
	case Right:
		body[0].x += 1;
		break;
	default:
		break;
	}
}

void Snake::setSpeed(int s)
{
	speed = s;
	delay = maxDelay - s * 0.01F;
}

int Snake::getSpeed()
{
	return speed;
}

void Snake::update(float elapsedTime)
{
	elapsedTimeSumm += elapsedTime;
	if (elapsedTimeSumm >= delay)
	{
		makeMove();
		elapsedTimeSumm = 0;
	}
}

sf::Vector2i& Snake::operator[](int i)
{
	return body[i];
}