#include "Mark.h"

Mark::Mark(int id, int v, int stdid, int subjid, int trm)
{
	setMark(id, v, stdid, subjid, trm);
}
Mark::Mark(string s)
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
				setValue(stoi(p));
				break;
			case 2:
				setStudentId(stoi(p));
				break;
			case 3:
				setSubjectId(stoi(p));
				break;
			case 4:
				setTurm(stoi(p));
				break;
			default:
				break;
			}
			c++;
		}
	}
}
Mark::Mark(const Mark& m)
{
	setMark(m.Id, m.Value, m.StudentId, m.SubjectId, m.term);
}
int Mark::getId()
{
	return Id;
}

int Mark::getValue()
{
	return Value;
}

int Mark::getTerm()
{
	return term;
}

int Mark::getStudentId()
{
	return StudentId;
}

int Mark::getSubjectId()
{
	return SubjectId;
}

void Mark::setId(int id)
{
	Id = id;
}

void Mark::setValue(int v)
{
	Value = v;
}

void Mark::setStudentId(int stdid)
{
	StudentId = stdid;
}

void Mark::setSubjectId(int subjid)
{
	SubjectId = subjid;
}

void Mark::setTurm(int tem)
{
	term = tem;
}


void Mark::setMark(int id, int v, int stdid, int subjid, int trm)
{
	setId(id);
	setValue(v);
	setStudentId(stdid);
	setSubjectId(subjid);
	setTurm(trm);
}

string Mark::ToString()
{
	return to_string(Id) + " " + to_string(Value) + " " + to_string(StudentId) + " " + to_string(SubjectId) + " " + to_string(term);
}
