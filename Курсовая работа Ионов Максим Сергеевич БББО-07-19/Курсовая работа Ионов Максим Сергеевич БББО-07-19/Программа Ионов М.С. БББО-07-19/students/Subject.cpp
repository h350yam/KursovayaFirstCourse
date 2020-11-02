#include "Subject.h"

Subject::Subject(int id, string name, string info)
{
	setSubject(id, name, info);
}

Subject::Subject(string s)
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
				setInfo(p);
				break;			
			default:
				break;
			}
			c++;
		}
	}
}

Subject::Subject(const Subject& s)
{
	setSubject(s.Id, s.Name, s.Info);
}

string Subject::getInfo()
{
	return Info;
}

string Subject::getName()
{
	return  Name;
}

int Subject::getId()
{
	return Id;
}

void Subject::setName(string name)
{
	Name = name;
}

void Subject::setInfo(string info)
{
	Info = info;
}

void Subject::setId(int id)
{
	Id = id;
}

void Subject::setSubject(int id, string name, string info)
{
	setId(id);
	setName(name);
	setInfo(info);
}

string Subject::ToString()
{
	return to_string(Id) + " " + Name + " " + Info;
}
