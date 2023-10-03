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
		std::string num;
	};

	fullName FN;
	dateOfBirth DB;
	numberOfPhone NP;
	short index;

	friend istream& operator>>(std::istream& in, student& Student);
	friend ostream& operator<<(std::ostream& out, const student& Student);
	//���������� ������
	//���������� �����

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

	//���������� ����� ������
	//���������� ������������

	short getSize();

	void addStudent(student& newStudent);
	void addSameStudents(short addSize, student* masOfNewStudent);
	void delStudent(short index);
	short srhStudent_FullName();
	short srhStudent_DayOfBirth();
	short srhStudent_PhoneNumber(string phone);
	
};