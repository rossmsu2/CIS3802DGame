#ifndef __HPP__SPAWNER__
#define __HPP__SPAWNER__

#include "Interfaces.hpp"
#include "Scene.hpp"
#include "Zombie.hpp"

class Spawner : public UGameObject {

public:
	Spawner(Scene* scene);
	~Spawner();
	void update(double delta);
	
private:
	Scene* scene;


};

#endif