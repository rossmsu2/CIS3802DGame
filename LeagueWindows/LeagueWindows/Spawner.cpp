#include "Spawner.hpp"


Spawner::Spawner(Scene* scene) {
	this->scene = scene;
}

Spawner::~Spawner() {

}

void Spawner::update(double delta) {
	if ((rand() % 1000 + 1) >= 975) {
		try {
			Zombie* z = new Zombie(950, rand() % 650 + 60);
			z->left(delta);
			this->scene->addNewObject(z, z);
		}
		catch (int x) {
		
		}
	}
}