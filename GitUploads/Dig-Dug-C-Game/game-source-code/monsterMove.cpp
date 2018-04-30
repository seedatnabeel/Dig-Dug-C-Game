#include "monsterMove.h"


monsterMove::monsterMove()
{}

void monsterMove::tunnel_check(std::vector <tunnel> &tunnelVector, std::vector <genie> &genieVector, float srs_xpos, float srs_ypos)
{
	
	int counter = 0;
	for (auto iter = begin(genieVector); iter != end(genieVector); iter++)
	{
		int counter2 = 0;
		for (auto iter4 = begin(tunnelVector); iter4 != end(tunnelVector); iter4++)
		{
			if (genieVector.at(counter).rect.getGlobalBounds().intersects(tunnelVector.at(counter2).rect.getGlobalBounds()))
			{
			   genieVector.at(counter).ghost=false;
			   break;
			}
			else
			{
				genieVector.at(counter).ghost=true;
				}

			counter2++;
		}
		genieVector.at(counter).updateMovement(srs_xpos,srs_ypos);
		counter++;
	} 
}