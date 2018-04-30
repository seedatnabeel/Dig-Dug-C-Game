
#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include "lightning.h"
#include "genie.h"

/**
* <b> COLLISION CLASS HEADER FILE </b>
 * @class collision
 * @brief The class detects and handles the collision between genie and lightning
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 24/09/2016
 * @file collision.h
 */

class collision
{
public:
   /**
    * @brief Constructor
    */
	collision();
	
	/**
		* @brief Function which detects the collision between genie and lightning. 
		* It then sets the hit position in the x and y for explosion, as well as, 
		* setting genies alive state to false should the time of impact be greater than 1 second (i.e. killing genie)
		* @param <genieVector> vector of genie objects
		* @param <lightningVector> vector of lightning objects
		* @param <hit_posx> hit position in the x
		* @param <hit_posy> hit position in the y
		* @return void
		*/
	void mons_lightning(std::vector<genie> & , std::vector<lightning>&, float &, float &);
	
private:	
	sf::Clock timer;
	
	};
	
#endif	