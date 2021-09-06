#pragma once
#include "vec3.h"
#include "vec4.h"

class mat4{
// Variables
public:
	vec4 m [4];
// Constructors
public:
	mat4(); // zero length vector
	mat4(const vec4 r0, const vec4 r1, const vec4 r2, const vec4 r3);
	mat4(const mat4& v);
// Methodes and Operatores 
public:
	void operator=(const mat4& rhs);
	mat4 operator*(const mat4 rhs);
	bool operator==(const mat4& rhs);
	bool operator!=(const mat4& rhs);
	vec4& operator[](const unsigned int i); // range [0,3]
	const vec4& operator[](const unsigned int i) const; //could be needed
};
// Functions 
	float determinant(const mat4& m);
	mat4 inverse(const mat4& m); // returns identity upon failure
	mat4 transpose(const mat4& m);
	mat4 rotationx(const float& rad); // radians
	mat4 rotationy(const float& rad);
	mat4 rotationz(const float& rad);
	mat4 rotationaxis(const vec3& v, const float rad);
