#include "Engine.hpp"
#include "Banana.hpp"
#include "HUD.hpp"
#include "Sprite.hpp"
#include "Wizard.hpp"
#include "Zombie.hpp"
#include "Fireball.hpp"
#include <SDL.h>
#include <vector>

int main(int argc, char** argv){
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
	}

	// Create a scene
	Scene one;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 768);

	//Wizard* Bob = new Wizard();
	//Bob->setScene(&one);
	//one.addUpdateable(Bob->wizard);
	//one.addDrawable(Bob->wizard);
	//auto Bob_up = [Bob](double delta) { Bob->up(delta); };
	//auto Bob_down = [Bob](double delta) { Bob->down(delta); };
	//auto Bob_fire = [Bob](double delta) { Bob->fire(delta); };
	//one.addKeyEvent(SDLK_w, Bob_up);
	//one.addKeyEvent(SDLK_s, Bob_down);
	//one.addKeyEvent(SDLK_SPACE, Bob_fire);

	std::vector<Zombie*> Freds;
	Zombie* Fred = new Zombie();
	one.addUpdateable(Fred->zombie);
	one.addDrawable(Fred->zombie);
	Fred->zombie->moveSpriteOver(1000, 300);
	Fred->left(0.0);

	// Make a banana and add to scene. Should update and draw.
	/*
	Banana* b = new Banana();
	one.addUpdateable(b);
	one.addDrawable(b);
	auto b_up = [b](double delta) { b->up(delta); };
	auto b_down = [b](double delta) { b->down(delta); };
	auto b_left = [b](double delta) { b->left(delta); };
	auto b_right = [b](double delta) { b->right(delta); };
	one.addKeyEvent( SDLK_w, b_up );
	one.addKeyEvent( SDLK_a, b_left );
	one.addKeyEvent( SDLK_d, b_right );
	one.addKeyEvent( SDLK_s, b_down );
	*/
	// Add the HUD
	HUD* h = new HUD();
	one.addUpdateable(h);
	one.addDrawable(h);

	// Set the scene in the engine
	engine.setScene(&one);
	
	// Get the engine running.
	engine.run();

	return 0;
}
