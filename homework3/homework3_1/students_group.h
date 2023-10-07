#pragma once
#define EMPTY 0

#include "include.h"
using namespace std;


struct student
{
	struct fullName
	{
		string name;
		string surname;
		string patherName;
		//перегрузка вывода
	};

	struct dateOfBirth
	{
		short day;
		short month;
		short year;
		//перегрузка вывода
		//метод получения месяца как слова
	};

	struct numberOfPhone
	{
		std::string num;
	};

	fullName FN;
	dateOfBirth DB;
	numberOfPhone NP;
	short index;

	friend istream& operator>>(std::istream& in, student& Student);
	friend ostream& operator<<(std::ostream& out, const student& Student);
	//перегрузка вывода
	//перегрузка ввода

};


class studentsGroup
{

private:
	student* group;
	short size;
	string nameGroup;

	short srhStudent_Index(student* mas, short size, short index);

public:
	studentsGroup(); //default 
	studentsGroup(const studentsGroup& otherGroup);
	~studentsGroup();

	//перегрузка ввода вывода
	//перегрузка присваивания

	short getSize();

	void addStudent(student& newStudent);
	void addSameStudents(short addSize, student* masOfNewStudent);
	void delStudent(short index);
	short srhStudent_FullName(string surname, string name, string fathername);
	short srhStudent_DayOfBirth(short day, short month, short year);
	short srhStudent_PhoneNumber(string phone);
	
	friend ostream& operator<<(std::ostream& out, const studentsGroup& Group);
};