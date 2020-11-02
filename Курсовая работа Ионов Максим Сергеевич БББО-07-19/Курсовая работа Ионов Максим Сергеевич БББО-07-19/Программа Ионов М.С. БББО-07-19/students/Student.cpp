class Date;

#include "Student.h"
#include "Date.h"


Student::Student()
{
	Name = string();
	SecName = string();
	Patronymic = string();
	
	DayOfBirth = Date();
	YearStart = string();
	Faculty = string();
	Group = string();
	RecordBook = string();
}

Student::Student(int id, string name, string secname, string patro, char g,  Date dayofbirth,
	string yearstart, string faculttm, string group, string recbook)
{
	setStudent(id, name, secname, patro, g, dayofbirth, yearstart, faculttm, group, recbook);
}

Student::Student(const Student& s)
{
	setStudent(s.Id, s.Name, s.SecName, s.Patronymic, s.Gender, s.DayOfBirth, s.YearStart, s.Faculty, s.Group, s.RecordBook);
}

Student::Student(string s)
{
	if (s[s.size() - 1] != ' ') {
		s += " ";
	}
	int last = 0;
	int c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			string p = s.substr(last, i - last);
			last = i + 1;
			switch (c)
			{
			case 0:
				setId(stoi(p));				
				break;
			case 1:
				setName(p);
				break;
			case 2:
				setSecName(p);
				break;
			case 3:
				setPatronymic(p);
				break;
			case 4:
				setGender(p[0]);
				break;
			case 5:
				setDayOfBirth(Date(p));
				break;
			case 6:
				setYearStart(p);
				break;
			case 7:
				setFaculty(p);
				break;
			case 8:
				setGroup(p);
				break;
			case 9:
				setRecordBook(p);
				break;
			default:
				break;
			}
			c++;
		}
	}
}



int Student::getId() {
	return Id;
}
string Student::getName() {
	return Name;
}
string Student::getSecName() {
	return SecName;
}
string Student::getPatronymic() {
	return Patronymic;
}

Date Student::getDayOfBirth()
{
	return DayOfBirth;
}

string Student::getYearStart()
{
	return YearStart;
}

string Student::getRecordBook()
{
	return RecordBook;
}

string Student::getFaculty()
{
	return Faculty;
}

string Student::getGroup()
{
	return Group;
}

char Student::getGender()
{
	return Gender;
}

void Student::setId(int id)
{
	Id = id;
}

void Student::setName(string name)
{
	Name = name;
}

void Student::setSecName(string secname)
{
	SecName = secname;
}

void Student::setPatronymic(string patro)
{
	Patronymic = patro;
}

void Student::setDayOfBirth(Date date)
{
	DayOfBirth = date;
}

void Student::setYearStart(string date)
{
	YearStart = date;
}

void Student::setRecordBook(string r)
{
	RecordBook = r;
}

void Student::setFaculty(string f)
{
	Faculty = f;
}

void Student::setGroup(string g)
{
	Group = g;
}

void Student::setGender(char c)
{
	Gender = c;
}

void Student::setStudent(int id, string name, string secname, string patro, char g, Date dayofbirth,
	string yearstart, string faculttm, string group, string recbook)
{
	setId(id);
	setName(name);
	setSecName(secname);
	setPatronymic(patro);
	setGender(g);
	getDayOfBirth();
	getYearStart();
	setDayOfBirth(dayofbirth);
	setYearStart(yearstart);
	setRecordBook(recbook);
	setFaculty(faculttm);
	setGroup(group);
}

string Student::getInfo()
{
	return Name + " " + SecName + " " + Patronymic;
}


string Student::ToString()
{
	return to_string(Id) + " " + Name +
		" " + SecName + " " + Patronymic + " " + Gender +
		" " + DayOfBirth.ToString() + " " +
		YearStart + " " + Faculty +
		" " + Group + " " + RecordBook;
}
