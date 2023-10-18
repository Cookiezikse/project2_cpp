#include <iostream>
#include<vector>
#include "GameObjectLib.h"

void HelloFromLib()
{
	std::cout << "Hello from GameObjectLib" << std::endl;
}

void HelloFromGameObject() {
	std::cout << "Hello from GameObject" << std::endl;
}

const std::string GameObject::getName() const { 
	return name; 
};

void GameObject::setName(std::string& name_set) { 
	name = name_set; 
};

const std::string GameObject::getTag() const {
	return tag; 
};
void GameObject::setScale(float scale_set) { 
	scale = scale_set; 
};

float GameObject::getScale() const { 
	return scale; 
};

void GameObject::setTag(const std::string& tag_set) {
	tag = tag_set;
};

bool GameObject::isTag(const std::string& tag_check) const {
	return tag == tag_check;
}