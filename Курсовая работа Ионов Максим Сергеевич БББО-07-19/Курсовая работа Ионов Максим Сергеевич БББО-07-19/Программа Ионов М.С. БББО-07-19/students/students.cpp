#include <iostream>
#include <time.h>
#include <string>

#include <windows.h>;
#include "StudentsWorker.h"
#include "SubjectWorker.h"
#include "MarksWorker.h"


using namespace std;


string getRecordBook(int id, StudentsWorker* stdw, SubjectWorker* sw, MarksWorker* mw)
{
	string result = stdw->getStudentById(id)->getInfo() + "\n";
	result += "Факультет " + stdw->getStudentById(id)->getFaculty() + "\n";
	result += "Зачетная книжка " + stdw->getStudentById(id)->getRecordBook() + "\n";
	result += "Год поступления " + stdw->getStudentById(id)->getYearStart() + "\n";


	auto subjects = sw->getSubjectsId();

	bool existenything = 0;
	for (int term = 1; term <= 6; term++) {
		string r = "Marks in " + to_string(term) + " term:\n";
		bool exist = 0;
		for (int i = 0; i < sw->Count(); i++) {
			auto marks = mw->getMarksForStudentSubj(id, subjects[i], term);
			if (marks.size() > 0) {
				r += sw->getSubjectById(subjects[i])->getName() + ": ";
				exist = 1;
				for (auto j : marks) {
					r += to_string(j) + " ";
				}
				r += "\n";
			}
		}
		if (exist) {
			result += r;
			existenything = 1;
		}
	}
	if (existenything) {
		return result;
	}
	else {
		return result + "У студента нет оценок";
	}
}

//Проверка строки на правильность ввода (пустая строка)
bool enterString(string* s, string text) {
	cout << text << ": ";
	cin >> *s;
	if (s->size() == 0) {
		cout << "Ошибка ввода, повторите ввод: ";
		cin >> *s;
		if (s->size() == 0) {
			cout << "Ошибка ввода\n";
			return false;
		}
	}
	return true;
}

//Проверка правильности ввода даты
bool checkDate(string str) {
	static std::regex rgx{ R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20\d\d))" };
	std::smatch res;
	if (std::regex_search(str, res, rgx))
	{		
		return true;
	}
	return false;
}

//Вывод меню
void menu() {
	cout << "Введите пункт меню для выполнения :\n";
	cout << "Пункт 1 - Добавить студента\n";
	cout << "Пункт 2 - Удалить студента\n";
	cout << "Пункт 3 - Добавить предмет\n";
	cout << "Пункт 4 - Удалить предмет\n";
	cout << "Пункт 5 - Добавить оценку\n";
	cout << "Пункт 6 - Вывести всех студентов\n";
	cout << "Пункт 7 - Вывести все предметы\n";
	cout << "Пункт 8 - Вывести зачётку студента по ID\n";
	cout << "Пункт 9 - Выполнить вариант 34\n";
	cout << "Пункт 0 - Выйти из программы\n";
}
void menuPrintStud() {
	cout << "Введите 1, чтобы вывести только имена студентов через ID\n";
	cout << "Введите 2, чтобы вывести всю информацию о студентах\n";
	cout << "Введите 3, чтобы вывести всю информацию о студентах с оценками\n";
	cout << "Введите 4, чтобы получить информацию о студентах, отсортированных по средней оценке\n";
}
void menuCourse() {
	cout << "Введите M, чтобы вывести студентов без троек мужского пола\n";
	cout << "Введите F, чтобы вывести студентов без троек женского пола\n";
}
void menuPrintSubj() {
	cout << "Введите 1, чтобы вывести только названия предметов с их ID\n";
	cout << "Введите 2, чтобы вывести всю информацию о предметах\n";
}

//Выставление оценки
void SetMark(StudentsWorker* sw, SubjectWorker* sbw, MarksWorker * mw) {
	int stdid, sbjid, val, id, term;
	cout << "Введите id студента ";
	cin >> stdid;
	if (!sw->existId(stdid)) {
		cout << "Нет такого студента" << endl;
		return;
	}
	cout << "Введите id предмета ";
	cin >> sbjid;
	if (!sbw->existId(sbjid)) {
		cout << "Нет такого предмета" << endl;
		return;
	}
	cout << "Введите оценку ";
	cin >> val;
	cout << "Введите семестр ";
	cin >> term;
	id = mw->AddMark(Mark(-1, val, stdid, sbjid, term));
	cout << "Выставлена оценка с id = " << id << endl;
}

// Процедура вывода информации о предметах
void PrintSubj(StudentsWorker * sw, SubjectWorker * sbw, MarksWorker* mw) {
	int comand;
	string* list;
	menuPrintSubj();
	cin >> comand;
	switch (comand)
	{
	case 1:
		list = sbw->subjectNames();
		for (int i = 0; i < sbw->Count(); i++) {
			cout << list[i] << endl;
		}
		break;

	case 2:
		list = sbw->getInfo();
		for (int i = 0; i < sbw->Count(); i++) {
			cout << list[i] << endl;
		}
		break;
	default:
		break;
	}
}
// Добавление нового студента
void AddStud(StudentsWorker * sw) {
	string name, scname, patro, dob, dor, fac, group, rb, id;
	char g;
	enterString(&name, "Введите имя");
	enterString(&scname, "Введите фамилию");
	enterString(&patro, "Введите отчество");

	cout << "Введите пол (m или f) ";
	cin >> g;
	if (g != 'm' && g != 'f') {
		cout << "Ошибка ввода, повторите ввод (m или f): " << endl;
		cin >> g;
		if (g != 'm' && g != 'f') {
			cout << "Ошибка ввода\n";
			return;
		}
	}
	cout << "Введите дату рождения в формате ДД.ММ.ГГГГ: ";
	cin >> dob;
	if (!checkDate(dob)) {
		cout << "Ошибка ввода, повторите ввод: ";
		cin >> dob;
		if (!checkDate(dob)) {
			"Ошибка ввода\n";
			return;
		}
	}	
	enterString(&dor, "Введите год поступления");
	enterString(&fac, "Введите факультет");
	enterString(&group, "Введите группу");
	enterString(&rb, "Введите номер зачетки");
	id = sw->AddStudent(Student(-1, name, scname, patro, g, Date(dob), dor, fac, group, rb));

	cout << "Студент добавлен под id = " << sw->getStudentByRecordBook(rb)->getId() << endl;
}
// Удаление студента
void DeleteStud(StudentsWorker * sw) {
	int id;
	cout << "Введите id студента для удаления ";
	cin >> id;
	if (sw->existId(id)) {
		sw->DeleteStudentById(id);
	}
	else {
		cout << "Нет студента с таким id";
	}
}
// Вывод информации о студентах
void PrintStud(StudentsWorker * sw, SubjectWorker * sbw, MarksWorker* mw) {
	vector<string> list;
	char g = 'b';
	vector<int> m, ids;
	vector<pair<int, string> > a;
	int comand;
	menuPrintStud();
	cin >> comand;
	cout << "Введите b, если хотите вывести всех студентов\n        m, если хотите вывести только студентов мужского пола\n        f, если хотите вывести студентов женского пола\n";
	cin >> g;
	if (g != 'b' && g != 'f' && g != 'm') {
		cout << "Ошибка ввода";
		return;
	}
	switch (comand)
	{
	case 1:
		list = sw->studNames(g);
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << endl;
		}
		break;

	case 2:
		list = sw->getInfo(g);
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << endl;
		}
		break;
	case 3:
		ids = sw->getAllId(g);
		list = sw->getInfo(g);
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << " Оценки: ";

			m = mw->getMarksForStudent(ids[i]);
			for (auto j : m) {
				cout << j << ' ';
			}
			cout << endl;
		}
		break;
	case 4:
		int term;
		cout << "Введите номер семестра или 0, если интересуют все семестры: ";
		cin >> term;
		if (term < 0 || term > 6) {
			cout << "Ошибка ввода";
			return;
		}
		ids = sw->getAllId(g);
		list = sw->getInfo(g);
		a.resize(list.size());
		for (int i = 0; i < list.size(); i++) {
			a[i].second = sw->getStudentById(ids[i])->getInfo();
			m = mw->getMarksForStudent(ids[i], term);
			double sum = 0;
			for (auto j : m) {
				sum += j;
			}
			if (m.size() == 0) {
				a[i].first = -1;
			}
			else {
				a[i].first = sum / m.size();
			}
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		for (auto i : a) {
			if (i.first != -1) {
				cout << i.second << " Средний балл: " << i.first << endl;
			}
		}
		break;
	default:
		break;
	}
}

// Добавление предмета
void AddSubj(SubjectWorker * sbw) {
	string name, info;
	enterString(&name, "Введите название");
	enterString(&info, "Введите информацию");

	int id = sbw->AddSubject(Subject(-1, name, info));

	cout << "Предмет добавлен под id = " << id << endl;
}
// Удаление предмета
void DeleteSubj(SubjectWorker * sbw) {
	int id;
	cout << "Введите id предмета для удаления ";
	cin >> id;
	if (sbw->existId(id)) {
		sbw->DeleteSubjectById(id);
	}
	else {
		cout << "Нет предмета с таким id\n";
	}
}

void RecordBookInfo(StudentsWorker* sw, SubjectWorker* sbw, MarksWorker* mw) {
	int id;
	cout << "Введите id студнета ";
	cin >> id;
	if (sw->existId(id)) {
		cout << getRecordBook(id, sw, sbw, mw) << endl;
	}
	else {
		cout << "Нет такого студента, попробуйте снова: ";
		cin >> id;
		if (sw->existId(id)) {
			cout << getRecordBook(id, sw, sbw, mw) << endl;
		}
		else {
			cout << "Ошибка ввода";
			return;
		}
	}
}

// Выполнение варианта 34
void CourseWork(StudentsWorker* sw, SubjectWorker* sbw, MarksWorker* mw) {
	vector<string> list;
	char g = 'b';
	vector<int> m, ids;
	menuCourse();
	cin >> g;
	if (g != 'b' && g != 'f' && g != 'm' && g != 'м' && g != 'ж') {
		cout << "Ошибка ввода";
		return;
	}
	else {
		ids = sw->getAllId(g);
		list = sw->getInfo(g);
		for (int i = 0; i < list.size(); i++) {
			int block = 0;
			m = mw->getMarksForStudent(ids[i]);
			for (auto j : m)
			{
				if (j <= 3)
				{
					block++;
				}
			}
			if (block != 0)
			{

			}
			else {
				cout << list[i] << " Оценки: ";
				for (auto j : m) {
					cout << j << ' ';
				}
			}
			cout << endl;
		}
	}
}


int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	menu();
	StudentsWorker sw("Students.txt");
	SubjectWorker sbw("Subjects.txt");
	MarksWorker mw("Marks.txt");
	

	sw.Load();
	sbw.Load();
	mw.Load();
	int id, comand;

	int c;
	cin >> c;
	while (1) {
		switch (c)
		{
		case 1:
			AddStud(&sw);
			break;
		case 2:
			DeleteStud(&sw);
			break;
		case 3:
			AddSubj(&sbw);
			break;
		case 4:
			DeleteSubj(&sbw);
			break;
		case 5:
			SetMark(&sw, &sbw, &mw);
			break;
		case 6:
			PrintStud(&sw, &sbw, &mw);
			break;
		case 7:
			PrintSubj(&sw, &sbw, &mw);
			break;
		case 8:
			RecordBookInfo(&sw, &sbw, &mw);
			break;
		case 9:
			CourseWork(&sw, &sbw, &mw);
			break;
		case 0:
			sw.Save();
			sbw.Save();
			mw.Save();
			return 0;
			break;
		default:
			cout << "Неправильная команда, повторите ввод";
			break;
		}
		menu();
		cin >> c;
	}
}
