#ifndef			__HPP__SCENE__
#define			__HPP__SCENE__

#include <SDL.h>
#include <vector>
#include <utility>
#include <functional>
#include "Interfaces.hpp"
#include "Utility.hpp"

class Scene {
public:
	Scene();
	~Scene();
	void addUpdateable(Updateable* obj);
	void addDrawable(Drawable* obj);
	void addKeyEvent(SDL_Keycode key, Callback fn);
	void addNewObject(Updateable* obj);
	void addAllNew();
	void objectsToDelete(Updateable* obj);
	void deleteAll();

private:
	std::vector<Updateable*> newObjects;
	std::vector<Updateable*> deleteObjects;
	std::vector<Updateable*> updateables;
	std::vector<Drawable*> drawables;
	std::vector<std::pair<SDL_Keycode, Callback > > keyEvents;

	friend class Engine;
	friend class GameStatus;
};

#endif