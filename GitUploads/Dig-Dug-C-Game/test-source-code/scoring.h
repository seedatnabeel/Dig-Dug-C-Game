
#ifndef SCORING_H
#define SCORING_H
#include "graphics.h"
#include <memory>

/**
 * @class TextFileNotLoaded
  * @brief class which throws an exception when txt file not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file scoring.h

 */
class TextFileNotLoaded{};

/**
* <b> SCORING CLASS HEADER FILE </b>
 * @class scoring
 * @brief Class which stores the scoring (lives and state of sorceress), as well as, sets the text of lives to print to screen
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file scoring.h
 
 */

class scoring:public graphics
{
public:
        /**
        *@brief Constructor initialzes the shared pointer to graphics
		*/
	    scoring();
		/**
		 * @brief Initializes the sfml text library with sansation.tff font. 
		 * It then sets the string in the text to the number of lives. It the returns the Text with the string as: e.g "Lives: 3 " 
		 * @return sf::Text - the string which will be drawn in the game class
		 */
		Text printLives();
		int srsLives=3;
		bool srsDead=false;

	private:
		std::shared_ptr<graphics> Graphics;
		Font Font;
        
};
#endif