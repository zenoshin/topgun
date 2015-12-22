/*
 * Player.cpp
 *
 *  Created on: Dec 20, 2015
 *      Author: myung
 */

#include "Player.h"

bool Player::init(float centerY)
{
	if(false == texture.loadFromFile("Biplane.png"))
		return false;

	pc.setTexture(texture);
	pc.setScale(0.1f, 0.1f);
	const auto pcBound = pc.getLocalBounds();
	pc.setOrigin(pcBound.width / 2.f, pcBound.height / 2.f);
	pc.setPosition(pc.getGlobalBounds().width, centerY);

	return true;
}

void Player::update(float elapsedSeconds)
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
	pc.move(move * 100.f * elapsedSeconds);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(pc);
}
