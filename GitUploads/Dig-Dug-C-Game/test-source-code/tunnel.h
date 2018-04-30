#ifndef TUNNEL_H
#define TUNNEL_H

#include "graphics.h"

/**
* <b> TUNNEL CLASS HEADER FILE </b>
 * @class tunnel
 * @brief This class loads a pre-set tunnel map and the tunnels Sorceress makes into the tunnel vector
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 25/09/2016
 * @file tunnel.h
 */

class tunnel:public graphics
{
	public:
		rect rect;
		/**
		 * @brief Constructor sets the size and colour of the tunnels which sorceress makes
		 */
		tunnel();
		/**
		* @brief This function loads the co-ordinates from tunnel into a vector and sets postion of tunnel images
		* @param <tunnelVector> vector of tunnel co-ordinates 
        * @param <tunnel1> tunnel object
		* @return vector
		*/
		void start(std::vector<tunnel>* , tunnel );
};

#endif 