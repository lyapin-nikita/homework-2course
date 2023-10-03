#include "students_group.h"


//structs
istream& operator>>(std::istream& in, student& Student)
{
	cout << "input the name: ";
	in >> Student.FN.name;
	cout << "input the surname: ";
	in >> Student.FN.surname;
	cout << "input the pathername: ";
	in >> Student.FN.patherName;

	cout << "input the birthday:" << endl << "	day: ";
	in >> Student.DB.day;
	cout << "	month: ";
	in >> Student.DB.month;
	cout << "	year: ";
	in >> Student.DB.year;

	cout << "input the phonenumber: ";
	in >> Student.NP.num;

	cout << "input the index of student: ";
	in >> Student.index;

	return in;
}

ostream& operator<<(std::ostream& out, const student& Student)
{
	out << "student " << Student.index << endl;
	out << Student.FN.surname << " " << Student.FN.name << " " << Student.FN.patherName << endl;
	out << Student.DB.day << ".";
	if (Student.DB.month < 10) { out << '0'; }
	out << Student.DB.month << "." << Student.DB.year << endl;
	out << Student.NP.num;

	return out;
}






//class
studentsGroup::studentsGroup()
{
	this->size = 0;
	this->group = nullptr;
}

studentsGroup::studentsGroup(const studentsGroup& otherGroup)
{
	this->size = otherGroup.size;
	this->group = otherGroup.group;
}

studentsGroup::~studentsGroup()
{
	delete[] group;
}



short studentsGroup::getSize() { return this->size; }

void studentsGroup::addStudent(student& newStudent)
{
	student* newGroup = new student[size+1];
	for (short i = 0; i < size; ++i) { newGroup[i] = group[i]; }
	newGroup[size] = newStudent;
	size++;
	delete[] group;
	group = newGroup;
}

void studentsGroup::addSameStudents(short addSize, student* masOfNewStudent)
{
	student* newGroup = new student[size + addSize];
	for (short i = 0; i < size; ++i) { newGroup[i] = group[i]; }
	for (short i = size; i < size + addSize; ++i) { newGroup[i] = masOfNewStudent[i - size]; }
	size += addSize;
	delete[] group;
	group = newGroup;
}

