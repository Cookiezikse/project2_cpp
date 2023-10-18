#pragma once

#include <iostream>
#include<vector>
class GameObject {
public:
	//GameObject(const std::string& name)	
	//	: name(name){}
	const std::string getTag() const;
	void setTag(const std::string& tag_set);
	const std::string getName() const;
	float getScale() const;
	bool isTag(const std::string& tag_check) const;

	void setName(std::string& name_set);
	void setScale(float scale_set);
	//const glm::vec2 GetPosition() const { return position; };
	//const glm::vec2 GetRotation() const { return rotation; };
	//const glm::vec2 GetScale() const { return scale; };
	//const glm::vec2 GetColor() const { return color; };

private:
	std::string name = "GameObject";
	std::string tag;
	std::vector<std::string> *Components;
	float scale = 1;
	//glm::vec2 position;
	//glm::vec2 rotation;
	//glm::vec2 color;




};
