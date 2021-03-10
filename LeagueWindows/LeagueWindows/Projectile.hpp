#ifndef			__HPP__PROJECTILE__
#define			__HPP__PROJECTILE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"

class Projectile : public DUGameObject {
	public:
		Projectile();
		Projectile(Sprite sprite);
		~Projectile();
		void update(double delta);
		void draw();
	private:
		Vector3 velocity;
	
	friend class Sprite;

};

#endif