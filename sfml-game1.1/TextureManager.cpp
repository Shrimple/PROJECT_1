#include "TextureManager.h"
#include <boost\utility.hpp>

using namespace csp;

TextureManager::TextureManager() {
}

bool TextureManager::init(MNEngine * const ptr){
	enginePtr = ptr;
	std::cout << "-TextureManager init @ " << boost::addressof(*this) << "." << std::endl;
	std::cout << "Engine ptr @ " << enginePtr << "." << std::endl;
	return false;
}

int TextureManager::loadTex(std::string fileName) {
	TextureData td;
	sf::Texture tex;
	int i = 0;

	for (TextureData td : textureVector) {
		if (td.fileName.compare(fileName) == 0) {
			std::cout << "texture exists @ index #" + i << std::endl;
			return i;
		}
		i++;
	}

	if (!tex.loadFromFile(fileName)) {
		std::cout << "invalid texture filename." << std::endl;

	}
	else {
		td.fileName = fileName;
		td.tex = tex;

		//cout << "loaded : " << fileName << " with index " << textureVector.size() << endl;
		tex.loadFromFile(fileName);
		textureVector.push_back(td);
	}

	printf("texVecSize:%d\n", textureVector.size());

	return textureVector.size() - 1;
}

sf::Texture &TextureManager::get(int i) {
	if ((i >= 0) && (textureVector.size() - 1 >= i)) {
		//cout << "texture loaded from vector @ " + i << endl;
		return textureVector.at(i).tex;

	}
	else {
		std::cout << "tried to load a null texture! (-1)" << std::endl;
	}

	std::cout << "loading placeholder tex from vector." << std::endl;
	return textureVector.at(0).tex;
}

sf::Texture &TextureManager::get(std::string filename) {
	
	for (int i = 0; i < textureVector.size(); i++) {
		if (textureVector.at(i).fileName == filename)
			return textureVector.at(i).tex;
	}

	std::cout << "tried to load a null texture! (-1)" << std::endl;
	std::cout << "loading placeholder tex from vector." << std::endl;
	return textureVector.at(0).tex;
}

TextureManager::~TextureManager() {
}
