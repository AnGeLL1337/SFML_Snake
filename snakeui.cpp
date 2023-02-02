#include "snakeui.h"
#include "strings.h"
#include "constants.h"

SnakeUI::SnakeUI()
{
	looseVisible = false;

	mainFont.loadFromFile(resourcesFolder + "/" + fontsFolder + "/Explora-Regular.ttf");

	//Text for score indicator
	scoreText.setFont(mainFont);
	scoreText.setString(strings::scoreString + " 0");
	scoreText.setPosition(50, windowHeight - 35);
	scoreText.setFillColor(sf::Color::Black);

	//Lose text
	youLooseText.setFont(mainFont);
	youLooseText.setString(strings::youlooseString);
	youLooseText.setPosition(280, 300);
	youLooseText.setFillColor(sf::Color::Black);
	youLooseText.setOutlineColor(sf::Color::White);
	youLooseText.setOutlineThickness(3);
	youLooseText.setCharacterSize(50);

	//Press R to Restart Text
	pressToRestartText.setFont(mainFont);
	pressToRestartText.setString(strings::pressRToRestart);
	pressToRestartText.setPosition(300, 350);
	pressToRestartText.setFillColor(sf::Color::Black);
	pressToRestartText.setOutlineColor(sf::Color::White);
	pressToRestartText.setOutlineThickness(3);
	pressToRestartText.setCharacterSize(40);
}

SnakeUI::~SnakeUI()
{
}

void SnakeUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(scoreText);
	if (looseVisible) {
		target.draw(youLooseText);
		target.draw(pressToRestartText);
	}
}

void SnakeUI::setScore(int score)
{
	scoreText.setString(strings::scoreString + " " + std::to_string(score));
}

void SnakeUI::showYouLose()
{
	looseVisible = true;
}

void SnakeUI::hideYouLose()
{
	looseVisible = false;
}

void SnakeUI::update(float elapsedTime)
{
	if (looseVisible) {
		elapsedTimeSumm += elapsedTime;

		if (elapsedTimeSumm >= 0.5)
		{
			if (youLooseText.getFillColor() == sf::Color::Black)
			{
				youLooseText.setFillColor(sf::Color::White);
				youLooseText.setOutlineColor(sf::Color::Black);
			}
			else
			{
				youLooseText.setFillColor(sf::Color::Black);
				youLooseText.setOutlineColor(sf::Color::White);
			}

			elapsedTimeSumm = 0;
		}
	}
}