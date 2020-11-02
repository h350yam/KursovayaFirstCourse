#pragma once


#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	Date();
	Date(int d, int m, int y);
	Date(const Date& date);
	Date(string s);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int day, int month, int year);

	string ToString();
private:
	int day;
	int month;
	int year;
};
