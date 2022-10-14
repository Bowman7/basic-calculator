#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;

int main()
{
	sf::Event event;
	sf::Window mwindow(sf::VideoMode(480,480),"sf");
	while(true)
	{
		sf::Vector2i pos;
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			pos=sf::Mouse::getPosition();
			std::cout<<"pos x: "<<pos.x<<"pos y: "<<pos.y<<std::endl;
		}
		
	}
	return 0;
}
