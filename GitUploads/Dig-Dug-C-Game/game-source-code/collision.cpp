#include "collision.h"

collision::collision()
{}

void collision::mons_lightning(std::vector <genie> &genieVector, std::vector <lightning> &lightningVector, float &hit_posx, float &hit_posy)
{
	int counter = 0;
	if(genieVector.size()!=0)
	{
		for (auto it = begin(lightningVector); it != end(lightningVector); it++)
		{   
			int counter2 = 0;

			for (auto it2 = begin(genieVector); it2 != end(genieVector); it2++)
			{ 
				if (lightningVector.at(counter).rect.getGlobalBounds().intersects(genieVector.at(counter2).rect.getGlobalBounds()))
				{  
					hit_posx=genieVector.at(counter2).rect.getPosition().x;
					hit_posy=genieVector.at(counter2).rect.getPosition().y;
					
					if (timer.getElapsedTime().asSeconds()>1)
					{
						genieVector.at(counter2).alive = false;
						timer.restart();
					}
				}
				
			counter2++;
			}

		counter++;
		}
	} 
}