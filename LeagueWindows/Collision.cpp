#include "Engine.hpp"
#include "Collision.hpp"
#include <typeinfo>
#include <string>


Collision::Collision() {
	int i = 0;
}

Collision::~Collision() {

}

void Collision::check(std::vector<Updateable*> check) {
	std::string temp;
	std::string temp2;
	for (auto it = check.begin(); it != check.end(); it++) {
		std::string temp (typeid(**it).name());
		if ((temp == "class Fireball")) {	
			for (auto j = check.begin(); j != check.end(); j++) {
				std::string temp2 (typeid(**j).name());
				if (temp2 == "class Zombie") {
					
				}
			}
		}
	}
}

void Collision::update(double delta) {

}