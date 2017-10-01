#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "Game.h"

int main()
{
	srand(time(0));
	sf::Image icon;
	icon.loadFromFile("graphics/icon.png");
	int windowStyle = !sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close;
	sf::RenderWindow window(sf::VideoMode(600, 700), "Yoba-Man", windowStyle);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	Game game(window);
	game.run();

    return 0;
}

