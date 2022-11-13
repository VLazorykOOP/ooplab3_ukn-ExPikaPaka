#pragma once
#include <ctime>
#include <Windows.h>
#include <iostream>

class Date {
	time_t  _t;
	tm* _tPtr;
	char date[12][12] = {"Січня", "Лютого", "Березня", "Квітня", "Травня", "Червня",
						 "Липня", "Серпня", "Вересня", "Жовтня", "Листопада", "Грудня"};
	char day;
	char month;
	int year;

public:
	Date();
	Date(char setDay, char setMonth, int setYear);

	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();

	void setDay(int setDay);
	void setMonth(int setMonth);
	void setYear(int setYear);

	void printDate();
	void printTextDate();
};
