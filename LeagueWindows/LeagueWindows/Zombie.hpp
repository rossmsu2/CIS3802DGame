#ifndef			__HPP__ZOMBIE__
#define			__HPP__ZOMBIE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"

class Zombie {
public:
	Zombie();
	Zombie(Sprite sprite);
	~Zombie();
	void update(double delta);
	void draw();
private:
	

};

#endif