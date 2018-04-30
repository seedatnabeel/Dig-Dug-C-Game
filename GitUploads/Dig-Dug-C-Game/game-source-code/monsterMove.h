#ifndef MONSTERMOVE_H
#define MONSTERMOVER_H

#include <vector>
#include "tunnel.h"
#include "genie.h"
#include "sorceress.h"

/**
* <b> MONSTERMOVE CLASS HEADER FILE </b>
 * @class monsterMove
 * @brief Class which polls the monsters ability to move. If it can move in a tunnel, set ghost mode to false, if can't move then set ghost mode to true
 * Lastly, the class based on this calls Genies move update function
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file monsterMove.h
 
 */

class monsterMove
{
public:
    /**
     * @brief Constructor
     */
	monsterMove();
	/**
	 * @brief Function which iterates through both the tunnel and genie vectors and checks for an intersection. If there is an intersection monster moves normal.
	 * If no intersection monster moves in ghost mode. The monsters update movement function is then called appropriately
	 * @param <tunnelVector> vector of tunnels passed by ref
      *@param <genieVector> vector of genies passed by ref
     *@param <srs_xpos> x-co-ords of sorceress
	 * @param <srs_ypos> y-co-ords of sorceress
	 */
	virtual void tunnel_check(std::vector<tunnel> & , std::vector<genie>&,float, float);
	sf::Clock timer1;
	
	};
	
#endif	