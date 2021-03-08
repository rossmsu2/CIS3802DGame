#ifndef			__HPP__PROJECTILE__
#define			__HPP__PROJECTILE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"

class Projectile {
public:
	Projectile();
	Projectile(Sprite sprite);
	~Projectile();
	void update(double delta);
	void draw();
private:
	

};

#endif