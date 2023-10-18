#pragma once

#include <iostream>
#include<vector>
class GameObject {
public:
	GameObject()	
		: isActive(true){}
	const std::string getTag() const;
	void setTag(const std::string& tag_set);
	const std::string getName() const;
	float getScale() const;
	bool isTag(const std::string& tag_check) const;

	void setName(std::string& name_set);
	void setScale(float scale_set);

private:
	std::string name = "GameObject";
	std::string tag;
	std::vector<std::string> Components;
	float scale = 1;
	bool isActive;


};
