#pragma once
#include "SFML\Graphics.hpp"
#include <unordered_map>
#include <string>

using namespace sf;
using namespace std;

class Tile : public Drawable
{
	void initialize();
public:
	static const int SIZE = 64;
	unordered_map<string, bool> walls;

	Tile();
	Tile(bool north, bool east, bool south, bool west);

	bool hasWallAt(const string);

	virtual void draw(RenderTarget & target, RenderStates states) const override;
	~Tile();
};

