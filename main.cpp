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
			sf::Vector2f move(0, 0);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				move.x -= 1;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				move.x += 1;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				move.y -= 1;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				move.y += 1;
			pc.move(move * 100.f * elapsedTime.asSeconds());

			window.clear(sf::Color::White);

			frameRate.draw(window);

			window.draw(pc);

			window.display();
		}
		else
			sf::sleep(sf::milliseconds(100));
	}

	return 0;
}
