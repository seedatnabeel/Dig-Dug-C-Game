#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include "sorceress.h"
#include "tunnel.h"
#include "lightning.h"
#include "genie.h"
#include "scoring.h"
#include "genie.h"
#include "explosion.h"
#include "background.h"
#include "monsterMove.h"
#include "killGenie.h"
#include "collision.h"
#include "killSrs.h"
#include "controls.h"
#include <memory>


/**
 * @class InvalidScreen
 * @brief class that throws exception when invalid screen is called
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file game.h
 */
class InvalidScreen{};

/**
*@brief enum class of possible screen displays
*/
enum class screenDisp
{
    Welcome, Splash, Win, Lose
};

/**
* <b> GAME CLASS HEADER FILE </b>
 * @class game
 * @brief The main game loop class: it updates the game state of all objects and draws the game to the screen. 
 * It is the intermediary class between presentation and logic layers
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file game.h
 
 */
class game
{
	public:
		//Constructor
		/**
        
		 * @brief Constructor 
		 */
		game();
		
		/**
		 * @brief Renders game window, makes shared pointer to graphics and set frameratelimit
		 * @param Pointer to window from graphics library sfml
		 */
		void gamewindow(Window*);
		/**
		 * @brief Function that calls all game state update functions in order to update the game
		 * @param <window> pointer to window
		 */
		void updateGameState();
		/**
		 * @brief Function that starts the game. Calls to initialize tunnels and monsters
		 * Is the function where the main game loop is
		 */
		void start();
		/**
		 * @brief Function which draws the various background screens: welcome, splash, game over screen and game win screen
		 * @param <screen> an enumerator class object of the different types of screens 
		 */
		void screens(screenDisp);
		/**
		 * @brief Function which draws all game objects to the screen
		 */
		void drawgame();

		sf::Clock timer;
		sf::Time elapsed2;
		sf::Time elapsed1;
		
		//all game objects
		background background;
		scoring myscore;
		sorceress mysrs;
		explosion myexplosion;
		monsterMove monsterMove;
		killGenie killDrgn;
		killSrs killSrs;
		collision collision;
		controls gameControls;
		
		/**
        *@brief vector of lightning objects
		*/
		std::vector<lightning> lightningVector;
		lightning mylightning;
		/**
        *@brief vector of tunnel objects
		*/
		std::vector<tunnel> tunnelVector;
		tunnel tunnel1;
		/**
        *@brief vector of genie objects
		*/
		std::vector<genie> genieVector;
        genie mygenie;
		
		/**
		 * @brief Calls the gameWin screen and checks if the user wants to end the game
		 */
		void gameWin();
		/**
		 * @brief Function which initializes the start positions of the genies
		 */
		void initGenies();
		float hit_posx=-100;
		float hit_posy=-100;
		bool win=false; 
		bool mygame=true;

private:
		
		Window* _gameWindow;
		/**
		*@brief create shared pointer to graphics
		*/
		std::shared_ptr<graphics> Graphics;
		Texture _backgroundTexture;
		Sprite _backgroundSprite;
		Texture _splashTexture;
		Sprite _splashSprite;
		Texture _welcomeTexture;
		Sprite _welcomeSprite;
		Sprite _expSprite;
		Texture  _expTexture;
		
};

#endif // GAME_H
