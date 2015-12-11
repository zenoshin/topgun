#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200,200), "Project Topgun");

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
				window.close();
		}
	}

	return 0;
}
