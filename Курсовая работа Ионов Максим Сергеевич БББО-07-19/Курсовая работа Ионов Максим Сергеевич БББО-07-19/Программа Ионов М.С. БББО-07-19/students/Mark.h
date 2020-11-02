#pragma once
#include <string>
using namespace std;

// Класс Оценка
class Mark
{
private:
	int Id;
	
	int Value;		// Значение оценка
	int StudentId;	// id студента с оценкой
	int SubjectId;	// id предмета

	int term;

public:
	Mark(int id, int v, int stdid, int subjid, int trm);
	Mark(string s);
	Mark(const Mark& m);
	
	int getId();
	int getValue();
	int getTerm();
	int getStudentId();
	int getSubjectId();

	void setId(int id);
	void setValue(int v);
	void setStudentId(int stdid);
	void setSubjectId(int subjid);
	void setTurm(int tem);

	void setMark(int id, int v, int stdid, int subjid, int term);

	string ToString();
};

