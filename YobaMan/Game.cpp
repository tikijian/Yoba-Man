#include "stdafx.h"
#include "Game.h"

using namespace sf;

Game::Game(RenderWindow &wnd) :
	window(wnd)
{

	if(! playerTex.loadFromFile("graphics/yoba-sprite.png")) throw FileLoadError();
	if(! wallsTex.loadFromFile("graphics/walls.png")) throw FileLoadError();

	player.setTexture(playerTex);
	player.setTextureRect(IntRect(0, 0, 700, 700));
	player.setScale(0.08f, 0.08f);
	player.setPosition(100.0f, 100.0f);

	leftWall.setTexture(wallsTex);
	leftWall.setTextureRect(IntRect(0, 0, 64, 64));
	leftWall.setPosition(100.0f, 100.0f);
	leftWall.setScale(2.0f, 2.0f);
	rightWall.setTexture(wallsTex);
	rightWall.setTextureRect(IntRect(192, 0, 64, 64));
	rightWall.setPosition(100.0f, 100.0f);

}

Game::~Game()
{
}


bool Game::run()
{
	Clock clock;

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}

				// game process inut

			}
		}

		/*---------*/
		// Updates
		/*---------*/
		sf::Time dt = clock.restart();

		//-----------


		/*---------*/
		// Rendering
		/*---------*/
		window.clear(sf::Color::Black);

		window.draw(player);
		window.draw(leftWall);
		window.draw(rightWall);

		window.display();
		//-----------
	}
	return true;
}

