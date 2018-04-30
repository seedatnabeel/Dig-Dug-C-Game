#include "scoring.h"
#include <string>

scoring::scoring()
{
	Graphics = std::make_shared<graphics>();;
}

Text scoring::printLives()
{
   if (!Font.loadFromFile("sansation.ttf"))
	{
		throw TextFileNotLoaded();
	}
	
	std::string s = std::to_string(srsLives);
	std::string lives= "Lives = " + s;

    Graphics->_text.setFont(Font);
	Graphics->_text.setString(lives);
	Graphics->_text.setColor(Color::White);
	Graphics->_text.setCharacterSize(50);
	Graphics->_text.setPosition(0, 0);
	
	return Graphics->_text;
	
	}