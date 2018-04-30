////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////                              MONSTER HUNTER:DIG DUG EDITION
////////////////                              SOFTWARE DEVELOPMENT 2 (ELEN 3009)
////////////////                              FINAL SUBMISSION
////////////////                              NABEEL SEEDAT (719484) & DEEPAM AMBELAL (719369)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "game.h"

using namespace std;

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280,800), "Monster Hunter: Dig Dug Edition");
	//window->setSize(sf::Vector2u(960,600));

    class game dig_dug;
	dig_dug.gamewindow(window);
	
	bool welcome=true;
	while(welcome)
	{
		dig_dug.screens(screenDisp::Welcome);
		if (dig_dug.gameControls.checkKey(UserInput::continueWelcome))
		{
			welcome=false;
			break;
		}
	}

	bool splash=true;
	while(splash)
	{
		dig_dug.screens(screenDisp::Splash);
		if (dig_dug.gameControls.checkKey(UserInput::continueSplash))
		{
			splash=false;
			break;
		}
	}

//	dig_dug.initBackground();
	dig_dug.start();

	return 0;
}

