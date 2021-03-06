#include "player.h"
#include "Levelsystem.h"
#include <iostream>

bool Player::validmove(sf::Vector2f pos) {
	return (ls::getTileAt(pos) != ls::WALL);
}

void Player::update(double dt) {

	float directionX = 0.0f;
	float directionY = 0.0f;
	
	sf::Vector2f movement = sf::Vector2f (0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(controls[0])) {
		directionX--;
	}
	else if (sf::Keyboard::isKeyPressed(controls[1])) {
		directionX++;
	}

	if (sf::Keyboard::isKeyPressed(controls[2])) {
		directionY--;
	}
	else if (sf::Keyboard::isKeyPressed(controls[3])) {
		directionY++;
	}

	movement.x = directionX * _speed * dt;
	movement.y = directionY * _speed * dt;

	
	if (validmove(getPosition() + movement)) {
		move(movement);
	}
	else {
		std::cout << "Invalid move" << std::endl;
	}

	Entity::update(dt);
}

Player::Player()
	: _speed(200.0f), Entity(std::make_unique<sf::CircleShape>(25.f)) {
	_shape->setFillColor(sf::Color::Magenta);
}

void Player::render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}
