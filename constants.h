#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>
#include <SFML/Graphics.hpp>

//Folder with all the files that will be used by the game
const std::string resourcesFolder = "resources";
//Folder with images
const std::string imagesFolder = "images";
//Folder with fonts
const std::string fontsFolder = "fonts";

//This text will be displayed as a title of a window
const std::string mainWindowTitle = "The Snake Game";

//Initial window style
const int mainWindowStyle = sf::Style::Default;

//Initial window width
const int windowWidth = 800;
//Initial window height
const int windowHeight = 600;

//Initial snake length
const int snakeLength = 4;
//Initial snake speed
const int snakeSpeed = 70;
//Max delay for every snake
const float maxDelay = 1.F;

//How many points of score one fruit will add
const int fruitScore = 10;

//How many points of score player needs to gain, to level up
const int levelScore = 100;
//How many speed will add in case on level up
const int levelSpeedup = 10;

#endif 