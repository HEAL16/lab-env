#pragma once

class vec4 {
// Variables 
public:
	float x;
	float y;
	float z;
	float w;
// Constructors
public:
	vec4(); // zero length vector
	vec4( const float x, const float y, const float z, const float w);
	vec4( const vec4& v);
// Methodes and Operatores 
public:
	void operator=(const vec4& rhs);
	vec4 operator-();
	vec4 operator+(const vec4& rhs);
	void operator+=(const vec4& rhs);
	vec4 operator-(const vec4& rhs);
	void operator-=(const vec4& rhs);
	void operator*=(const float scalar);
	vec4 operator*(const float scalar);
	bool operator==(const vec4& rhs);
	bool operator!=(const vec4& rhs);
	float operator[](const unsigned int i);
	const float operator[](const unsigned int i) const;// range [0,3]
};
// Functions
float dot(const vec4& a, const vec4& b);
float length(const vec4& v);
vec4 normalize(const vec4& v);

