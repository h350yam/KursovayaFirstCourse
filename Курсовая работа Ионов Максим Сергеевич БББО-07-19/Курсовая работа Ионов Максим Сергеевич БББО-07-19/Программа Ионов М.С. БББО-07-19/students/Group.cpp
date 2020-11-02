#include "Group.h"

Group::Group(int id, string name)
{
	Id = id;
	Name = name;
	StudentId.clear();
}

int Group::getId()
{
	return Id;
}

string Group::getName()
{
	return Name;
}

vector<int> Group::getStudents()
{
	return StudentId;
}

void Group::setId(int id)
{
	Id = id;
}

void Group::setName(string s)
{
	Name = s;
}

void Group::AddStudent(int* s)
{
	// TODO
}

void Group::AddStudent(vector<int> s)
{
	StudentId.emplace_back(s);
}

void Group::AddStudent(int s)
{
	StudentId.emplace_back(s);
}
