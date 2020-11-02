#include "Date.h"


Date::Date() {
	setDate(1, 1, 1970);
}
Date::Date(int d, int m, int y) {
	setDate(d, m, y);
}

Date::Date(const Date& date) {
	setDate(date.day, date.month, date.year);
}

Date::Date(string s)
{
	setDate(stoi(s.substr(0, 2)), stoi(s.substr(3, 2)), stoi(s.substr(6, 4)));
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

void Date::setDay(int day) {
	day = day;
}

void Date::setMonth(int month) {
	month = month;
}

void Date::setYear(int year) {
	year = year;
}

void Date::setDate(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

string Date::ToString()
{
	day %= 100;
	month %= 100;
	string temp = "";
	if (day < 9) {
		temp += "0";
	}
	
	temp += to_string(day) + "/";
	if (month < 9) {
		temp += "0";
	}
	temp += to_string(month) + "/";

	temp += to_string(year);

	return temp;
}
