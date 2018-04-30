#include "explosion.h"

explosion::explosion()
{
	Graphics= std::make_shared<graphics>();
	Graphics -> setTexture(&_explosionTexture);
	Graphics -> setSprite(&_explosionSprite);

	if ((Graphics -> loadTextureFromFile("explosion-80x80.png")))
	{     
		Graphics -> setSpriteTexture(_explosionTexture);
	}

	else {
		throw explosionNotLoaded();
	}
}

Sprite* explosion::init_explosion()
{
	return &_explosionSprite;
}

void explosion::update(float time_contact , float xpos, float ypos)
{   
	Graphics -> setPosition(xpos, ypos);
	
	if(time_contact>0 && time_contact<=0.7)
	{
		Graphics -> setTextureRect(0,0,80,80);
		expPart1=true;
		expPart2=false;
		expPart3=false;
		expPart4=false;
	}

	else if(time_contact>0.7 && time_contact<=1.4)
	{
		Graphics -> setTextureRect(80,0,80,80);
		expPart1=false;
		expPart2=true;
		expPart3=false;
		expPart4=false;
	}
	
	else if(time_contact>1.4 && time_contact<=2)
	{
		Graphics -> setTextureRect(160,0,80,80);
		expPart1=false;
		expPart2=false;
		expPart3=true;
		expPart4=false;
	}

	else
	{
		Graphics -> setTextureRect(240,0,80,80);
		expPart1=false;
		expPart2=false;
		expPart3=false;
		expPart4=true;
	}


}
