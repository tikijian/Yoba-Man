#include "stdafx.h"
#include "Tile.h"
#include "AssetManager.h"

Tile::Tile()
{
	walls.emplace("north", false);
	walls.emplace("east", false);
	walls.emplace("south", false);
	walls.emplace("west", false);
}

Tile::Tile(bool north, bool east, bool south, bool west)
{
	walls.emplace("north", north);
	walls.emplace("east", east);
	walls.emplace("south", south);
	walls.emplace("west", west);
}

void Tile::initialize(float xPos, float yPos)
{
	AssetManager& assets = AssetManager::Instance();

	// set not-empty flag if any wals
	int i = 0;
	for (auto it : walls) {
		if (!it.second) continue;

		empty = false;
		wallSprites[i].setTexture(assets.get("wall.png"));

		if (it.first == "west") {
			wallSprites[i].setPosition(xPos, yPos);
		}
		else if (it.first == "east") {
			wallSprites[i].setPosition(xPos + (float) SIZE - (float) THICK, yPos);
		}
		else if (it.first == "north") {
			wallSprites[i].setPosition(xPos, yPos);
			wallSprites[i].setRotation(-90.0f);
		}
		else if (it.first == "south") {
			wallSprites[i].setPosition(xPos, yPos + (float) SIZE);
			wallSprites[i].setRotation(-90.0f);
		}
		i++;
	}
}

bool Tile::hasWallAt(const string side)
{
	return walls.at(side) ? true : false;
}

void Tile::draw(RenderWindow & wnd)
{
	if (empty) return;
	for (int i = 0; i < 4; i++) {
		wnd.draw(wallSprites[i]);
	}
}

Tile::~Tile()
{
}
