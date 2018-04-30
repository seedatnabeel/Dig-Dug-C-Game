
#include "controls.h"

// Constructor
controls::controls()
{}

bool controls::checkKey(UserInput key)
{
    bool pressed = false;
    switch (key)
    {
       
        case UserInput::Up:
        {
            if (Keyboard::isKeyPressed(Keyboard::Up))
                pressed = true;
            break;
        }
       
        case UserInput::Down:
        {
            if (Keyboard::isKeyPressed(Keyboard::Down))
                pressed = true;
            break;
        }
        case UserInput::Left:
        {
            if (Keyboard::isKeyPressed(Keyboard::Left))
                pressed = true;
            break;
        }
	
        case UserInput::Right:
        {
            if (Keyboard::isKeyPressed(Keyboard::Right))
                pressed = true;
            break;
        }
        case UserInput::Shoot:
        {
            if (Keyboard::isKeyPressed(Keyboard::Space))
                pressed = true;
            break;
        }
		 case UserInput::Escape:
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                pressed = true;
            break;
        }
		 case UserInput::continueWelcome:
        {
            if (Keyboard::isKeyPressed(Keyboard::Space))
                pressed = true;
            break;
        }
		 case UserInput::continueSplash:
        {
            if (Keyboard::isKeyPressed(Keyboard::RShift))
                pressed = true;
            break;
        }
		
        default:
        {
            pressed = false;
            break;
        }
    }
    return pressed;
}

