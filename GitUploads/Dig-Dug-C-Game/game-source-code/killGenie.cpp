#include "killGenie.h"

killGenie::killGenie()
{}

void killGenie::kill_genie(std::vector <genie> &genieVector)
{
	int counter = 0;
	for (auto it = begin(genieVector); it != end(genieVector); it++)
	{
		if (genieVector.at(counter).alive == false)
		{    
			genieVector.erase(it);
		}

		counter++;
	}

}
