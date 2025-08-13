#pragma once
#include <cassert>
#include "math.h"


template<typename T>
struct Vector2
{
	union {
		struct{ T x, y; };
		struct { T u, v; };

	};
	
	Vector2() = default;
	Vector2(T x, T y) : x(x), y(y) {}

	 T operator [] (unsigned int index) const { assert(index < 2); return (&x)[index]; }

	 T& operator [] (unsigned int index)  { 
		assert(index < 2); 
	return (&x)[index]; 
	}


	Vector2 operator + (const Vector2 v) {
		return Vector2{ x + v.x, y + v.y };
	}
	Vector2 operator - (const Vector2 v) {
		return Vector2{ x - v.x, y - v.y };
	}
	Vector2 operator * (const Vector2 v) {
		return Vector2{ x * v.x, y * v.y };
	}
	Vector2 operator / (const Vector2 v) {
		return Vector2{ x / v.x, y / v.y };
	}

	Vector2& operator += (const Vector2 v) {
		x += v.x;
		y += v.y;
			return *this;
	}
	Vector2& operator -= (const Vector2 v) {
		x -= v.x;
		y -= v.y;
			return *this;
	}
	Vector2& operator *= (const Vector2 v) {
		x *= v.x;
		y *= v.y;
			return *this;
	}
	Vector2& operator /= (const Vector2 v) {
		x /= v.x;
		y /= v.y;
			return *this;
	}


	Vector2 operator + (float s) const {
		return Vector2{ x + s, y + s };
	}
	Vector2 operator - (float s) const {
		return Vector2{ x - s, y - s };
	}
	Vector2 operator * (float s) const {
		return Vector2{ x * s, y * s };
	}
	Vector2 operator / (float s) const {
		return Vector2{ x / s, y / s };
	}

	Vector2 operator += (float s) {
		return Vector2{ x += s, y += s };
	}
	Vector2 operator -= (float s) {
		return Vector2{ x -= s, y -= s };
	}
	Vector2 operator *= (float s) {
		return Vector2{ x *= s, y *= s };
	}
	Vector2 operator /= (float s) {
		return Vector2{ x /= s, y /= s };
	}


	float length() const {
		return sqrt(x * x + y * y);
	}
	float lengthSqr() const {
		return (x * x) + (y * y);
	}

	Vector2 Normalized() const { return *this / length() ; } // REMEMBER: * can be used to dereference



	//returns angle in radians between the positive x axis and the point x,y
	float Angle() const { return parabellum::math::atan2f(y, x); }

	Vector2 Rotate(float radians) const {
		Vector2 v;
		v.x = x * parabellum::math::cosf(radians) - y * parabellum::math::sinf(radians);
		v.y = x * parabellum::math::sinf(radians) + y * parabellum::math::cosf(radians);
		return v;
	}
};
template <typename T>
std::ostream& operator << (std::ostream& stream, const Vector2<T>& v) {
	stream << "{" << v.x << ", " << v.y << "}";
	return stream;
}
template <typename T>
std::istream& operator >> (std::istream& stream, Vector2<T>& v) {
	char ch = '\0';
	if (!(stream >> std::ws >> ch) || ch != '{') {
		stream.setstate(std::ios::failbit);
		return stream;
	}
	if (!(stream >> std::ws >> v.x)) {
		stream.setstate(std::ios::failbit);

		return stream;
	}
	if (!(stream >> std::ws >> ch) || ch != ',') {
		stream.setstate(std::ios::failbit);

		return stream;
	}
	if (!(stream >> std::ws >> v.y)) {
		stream.setstate(std::ios::failbit);

		return stream;
	}
	if (!(stream >> std::ws >> ch) || ch != '}') {
		stream.setstate(std::ios::failbit);

		return stream;
	}


	return stream;
}

using ivec2 = Vector2<int>;
using vec2 = Vector2<float>;
