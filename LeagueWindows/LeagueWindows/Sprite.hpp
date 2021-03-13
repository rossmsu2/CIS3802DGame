#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <string>

class Sprite : public DUGameObject {
	public:
        Sprite();
		Sprite(std::string Image);
        Sprite(SDL_Surface* inputSurface);
		~Sprite();
		void update(double delta);
		void draw();	
	private:
		Vector3 velocity;

		friend class Wizard;
		friend class Zombie;
		friend class Fireball;

};

#endif
