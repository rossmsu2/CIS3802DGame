#ifndef			__HPP__WIZARD__
#define			__HPP__WIZARD__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"
#include "Engine.hpp"
#include "Scene.hpp"

class Wizard : public Sprite {
	public:
		Wizard();
		~Wizard();
		void fire();
		void up(double delta);
		void down(double delta);
		void setScene(Scene* s);
		Scene* scene;
	private:
		
		friend class Fireball;

};

#endif
