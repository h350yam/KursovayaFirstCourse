#pragma once
#include <string>
#include <regex>
#include "Date.h"

using namespace std;

class Student
{
private:
	int Id;
	string Name;
	string SecName;
	string Patronymic;
	char Gender;
	Date DayOfBirth;
	string YearStart;
	string Faculty;
	string Group;
	string RecordBook;
public:
	Student();
	Student(int id, string name, string secname, string patro, char g, Date dayofbirth, string yearstart,
		string faculttm, string group, string recbook);
	Student(const Student& s);
	Student(string s);

	int getId();
	string getName();
	string getSecName();
	string getPatronymic();
	Date getDayOfBirth();
	string getYearStart();
	string getRecordBook();
	string getFaculty();
	string getGroup();
	char getGender();

	void setId(int id);
	void setName(string name);
	void setSecName(string secname);
	void setPatronymic(string patro);
	void setDayOfBirth(Date date);
	void setYearStart(string date);
	void setRecordBook(string r);
	void setFaculty(string f);
	void setGroup(string g);
	void setGender(char c);

	void setStudent(int id, string name, string secname, string patro, char g, Date dayofbirth, string yearstart,
		string faculttm, string group, string recbook);

	string getInfo();

	string ToString();
};

