/*
 * Player.h
 *
 *  Created on: Dec 20, 2015
 *      Author: myung
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	bool init(float centerY);
	void update(float elapsedSeconds);

private:
	sf::Texture texture;
	sf::Sprite pc;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif /* PLAYER_H_ */
