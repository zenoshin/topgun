#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200,200), "Project Topgun");

	sf::Font font;
	if(false == font.loadFromFile("waltographUI.ttf"))
		return -1;
	sf::Text frameRateText;
	frameRateText.setFont(font);
	frameRateText.setString("-fps");
	frameRateText.setCharacterSize(12);
	frameRateText.setColor(sf::Color::White);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
				window.close();

			window.clear();

			window.draw(frameRateText);

			window.display();
		}
	}

	return 0;
}
