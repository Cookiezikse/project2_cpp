#include "Header.h"
#include "GameObjectLib.h"

void CallLibFunction()
{
	GameObject object;
	std::string Name = "Joueur";
	object.setName(Name);
	std::cout << object.getName() << std::endl;
	std::cout << object.getTag()  << "ok" << std::endl;
}
