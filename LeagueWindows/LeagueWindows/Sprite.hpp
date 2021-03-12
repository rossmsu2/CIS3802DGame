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
		void setVelocityX(int x);
		void setVelocityY(int y);
		void setVelocityZ(int z);
		void setPositionX(int x);
		void setPositionY(int y);
		void moveSpriteOver(int x, int y);
		Vector3 getPosition();
		Vector3 getVelocity();
	private:
		Vector3 velocity;

};

#endif
