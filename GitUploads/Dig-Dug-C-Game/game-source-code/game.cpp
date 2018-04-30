#include "game.h"
game::game(){}

void game::gamewindow(Window* window)
{
	_gameWindow = window;
	_gameWindow -> setFramerateLimit(60);
	Graphics= std::make_shared<graphics>();
}

void game::updateGameState()
{
	monsterMove.tunnel_check(tunnelVector, genieVector,mysrs.get_xpos(),mysrs.get_ypos());
	killSrs.kill_srs(mysrs, genieVector, myscore);
	killDrgn.kill_genie(genieVector);
	hit_posx=-100;
	hit_posy=-100;
}

void game::screens(screenDisp screen)
{
		_gameWindow -> clear();
		switch (screen)
		{
	      case screenDisp::Welcome :_gameWindow -> draw(*(background.welcome()));
				 break;
		  case screenDisp::Splash :_gameWindow ->  draw(*(background.splash()));
				 break;
          case screenDisp::Lose :_gameWindow -> draw(*(background.gameOverScreen()));
				 break;	
          case screenDisp::Win :_gameWindow -> draw(*(background.winScreen()));
				 break;		
          default:
        {
           throw InvalidScreen();
        } 	
	}		
		_gameWindow -> display();
}

void game::gameWin()
{	while(win==true)
	{   screens(screenDisp::Win);
		if (gameControls.checkKey(UserInput::Escape))
		{
			_gameWindow -> close();
			break;
		}
	}
}
void game::initGenies()
{   mygenie.rect.setPosition(960, 480);
	genieVector.push_back(mygenie);
	mygenie.rect.setPosition(240,640);
	genieVector.push_back(mygenie);
	mygenie.rect.setPosition(-10000,-10000);
	genieVector.push_back(mygenie);}

void game::start()
{
	tunnel1.start(&tunnelVector, tunnel1);
	initGenies();
	
	
	while ((mygame == true))
	{ 
		mysrs.update();
		mysrs.move();

		if ((gameControls.checkKey(UserInput::Left))||(gameControls.checkKey(UserInput::Right))
		||(gameControls.checkKey(UserInput::Up))||(gameControls.checkKey(UserInput::Down)))
		{
			tunnel1.rect.setPosition(mysrs.rect.getPosition());
			tunnelVector.push_back(tunnel1);
		}		
		
		elapsed2 = timer.getElapsedTime();
		
		while(gameControls.checkKey(UserInput::Shoot))
		{   
			mylightning.update(mysrs.direction, mysrs.get_xpos(),mysrs.get_ypos());
			lightningVector.push_back(mylightning);
			elapsed1 = timer.getElapsedTime();
			_gameWindow->draw(*(mylightning.init_lightning()));
			collision.mons_lightning(genieVector,lightningVector,hit_posx,hit_posy);
			myexplosion.update((elapsed1.asSeconds()-elapsed2.asSeconds()),hit_posx-20,hit_posy-10);
			_gameWindow->draw(*(myexplosion.init_explosion()));
			_gameWindow -> display();
		}

		updateGameState();
		drawgame();

		if((genieVector.size()==1))
		{  win=true;
			gameWin();}
			
		if((myscore.srsDead)||(gameControls.checkKey(UserInput::Escape)))
		{  mygame=false;}	
	}

	while(mygame==false)
    {
		screens(screenDisp::Lose);
		if (gameControls.checkKey(UserInput::Escape))
		{
			_gameWindow -> close();
			break;
		}
	}
}

void game::drawgame()
{
	_gameWindow -> clear();
	_gameWindow -> draw(*(background.back()));

	int counter = 0;
	for(auto iter1 = begin(tunnelVector); iter1 != end(tunnelVector); iter1++)
	{
		_gameWindow->draw(tunnelVector.at(counter).rect);
		counter++;
	}

	_gameWindow->draw(*(mysrs.init_srs()));

	counter = 0;
	for (auto it = begin(genieVector); it != end(genieVector); it++)
	{
		genieVector[counter].update();
		 _gameWindow->draw(*(genieVector.at(counter).init_genie()));
		counter++;
	}
		_gameWindow->draw((myscore.printLives()));	
		
	_gameWindow -> display();	
}
