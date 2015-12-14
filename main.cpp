#include <SFML/Graphics.hpp>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640,480), "Project Topgun");

	sf::Font font;
	if(false == font.loadFromFile("waltographUI.ttf"))
		return -1;
	sf::Text frameRateText;
	frameRateText.setFont(font);
	frameRateText.setString("-fps");
	frameRateText.setCharacterSize(12);
	frameRateText.setColor(sf::Color::White);
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

		window.clear();

		++frameCount;
		if(clock.getElapsedTime().asSeconds() >= 1.f)
		{
			frameRateText.setString(std::to_string(frameCount) + "fps");
			clock.restart();
			frameCount = 0;
		}
		frameRateText.setOrigin(frameRateText.getLocalBounds().width, 0);
		frameRateText.setPosition(window.getSize().x, 0);
		window.draw(frameRateText);

		window.display();
	}

	return 0;
}
