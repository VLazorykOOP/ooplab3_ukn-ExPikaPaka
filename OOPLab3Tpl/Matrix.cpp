#include "Matrix.h"
#include "ColorText.h"
#include <iostream>

Matrix::Matrix() {
	row = 5;
	collum = 5;
	isError = 0;

	matrix = new Vector[row];
	
	for (int i = 0; i < row; i++) {
		matrix[i].initialize(collum);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			setX(i, j, 0);
		}
	}
}

Matrix::Matrix(unsigned int rowCount, unsigned int collumCount) {
	if ((rowCount > 0 && rowCount < 65535) && (collumCount > 0 && collumCount < 65535)) {
		row = rowCount;
		collum = collumCount;
		isError = 0;

		matrix = new Vector[row];

		for (unsigned int i = 0; i < row; i++) {
			matrix[i].initialize(collum);
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, 0);
			}
		}
	}
	else {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Розмір матриці некоректний! Об`єкт не створено.\n", 113);
	}
}


Matrix::Matrix(unsigned int size) {
	if (size > 0 && size < 65535) {
		row = size;
		collum = size;
		isError = 0;

		matrix = new Vector[row];

		for (unsigned int i = 0; i < row; i++) {
			matrix[i].initialize(collum);
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, 0);
			}
		}
	}
	else {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Розмір матриці некоректний! Об`єкт не створено.\n", 113);
	}
}


Matrix::Matrix(unsigned int rowCount, unsigned int collumCount, double value) {
	if ((rowCount > 0 && rowCount < 65535) && (collumCount > 0 && collumCount < 65535)) {
		row = rowCount;
		collum = collumCount;
		isError = 0;

		matrix = new Vector[row];

		for (unsigned int i = 0; i < row; i++) {
			matrix[i].initialize(collum);
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, value);
			}
		}
	}
	else {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Розмір матриці некоректний! Об`єкт не створено.\n", 113);
	}
}

Matrix::Matrix(Matrix& a) {
	matrix = a.matrix;
	row = a.row;
	collum = a.collum;
	isError = a.isError;
}

//Matrix::~Matrix() {
//	delete[] matrix;
//}

double Matrix::getX(unsigned int row, unsigned int collum) {
	return matrix[row].getX(collum);
}

void Matrix::setX(unsigned int row, unsigned int collum, double x) {
	matrix[row].setX(collum, x);
}

unsigned int Matrix::getRowCnt() {
	return row;
}

unsigned int Matrix::getCollumCnt() {
	return collum;
}

bool Matrix::error() {
	return isError ? 1 : 0;
}

void Matrix::print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			std::cout << getX(i, j) << "\t";
		}
		std::cout << "\n";
	}
}

Matrix* Matrix::operator=(Matrix& a) {
	matrix = a.matrix;
	row = a.row;
	collum = a.collum;
	return this;
}

bool Matrix::operator==(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				if (getX(i, j) != a.getX(i, j)) return 0;
			}
		}
		return 1;
	}
	return 0;
}

Matrix* Matrix::operator+(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) + a.getX(i, j));
			}
		}
	}
	else {
		isError = 1;
	}
	return this;
}

Matrix* Matrix::operator+=(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) + a.getX(i, j));
			}
		}
	}
	else {
		isError = 1;
	}
	return this;
}

Matrix* Matrix::operator-(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) - a.getX(i, j));
			}
		}
	}
	else {
		isError = 1;
	}
	return this;
}

Matrix* Matrix::operator-=(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) - a.getX(i, j));
			}
		}
	}
	else {
		isError = 1;
	}
	return this;
}

Matrix* Matrix::operator*(double a) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			setX(i, j, getX(i, j) * a);
		}

	}
	return this;
}

Matrix* Matrix::operator*=(double a) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			setX(i, j, getX(i, j) * a);
		}
	}

	return this;
}

Matrix* Matrix::operator/(double a) {
	if (a) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) / a);
			}
		}
	}
	else {
		isError = 1;
	}
	return this;
}

Matrix* Matrix::operator/=(double a) {
	if (a) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) / a);
			}
		}
	}
	else {
		isError = 1;
	}
	return this;
}
