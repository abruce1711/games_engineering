// entity.h
// Handles position and movement for on screen entities
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "maths.h"
#include <algorithm>
#include <typeindex>
#include <vector>

class Component {
protected:
	Entity *const _parent;
	bool _fordeletion; // should be removed
	explicit Component(Entity *const p);

public:
	Component() = delete;
	bool is_fordeletion() const;
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~Component();
};

class Entity {

protected:
	std::vector<std::shared_ptr<Component>> _components;
	sf::Vector2f _position;
	float _rotation;
	bool _alive;       // should be updated
	bool _visible;     // should be rendered
	bool _fordeletion; // should be deleted
public:
	Entity();
	virtual ~Entity();
	virtual void update(double dt);
	virtual void render();

	const sf::Vector2f &getPosition() const;
	void setPosition(const sf::Vector2f &_position);
	bool is_fordeletion() const;
	float getRotation() const;
	void setRotation(float _rotation);
	bool isAlive() const;
	void setAlive(bool _alive);
	void setForDelete();
	bool isVisible() const;
	void setVisible(bool _visible);
};

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render();
};