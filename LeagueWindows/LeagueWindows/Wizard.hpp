#ifndef			__HPP__WIZARD__
#define			__HPP__WIZARD__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"

class Wizard {
	public:
		Wizard();
		Wizard(Sprite* sprite);
		~Wizard();
		void fire(double delta);
		void up(double delta);
		void down(double delta);
		Sprite* wizard;
	private:
	
	friend class Sprite;
	

};

#endif
