#include "Wizard.hpp"
#include "Fireball.hpp"

Wizard::Wizard(){
	wizard = new Sprite("../assets/wizard.png");
}
Wizard::Wizard(Sprite* sprite) {
	wizard = sprite;
}
Wizard::~Wizard() {
	wizard->~Sprite();
}
void Wizard::fire(double delta) {
	Fireball* f = new Fireball();
	f->position.setX(wizard->getPosition().getX());
	f->position.setY(wizard->getPosition().getY());
	f->velocity.setX(100);
	this->scene->addDrawable(f);
	this->scene->addUpdateable(f);
}
void Wizard::up(double delta) {
	wizard->setVelocityY(-100);
}
void Wizard::down(double delta) {
	wizard->setVelocityY(100);
}

void Wizard::setScene(Scene* scene) {
	this->scene = scene;
}




