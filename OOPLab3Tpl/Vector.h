#pragma once
class Vector {
	double* arr;
	unsigned int length;

public:
	Vector();
	Vector(int Length);
	void initialize(int Length);
	void setX(int position, double x);
	double getX(int position);
	~Vector();
};

