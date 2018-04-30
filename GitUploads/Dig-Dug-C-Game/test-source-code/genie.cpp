#include "genie.h"

genie::genie()
{
	Graphics= std::make_shared<graphics>();
	Graphics -> setTexture(&_genieTexture);
	Graphics -> setSprite(&_genieSprite);
	rect.setSize(Vector2f(60, 60));

	rect.setPosition(-100, -200);
	rect.setFillColor(Color::Transparent);
	if ((Graphics -> loadTextureFromFile("red-genie2-80x80.png")))
	{     
		Graphics -> setSpriteTexture(_genieTexture);
		Graphics -> setPosition(_xpos, _ypos);
		Graphics -> setTextureRect(0,0,80,80);
	}

	else
	{
		throw genieNotLoaded();
	}

}

Sprite* genie::init_genie()
{
	return &_genieSprite;
}

void genie::update()
{
    _genieSprite.setPosition(rect.getPosition());
}

float genie::get_xpos()
{
	return _xpos;
}

float genie::get_ypos()
{
	return _ypos;
}

void genie::move_patrol()
{
	if((rect.getPosition().x<1120))
	{
		rect.move(1,0);
	}
	
	else{moveright=false;}
	
	if(!moveright)
	{
		
		rect.move(-1,0);
	}
	
	if(!moveright)
	{
		rect.move(-1,0);
	}
	
	if((rect.getPosition().x==880))
	{
		moveright=true;
		}
}

void genie::updateMovement(float ddx,float ddy)
{
	if(!ghost)_genieSprite.setTextureRect(sf::IntRect(0, 0, 80, 80));
	else if(ghost)_genieSprite.setTextureRect(sf::IntRect(80, 0, 80, 80));
	
	float dx=ddx- rect.getPosition().x  ;
	float dy = ddy- rect.getPosition().y ;
	float dist = hypot(dx, dy);
	
	if(dist<500)
	{
		withinRadius=true;
		}
		
	if(withinRadius)
	{
		
	deltax=dx/dist;
    deltay=dy/dist; 

		if(timer.getElapsedTime().asSeconds()>0.000002)
		{
			if(rect.getPosition().x!=ddx)
	{ 
		rect.move(deltax*move,0);
	}
	
   if(rect.getPosition().y!=ddy)
	{
		rect.move(0,deltay*move);
	}
			timer.restart();
		}
	}

	else
	{
		move_patrol();
	}
}