#include "Engine.hpp"
#include "Fireball.hpp"

Fireball::Fireball() {
    surface = IMG_Load("../assets/fireball.png"); // insert the path for the fireball
    if (surface == NULL) {
        SDL_Log("Unable to load fireball.");
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
    velocity.setX(200);
    velocity.setY(0);
    velocity.setZ(0);
}

Fireball::Fireball(Vector3 input) {
    surface = IMG_Load("../assets/fireball.png"); // insert the path for the fireball
    if (surface == NULL) {
        SDL_Log("Unable to load fireball.");
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
    position.setY(input.getY());
    velocity.setX(200);
    velocity.setY(0);
    velocity.setZ(0);

}

Fireball::~Fireball() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Fireball::update(double delta) {
    // So we stop getting the compiler warning for now.
    position.setX(position.getX() + velocity.getX() * delta);
    position.setY(position.getY() + velocity.getY() * delta);
    if (position.getX() > 1024 - rect->w || position.getX() < 0) {
        velocity.setX(-velocity.getX());
    }
    
}

void Fireball::draw() {
    SDL_Rect* dst = new SDL_Rect();
    dst->x = position.getX();
    dst->y = position.getY();
    dst->w = rect->w;
    dst->h = rect->h;
    SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}

Vector3 Fireball::getPosition() {
    return position;
}