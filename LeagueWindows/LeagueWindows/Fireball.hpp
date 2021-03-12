#ifndef            __HPP__PROJECTILE__
#define            __HPP__PROJECTILE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"

class Fireball : public DUGameObject {
public:
    Fireball();
    ~Fireball();
    void update(double delta);
    void draw();
private:
    Vector3 velocity;

    friend class Wizard;
};

#endif
