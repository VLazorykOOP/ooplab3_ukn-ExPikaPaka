#pragma once
#include <iostream>
#include "ColorText.h"
#include <cmath>

class Vec3 {
public:
	float x, y, z;
	bool isError;


	Vec3();
	Vec3(float a);
	Vec3(float X, float Y, float Z);
	Vec3(float *a);
	Vec3(Vec3 &a);
	~Vec3();

	void setX(float X);
	void setY(float Y);
	void setZ(float Z);
	void fill(float X, float Y, float Z);
	float getX();
	float getY();
	float getZ();
	void print();

	Vec3* operator=(Vec3& a);
	Vec3* operator+(Vec3& a);
	Vec3* operator+=(Vec3& a);
	Vec3* operator-(Vec3& a);
	Vec3* operator-=(Vec3& a);
	float operator*(Vec3& a);
	float operator*=(Vec3& a);
	Vec3* operator*(float a);
	Vec3* operator*=(float a);
	Vec3* operator/(float a);
	Vec3* operator/=(float a);
	Vec3* operator/(Vec3& a);
	Vec3* operator/=(Vec3& a);
	bool operator<(Vec3& a);
	bool operator<=(Vec3& a);
	bool operator>(Vec3& a);
	bool operator>=(Vec3& a);
	bool operator==(Vec3& a);
};

