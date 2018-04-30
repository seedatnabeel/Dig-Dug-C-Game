#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <type_traits>

typedef sf::RenderWindow Window;
typedef sf::Keyboard Keyboard;
typedef sf::Sprite Sprite;
typedef sf::Texture Texture;
typedef Keyboard::Key Key;
typedef sf::Text Text;
typedef sf::Font Font;
typedef sf::RectangleShape rect;
typedef sf::Color Color;
typedef sf::Vector2f Vector2f;

/**
* <b> GRAPHICS CLASS HEADER FILE </b>
 * @class graphics
 * @brief Decoupled graphics class which implements all sfml functionality 
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 24/09/2016
 * @file graphics.h
 */

class graphics
{
public:
	   /**
	    * @brief Constructor
	    */
		graphics();
		/**
		 * @brief Function which sets sprite variable to sprite
		 * @param <mySprite> pointer to a sprite
		 */
		virtual void setSprite(sf::Sprite*);
		/**
		 * @brief Function which moves the sprite
		 * @param <x> x amount to move the sprite, 
		 * @param <y> y amount to move the sprite
		 */
		virtual void move(const float, const float);
		/**
		 * @brief  Function which sets the texture to the sprite (i.e. setting the sprites texture)
		 * @param <myTexture> const Texture by ref
		 */
		virtual void setSpriteTexture(const Texture&);
		/**
		 * @brief Function which sets the position of the sprite
		 * @param  <x> x position for the sprite,
         *  @param  <y> y position of the sprite
		 */
		virtual void setPosition(const float x, const float y);
		/**
		 * @brief Function which sets an internal rectangle around the sprite
		 * @param <x> x position for the rect 
		 * @param  <y> y position for the rect
		 * @param <length> lenght of rect
		 * @param <width> width of rect
		 */
		virtual void setTextureRect(const float x, const float y, const float length, const float width );
		/**
		 * @brief Function which sets texture variable to texture
		 * @param <myTexture> pointer to texture
		 */
		virtual void setTexture(sf::Texture*);
		/**
		 * @brief Function returns a boolean true if file correctly read in
		 * @param <fileName> file read in
		 * @return bool
		 */
		bool loadTextureFromFile(const std::string&);
		sf::Text _text;

	private:
		sf::Sprite* _sprite;
		sf::Texture* _texture;
		
};

#endif 
