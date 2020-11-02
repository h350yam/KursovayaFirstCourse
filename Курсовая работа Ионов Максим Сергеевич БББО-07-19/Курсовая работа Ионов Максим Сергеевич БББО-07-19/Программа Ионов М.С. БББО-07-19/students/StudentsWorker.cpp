#include "StudentsWorker.h"

StudentsWorker::StudentsWorker(string p)
{
	path = p;
	stud.clear();
}

void StudentsWorker::Load()
{
	ifstream in(path);
	string q;
	while (getline(in, q)) {
		stud.emplace_back(Student(q));		
	}
	in.close();

}

void StudentsWorker::Save()
{
	ofstream out(path);
	for (auto i : stud) {
		out << i.ToString() << endl;
	}
}

Student* StudentsWorker::getStudentById(int id)
{
	for (int i = 0; i < stud.size(); i++) {
		if (stud[i].getId() == id) {
			return &stud[i];
		}
	}
	return NULL;
}

Student* StudentsWorker::getStudentByRecordBook(string record)
{
	for (auto i : stud) {
		if (i.getRecordBook() == record) {
			return &i;
		}
	}
	return NULL;
}

int StudentsWorker::AddStudent(Student s)
{
	if (s.getId() == -1) {
		int mx = 0;
		for (auto i : stud) {
			mx = std::max(mx, i.getId());
		}
		s.setId(mx + 1);
		stud.emplace_back(s);
		return s.getId();
	}
	else {
		stud.emplace_back(s);
		return s.getId();
	}
}

void StudentsWorker::DeleteStudentById(int id)
{
	if (existId(id)) {
		for (int i = 0; i < stud.size(); i++) {
			if (stud[i].getId() == id) {
				stud.erase(stud.begin() + i);
				return;
			}
		}
	}
}

int StudentsWorker::Count()
{
	return stud.size();
}

vector<string> StudentsWorker::studNames(char g)
{
	vector<string> a;
	for (int i = 0; i < stud.size(); i++) {
		if (g == 'b') {
			a.push_back(to_string(stud[i].getId()) + " " + stud[i].getName());
		}
		if (g == 'm' && stud[i].getGender() == 'm') {
			a.push_back(to_string(stud[i].getId()) + " " + stud[i].getName());
		}
		if (g == 'f' && stud[i].getGender() == 'f') {
			a.push_back(to_string(stud[i].getId()) + " " + stud[i].getName());
		}
	}
	return a;
}

vector<string> StudentsWorker::getInfo(char g)
{
	vector<string> a;
	for (int i = 0; i < stud.size(); i++) {
		if (g == 'b') {
			a.emplace_back(stud[i].ToString());
		}
		if (g == 'm' && stud[i].getGender() == 'm') {
			a.emplace_back(stud[i].ToString());
		}
		if (g == 'f' && stud[i].getGender() == 'f') {
			a.emplace_back(stud[i].ToString());
		}
	}
	return a;
}

vector<int> StudentsWorker::getAllId(char g)
{
	vector<int> r;
	for (int i = 0; i < stud.size(); i++) {
		if (g == 'b') {
			r.emplace_back(stud[i].getId());
		}
		if (g == 'm' && stud[i].getGender() == g) {
			r.emplace_back(stud[i].getId());
		}
		if (g == 'f' && stud[i].getGender() == g) {
			r.emplace_back(stud[i].getId());
		}
	}
	return r;
}

bool StudentsWorker::existId(int id) {
	for (auto i : stud) {
		if (i.getId() == id) {
			return true;
		}
	}
	return false;
}