#pragma once
#include "ecm.h"

class Ghost : public Entity {
private:
	float _speed;
	sf::Color _colour;
	float _movementCool = 0.f;
	float directionX = 0.f;
	float directionY = 0.f;

public:
	void update(double dt) override;
	Ghost();
	void render() const override;
	void setSpeed(float increase);
	void setColour(sf::Color colour);
};
