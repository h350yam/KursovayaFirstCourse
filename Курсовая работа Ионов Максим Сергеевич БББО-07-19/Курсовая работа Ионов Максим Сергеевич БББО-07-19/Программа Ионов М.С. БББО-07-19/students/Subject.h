
#include <string>
#pragma once	
using namespace std;

class Subject
{
public:
	Subject(int id, string name, string info);
	Subject(string s);
	Subject(const Subject& s);


	string getInfo();
	string getName();
	int getId();

	void setName(string name);
	void setInfo(string info);
	void setId(int id);

	void setSubject(int id, string name, string info);

	string ToString();
private:
	int Id;
	string Name;
	string Info;
};

