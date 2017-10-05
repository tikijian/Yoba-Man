#pragma once
#include "SFML\Graphics.hpp"
#include <unordered_map>
#include <string>

using namespace sf;
using namespace std;

class Tile : RectangleShape
{
	bool empty = true;
	Sprite wallSprites[4];

public:
	static const int SIZE = 64;
	static const int THICK = 3;
	unordered_map<string, bool> walls;
	void initialize(float xPos, float yPos);

	Tile();
	Tile(bool north, bool east, bool south, bool west);

	bool hasWallAt(const string);
	bool isEmpty() { return empty; };
	
	void draw(RenderWindow &);
	~Tile();
};

