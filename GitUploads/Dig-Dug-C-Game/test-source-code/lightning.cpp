
#include "lightning.h"

lightning::lightning()
{
	Graphics= std::make_shared<graphics>();
	Graphics -> setTexture(&_lightningTexture);
	Graphics -> setSprite(&_lightningSprite);

	if ((Graphics -> loadTextureFromFile("lightning-all-400x280.png")))
	{     
		Graphics -> setSpriteTexture(_lightningTexture);
	}

	else{throw lightningNotLoaded();}
}

Sprite* lightning::init_lightning()
{
	return &_lightningSprite;
}


void lightning::update(int direction, float xpos, float ypos)
{   
	if (direction==1) // Up
	{
		Graphics -> setPosition(xpos, ypos+20-20*val);
		Graphics -> setTextureRect(0,280-20*val,80,20*val);
		rect.setSize(Vector2f(5, -20*val));
		rect.setPosition(xpos+40, ypos+15);
		rect.setFillColor(Color::Transparent);

		val++;
		if (val>10)
			{val=0;}
	}

	else if (direction == 2) // Down
	{
		Graphics -> setPosition(xpos, ypos+55);
		Graphics -> setTextureRect(80,80,80,20*val);
		rect.setSize(Vector2f(5, 20*val));
		rect.setPosition(xpos+40, ypos+55);
		rect.setFillColor(Color::Transparent);

		val++;
		if (val>10)
			{val=0;}
	}

	else if (direction == 3) // Right
	{
		Graphics -> setPosition(xpos+50, ypos+15);
		Graphics -> setTextureRect(0,0,20*val,80);
		rect.setSize(Vector2f(20*val, 5));
		rect.setPosition(xpos+50, ypos+50);
		rect.setFillColor(Color::Transparent);

		val++;
		if (val>10)
			{val=0;}
	}

	else if (direction == 4) // Left
	{
		Graphics -> setPosition(xpos+30-(20*val), ypos+15);
		Graphics -> setTextureRect(400-(20*val), 0, 20*val, 80);
		rect.setSize(Vector2f(20*val, 5));
		rect.setPosition(xpos+30-(20*val), ypos+50);
		rect.setFillColor(Color::Transparent);

		val++;
		if (val>10)
			{val=0;}
	}

	else if (direction == 0) //default
	{
		Graphics -> setPosition(xpos, ypos+55);
		Graphics -> setTextureRect(80,80,80,20*val);
		rect.setSize(sf::Vector2f(5, 20*val));
		rect.setPosition(xpos+40, ypos+55);
		rect.setFillColor(Color::Transparent);

		val++;
		if (val>10)
			{val=0;}
	}
}
