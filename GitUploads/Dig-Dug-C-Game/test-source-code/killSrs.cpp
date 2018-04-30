#include "killSrs.h"

killSrs::killSrs()
{}

void killSrs::kill_srs(sorceress &mysrs,std::vector <genie> &genieVector, scoring &myscore)
{
	int counter = 0;
	for (auto it = begin(genieVector); it != end(genieVector); it++)
	{
		if (mysrs.rect.getGlobalBounds().intersects(genieVector.at(counter).rect.getGlobalBounds()))
		{
			
			if(timer1.getElapsedTime().asSeconds()>1)
			{
			 myscore.srsLives=myscore.srsLives-1;
			 timer1.restart();
			}
			if (myscore.srsLives<=0)
			{
				myscore.srsDead=true;
			}
		}
		counter++;
	} 

}
