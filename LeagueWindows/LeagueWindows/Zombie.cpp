#include "Zombie.hpp"

Zombie::Zombie() { 
	zombie = new Sprite("../assets/zombie.png");
}
Zombie::Zombie(Sprite* sprite) {
	zombie = sprite;
}
Zombie::Zombie(Sprite* sprite, int x, int y) {
	zombie = sprite;
	sprite->setPositionX(x);
	sprite->setPositionY(y);
}
Zombie::~Zombie() {
	zombie->~Sprite();
}

void Zombie::left(double delta) {
	zombie->setVelocityX(-30);
}