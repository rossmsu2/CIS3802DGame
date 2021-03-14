#include <SDL.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::addUpdateable(Updateable* obj) {
    this->updateables.push_back(obj);
}

void Scene::addNewObject(Updateable* obj) {
    this->newObjects.push_back(obj);
}

void Scene::addDrawable(Drawable* obj) {
    this->drawables.push_back(obj);
}

void Scene::addKeyEvent(SDL_Keycode key, Callback fn) {
    keyEvents.push_back(std::make_pair(key, fn));
}

void Scene::addAllNew() {
    for (auto it = this->newObjects.begin(); it != newObjects.end(); ++it) {
        this->updateables.push_back(*it);
    }
    this->newObjects.clear();
}

void Scene::objectsToDelete(Updateable* obj) {
    this->deleteObjects.push_back(obj);
}

void Scene::deleteAll() {
    int i = 0;
    for (auto it = this->deleteObjects.begin(); it != deleteObjects.end(); ++it) {
        this->updateables.erase(this->deleteObjects.begin() + i);
        it--;
        i++;
    }
    this->deleteObjects.clear();
}