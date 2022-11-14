#include "MyVec3.h"

Vec3::Vec3() {
	x = y = z = 0;
	isError = 0;
}

Vec3::Vec3(float a) {
	x = y = z = a;
	isError = 0;
}

Vec3::Vec3(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
	isError = 0;
}


Vec3::Vec3(float* a) {
	if (a == NULL) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Переданий вказівник пустий! Встановлено значення 0 в усі поля.\n", 113);
		x = y = z = 0;
		isError = 1;
	}
	else {
		x = a[0];
		y = a[1];
		z = a[2];
		isError = 0;
	}
}

Vec3::Vec3(Vec3 &a) {
	x = a.x;
	y = a.y;
	z = a.z;
	isError = a.isError;
}


Vec3::~Vec3() {
	std::cout << ' ';
	CText("Деструктор. Вивід інформації\n", 3); std::cout << ' ';
	CText("Vec3 [x] :", 112);	std::cout << " " << x << "\n" << " ";
	CText("Vec3 [y] :", 112);	std::cout << " " << y << "\n" << " ";
	CText("Vec3 [z] :", 112);	std::cout << " " << z << "\n";
}


void Vec3::setX(float X) {
	x = X;
}

void Vec3::setY(float Y) {
	y = Y;
}

void Vec3::setZ(float Z) {
	z = Z;
}

void Vec3::fill(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
}
float Vec3::getX() {
	return x;
}

float Vec3::getY() {
	return y;
}

float Vec3::getZ() {
	return z;
}


void Vec3::print() {
	std::cout << ' ';
	CText("Вивід інформації\n", 3);	std::cout << ' ';
	CText("Vec3 [x] :", 112);	std::cout << " " << x << "\n" << " ";
	CText("Vec3 [y] :", 112);	std::cout << " " << y << "\n" << " ";
	CText("Vec3 [z] :", 112);	std::cout << " " << z << "\n";
}


Vec3& Vec3::operator=(Vec3& a) {
	x = a.x;
	y = a.y;
	z = a.z;
	isError = a.isError;
	return *this;
}

Vec3& Vec3::operator+(Vec3& a) {
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

Vec3& Vec3::operator+=(Vec3& a) {
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

Vec3& Vec3::operator-(Vec3& a) {
	x -= a.x;
	y -= a.y;
	z -= a.z;
	return *this;
}

Vec3& Vec3::operator-=(Vec3& a) {
	x -= a.x;
	y -= a.y;
	z -= a.z;
	return *this;
}

float Vec3::operator*(Vec3& a) {
	return (y * a.z - z * a.y) - (x * a.z - z * a.x) + (x * a.y - y * a.x);
}

float Vec3::operator*=(Vec3& a) {
	return (y * a.z - z * a.y) - (x * a.z - z * a.x) + (x * a.y - y * a.x);
}

Vec3& Vec3::operator*(float a) {
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

Vec3& Vec3::operator*=(float a) {
	x *= a;
	y *= a;
	z *= a;
	return *this;
}


Vec3& Vec3::operator/(float a) {
	if (!a) {
		isError = 1;
	}
	else {
		x /= a;
		y /= a;
		z /= a;
	}
	return *this;
}
Vec3& Vec3::operator/=(float a) {
	if (!a) {
		isError = 1;
	}
	else {
		x /= a;
		y /= a;
		z /= a;
	}
	return *this;
}

Vec3& Vec3::operator/(Vec3 &a) {
	if (!a.x && !a.y && !a.z) {
		isError = 1;
	}
	else {
		x /= a.x;
		y /= a.y;
		z /= a.z;
	}
	return *this;
}
Vec3& Vec3::operator/=(Vec3 &a) {
	if (!a.x && !a.y && !a.z) {
		isError = 1;
	}
	else {
		x /= a.x;
		y /= a.y;
		z /= a.z;
	}
	return *this;
}

bool Vec3::operator<(Vec3& a) {
	return sqrt(x * x + y * y + z * z) < sqrt(a.x * a.x + a.y * a.y + a.z * a.z) ? 1 : 0;
}

bool Vec3::operator<=(Vec3& a) {
	return sqrt(x * x + y * y + z * z) <= sqrt(a.x * a.x + a.y * a.y + a.z * a.z) ? 1 : 0;
}

bool Vec3::operator>(Vec3& a) {
	return sqrt(x * x + y * y + z * z) > sqrt(a.x * a.x + a.y * a.y + a.z * a.z) ? 1 : 0;
}

bool Vec3::operator>=(Vec3& a) {
	return sqrt(x * x + y * y + z * z) >= sqrt(a.x * a.x + a.y * a.y + a.z * a.z) ? 1 : 0;
}

bool Vec3::operator==(Vec3& a) {
	if (x == a.x && y == a.y && z == a.z) return 1;
	return 0;
}


