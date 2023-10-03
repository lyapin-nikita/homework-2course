#pragma once

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
	short srhStudent_FullName();
	short srhStudent_DayOfBirth();
	short srhStudent_PhoneNumber(string phone);
	
};