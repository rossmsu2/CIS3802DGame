#ifndef			__HPP__ZOMBIE__
#define			__HPP__ZOMBIE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"

class Zombie {
	public:
		Zombie();
		Zombie(Sprite* sprite);
		~Zombie();
		void left(double delta);
		Sprite* zombie;
	private:

	friend class Sprite;
	

};

#endif