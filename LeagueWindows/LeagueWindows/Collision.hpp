#ifndef			__HPP__Collision__
#define			__HPP__Collision__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <vector>

class Collision : public UGameObject {
public:

	Collision();
	~Collision();
	void check(std::vector<Updateable*> check);
	void update(double delta);

private:
	


};




#endif
