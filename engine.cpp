// engine.cpp -- methods defenitions for class Engine (engine.h)
#include "constants.h"
#include "engine.h"
#include <iostream>
Engine::Engine()
	: fieldHeight(36), fieldWidth(50), tileSize(16),
	snake(Vector2i(10, 10), Direction::Down, 6, snakeSpeed),
	score(0), level(1)
{
	using namespace sf;
	Vector2f resolution;
	resolution.x = fieldWidth * tileSize;
	resolution.y = fieldHeight * tileSize + 40;

	window.create(VideoMode(windowWidth, windowHeight), mainWindowTitle, mainWindowStyle);
	// Load image of grey tile
	whiteTile.loadFromFile(imagesFolder + "/grey.png");
	// Load image of apple tile
	redTile.loadFromFile(imagesFolder + "/apple.png");
	// Load image of green tile
	greenTile.loadFromFile(imagesFolder + "/green.png");

	// Set textures to sprites
	whiteSprite.setTexture(whiteTile);
	redSprite.setTexture(redTile);
	greenSprite.setTexture(greenTile);

	// Set random position for the fruit
	fruit.setPosition(rand() % fieldWidth, rand() % fieldHeight);
}

void Engine::start()
{
	// Time counting
	Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		if (!gameFailed)
		{
			// Manage snake self-eating
			for (int i = 1; i < snake.getLength(); i++)
				if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
				{
					snakeUI.showYouLose();
					gameFailed = true;
					break;
				}

			// Manage fruit eating
			if (snake[0].x == fruit.getX() && snake[0].y == fruit.getY())
			{
				snake.addPoint();

				fruit.setPosition(rand() % fieldWidth,
					rand() % fieldHeight);

				score += fruitScore;
				snakeUI.setScore(score);

				if (score % levelScore == 0)
				{
					level++;
					// Increase speed
					snake.setSpeed(snake.getSpeed() + levelSpeedup);
				}
				/* Debugging

				std::cout << snake.getSpeed() << std::endl
					<< level << std::endl
					<< levelSpeedup << std::endl
					<< std::endl;
				*/
			}

			// Manage snake teleport
			if (snake[0].x > fieldWidth)
				snake[0].x = 0;
			else if (snake[0].x < 0)
				snake[0].x = fieldWidth;
			else if (snake[0].y > fieldHeight - 1)
				snake[0].y = 0;
			else if (snake[0].y < 0)
				snake[0].y = fieldHeight - 1;
		}

		// Scan for user input
		input();

		// Update all objects state
		update(dtAsSeconds);

		draw();
	}
}

void Engine::input()
{

	if (Keyboard::isKeyPressed(Keyboard::Down))
		snake.setDirection(Direction::Down);
	else if (Keyboard::isKeyPressed(Keyboard::Left))
		snake.setDirection(Direction::Left);
	else if (Keyboard::isKeyPressed(Keyboard::Right))
		snake.setDirection(Direction::Right);
	else if (Keyboard::isKeyPressed(Keyboard::Up))
		snake.setDirection(Direction::Up);
	else if (Keyboard::isKeyPressed(Keyboard::R))
	{
		snakeUI.hideYouLose();
		restart();
	}
}

void Engine::draw()
{
	// Clear window
	window.clear(sf::Color::White);

	// Draw field
	for (int i = 0; i < fieldWidth; i++)
		for (int j = 0; j < fieldHeight; j++)
		{
			whiteSprite.setPosition(i * tileSize, j * tileSize);
			window.draw(whiteSprite);
		}

	// Draw snake tiles
	for (int i = 0; i < snake.getLength(); i++)
	{
		greenSprite.setPosition(snake.getPoint(i).x * tileSize,
			snake.getPoint(i).y * tileSize);

		window.draw(greenSprite);
	}

	// Draw fruit
	redSprite.setPosition(fruit.getPosition().x * tileSize,
		fruit.getPosition().y * tileSize);
	window.draw(redSprite);

	// Draw UI
	window.draw(snakeUI);

	// Display all the drawed content
	window.display();
}

void Engine::update(float dtAsSeconds)
{
	if (!gameFailed)
		snake.update(dtAsSeconds);
	snakeUI.update(dtAsSeconds);
}

void Engine::restart()
{
	snake = Snake(Vector2i(10, 10), Direction::Down, 6, snakeSpeed);
	score = 0;
	level = 1;

	gameFailed = false;

	// Set random position for the fruit
	fruit.setPosition(rand() % fieldWidth,
		rand() % fieldHeight);
}