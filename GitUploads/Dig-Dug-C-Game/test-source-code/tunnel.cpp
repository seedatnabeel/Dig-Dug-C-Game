#include "tunnel.h"
#include <fstream>

using namespace std;
tunnel::tunnel()
{
	rect.setSize(Vector2f(80,80));
	rect.setFillColor(Color (150,75,0));
	rect.setPosition(160,160);
}

void tunnel::start(std::vector <tunnel> *tunnelVector, tunnel tunnel1)
{
	ifstream pretunnel ("tunnel-coords.txt");
	int tun_x=0;
	int tun_y=0;
	
	while(pretunnel >> tun_x >> tun_y)
	{
		tunnel1.rect.setPosition(tun_x,tun_y);
	    tunnelVector->push_back(tunnel1);
		}
}
