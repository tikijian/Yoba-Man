#include "stdafx.h"
#include "Game.h"
#include "AssetManager.h"
#include "Tile.h"

using namespace sf;

Game::Game(RenderWindow &wnd) :
	window(wnd)
{
	AssetManager &aManager = AssetManager::Instance();

	player.setTexture(aManager.get("yoba-sprite.png"));
	player.setTextureRect(IntRect(0, 0, 700, 700));
	player.setScale(0.08f, 0.08f);
	player.setPosition(302.0f, 102.0f);
}

Game::~Game()
{
}


bool Game::run()
{
	Clock clock;
	Tile emptyWall;
	Tile wall(true, true, true, true);

	emptyWall.initialize(100.0f, 100.0f);
	wall.initialize(300.0f, 100.0f);

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
		emptyWall.draw(window);
		wall.draw(window);

		window.display();
		//-----------
	}
	return true;
}

