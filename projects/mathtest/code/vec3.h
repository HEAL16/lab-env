#pragma once

class vec3 {
	// Variables 
public:
	float x;
	float y;
	float z;
	// Constructors
public:
	vec3(); // zero length vector
	vec3(const float x, const float y, const float z);
	vec3(const vec3& v);
	// Methodes and Operatores 
public:
	void operator=(const vec3& rhs);
	vec3 operator-();
	vec3 operator+(const vec3& rhs);
	void operator+=(const vec3& rhs);
	vec3 operator-(const vec3& rhs);
	void operator-=(const vec3& rhs);
	void operator*=(const float scalar);
	vec3 operator*(const float scalar);
	bool operator==(const vec3& rhs);
	bool operator!=(const vec3& rhs);
	float operator[](const unsigned int i); // range [0,2]
	const float operator[](const unsigned int i) const;// range [0,3]
};
// Functions
float dot(const vec3& a, const vec3& b);
float length(const vec3& v);
vec3 cross(const vec3& a, const vec3& b);
vec3 normalize(const vec3& v);

