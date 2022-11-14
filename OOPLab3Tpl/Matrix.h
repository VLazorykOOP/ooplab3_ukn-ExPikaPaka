#pragma once
#include "Vector.h"

class Matrix {
	Vector* matrix;
	unsigned int row;
	unsigned int collum;
	bool isError;
	
public:
	Matrix();
	Matrix(Matrix& a);
	Matrix(unsigned int size);
	Matrix(unsigned int rowCount, unsigned int collumCount);
	Matrix(unsigned int rowCount, unsigned int collumCount, double value);
	//~Matrix();
	double getX(unsigned int row, unsigned int collum);
	void setX(unsigned int row, unsigned int collum, double x);
	unsigned int getRowCnt();
	unsigned int getCollumCnt();
	bool error();
	void print();

	Matrix& operator=(Matrix& a);
	bool operator==(Matrix& a);
	Matrix& operator+(Matrix& a);
	Matrix& operator+=(Matrix& a);
	Matrix& operator-(Matrix& a);
	Matrix& operator-=(Matrix& a);
	Matrix& operator*(double a);
	Matrix& operator*=(double a);
	Matrix& operator/(double a);
	Matrix& operator/=(double a);
};

