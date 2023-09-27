#pragma once

#include "include.h"



class studentsGroup
{

private:


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
			string num;
		};

		fullName FN;
		dateOfBirth DB;
		numberOfPhone NP;
		short index;
		//перегрузка вывода
		
	};

	student* group;
	short size;



public:
	studentsGroup(); //default 
	studentsGroup(const studentsGroup& otherGroup);
	~studentsGroup();

	//перегрузка ввода вывода
	//перегрузка присваивания

	short getSize();

	void addStudent();
	void addSameStudents(short addSize);
	void delStudent(short index);
	short srhStudent_FullName();
	short srhStudent_DayOfBirth();
	short srhStudent_PhoneNumber(string phone);
	
};