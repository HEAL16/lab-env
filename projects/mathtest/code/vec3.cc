#include "vec3.h"
#include <cmath>
// Constructores
vec3::vec3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

vec3::vec3(const float x, const float y, const float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3::vec3(const vec3& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

// Methodes and Operatores
void vec3::operator=(const vec3& rhs)
{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		return;
}

vec3 vec3::operator-()
{
	return vec3(-this->x, -this->y, -this->z);
}

vec3 vec3::operator+(const vec3& rhs)
{
	return vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

void vec3::operator+=(const vec3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return;
}

vec3 vec3::operator-(const vec3& rhs)
{
	return vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

void vec3::operator-=(const vec3& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return;
}

void vec3::operator*=(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return;
}

vec3 vec3::operator*(const float scalar)
{
	return vec3(this->x * scalar, this->y * scalar, this->z * scalar);
}

bool vec3::operator==(const vec3& rhs)
{
	return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
}

bool vec3::operator!=(const vec3& rhs)
{
	return this->x != rhs.x && this->y != rhs.y && this->z != rhs.z;
}

float vec3::operator[](const unsigned int i)
{
	if (i == 0) { return this->x; }
	if (i == 1) { return this->y; }
	if (i == 2) { return this->z; }
	//safety if greter than 3
	unsigned int j = i % 3;
	if (j == 0) { return this->x; }
	if (j == 1) { return this->y; }
	if (j == 2) { return this->z; }

}

const float vec3::operator[](const unsigned int i) const
{
	if (i == 0) { return this->x; }
	if (i == 1) { return this->y; }
	if (i == 2) { return this->z; }

	//safety if greter than 3
	unsigned int j = i % 3;
	if (j == 0) { return this->x; }
	if (j == 1) { return this->y; }
	if (j == 2) { return this->z; }

}
// Functions
float dot(const vec3& a, const vec3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float length(const vec3& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3 cross(const vec3& a, const vec3& b)
{
	return vec3(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
}

vec3 normalize(const vec3& v)
{
	float const scalar = length(v);
	return vec3(v.x / scalar, v.y / scalar, v.z / scalar);
}