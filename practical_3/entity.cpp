#include "entity.h"

void Entity::update(const double dt)
{
	_shape->setPosition(_position);
}

const sf::Vector2f Entity::getPosition()
{
	return _position;
}

void Entity::setPosition(const sf::Vector2f & pos)
{
	_position = pos;
}

void Entity::move(const sf::Vector2f &pos)
{
	_position += pos;
}

Entity::Entity(std::unique_ptr<sf::Shape> s) : _shape(std::move(s)) {}