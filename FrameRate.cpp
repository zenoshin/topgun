/*
 * frameRate.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: myung
 */

#include <string>
#include "FrameRate.h"

FrameRate::FrameRate(const sf::Font& font)
: m_frameCount(0)
{
	m_text.setFont(font);
	m_text.setString("-fps");
	m_text.setCharacterSize(20);
}

void FrameRate::draw(sf::RenderWindow& window)
{
	++m_frameCount;
	if(m_clock.getElapsedTime().asSeconds() >= 1.f)
	{
		m_text.setString(std::to_string(m_frameCount) + "fps");
		m_text.setOrigin(m_text.getLocalBounds().width + 6, 0);
		m_text.setColor(m_frameCount >= 30 ? sf::Color::Green :
				m_frameCount >= 10 ? sf::Color::Yellow : sf::Color::Red);
		m_clock.restart();
		m_frameCount = 0;
	}

	drawShadow(window);
	drawText(window);
}

void FrameRate::drawShadow(sf::RenderWindow& window)
{
	m_text.setPosition(window.getSize().x + 1, 1);
	const auto orgColor = m_text.getColor();
	m_text.setColor(sf::Color(0, 0, 0, 128));
	window.draw(m_text);
	m_text.setColor(orgColor);
}

void FrameRate::drawText(sf::RenderWindow& window)
{
	m_text.setPosition(window.getSize().x, 0);
	window.draw(m_text);
}
