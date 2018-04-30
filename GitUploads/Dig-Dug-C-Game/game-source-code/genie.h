#ifndef GENIE_H
#define GENIE_H

#include "graphics.h"
#include <vector>
#include <memory>

/**
 * @class genieNotLoaded
 * @brief class that throws exception when genie sprite not loaded
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file genie.h
 */
class genieNotLoaded{};

/**
* <b> GENIE CLASS HEADER FILE </b>
 * @class genie
 * @brief Class of Genie which has all the attributes and responsbilities of a genie object
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file genie.h
 
 */

class genie:public graphics
{
public:
	
		/**
        *@brief Constructor which reads genie in from memory and stores the sprite, as well as, initialzing the bounding rectangle
		*/
		genie();
		bool alive = true;
		/**
		 * @brief Function which returns a pointer to the genie sprite
		 * @return Pointer to the genie sprite 
		 */
		Sprite* init_genie();
		/**
		 * @brief Function which sets the position of the sprite to that of the genie rectangle
		 */
		void update();
		/**
		 * @brief Function which takes in sorceress co-ords. It calculates the shortest distance. Based on the distance either genie moves patrol form
		 * or if in proximity (less than 500 pixels from genie) then the chase algorithm is executed
		 * @param <ddx> sorceress current x pos
		 * @param <ddy> sorceress current y pos
		 */
		void updateMovement(float, float);
		/**
		 * @brief Function which returns the genies x position
		 * @return Float of the genies x pos 
		 */
		float get_xpos();
		/**
		 * @brief Function which returns the genies y position
		 * @return Float of the genies y pos 
		 */
		float get_ypos();
		/**
		 * @brief Function which implements the move patrol method of genies movement
		 * This is called when sorceress is more than 500 pixels away from a genie. 
		 */
		void move_patrol();
		
		rect rect;
		bool ghost=false;
		bool moveright=true;
		bool withinRadius=false;
		float deltax;
		float deltay;
		Sprite _genieSprite;
		
private:
	    /**
        *@brief creates a shared pointer to graphics
		*/
		std::shared_ptr<graphics> Graphics;
		
		Texture  _genieTexture;
		Sprite _ghostSprite;
		Texture  _ghostTexture;
		float _xpos=1000;
		float _ypos=800;
		float move = 1.7;
		sf::Clock timer;
};

#endif 
