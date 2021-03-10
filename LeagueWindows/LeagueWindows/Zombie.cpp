#include "Zombie.hpp"

Zombie::Zombie() { 
	zombie = new Sprite("../assets/zombie.png");
}
Zombie::Zombie(Sprite* sprite) {
	zombie = sprite;
}
Zombie::~Zombie() {
	zombie->~Sprite();
}

void Zombie::left(double delta) {
	zombie->setVelocityX(-50);
}