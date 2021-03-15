#include "Engine.hpp"
#include "Fireball.hpp"

static int counter = 0;

Fireball::Fireball(Scene* s) {
    counter = counter + 1;
    if (counter > 5) {
        throw 99;
    }
    scene = s;
    surface = IMG_Load("../assets/fireball.png");
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
    velocity.setX(1000);
    velocity.setY(0);
    velocity.setZ(0);
}

Fireball::~Fireball() {
    counter = counter - 1;
}

void Fireball::update(double delta) {
    // So we stop getting the compiler warning for now.
    position.setX(position.getX() + velocity.getX() * delta);
    position.setY(position.getY() + velocity.getY() * delta);
    if (position.getX() > 1024 - rect->w) {
        this->scene->objectsToDelete(this, this);
        /*delete this;*/
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