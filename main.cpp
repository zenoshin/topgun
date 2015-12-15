#include <SFML/Graphics.hpp>
#include "frameRate.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Project Topgun");
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if(false == font.loadFromFile("waltographUI.ttf"))
		return -1;

	FrameRate frameRate(font);

	sf::Texture pcTexture;
	pcTexture.loadFromFile("Biplane.png");
	sf::Sprite pc;
	pc.setTexture(pcTexture);
	pc.setScale(0.1f, 0.1f);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
				window.close();
		}

		window.clear(sf::Color::White);

		frameRate.draw(window);

		window.draw(pc);

		window.display();
	}

	return 0;
}
