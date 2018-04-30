#include "graphics.h"

graphics::graphics()
{}

void graphics::setSprite(sf::Sprite* mySprite)
{
	_sprite = mySprite;
	return;
}

void graphics::setPosition(const float x, const float y)
{
	_sprite -> setPosition(x, y);
}


void graphics::setTextureRect(const float x, const float y, const float length, const float width )
{
	_sprite -> setTextureRect(sf::IntRect(x, y, length, width));
}


void graphics::move(const float x, const float y)
{
	_sprite -> move(x,y);
	return;
}

void graphics::setTexture(sf::Texture* myTexture)
{
	_texture = myTexture;
}

bool graphics::loadTextureFromFile(const std::string& fileName)
{
	return _texture -> loadFromFile(fileName);
}

void graphics::setSpriteTexture(const Texture& myTexture)
{
	_sprite -> setTexture(myTexture);
	return;
}


