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
	if(false == pcTexture.loadFromFile("Biplane.png"))
		return -1;
	sf::Sprite pc;
	pc.setTexture(pcTexture);
	pc.setScale(0.1f, 0.1f);
	const auto pcBound = pc.getLocalBounds();
	pc.setOrigin(pcBound.width / 2.f, pcBound.height / 2.f);
	pc.setPosition(pc.getGlobalBounds().width, window.getSize().y / 2);

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
