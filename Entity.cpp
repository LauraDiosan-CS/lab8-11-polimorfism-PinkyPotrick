#include "Entity.h"

Entity::Entity() {

}

Entity::~Entity() {

}

int Entity::getID() {
		return this->ID;
}

void Entity::setID(int newID) {
	this->ID = newID;
}