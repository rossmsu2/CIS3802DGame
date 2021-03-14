#include "Wizard.hpp"
#include "Fireball.hpp"

Wizard::Wizard() {
	surface = IMG_Load("../assets/wizard.png");
	if (surface == NULL) {
		SDL_Log("Unable to load wizard.");
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if (texture == NULL) {
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}
	rect->x = 0;
	rect->y = 0;
	rect->w = surface->w;
	rect->h = surface->h;
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
	position.setY(61);
}
Wizard::~Wizard() {
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}
void Wizard::fire() {
	try {
		Fireball* f = new Fireball(this->scene);
		f->position.setX(position.getX());
		f->position.setY(position.getY());
		this->scene->addDrawable(f);
		this->scene->addUpdateable(f);
	}
	catch (int x){
	
	}

}
void Wizard::up(double delta) {
	velocity.setY(-1000 * delta);
}
void Wizard::down(double delta) {
	velocity.setY(1000 * delta);
}

void Wizard::setScene(Scene* s) {
	this->scene = s;
}
