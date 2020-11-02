#include "SubjectWorker.h"

SubjectWorker::SubjectWorker(string p)
{
	path = p;
}

void SubjectWorker::Load()
{
	ifstream in(path);
	string q;
	while (getline(in, q)) {
		subjects.emplace_back(Subject(q));
	}
	in.close();
}

void SubjectWorker::Save()
{
	ofstream out(path);
	for (auto i : subjects) {
		out << i.ToString() << endl;
	}
}

Subject* SubjectWorker::getSubjectById(int id)
{
	for (int i = 0; i < subjects.size(); i++) {
		if (subjects[i].getId() == id) {
			return &subjects[i];
		}
	}
	return NULL;
}

int SubjectWorker::AddSubject(Subject s)
{
	if (s.getId() == -1) {
		int mx = 0;
		for (auto i : subjects) {
			if (i.getId() > mx) {
				mx = i.getId();
			}
		}
		s.setId(mx + 1);
		subjects.emplace_back(s);
		return mx + 1;
	}
	else {
		subjects.emplace_back(s);
		return s.getId();
	}
}

void SubjectWorker::DeleteSubjectById(int id)
{
	if (existId(id)) {
		for (int i = 0; i < subjects.size(); i++)		{
			if (subjects[i].getId() == id) {
				subjects.erase(subjects.begin() + i);
				return;
			}
		}
	}
}

bool SubjectWorker::existId(int id)
{
	for (auto i : subjects) {
		if (i.getId() == id) {
			return true;
		}
	}
	return false;
}

int SubjectWorker::Count()
{
	return subjects.size();
}

string* SubjectWorker::subjectNames()
{
	string* a = new string[subjects.size()];
	for (int i = 0; i < subjects.size(); i++) {
		a[i] = to_string(subjects[i].getId()) + " " + subjects[i].getName();
	}
	return a;
}

string* SubjectWorker::getInfo()
{
	string* a = new string[subjects.size()];
	for (int i = 0; i < subjects.size(); i++) {
		a[i] = subjects[i].ToString();
	}
	return a;
}

vector<int> SubjectWorker::getSubjectsId()
{
	vector<int> a(subjects.size());
	for (int i = 0; i < subjects.size(); i++) {
		a[i] = subjects[i].getId();
	}
	return a;
}
