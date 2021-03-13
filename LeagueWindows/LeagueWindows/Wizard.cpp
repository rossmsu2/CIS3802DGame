#include "Wizard.hpp"
#include "Fireball.hpp"

Wizard::Wizard() {
	wizard = new Sprite("../assets/wizard.png");
	wizard->position.setY(61);
}
Wizard::~Wizard() {
	wizard->~Sprite();
}
void Wizard::fire() {
	Fireball* f = new Fireball(this);
	f->fire->position.setX(wizard->position.getX());
	f->fire->position.setY(wizard->position.getY());
	this->scene->addDrawable(f->fire);
	this->scene->addUpdateable(f->fire);
}
void Wizard::up(double delta) {
	wizard->velocity.setY(-1000 * delta);
}
void Wizard::down(double delta) {
	wizard->velocity.setY(1000 * delta);
}

void Wizard::setScene(Scene* s) {
	this->scene = s;
}
