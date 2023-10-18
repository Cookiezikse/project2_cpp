#include <iostream>
#include<vector>
#include "GameObjectLib.h"

//GETTERS

const std::string GameObject::getName() const { return name; };
const std::string GameObject::getTag() const {return tag; };
float GameObject::getScale() const { return scale; };

//SETTERS

void GameObject::setTag(const std::string& tag_set) { tag = tag_set; };
bool GameObject::isTag(const std::string& tag_check) const { return tag == tag_check; };
void GameObject::setScale(float scale_set) { scale = scale_set; };
void GameObject::setName(std::string& name_set) { name = name_set; };