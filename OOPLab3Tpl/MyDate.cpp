#define _CRT_SECURE_NO_WARNINGS
#include "MyDate.h"
#include "ColorText.h"

Date::Date() {
	system("chcp 1251");
	system("cls");

	_t = time(NULL);
	_tPtr = localtime(&_t);
	day = _tPtr->tm_mday;
	month = _tPtr->tm_mon + 1;
	year = 1900 + _tPtr->tm_year;
}


Date::Date(char setDay, char setMonth, int setYear) {
	system("chcp 1251");
	system("cls");

	_t = time(NULL);
	_tPtr = localtime(&_t);
	setDay = setDay < 0 ? -setDay : setDay;
	if (setDay > 31) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ���� ������ �� 31! ����������� �������� ����.\n", 113);
		day = _tPtr->tm_mday;
	}
	else if (!setDay) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ���� �� ���� ���� 0! ����������� �������� ����.\n", 113);
		day = _tPtr->tm_mday;
	}
	else
		day = setDay;

	setMonth = setMonth < 0 ? -setMonth : setMonth;
	if (setMonth > 12) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ����� ������ �� 12! ����������� �������� �����.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else if (!setMonth) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ����� �� ���� ���� 0! ����������� �������� �����.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else
		month = (char)setMonth;

	setYear = setYear < 0 ? -setYear : setYear;
	if (setYear > 65535) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� �� ������ �� 32767! ����������� �������� ��.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else if (!setYear) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� �� �� ���� ���� 0! ����������� �������� ��.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else
		year = setYear;
}

unsigned int Date::getDay() {
	return (int)day;
}
unsigned int Date::getMonth() {
	return (int)month;
}
unsigned int Date::getYear() {
	return year;
}

void Date::setDay(int setDay) {
	setDay = setDay < 0 ? -setDay : setDay;
	if (setDay > 31) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ���� ������ �� 31! ����������� �������� ����.\n", 113);
		day = _tPtr->tm_mday;
	}
	else if (!setDay) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ���� �� ���� ���� 0! ����������� �������� ����.\n", 113);
		day = _tPtr->tm_mday;
	}
	else
		day = (unsigned char)setDay;
}

void Date::setMonth(int setMonth) {
	setMonth = setMonth < 0 ? -setMonth : setMonth;
	if (setMonth > 12) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ����� ������ �� 12! ����������� �������� �����.\n", 113);
		month = _tPtr->tm_mon;
	}
	else if (!setMonth) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� ����� �� ���� ���� 0! ����������� �������� �����.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else
		month = (char)setMonth;
}

void Date::setYear(int setYear) {
	setYear = setYear < 0 ? -setYear : setYear;
	if (setYear > 32767) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� �� ������ �� 32767! ����������� �������� ��.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else if (!setYear) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" �������� �� �� ���� ���� 0! ����������� �������� ��.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else
		year = setYear;
}

void Date::printDate() {
	std::cout << (int)day << '.' << (int)month << '.' << year;
}

void Date::printTextDate() {
	std::cout << (int)day << ' ' << date[month - 1] << ' ' << year << " ����";
}