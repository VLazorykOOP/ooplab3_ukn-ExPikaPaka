#include "Vector.h"
#include <iostream>
#include <Windows.h>

Vector::Vector() {

}

Vector::Vector(int Length) {
	if (Length > 0 && Length <= 65535)
		length = Length;
	else
		length = 65535;
	arr = new double[length];
	memset(arr, 0, sizeof(arr));
}

void Vector::initialize(int Length) {
	if (Length > 0 && Length <= 65535)
		length = Length;
	else
		length = 65535;
	arr = new double[length];
	memset(arr, 0, sizeof(arr));
}

void Vector::setX(int position, double x) {
	if(position >= 0 && position <= 65535)
		arr[position] = x;
}

double Vector::getX(int position) {
	if (position >= 0 && position <= 65535)
		return arr[position];
	else
		return 0;
	
}
Vector::~Vector() {
	delete[] arr;
}
