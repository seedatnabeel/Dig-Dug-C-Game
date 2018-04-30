
#ifndef KILLSRS_H
#define KILLSRS_H

#include <vector>
#include "genie.h"
#include "sorceress.h"
#include "scoring.h"

/**
* <b> KILLSRS CLASS HEADER FILE </b>
 * @class killSrs
 * @brief Class which polls collisions between genie and sorceress and then remove life points
 * If all life points are gone, the sorceress condition is set to dead (killing sorceress)
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file killSrs.h
 
 */

class killSrs
{
public:
   /**
    * @brief Constructor
    */
	killSrs();
	/**
	 * @brief Function which iterates through the genie vector and polls a collison with sorceress. If a collision occurs, a life point is deducted from sorceress.
	 * When the life points reaches zero sorceress is dead and the condition of srsDead is set to true
	 * @param <mysrs> object of sorceress passed by reference
	 * @param <genieVector> vector of genies passed by ref, 
	 * @param <myscore> object of scoring passed by reference
	 */
	void kill_srs(sorceress &, std::vector<genie>&, scoring &);
	sf::Clock timer1;
	
	};
	
#endif		