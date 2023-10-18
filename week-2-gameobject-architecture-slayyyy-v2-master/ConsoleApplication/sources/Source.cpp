#include "Header.h"
#include "GameObjectLib.h"
#include <iostream>
#include "Vector2.h"

void CallLibFunction()
{
	GameObject object;
	std::string Name = "Joueur";
	object.setName(Name);
	std::cout << object.getName() << std::endl;
	std::cout << object.getTag()  << "ok" << std::endl;



	// Utilisation des constructeurs et des proprietes statiques
	std::cout << "\n\t\t\t Utilisation des constructeurs et des proprietes statiques: \n";
	Vector2 v1(1.0f, 2.0f);
	Vector2 v2(3.0f, 4.0f);

	v1.Print();  // Affiche v1
	v2.Print();  // Affiche v2

	Vector2::up.Print();
	Vector2::down.Print();
	Vector2::left.Print();
	Vector2::right.Print();
	Vector2::zero.Print();



	// Utilisation des operations arithmetiques
	std::cout << "\n\n\n\n\t\t\t Utilisation des operations arithmetiques: \n";

	Vector2 sum = v1 + v2;
	Vector2 diff = v1 - v2;
	Vector2 scaled = v1 * 2.0f;
	Vector2 divided = v2 / 2.0f;

	sum.Print();
	diff.Print();
	scaled.Print();
	divided.Print();

	// Utilisation des operations de comparaison
	std::cout << "\n\n\n\n\t\t\t Utilisation des operations de comparaison: \n";

	bool areEqual = v1 == v2;
	bool notEqual = v1 != v2;

	std::cout << "v1 et v2 sont egaux: " << areEqual << "\n";
	std::cout << "v1 et v2 sont differents: " << notEqual << "\n";

	// Proprietes
	std::cout << "\n\n\n\n\t\t\t Proprietes: \n";

	std::cout << "Magnitude de v1: " << v1.Magnitude() << "\n";
	std::cout << "SqrMagnitude de v1: " << v1.SqrMagnitude() << "\n";

	Vector2 normalizedV1 = v1.Normalized();
	normalizedV1.Print();

	// Methodes publiques
	std::cout << "\n\n\n\n\t\t\t Methodes Publiques : \n";

	v1.Set(10.0f, 20.0f);
	v1.Print();

	v1.Normalize();
	v1.Print();

	// Methodes statiques
	std::cout << "\n\n\n\n\t\t\t Methodes Statiques : \n";

	std::cout << "Angle entre v1 et v2: " << Vector2::Angle(v1, v2) << "\n";
	std::cout << "Distance entre v1 et v2: " << Vector2::Distance(v1, v2) << "\n";
	std::cout << "Dot product de v1 et v2: " << Vector2::Dot(v1, v2) << "\n";

	Vector2 lerpResult = Vector2::Lerp(v1, v2, 0.5f);
	lerpResult.Print();

	Vector2 maxResult = Vector2::Max(v1, v2);
	Vector2 minResult = Vector2::Min(v1, v2);

	maxResult.Print();
	minResult.Print();

	Vector2 moveTowardsResult = Vector2::MoveTowards(v1, v2, 1.0f);
	moveTowardsResult.Print();

	Vector2 perpResult = Vector2::Perpendicular(v1);
	perpResult.Print();


	Vector2 scaleResult = Vector2::Scale(v1, v2);
	scaleResult.Print();

	std::cout << "Signed angle entre v1 et v2: " << Vector2::SignedAngle(v1, v2) << "\n";

}
