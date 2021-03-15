#ifndef			__HPP__HUD__
#define			__HPP__HUD__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <random>
#include <string>
#include <chrono>

class HUD : public DUGameObject {
public:
	HUD();
	~HUD();
	void update(double delta);
	void draw();
	void gameEnd();
private:
	TTF_Font* font;
	SDL_Color color;
	int elapsed;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> uni;
	int zombies;
	std::chrono::time_point<std::chrono::high_resolution_clock> clockStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> clockEnd;
	float elapsedTime;
	std::string display;


};

#endif