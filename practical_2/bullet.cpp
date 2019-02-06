#include "bullet.h"

Bullet::Bullet(const sf::Vector2f & pos, const bool mode){}

Bullet::Bullet(){}

void Bullet::Update(const float & dt) {
	move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
}
