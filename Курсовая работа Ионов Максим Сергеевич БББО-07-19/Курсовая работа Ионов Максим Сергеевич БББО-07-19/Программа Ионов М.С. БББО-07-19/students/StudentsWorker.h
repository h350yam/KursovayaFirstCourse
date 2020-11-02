#include <iostream>
#include "Student.h"
#include "Worker.h"
#include <vector>
#include <fstream>

#pragma once

// Класс работы со студентами
class StudentsWorker : Worker
{
public:
	StudentsWorker(string p = "");

	void Load();
	void Save();

	Student* getStudentById(int id);
	Student* getStudentByRecordBook(string rec);

	int AddStudent(Student s);
	void DeleteStudentById(int id);
	bool existId(int id);

	int Count();
	// Получение списка имен студентов
	vector<string> studNames(char g);
	// Получение списка с полной информации о студентах
	vector<string> getInfo(char g);
	// Получение списка с id всех студентов
	vector<int> getAllId(char g);

	
private:
	string path;
	vector<Student> stud;
};

