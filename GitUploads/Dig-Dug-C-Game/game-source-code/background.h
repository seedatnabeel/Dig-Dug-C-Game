#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "graphics.h"
#include <memory>

/**
 * @class backNotLoaded
 * @brief class that throws exception when background not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file background.h
 */
class backNotLoaded{};
/**
 * @class welcomeNotLoaded
 * @brief class that throws exception when welcome screen not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file background.h
 
 */
class welcomeNotLoaded{};
/**
 * @class winNotLoaded
 * @brief class that throws exception when win screen screen not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file background.h
 
 */
class winNotLoaded{};
/**
 * @class overNotLoaded
 * @brief class that throws exception when game over screen not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file background.h
 
 */
class overNotLoaded{};
/**
 * @class splashNotLoaded
 * @brief class that throws exception when splash screen not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file background.h
 
 */
class splashNotLoaded{};

/**
* <b> BACKGROUND CLASS HEADER FILE </b>
 * @class background
 * @brief The background class reads in background sprites from memory and stores them as data members. It also points to the graphics class through a shared_ptr
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 24/09/2016
 * @file background.h
 
 */

class background:public graphics
{
	public:
		//Constructor
		/**
		 * @brief The constrctor makes the shared pointer to graphics, as well as, reading in and storing in the background image
		 * @return Constructor 
		 */
		background();
		/**
		 * @brief Reads in and stores the splash screen texture and sprite. The "setting" of the texture and sprite is through the pointer to graphics
		 * @return Pointer to the Sprite 
		 */
		Sprite* splash();
		/**
		 * @brief Reads in and stores the splash screen texture and sprite. The "setting" of the texture and sprite is through the pointer to graphics
		 * @return Pointer to the Sprite 
		 */
		Sprite* back();
		/**
		 * @brief the function returns the background sprite
		 * @return Pointer to the Sprite 
		 */
		Sprite* welcome();
		/**
		 * @brief Reads in and stores the win screen texture and sprite. The "setting" of the texture and sprite is through the pointer to graphics
		 * @return Pointer to the Sprite 
		 */
		Sprite* winScreen();
		/**
		 * @brief Reads in and stores the game over screen texture and sprite. The "setting" of the texture and sprite is through the pointer to graphics
		 * @return Pointer to the Sprite 
		 */
		Sprite* gameOverScreen();

	private:
		Sprite _welcomeSprite;
		Texture  _welcomeTexture;
		Sprite _splashSprite;
		Texture  _splashTexture;
		Sprite _overSprite;
		Texture  _overTexture;
		Sprite _backSprite;
		Texture  _backTexture;
		Sprite _winSprite;
		Texture  _winTexture;
		/** @brief creates a shared pointer to the graphics class
		*/
		std::shared_ptr<graphics> Graphics;
		
};

#endif 