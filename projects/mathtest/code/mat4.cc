﻿#include "mat4.h"
#include "vec4.h"
#include <math.h>
// Constructores
mat4::mat4()
{
	this->m[0] = vec4(1.0f, 0.0f, 0.0f, 0.0f);
	this->m[1] = vec4(0.0f, 1.0f, 0.0f, 0.0f);
	this->m[2] = vec4(0.0f, 0.0f, 1.0f, 0.0f);
	this->m[3] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
}

mat4::mat4(const vec4 r0, const vec4 r1, const vec4 r2, const vec4 r3)
{
	this->m[0] = r0;
	this->m[1] = r1;
	this->m[2] = r2;
	this->m[3] = r3;
}

mat4::mat4(const mat4& v)
{
	this->m[0] = v[0];
	this->m[1] = v[1];
	this->m[2] = v[2];
	this->m[3] = v[3];
}

// Methodes and Operatores

void mat4::operator=(const mat4& rhs) //void
{
		this->m[0] = rhs[0];
		this->m[1] = rhs[1];
		this->m[2] = rhs[2];
		this->m[3] = rhs[3];
		return;
}

mat4 mat4::operator*(const mat4& rhs) const
{
	return mat4(
		vec4(
			(rhs[0].x * m[0].x + rhs[1].x * m[0].y + rhs[2].x * m[0].z + rhs[3].x * m[0].w),
			(rhs[0].y * m[0].x + rhs[1].y * m[0].y + rhs[2].y * m[0].z + rhs[3].y * m[0].w),
			(rhs[0].z * m[0].x + rhs[1].z * m[0].y + rhs[2].z * m[0].z + rhs[3].z * m[0].w),
			(rhs[0].w * m[0].x + rhs[1].w * m[0].y + rhs[2].w * m[0].z + rhs[3].w * m[0].w)),
		vec4(
			(rhs[0].x * m[1].x + rhs[1].x * m[1].y + rhs[2].x * m[1].z + rhs[3].x * m[1].w),
			(rhs[0].y * m[1].x + rhs[1].y * m[1].y + rhs[2].y * m[1].z + rhs[3].y * m[1].w),
			(rhs[0].z * m[1].x + rhs[1].z * m[1].y + rhs[2].z * m[1].z + rhs[3].z * m[1].w),
			(rhs[0].w * m[1].x + rhs[1].w * m[1].y + rhs[2].w * m[1].z + rhs[3].w * m[1].w)),
		vec4(
			(rhs[0].x * m[2].x + rhs[1].x * m[2].y + rhs[2].x * m[2].z + rhs[3].x * m[2].w),
			(rhs[0].y * m[2].x + rhs[1].y * m[2].y + rhs[2].y * m[2].z + rhs[3].y * m[2].w),
			(rhs[0].z * m[2].x + rhs[1].z * m[2].y + rhs[2].z * m[2].z + rhs[3].z * m[2].w),
			(rhs[0].w * m[2].x + rhs[1].w * m[2].y + rhs[2].w * m[2].z + rhs[3].w * m[2].w)),
		vec4(
			(rhs[0].x * m[3].x + rhs[1].x * m[3].y + rhs[2].x * m[3].z + rhs[3].x * m[3].w),
			(rhs[0].y * m[3].x + rhs[1].y * m[3].y + rhs[2].y * m[3].z + rhs[3].y * m[3].w),
			(rhs[0].z * m[3].x + rhs[1].z * m[3].y + rhs[2].z * m[3].z + rhs[3].z * m[3].w),
			(rhs[0].w * m[3].x + rhs[1].w * m[3].y + rhs[2].w * m[3].z + rhs[3].w * m[3].w)));
}

vec4 mat4::operator*(const vec4& rhs) const
{
	return vec4(
		(m[0].x * rhs.x + m[1].x * rhs.y + m[2].x * rhs.z + m[3].x * rhs.w),
		(m[0].y * rhs.x + m[1].y * rhs.y + m[2].y * rhs.z + m[3].y * rhs.w),
		(m[0].z * rhs.x + m[1].z * rhs.y + m[2].z * rhs.z + m[3].z * rhs.w),
		(m[0].w * rhs.x + m[1].w * rhs.y + m[2].w * rhs.z + m[3].w * rhs.w));
}

bool mat4::operator==(const mat4& rhs)
{
	return this->m[0] == rhs[0] && this->m[1] == rhs[1] && this->m[2] == rhs[2] && this->m[3] == rhs[3];
}

bool mat4::operator!=(const mat4& rhs)
{
	return this->m[0] != rhs[0] && this->m[1] != rhs[1] && this->m[2] != rhs[2] && this->m[3] != rhs[3];
}

vec4& mat4::operator[](const unsigned int i)
{
	if (i == 0) { return this->m[0]; }
	if (i == 1) { return this->m[1]; }
	if (i == 2) { return this->m[2]; }
	if (i == 3) { return this->m[3]; }
	//safety if greter than 3
	unsigned int j = i % 4;
	if (j == 0) { return this->m[0]; }
	if (j == 1) { return this->m[1]; }
	if (j == 2) { return this->m[2]; }
	if (j == 3) { return this->m[3]; }
}

const vec4& mat4::operator[](const unsigned int i) const
{
	if (i == 0) { return this->m[0]; }
	if (i == 1) { return this->m[1]; }
	if (i == 2) { return this->m[2]; }
	if (i == 3) { return this->m[3]; }
	//safety if greter than 3
	unsigned int j = i % 4;
	if (j == 0) { return this->m[0]; }
	if (j == 1) { return this->m[1]; }
	if (j == 2) { return this->m[2]; }
	if (j == 3) { return this->m[3]; }
}

// Functions

float determinant(const mat4& m)
{	return
		  m[0].x * (m[1].y * m[2].z * m[3].w - m[1].y * m[2].w * m[3].z - m[1].z * m[2].y * m[3].w + m[1].z * m[2].w * m[3].y + m[1].w * m[2].y * m[3].z - m[1].w * m[2].z * m[3].y)
		- m[0].y * (m[1].x * m[2].z * m[3].w - m[1].x * m[2].w * m[3].z - m[1].z * m[2].x * m[3].w + m[1].z * m[2].w * m[4].w + m[1].w * m[2].x * m[3].z - m[1].w * m[2].z * m[4].w)
		+ m[0].z * (m[1].x * m[2].y * m[3].w - m[1].x * m[2].w * m[3].y - m[1].y * m[2].x * m[3].w + m[1].y * m[2].w * m[4].w + m[1].w * m[2].x * m[3].y - m[1].w * m[2].y * m[4].w)
		- m[0].w * (m[1].x * m[2].y * m[3].z - m[1].x * m[2].z * m[3].y - m[1].y * m[2].x * m[3].z + m[1].y * m[2].z * m[4].w + m[1].z * m[2].x * m[3].y - m[1].z * m[2].y * m[4].w);
}

mat4 inverse(const mat4& m)
{
	float det = determinant(m);
	if (det == 0)
	{
		return mat4();

	}
	det = 1 / det;

	return mat4(
		vec4(m[1].y*m[2].z*m[3].w + m[1].z*m[2].w*m[3].y + m[1].w*m[2].y*m[3].z - m[1].y*m[2].w*m[3].z - m[1].z*m[2].y*m[3].w - m[1].w*m[2].z*m[3].y,
			 m[0].y*m[2].w*m[3].z + m[0].z*m[2].y*m[3].w + m[0].w*m[2].z*m[3].y - m[0].y*m[2].w*m[3].w - m[0].z*m[2].w*m[3].y - m[0].w*m[2].y*m[3].z,
			 m[0].y*m[1].z*m[3].w + m[0].z*m[1].w*m[3].y + m[0].w*m[1].y*m[3].z - m[0].y*m[1].w*m[3].z - m[0].z*m[1].y*m[3].w - m[0].w*m[1].z*m[3].y,
			 m[0].y*m[1].w*m[2].z + m[0].z*m[1].y*m[2].w + m[0].w*m[1].z*m[2].y - m[0].y*m[1].z*m[2].w - m[0].z*m[1].w*m[2].y - m[0].w*m[1].y*m[2].z
			)*det,
		vec4(m[1].x*m[2].w*m[3].z + m[1].z*m[2].x*m[3].w + m[1].w*m[2].z*m[3].x - m[1].x*m[2].z*m[3].w - m[1].z*m[2].w*m[3].x - m[1].w*m[2].x*m[3].z,
			 m[0].x*m[2].z*m[3].w + m[0].z*m[2].w*m[3].x + m[0].w*m[2].x*m[3].z - m[0].x*m[2].w*m[3].z - m[0].z*m[2].x*m[3].w - m[0].w*m[2].z*m[3].x,
			 m[0].x*m[1].w*m[3].z + m[0].z*m[1].x*m[3].w + m[0].w*m[1].z*m[3].x - m[0].x*m[1].z*m[3].w - m[0].z*m[1].w*m[3].x - m[0].w*m[1].x*m[3].z,
			 m[0].x*m[1].z*m[2].w + m[0].z*m[1].w*m[2].x + m[0].w*m[1].x*m[2].z - m[0].x*m[1].w*m[2].z - m[0].z*m[1].x*m[2].w - m[0].w*m[1].z*m[2].x
			)*det,
		vec4(m[1].x*m[2].y*m[3].w + m[1].y*m[2].w*m[3].x + m[1].w*m[2].x*m[3].y - m[1].x*m[2].w*m[3].y - m[1].y*m[2].x*m[3].w - m[1].w*m[2].y*m[3].x,
			 m[0].x*m[2].w*m[3].y + m[0].y*m[2].x*m[3].w + m[0].w*m[2].y*m[3].x - m[0].x*m[2].y*m[3].w - m[0].y*m[2].w*m[3].x - m[0].w*m[2].x*m[3].y,
			 m[0].x*m[1].y*m[3].w + m[0].y*m[1].w*m[3].x + m[0].w*m[1].x*m[3].y - m[0].x*m[1].w*m[3].y - m[0].y*m[1].x*m[3].w - m[0].w*m[1].y*m[3].x,
			 m[0].x*m[1].w*m[2].y + m[0].y*m[1].x*m[2].w + m[0].w*m[1].y*m[2].x - m[0].x*m[1].y*m[2].w - m[0].y*m[1].w*m[2].x - m[0].w*m[1].x*m[2].y
			)*det,
		vec4(m[1].x*m[2].z*m[3].y + m[1].y*m[2].x*m[3].z + m[1].z*m[2].y*m[3].x - m[1].x*m[2].y*m[3].z - m[1].y*m[2].z*m[3].x - m[1].z*m[2].x*m[3].y,
			 m[0].x*m[2].y*m[3].z + m[0].y*m[2].z*m[3].x + m[0].z*m[2].x*m[3].y - m[0].x*m[2].z*m[3].y - m[0].y*m[2].x*m[3].z - m[0].z*m[2].y*m[3].x,
			 m[0].x*m[1].z*m[3].y + m[0].y*m[1].x*m[3].z + m[0].z*m[1].y*m[3].x - m[0].x*m[1].y*m[3].z - m[0].y*m[1].z*m[3].x - m[0].z*m[1].x*m[3].y,
			 m[0].x*m[1].y*m[2].z + m[0].y*m[1].z*m[2].x + m[0].z*m[1].x*m[2].y - m[0].x*m[1].z*m[2].y - m[0].y*m[1].x*m[2].z - m[0].z*m[1].y*m[2].x
			)*det
	);
}

mat4 transpose(const mat4& m)
{
	return mat4(
		vec4(m[0].x, m[1].x, m[2].x, m[3].x),
		vec4(m[0].y, m[1].y, m[2].y, m[3].y),
		vec4(m[0].z, m[1].z, m[2].z, m[3].z),
		vec4(m[0].w, m[1].w, m[2].w, m[3].w));
}

mat4 rotationx(const float& rad)
{
	return mat4(
		vec4(1.0f,     0.0f,      0.0f, 0.0f),
		vec4(0.0f, cos(rad),  sin(rad), 0.0f),
		vec4(0.0f,-sin(rad),  cos(rad), 0.0f),
		vec4(0.0f,     0.0f,      0.0f, 1.0f)
	);
}

mat4 rotationy(const float& rad)
{
	return mat4(
		vec4( cos(rad), 0.0f,-sin(rad), 0.0f),
		vec4(     0.0f, 1.0f,     0.0f, 0.0f),
		vec4( sin(rad), 0.0f, cos(rad), 0.0f),
		vec4     (0.0f, 0.0f,     0.0f, 1.0f)
	);
}

mat4 rotationz(const float& rad)
{
	return mat4(
		vec4( cos(rad), sin(rad),  0.0f, 0.0f),
		vec4(-sin(rad), cos(rad),  0.0f, 0.0f),
		vec4(     0.0f,     0.0f,  1.0f, 0.0f),
		vec4(     0.0f,     0.0f,  0.0f, 1.0f)
	);
}

mat4 rotationaxis(const vec3& v, const float rad)
{
	return mat4(
		vec4((v.x * v.x) + ((v.y * v.y) + (v.z * v.z)) * cos(rad),          v.x * v.y * (1 - cos(rad)) + v.z * sin(rad),          v.x * v.z * (1 - cos(rad)) - v.y * sin(rad), 0.0f),
		vec4(         v.x * v.y * (1 - cos(rad)) - v.z * sin(rad), (v.y * v.y) + ((v.x * v.x) + (v.z * v.z)) * cos(rad),          v.y * v.z * (1 - cos(rad)) + v.x * sin(rad), 0.0f),
		vec4(         v.x * v.z * (1 - cos(rad)) + v.y * sin(rad),           v.y * v.z *(1 - cos(rad)) - v.x * sin(rad), (v.z * v.z) + ((v.x * v.x) + (v.y * v.y)) * cos(rad), 0.0f),
		vec4(                                                0.0f,                                                 0.0f,                                                 0.0f, 1.0f));
}