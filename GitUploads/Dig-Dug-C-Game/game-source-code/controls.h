#ifndef CONTROLS_H
#define CONTROLS_H

#include "graphics.h"
/**
*@brief enum class of all possible controls
*/
enum class UserInput
{
    Up, Right, Left, Down,
    Shoot, Escape, continueSplash, continueWelcome
};

/**
 * <b> CONTROLS CLASS HEADER FILE </b>
 * @class controls
 * @brief Class which polls for user input and returns booleans to the calling function
 * @author Nabeel Seedat (719484) & Deepam Ambelal (719369)
 * @date 24/09/2016
 * @file controls.h
 */

class controls
{
    public:
        /**
         * @brief Constructor
         */
        controls();
		
		/**
		* @brief Function which polls for different user input and returns a boolean of true if condition is met
		* @param <key> enumerator based on user input
		* @return boolean of true if condition is met
		*/
        bool checkKey(UserInput);
};

#endif 
