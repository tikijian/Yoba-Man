#include "stdafx.h"
#include "Tile.h"

Tile::Tile()
{
	walls.emplace("north", false);
	walls.emplace("east", false);
	walls.emplace("south", false);
	walls.emplace("west", false);

	initialize();
}

Tile::Tile(bool north, bool east, bool south, bool west)
{
	walls.emplace("north", north);
	walls.emplace("east", east);
	walls.emplace("south", south);
	walls.emplace("west", west);

	initialize();
}

bool Tile::hasWallAt(const string side)
{
	return walls.at(side) ? true : false;
}


Tile::~Tile()
{
}

void Tile::draw(RenderTarget & target, RenderStates states) const
{
}
