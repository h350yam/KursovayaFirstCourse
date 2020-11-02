#include <iostream>
#include "Subject.h"
#include "Worker.h"

#include <vector>
#include <fstream>

#pragma once
// Класс работы со студентами
class SubjectWorker : Worker
{
public:
	SubjectWorker(string p = "");

	void Load();
	void Save();

	Subject* getSubjectById(int id);

	int AddSubject(Subject s);
	void DeleteSubjectById(int id);
	bool existId(int id);

	int Count();

	// Получение списка названий предметов
	string* subjectNames();
	// Получение списка полной информации о предметах
	string* getInfo();

	// Получение id всех предметов
	vector<int> getSubjectsId();
private:
	string path;
	vector<Subject> subjects;
};

