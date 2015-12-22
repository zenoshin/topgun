#include <fstream>
#include <SFML/Graphics.hpp>
#include "frameRate.h"
#include "Player.h"

int main()
{
	std::ofstream logFile("log.txt");
	sf::err().rdbuf(logFile.rdbuf());

	sf::RenderWindow window(sf::VideoMode(800,600), "Project Topgun");
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if(false == font.loadFromFile("waltographUI.ttf"))
		return -1;

	FrameRate frameRate(font);

	Player player;
	if(false == player.init(window.getSize().y / 2))
		return -1;

	sf::Clock clock;
	while(window.isOpen())
	{
		auto elapsedTime = clock.restart();

		sf::Event event;
		static bool focused = true;
		while(window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
				window.close();

			if(sf::Event::LostFocus == event.type)
				focused = false;

			if(sf::Event::GainedFocus == event.type)
				focused = true;
		}

		if(focused)
		{
			player.update(elapsedTime.asSeconds());

			window.clear(sf::Color::White);

			frameRate.draw(window);

			window.draw(player);

			window.display();
		}
		else
			sf::sleep(sf::milliseconds(100));
	}

	return 0;
}
