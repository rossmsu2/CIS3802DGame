#ifndef            __HPP__PROJECTILE__
#define            __HPP__PROJECTILE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include "Wizard.hpp"

class Fireball : public Sprite {
public:
    Fireball(Scene* s);
    ~Fireball();
    void update(double delta);
    void draw();
private:
    Scene* scene;
};

#endif