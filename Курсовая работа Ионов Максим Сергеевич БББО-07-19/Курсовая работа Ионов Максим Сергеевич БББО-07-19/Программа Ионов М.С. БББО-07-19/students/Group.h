#pragma once
#include <string>
#include <vector>

using namespace std;

class Group
{
private:
	int Id;
	string Name;
	vector<int> StudentId;
public:
	Group(int id, string name);


	int getId();
	string getName();
	vector<int> getStudents();

	void setId(int id);
	void setName(string s);
	void AddStudent(int *s);
	void AddStudent(vector<int> s);
	void AddStudent(int s);
};

