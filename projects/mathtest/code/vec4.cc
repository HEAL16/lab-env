#include "vec4.h"
#include <cmath>
// Constructores
vec4::vec4()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

vec4::vec4(const float x, const float y, const float z, const float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

vec4::vec4(const vec4& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}

// Methodes and Operatores
void vec4::operator=(const vec4& rhs)
{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		this->w = rhs.w;
		return;
}

vec4 vec4::operator-()
{
	return vec4(-this->x, -this->y, -this->z, -this->w);
}

vec4 vec4::operator+(const vec4& rhs)
{
	return vec4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

void vec4::operator+=(const vec4& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;
	return;
}

vec4 vec4::operator-(const vec4& rhs)
{
	return vec4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
}

void vec4::operator-=(const vec4& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;
	return;
}

void vec4::operator*=(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	this->w *= scalar;
	return;
}

vec4 vec4::operator*(const float scalar)
{
	return vec4(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
}

bool vec4::operator==(const vec4& rhs)
{
	return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
}

bool vec4::operator!=(const vec4& rhs)
{
	return this->x != rhs.x && this->y != rhs.y && this->z != rhs.z && this->w != rhs.w;
}

float vec4::operator[](const unsigned int i)
{
	if (i == 0) { return this->x; }
	if (i == 1) { return this->y; }
	if (i == 2) { return this->z; }
	if (i == 3) { return this->w; }
	//safety if greter than 3
	unsigned int j = i % 4;
	if (j == 0) { return this->x; }
	if (j == 1) { return this->y; }
	if (j == 2) { return this->z; }
	if (j == 3) { return this->w; }
}

const float vec4::operator[](const unsigned int i) const
{
	if (i == 0) { return this->x; }
	if (i == 1) { return this->y; }
	if (i == 2) { return this->z; }
	if (i == 3) { return this->w; }
	//safety if greter than 3
	unsigned int j = i % 4;
	if (j == 0) { return this->x; }
	if (j == 1) { return this->y; }
	if (j == 2) { return this->z; }
	if (j == 3) { return this->w; }
}



// Functions
float dot(const vec4 & a, const vec4 & b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

float length(const vec4& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

vec4 normalize(const vec4& v)
{
	float const scalar = length(v);
	return vec4(v.x / scalar, v.y / scalar, v.z / scalar, v.w / scalar);
}


