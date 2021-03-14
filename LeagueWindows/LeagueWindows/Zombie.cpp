#include "Zombie.hpp"
#include "Engine.hpp"

static int counter = 0;

Zombie::Zombie() {
    counter = counter + 1;
    if (counter > 10) {
        throw 99;
    }
	surface = IMG_Load("../assets/zombie.png");
    if (surface == NULL) {
        SDL_Log("Unable to load zombie.");
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
}
Zombie::Zombie(int x, int y) {
    counter = counter + 1;
    if (counter > 10) {
        throw 99;
    }
    surface = IMG_Load("../assets/zombie.png");
    if (surface == NULL) {
        SDL_Log("Unable to load zombie.");
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
	position.setX(x);
	position.setY(y);
}
Zombie::~Zombie() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    counter = counter - 1;
}

void Zombie::update(double delta) {
    // So we stop getting the compiler warning for now.
    position.setX(position.getX() + velocity.getX() * delta);
    position.setY(position.getY() + velocity.getY() * delta);
    if (position.getX() <= 60) {
        
    }
}

void Zombie::left(double delta) {
	velocity.setX(-250 * delta);
}