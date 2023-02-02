//fruit.h - Fruit class, that describes fruit that snake can eat
#ifndef FRUIT_H_
#define FRUIT_H_

#include<SFML/Graphics.hpp>

class Fruit
{
private:
	int score;
	sf::Vector2i position;
public:
	Fruit()
		:score(0)
	{
	}

	Fruit(int s, sf::Vector2i pos)
		:score(s), position(pos)
	{
	}

	int getScore()
	{
		return score;
	}

	sf::Vector2i& getPosition()
	{
		return position;
	}

	void setPosition(int x, int y)
	{
		position.x = x;
		position.y = y;
	}

	int getX()
	{
		return position.x;
	}

	int getY()
	{
		return position.y;
	}

	~Fruit()
	{
	}
};

#endif

