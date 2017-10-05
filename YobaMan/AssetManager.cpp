#include "stdafx.h"
#include "AssetManager.h"
#include <iostream>

using namespace std;

const vector<string> AssetManager::textureNames = {
	"wall.png",
	"yoba-sprite.png"
};

AssetManager::AssetManager()
{
	for (vector<int>::size_type i = 0; i != textureNames.size(); i++) {
		stringstream path; 
		path << "graphics/";
		path << textureNames[i];
		sf::Texture texture;
		if(! texture.loadFromFile(path.str())) throw FileLoadError();

		textures[textureNames[i]] = texture;
	}
}


AssetManager::~AssetManager()
{
}
