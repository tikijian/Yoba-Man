#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Game
{
	class FileLoadError {};
	RenderWindow& window;
	
	Texture playerTex;
	Texture wallsTex;

	Sprite player;
	Sprite leftWall;
	Sprite rightWall;
public:
	Game(sf::RenderWindow&);
	~Game();

	bool run();
};

