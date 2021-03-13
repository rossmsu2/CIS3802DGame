#ifndef            __HPP__PROJECTILE__
#define            __HPP__PROJECTILE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include "Wizard.hpp"

class Fireball : public DUGameObject {
public:
    Fireball(Wizard* wiz);
    ~Fireball();
    void update(double delta);
    void draw();
    Sprite* fire;
    Wizard* wiz;
private:
    
};

#endif