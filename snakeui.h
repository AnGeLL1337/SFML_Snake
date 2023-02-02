#ifndef SNAKE_UI_H_
#define SNAKE_UI_H_

#include<SFML/Graphics.hpp>

class SnakeUI :
	public sf::Drawable
{
private:
	sf::Font mainFont;
	sf::Text scoreText;
	sf::Text youLooseText;
	sf::Text pressToRestartText;

	bool looseVisible;
	float elapsedTimeSumm;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	SnakeUI();
	~SnakeUI();

	void setScore(int score);
	void showYouLose();
	void hideYouLose();
	void update(float elapsedTime);
};
#endif