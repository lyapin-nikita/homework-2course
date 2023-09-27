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
			//���������� ������
		};

		struct dateOfBirth
		{
			short day;
			short month;
			short year;
			//���������� ������
			//����� ��������� ������ ��� �����
		};

		struct numberOfPhone
		{
			string num;
		};

		fullName FN;
		dateOfBirth DB;
		numberOfPhone NP;
		short index;
		//���������� ������
		
	};

	student* group;
	short size;



public:
	studentsGroup(); //default 
	studentsGroup(const studentsGroup& otherGroup);
	~studentsGroup();

	//���������� ����� ������
	//���������� ������������

	short getSize();

	void addStudent();
	void addSameStudents(short addSize);
	void delStudent(short index);
	short srhStudent_FullName();
	short srhStudent_DayOfBirth();
	short srhStudent_PhoneNumber(string phone);
	
};