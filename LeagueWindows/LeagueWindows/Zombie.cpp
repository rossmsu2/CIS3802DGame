#include "Zombie.hpp"

Zombie::Zombie() {
	zombie = new Sprite("../assets/zombie.png");
}
Zombie::Zombie(int x, int y) {
	zombie = new Sprite("../assets/zombie.png");
	zombie->position.setX(x);
	zombie->position.setY(y);
}
Zombie::~Zombie() {
	zombie->~Sprite();
}

void Zombie::left(double delta) {
	zombie->velocity.setX(-1 * delta);
}