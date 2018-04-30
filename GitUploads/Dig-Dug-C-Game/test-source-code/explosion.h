#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "graphics.h"
#include <memory>

/**
 * @class explosionNotLoaded
 * @brief class that throws exception when explosion sprite not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file explosion.h
 
 */
class explosionNotLoaded{};

/**
* <b> EXPLOSION CLASS HEADER FILE </b>
 * @class explosion
 * @brief The class creates a shared pointer to graphics, and then loads in and stores the explosion sprite from memory
 * Additionally, based on the time of impact, it will set the texture rectangle, such that the explosion sprite changes to create
 * the illusion of it exploding
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 24/09/2016
 * @file explosion.h
 
 */

class explosion:public graphics
{
public:
  /**
   * @brief Constructor creates the shared pointer to graphics and loads in and stores the explosion sprite and texture from memory
   */
		explosion();
	
	
		/**
		 * @brief Function returns a pointer to the explosion sprite
		 * @return Pointer to the explosion sprite 
		 */
		Sprite* init_explosion();
		/**
		 * @brief Function which updates the explosion sprite size based on the time of contact, as well as, setting its position
		 * @param <time_contact> time of contact of lightning
		 * @param <xpos> hit position in the x
		 * @param <ypos> hit position in the y
		 */
		void update(float, float, float);
		bool expPart1=false;
		bool expPart2=false;
		bool expPart3=false;
		bool expPart4=false;

private: 
	   /**
              @brief Shared pointer to the graphics class
 		*/
		std::shared_ptr<graphics> Graphics;
		Sprite _explosionSprite;
		Texture  _explosionTexture;
	};


#endif 