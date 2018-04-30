#ifndef KILLGENIE_H
#define KILLGENIE_H

#include <vector>
#include "genie.h"

/**
* <b> KILLGENIE CLASS HEADER FILE </b>
 * @class killGenie
 * @brief Class which erases (i.e. kills genie) should the kill conditions be met
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file killGenie.h
 
 */

class killGenie
{
public:
/**
 * @brief Constructor
 */
	killGenie();
	/**
	 * @brief Function which iterates through the vector of genies. 
	 * If the kill condition is met (i.e. alive =false), the object of genie is erased from the vector
	 * @param <genieVector> vector of genies passed by reference
	 */
	void kill_genie(std::vector<genie>&);
	
	};
	
#endif	