#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Worker.h"
#include "Mark.h"

using namespace std;

// ����� ������ � ��������
class MarksWorker : Worker
{
public:
	MarksWorker(string p = "");


	void Load();
	void Save();

	// ��������� ����� �� id
	Mark* getMarkById(int id);

	int AddMark(Mark s);
	void DeleteMarkById(int id);
	bool existId(int id);

	int Count();

	string* getInfo();

	// ��������� ������ ��� �������� �� ��������� ��������
	vector<int> getMarksForStudentSubj(int studId, int SubjectId, int term = 0);
	// ��������� ���� ������ ��� ��������
	vector<int> getMarksForStudent(int studId, int term = 0);


private:
	string path;
	vector<Mark> marks;
};

