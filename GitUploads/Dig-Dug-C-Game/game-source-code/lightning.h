#ifndef LIGHTNING_H
#define LIGHTNING_H

#include "graphics.h"
#include <memory>

/**
 * @class lightningNotLoaded
  * @brief class that throws exception when lightning sprite not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file lightning.h

 */
class lightningNotLoaded{};

/**
 * @class lightning
 * @brief Class of Lightining which has all the attributes and responsbilities of a lightning object
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file lightning.h
 */
class lightning:public graphics
{
public:
	    /**
        *@brief Constructor which reads lightning in from memory and stores the sprite, as well as, initialzing the bounding rectangle
		*/
		lightning();
		/**
		 * @brief Function which returns a pointer to the lightning sprite
		 * @return Pointer to the lightning sprite 
		 */
		Sprite* init_lightning();
		/**
		 * @brief updates lightnings position based on the direction of sorceress and to the correct co-ordinates
		 * i.e. it sets the lightning to the current position of sorceress
		 * @param <direction> integer value corresp to sorceress direction, 
		 * @param <xpos> xpos of sorceress
		 * @param <ypos> ypos of sorceress
		 */
		void update(int, float, float );
		rect rect;
		int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
		int val=0;
		
		
	private: 
	    /**
        *@brief creates a shared pointer to graphics
		*/
		std::shared_ptr<graphics> Graphics;
		Sprite _lightningSprite;
		Texture  _lightningTexture;
		/**
		 * @brief Sets the lightning sprite to the position of the bounding rectangle
		 */
		void set_lightning_sprite();
	};


#endif 