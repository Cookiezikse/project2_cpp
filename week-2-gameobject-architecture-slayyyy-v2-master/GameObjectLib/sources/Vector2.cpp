#include "Vector2.h"
#include <iostream>
#include <cmath>

// Initialisation des membres statiques
const Vector2 Vector2::up(0, 1);
const Vector2 Vector2::down(0, -1);
const Vector2 Vector2::left(-1, 0);
const Vector2 Vector2::right(1, 0);
const Vector2 Vector2::zero(0, 0);

// Constructeurs
Vector2::Vector2(float x, float y) : x(x), y(y) {}


// Opérations arithmétiques
Vector2 Vector2::operator+(const Vector2& v) const {
	return Vector2(x + v.x, y + v.y);
}
Vector2 Vector2::operator-(const Vector2& v) const {
	return Vector2(x - v.x, y - v.y);
}
Vector2 Vector2::operator*(float scalar) const {
	return Vector2(x * scalar, y * scalar);
}
Vector2 Vector2::operator/(float scalar) const {
	if (scalar == 0.0f) {
		throw std::runtime_error("Division par zéro dans Vector2.");
	}
	return Vector2(x / scalar, y / scalar);
}
Vector2& Vector2::operator/=(float scalar) {
	if (scalar == 0.0f) {
		throw std::runtime_error("Division par zéro dans Vector2.");
	}
	x /= scalar;
	y /= scalar;
	return *this;
}



// Propriétés
float Vector2::Magnitude() const {
	return std::sqrt(x * x + y * y);
}
float Vector2::SqrMagnitude() const {
	return x * x + y * y;
}

//----		Il manque le this[int]	----//

Vector2 Vector2::Normalized() const {
	Vector2 vecteurNormalise = *this;
	vecteurNormalise.Normalize();
	return vecteurNormalise;
}
Vector2 Vector2::getX() const {
	return x;
}
Vector2 Vector2::getY() const {
	return y;
}



// Opérations de comparaison
bool Vector2::operator==(const Vector2& v) const {
	return x == v.x && y == v.y;
}
bool Vector2::operator!=(const Vector2& v) const {
	return !(*this == v);
}



// Méthodes publiques
bool Vector2::Equals(const Vector2& v, float tolerance) const {
	return std::abs(x - v.x) <= tolerance && std::abs(y - v.y) <= tolerance;
}
void Vector2::Normalize() {
	float magnitude = Magnitude();
	if (magnitude > 1E-05f) {
		x /= magnitude;
		y /= magnitude;
	}
	else {
		*this = Vector2::zero;
	}
}

void Vector2::Set(float newX, float newY) {
	x = newX;
	y = newY;
}




// Méthodes statiques
constexpr float RAD_TO_DEG = 57.29578f;

float Vector2::Angle(const Vector2& from, const Vector2& to) {
	float denominateur = std::sqrt(from.SqrMagnitude() * to.SqrMagnitude());
	if (denominateur < 1E-15F) return 0.0f;
	float produitScalaire = Dot(from, to) / denominateur;
	return std::acos(std::max(-1.0f, std::min(1.0f, produitScalaire))) * RAD_TO_DEG;
}
Vector2 Vector2::ClampMagnitude(const Vector2& vector, float maxLength) {
	if (vector.SqrMagnitude() > maxLength * maxLength) return vector.Normalized() * maxLength;
	return vector;
}
float Vector2::Distance(const Vector2& a, const Vector2& b) {
	Vector2 delta = b - a;
	return delta.Magnitude();
}
float Vector2::Dot(const Vector2& a, const Vector2& b) {
	return a.x * b.x + a.y * b.y;
}
Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t) {
	t = (t < 0.0f) ? 0.0f : (t > 1.0f) ? 1.0f : t; // Version manuelle de clamp
	return a + (b - a) * t;
}
Vector2 Vector2::LerpUnclamped(const Vector2& a, const Vector2& b, float t) {
	return a + (b - a) * t;
}
Vector2 Vector2::Max(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(std::max(lhs.x, rhs.x), std::max(lhs.y, rhs.y));
}
Vector2 Vector2::Min(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(std::min(lhs.x, rhs.x), std::min(lhs.y, rhs.y));
}
Vector2 Vector2::MoveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta) {
	Vector2 toVector = target - current;
	float dist = toVector.Magnitude();
	if (dist <= maxDistanceDelta || dist == 0.0f) {
		return target;
	}
	return current + toVector / dist * maxDistanceDelta;
}
Vector2 Vector2::Perpendicular(const Vector2& inDirection) {
	return Vector2(-inDirection.y, inDirection.x);
}

Vector2 Vector2::Scale(const Vector2& a, const Vector2& b) {
	return Vector2(a.x * b.x, a.y * b.y);
}
float Vector2::SignedAngle(const Vector2& from, const Vector2& to) {
	float angle = Angle(from, to);
	float sign = (from.x * to.y - from.y * to.x) >= 0.0f ? 1.0f : -1.0f;
	return angle * sign;
}



// Surcharge pour le flux de sortie
std::ostream& operator<<(std::ostream& os, const Vector2& v) {
	return os << "(" << v.x << ", " << v.y << ")";
}


// Affichage
void Vector2::Print() const {
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}

