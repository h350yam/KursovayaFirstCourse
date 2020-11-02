#pragma once
#include <string>
using namespace std;

// ����� ������
class Mark
{
private:
	int Id;
	
	int Value;		// �������� ������
	int StudentId;	// id �������� � �������
	int SubjectId;	// id ��������

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

