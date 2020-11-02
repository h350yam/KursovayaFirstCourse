#include "MarksWorker.h"

MarksWorker::MarksWorker(string p)
{
	path = p;
}

void MarksWorker::Load()
{
	ifstream in(path);
	string q;
	while (getline(in, q)) {
		marks.emplace_back(Mark(q));
	}
	in.close();
}

void MarksWorker::Save()
{
	ofstream out(path);
	for (auto i : marks) {
		out << i.ToString() << endl;
	}
}

Mark* MarksWorker::getMarkById(int id)
{
	for (int i = 0; i < marks.size(); i++) {
		if (marks[i].getId() == id) {
			return &marks[i];
		}
	}
	return NULL;
}

int MarksWorker::AddMark(Mark s)
{
	if (s.getId() == -1) {
		int mx = 0;
		for (auto i : marks) {
			if (i.getId() > mx) {
				mx = i.getId();
			}
		}
		s.setId(mx + 1);
		marks.emplace_back(s);
		return mx + 1;
	}
	else {
		marks.emplace_back(s);
		return s.getId();
	}
}

void MarksWorker::DeleteMarkById(int id)
{
	if (existId(id)) {
		for (int i = 0; i < marks.size(); i++) {
			if (marks[i].getId() == id) {
				marks.erase(marks.begin() + i);
				return;
			}
		}
	}
}

bool MarksWorker::existId(int id)
{
	for (auto i : marks) {
		if (i.getId() == id) {
			return true;
		}
	}
	return false;
}

int MarksWorker::Count()
{
	return marks.size();
}

string* MarksWorker::getInfo()
{
	string* a = new string[marks.size()];
	for (int i = 0; i < marks.size(); i++) {
		a[i] = marks[i].ToString();
	}
	return a;
}

vector<int> MarksWorker::getMarksForStudentSubj(int studid, int subjectId, int term)
{
	vector<int> m;
	for (auto i : marks) {
		if (i.getStudentId() == studid && i.getSubjectId() == subjectId && (term == 0 || i.getTerm() == term)) {
			m.emplace_back(i.getValue());
		}
	}
	return m;
}

vector<int> MarksWorker::getMarksForStudent(int studId, int term)
{
	vector<int> m;
	for (auto i : marks) {
		if (i.getStudentId() == studId && (term == 0 || i.getTerm() == term)) {
			m.emplace_back(i.getValue());
		}
	}
	return m;
}

