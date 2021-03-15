#include <SDL.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"
#include <string>


Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::addUpdateable(Updateable* obj) {
    this->updateables.push_back(obj);
}

void Scene::addNewObject(Updateable* objU, Drawable* objD) {
    this->newObjects.push_back(objU);
    this->newDObjects.push_back(objD);

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
    for (auto it = this->newDObjects.begin(); it != newDObjects.end(); ++it) {
        this->drawables.push_back(*it);
    }
    this->newObjects.clear();
    this->newDObjects.clear();
}

void Scene::objectsToDelete(Updateable* objU, Drawable* objD) {
    this->deleteObjects.push_back(objU);
    this->deleteDObjects.push_back(objD);

}

void Scene::deleteAll() {
    
    for (auto it = this->deleteObjects.begin(); it != deleteObjects.end(); it++) {
        this->updateables.erase(it);
    }
    for (auto it = this->deleteDObjects.begin(); it != deleteDObjects.end(); it++) {
       this->drawables.erase(it);
    }
}