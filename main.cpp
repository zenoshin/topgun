#include <SFML/Graphics.hpp>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Project Topgun");
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if(false == font.loadFromFile("waltographUI.ttf"))
		return -1;
	sf::Text frameRateText;
	frameRateText.setFont(font);
	frameRateText.setString("-fps");
	frameRateText.setCharacterSize(20);
	sf::Clock clock;
	sf::Uint32 frameCount = 0;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
				window.close();
		}

		window.clear(sf::Color::White);

		++frameCount;
		if(clock.getElapsedTime().asSeconds() >= 1.f)
		{
			frameRateText.setString(std::to_string(frameCount) + "fps");
			clock.restart();
			frameCount = 0;
		}
		frameRateText.setOrigin(frameRateText.getLocalBounds().width + 6, 0);
		frameRateText.setPosition(window.getSize().x + 1, 1);
		frameRateText.setColor(sf::Color(0, 0, 0, 128));
		window.draw(frameRateText);
		frameRateText.setPosition(window.getSize().x, 0);
		frameRateText.setColor(sf::Color(224, 224, 224, 255));
		window.draw(frameRateText);

		window.display();
	}

	return 0;
}
