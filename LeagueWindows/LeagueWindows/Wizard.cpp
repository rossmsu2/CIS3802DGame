#include "Wizard.hpp"

Wizard::Wizard(){
	wizard = new Sprite("../assets/wizard.png");
}
Wizard::Wizard(Sprite* sprite) {
	wizard = sprite;
}
Wizard::~Wizard() {
	wizard->~Sprite();
}
void Wizard::fire(double delta) {}
void Wizard::up(double delta) {
	wizard->setVelocityY(-100);
}
void Wizard::down(double delta) {
	wizard->setVelocityY(100);
}




