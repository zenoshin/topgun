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
	sf::Text frameRateText;
	sf::Clock clock;
	sf::Uint32 frameCount;
};

#endif /* FRAMERATE_H_ */