/*
 * frameRate.h
 *
 *  Created on: Dec 14, 2015
 *      Author: myung
 */

#ifndef FRAMERATE_H_
#define FRAMERATE_H_

#include <SFML/Graphics.hpp>

class FrameRate
{
public:
	FrameRate(const sf::Font& font);
	void draw(sf::RenderWindow& window);

private:
	sf::Text m_text;
	sf::Clock m_clock;
	sf::Uint32 frameCount;

	void drawShadow(sf::RenderWindow& window);
	void drawText(sf::RenderWindow& window);
};

#endif /* FRAMERATE_H_ */
