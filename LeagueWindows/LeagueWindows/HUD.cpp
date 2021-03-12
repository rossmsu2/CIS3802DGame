#include "Engine.hpp"
#include "HUD.hpp"
#include <SDL_ttf.h>
#include <random>
#include <ctime>

HUD::HUD(){
	font = TTF_OpenFont("../assets/Mystical Snow.ttf", 32);
	if(font == NULL){
		SDL_Log("No font. %s", TTF_GetError());
	}
	color.r=0;
	color.g=0;
	color.b=0;
	zombies = 0;
	clockStart = std::chrono::steady_clock::now();
	clockEnd = std::chrono::steady_clock::now();
	elapsedTime = std::chrono::duration<float>(clockEnd - clockStart).count();
	elapsedTime = round(elapsedTime * 100.0) / 100.0;
	display = "Zombies Killed: " + std::to_string(zombies) + " Time: " + std::to_string(elapsedTime);
	surface = TTF_RenderText_Solid(font, display.c_str(), color); 
	if(surface == NULL){
		SDL_Log("Can't create text. %s", SDL_GetError());
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if(texture == NULL){
		SDL_Log("Can't create texture. %s", SDL_GetError());
	}
	rect->x = 0;
	rect->y = 0;
	rect->w = surface->w;
	rect->h = surface->h;
	rng=std::mt19937(rd());
	uni=std::uniform_int_distribution<int>(0,255);
}

HUD::~HUD(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void HUD::update(double delta){
	clockEnd = std::chrono::steady_clock::now();
	elapsedTime = std::chrono::duration<float>(clockEnd - clockStart).count();
	elapsedTime = round(elapsedTime * 100.0) / 100.0;
	display = "Zombies Killed: " + std::to_string(zombies) + " Time: " + std::to_string(elapsedTime);
	surface = TTF_RenderText_Solid(font, display.c_str(), color); 
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}

void HUD::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}
