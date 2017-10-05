#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <SFML\Graphics.hpp>

class AssetManager
{
	AssetManager();
	~AssetManager();
public:
	class FileLoadError {};
	static AssetManager & Instance()
	{
		static AssetManager s;
		return s;
	}

	std::unordered_map<std::string, sf::Texture> textures;

	const sf::Texture& get(const std::string & tex) { return textures[tex]; };

	const static std::vector<std::string> textureNames;
};

