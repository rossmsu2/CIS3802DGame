#ifndef			__HPP__WIZARD__
#define			__HPP__WIZARD__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"

class Wizard {
public:
	Wizard();
	Wizard(Sprite sprite);
	~Wizard();
	void update(double delta);
	void draw();
	void left(double delta);
	void right(double delta);
	void up(double delta);
	void down(double delta);
private:
	

};

#endif
