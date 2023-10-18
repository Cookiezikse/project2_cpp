#pragma once
#include <iostream>

class Vector2 {
public:
	// Variables
	float x, y;

	// Propriétés statiques communes
	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 left;
	static const Vector2 right;
	static const Vector2 zero;

	// Constructeurs
	Vector2(float x = 0.0f, float y = 0.0f);


	Vector2 getX() const;
	Vector2 getY() const;

	// Opérations arithmétiques
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator*(float scalar) const;
	Vector2 operator/(float scalar) const;
	Vector2& operator/=(float scalar);


	// Opérations de comparaison
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;


	// Propriétés
	float Magnitude() const;
	Vector2 Normalized() const;
	float SqrMagnitude() const;


	// Méthodes publiques
	bool Equals(const Vector2& v, float tolerance = 1E-5f) const;
	void Normalize();
	void Set(float newX, float newY);


	// Méthodes Statiques
	static float Angle(const Vector2& from, const Vector2& to);
	static Vector2 ClampMagnitude(const Vector2& vector, float maxLength);
	static float Distance(const Vector2& a, const Vector2& b);
	static float Dot(const Vector2& lhs, const Vector2& rhs);
	static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
	static Vector2 LerpUnclamped(const Vector2& a, const Vector2& b, float t);
	static Vector2 Max(const Vector2& lhs, const Vector2& rhs);
	static Vector2 Min(const Vector2& lhs, const Vector2& rhs);
	static Vector2 MoveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta);
	static Vector2 Perpendicular(const Vector2& inDirection);
	static Vector2 Reflect(const Vector2& inDirection, const Vector2& inNormal);
	static Vector2 Scale(const Vector2& a, const Vector2& b);
	static float SignedAngle(const Vector2& from, const Vector2& to);
	static Vector2 SmoothDamp(const Vector2& current, const Vector2& target, Vector2& currentVelocity, float smoothTime, float maxSpeed = INFINITY, float deltaTime = 0.02f);



	// Affichage
	void Print() const;

};
