#include "Engine.hpp"
#include "Fireball.hpp"

Fireball::Fireball(Wizard* wiz) {
    fire->surface = IMG_Load("../assets/fireball.png");
    if (fire->surface == NULL) {
        SDL_Log("Unable to load fireball.");
        exit(1);
    }
    fire->texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), fire->surface);
    if (fire->texture == NULL) {
        SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
        SDL_Log("Unable to create texture. %s", SDL_GetError());
    }
    this->wiz = wiz;
    fire->rect->x = 0;
    fire->rect->y = 0;
    fire->rect->w = fire->surface->w;
    fire->rect->h = fire->surface->h;
    fire->velocity.setX(100);
    fire->velocity.setY(0);
    fire->velocity.setZ(0);
}

Fireball::~Fireball() {
    fire->~Sprite();
    wiz->~Wizard();
}

void Fireball::update(double delta) {
    // So we stop getting the compiler warning for now.
    fire->position.setX(fire->position.getX() + fire->velocity.getX() * delta);
    fire->position.setY(fire->position.getY() + fire->velocity.getY() * delta);
    if (fire->position.getX() > 1024 - fire->rect->w || fire->position.getX() < 0) {
        fire->velocity.setX(fire->velocity.getX());
    }
}

void Fireball::draw() {
    SDL_Rect* dst = new SDL_Rect();
    dst->x = fire->position.getX();
    dst->y = fire->position.getY();
    dst->w = fire->rect->w;
    dst->h = fire->rect->h;
    SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}