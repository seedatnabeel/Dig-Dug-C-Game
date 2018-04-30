#include "sorceress.h"

sorceress::sorceress()
{
	Graphics= std::make_shared<graphics>();
	Graphics -> setTexture(&_srsTexture);
	Graphics -> setSprite(&_srsSprite);

	rect.setSize(Vector2f(32, 32));
	rect.setPosition(_xpos, _ypos);
	rect.setFillColor(Color::Transparent);
	
	if ((Graphics -> loadTextureFromFile("sorceress-sprites-80x80.png")))
	{     
		Graphics -> setSpriteTexture(_srsTexture);
		Graphics -> setPosition(_xpos, _ypos);
		Graphics -> setTextureRect(0,0,80,80);
	}
}

Sprite* sorceress::init_srs()
{
	return &_srsSprite;
}
    
void sorceress::update()
{
	_srsSprite.setPosition(rect.getPosition());
}
    
    
void sorceress::move(float x_increment, float y_increment)
{
	rect.move(x_increment,y_increment);
}    

void sorceress::moveU()
{
	move(0,-15);
	_ypos-=15;

	Graphics -> setTextureRect(imgPos*80 , 240 , 80 , 80 );
	imgPos++;
	
	if (imgPos>3){imgPos=0;}

	direction=1;
}    

void sorceress::moveD()
{
	move(0,15);
	_ypos+=15;

	Graphics -> setTextureRect(imgPos*80, 0 , 80 , 80 );
	imgPos++;

	if (imgPos>3){imgPos=0;}

	direction=2;
}   

void sorceress::moveR()
{
 	move(15,0);
	_xpos+=15;

	Graphics -> setTextureRect(imgPos*80, 160 , 80 , 80 );
	imgPos++;

	if (imgPos>3){imgPos=0;}

	direction=3;
}   

void sorceress::moveL()
{
	move(-15,0);
	_xpos-=15;

	Graphics -> setTextureRect(imgPos*80, 80 , 80 , 80 );
	imgPos++;

	if (imgPos>3){imgPos=0;}

	direction=4;
}   

float sorceress::get_xpos(){return _xpos;}

float sorceress::get_ypos(){return _ypos;}

void sorceress::move()
{
	if (gameControls.checkKey(UserInput::Right))
	{
		if(get_xpos()<1200)
			moveR();
	}

	else if (gameControls.checkKey(UserInput::Left))
	{
		if(get_xpos()>0)
			moveL(); 
	}   

	else if (gameControls.checkKey(UserInput::Up))
	{
		if(get_ypos()>160)
			moveU();
	}

	else if (gameControls.checkKey(UserInput::Down))
	{
		if(get_ypos()<716)
			moveD();
	}

	else {}
}