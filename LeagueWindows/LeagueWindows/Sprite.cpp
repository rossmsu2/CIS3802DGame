#include "Engine.hpp"
#include "Sprite.hpp"

Sprite::Sprite(){
    surface = IMG_Load("./assets/banana.png");
	if( surface == NULL ){
		SDL_Log("Unable to load Sprite.");
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if( texture == NULL ){
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

Sprite::Sprite(std::string Image){
	surface = IMG_Load(Image.c_str());
	if( surface == NULL ){
		SDL_Log("Unable to load Sprite.");
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if( texture == NULL ){
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

Sprite::Sprite(SDL_Surface* inputSurface){
	surface = inputSurface;
	if( surface == NULL ){
		SDL_Log("Unable to load Sprite.");
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if( texture == NULL ){
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

Sprite::~Sprite(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Sprite::update(double delta) {
	// So we stop getting the compiler warning for now.
	position.setX(position.getX() + velocity.getX() * delta);
	position.setY(position.getY() + velocity.getY() * delta);
	if (position.getX() > 1024 - rect->w || position.getX() < 0) {
		velocity.setX(-velocity.getX());
	}
	if (position.getY() > 768 - rect->h || position.getY() < 0) {
		velocity.setY(-velocity.getY());
	}
}

void Sprite::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}

void Sprite::setVelocityX(int x) {
	velocity.setX(x);
}

void Sprite::setVelocityY(int y) {
	velocity.setY(y);
}

void Sprite::setVelocityZ(int z) {
	velocity.setZ(z);
}

void Sprite::setPositionX(int x) {
	position.setX(x);
}

void Sprite::setPositionY(int y) {
	position.setY(y);
}

void Sprite::moveSpriteOver(int x, int y) {
	position.setX(position.getX() + x);
	position.setY(position.getY() + y);
}

Vector3 Sprite::getPosition() {
	return position;
}

Vector3 Sprite::getVelocity() {
	return velocity;
}
