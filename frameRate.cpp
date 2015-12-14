/*
 * frameRate.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: myung
 */

#include "frameRate.h"
#include <string>

FrameRate::FrameRate(const sf::Font& font)
: frameCount(0)
{
	frameRateText.setFont(font);
	frameRateText.setString("-fps");
	frameRateText.setCharacterSize(20);
}

void FrameRate::draw(sf::RenderWindow& window)
{
	++frameCount;
	if(clock.getElapsedTime().asSeconds() >= 1.f)
	{
		frameRateText.setString(std::to_string(frameCount) + "fps");
		frameRateText.setColor(frameCount >= 30 ? sf::Color::Green :
				frameCount >= 10 ? sf::Color::Yellow : sf::Color::Red);
		clock.restart();
		frameCount = 0;
	}
	frameRateText.setOrigin(frameRateText.getLocalBounds().width + 6, 0);
	const unsigned int windowWidth = window.getSize().x;
	frameRateText.setPosition(windowWidth + 1, 1);
	const auto orgColor = frameRateText.getColor();
	frameRateText.setColor(sf::Color(0, 0, 0, 128));
	window.draw(frameRateText);
	frameRateText.setColor(orgColor);
	frameRateText.setPosition(windowWidth, 0);
	window.draw(frameRateText);
}
