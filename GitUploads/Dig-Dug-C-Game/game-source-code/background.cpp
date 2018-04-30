#include "background.h"

background::background()
{
	Graphics= std::make_shared<graphics>();
	
	Graphics -> setTexture(&_backTexture);
	Graphics -> setSprite(&_backSprite);

	if(Graphics -> loadTextureFromFile("Background-1280x800.png")==true)
	{
		Graphics -> setSpriteTexture(_backTexture);
	}
	else {throw backNotLoaded();}
}

Sprite* background::splash()
{
	Graphics -> setTexture(&_splashTexture);
	Graphics -> setSprite(&_splashSprite);

	if(Graphics -> loadTextureFromFile("splash-intro-1280x800.png")==true)
	{
		Graphics -> setSpriteTexture(_splashTexture);
		return &_splashSprite;
	}
	
	else {throw splashNotLoaded();}
}
    
Sprite* background::welcome()
{
	Graphics -> setTexture(&_welcomeTexture);
	Graphics -> setSprite(&_welcomeSprite);

	if(Graphics -> loadTextureFromFile("splash-start-1280x800.png")==true)
	{
		Graphics -> setSpriteTexture(_welcomeTexture);
		return &_welcomeSprite;
	}
	
	else {throw welcomeNotLoaded();}
}	

Sprite* background::gameOverScreen()
{
	Graphics -> setTexture(&_overTexture);
	Graphics -> setSprite(&_overSprite);

	if(Graphics -> loadTextureFromFile("gameover-1280x800.png")==true)
	{
		Graphics -> setSpriteTexture(_overTexture);
		return &_overSprite;
	}
	
	else {throw overNotLoaded();}
}	

Sprite* background::winScreen()
{
	Graphics -> setTexture(&_winTexture);
	Graphics -> setSprite(&_winSprite);

	if(Graphics -> loadTextureFromFile("game-win-1280x800.png")==true)
	{
		Graphics -> setSpriteTexture(_winTexture);
		return &_winSprite;
	}
	
	else {throw winNotLoaded();}
}	
	
Sprite* background::back()
{
		return &_backSprite;
}	
	