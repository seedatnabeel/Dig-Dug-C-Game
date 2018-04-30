#ifndef SORCERESS_H
#define SORCERESS_H

#include "graphics.h"
#include "controls.h"
#include <memory>
/**
* <b> SORCERESS CLASS HEADER FILE </b>
 * @class sorceress
  * @brief The class initialises and  controls movement of the Sorceress sprite. The sprite will move and animate based on the direction the user inputs.
*  An invisible region is drawn around the sprite to be used for the collision testing
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file sorceress.h
 */
class sorceress:public graphics
{
	public:
		rect rect;
		int direction = 0; // 1 - up, 2 - down, 3 - right, 4 - left
		controls gameControls;
		/**
		 * @brief Constructor initializes the sorceress sprite properties
		 * @return Sprite properties
		 */
		sorceress();
		/**
		 * @brief fucntion which Returns Sorceress sprite
		 * @return pointer to the sorceress sprite
		 */
		Sprite* init_srs();
		/**
		 * @brief moves Sorceress' collision box to her new location
		 * @param <x_increment> the increment (i.e. in pixels) in which to move the sorceress rect in the x axis
		*  @param <y_increment> the increment (i.e. in pixels) in which to move the sorceress rect in the y axis
		 */
		void  move(float, float);
		/**
		 * @brief accesses Sorceress' x position from Private variable
		 * @return Sorceress' x co-ordinate
		 */
		float get_xpos();
		/**
		 * @brief accesses Sorceress' y position from Private variable
		 * @return Sorceress' y co-ordinate 
		 */
		float get_ypos();
		/**
		 * @brief restricts Sorceress' movements to the screen
		 */
		void move();
		/**
		 * @brief sets position of Sorceress' Sprite to collision box location
		 */
		void update();
		/**
		 * @brief Moves Sorceress' position 15 pixels right on screen, cycles through walking sprites and sets direction=3
		 */
		void moveR();
		/**
		 * @brief Moves Sorceress' position 15 pixels left on screen, cycles through walking sprites and sets direction=4
		 */
		void moveL();
		/**
		 * @brief Moves Sorceress' position 15 pixels Up on screen, cycles through walking sprites and sets direction=1
		 */
		void moveU();
		/**
		 * @brief Moves Sorceress' position 15 pixels down on screen, cycles through walking sprites and sets direction=2
		 */
		void moveD();
		
	private:
		Sprite _srsSprite;
		Texture  _srsTexture;
		std::shared_ptr<graphics> Graphics;
		float x_increment;
		float y_increment;
		float _xpos=160;
		float _ypos=160;
		int imgPos= 0;
		
};

#endif 