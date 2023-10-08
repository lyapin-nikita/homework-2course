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

student::student()
{

}







short studentsGroup::srhStudent_Index(student* mas, short size, short index)
{
	for (short i = 0; i < size; ++i)
	{
		if (mas[i].index == index) return i;
	}
	return -1;
}

//class
studentsGroup::studentsGroup()
{
	FILESTREAM.open("studentsData.txt", fstream::in | fstream::out | fstream::app);
	if (!FILESTREAM.is_open()) { cout << "error"; }
	else
	{
		cout << "file successfully opened!";
		short count = 0;
		string line;
		string word;
		while (getline(FILESTREAM, line)) { count++; }
		size = count;
		group = new student[size];
		FILESTREAM.seekg(0, ios::beg);
		for (short i = 0; i < size; ++i)
		{
			count = 0;
			getline(FILESTREAM, line);
			stringstream stringStream(line);
			while (stringStream >> word)
			{
				count++;
				if (count == 1) group[i].FN.surname = word;
				if (count == 2) group[i].FN.name = word;
				if (count == 3) group[i].FN.patherName = word;
				if (count == 4) group[i].DB.day = stoi(word);
				if (count == 5) group[i].DB.month = stoi(word);
				if (count == 6) group[i].DB.year = stoi(word);
				if (count == 7) group[i].NP.num = word;
				if (count == 8) group[i].index = stoi(word);
			}
		}
	}
	
}

studentsGroup::studentsGroup(const studentsGroup& otherGroup)
{
	this->size = otherGroup.size;
	this->group = otherGroup.group;
	this->nameGroup = otherGroup.nameGroup;
}

studentsGroup::~studentsGroup()
{
	FILESTREAM.close();
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

void studentsGroup::delStudent(short index)
{
	bool found = false;

	// ����� �������� �� ��������� �������
	for (int i = 0; i < size; i++) {
		if (group[i].index == index) {
			found = true;

			// ������� ���������� �������� � ������� ����� ������ ���������
			for (int j = i; j < size - 1; j++) {
				group[j] = group[j + 1];
			}
			size--;

			break;
		}
	}

	if (!found) {
		throw runtime_error("������� � ��������� �������� �� ������.");
	}
}

short studentsGroup::srhStudent_FullName(string surname, string name, string fathername)
{	
	int countOfSimillarStudents = 0;
	int countFIO = 0;
	short indexOfStudent;
	bool haveStudent = false;
	for (int i = 0; i < size; i++)
	{

		if (group[i].FN.name == name)
		{
			countFIO++;
		}
		if (group[i].FN.surname == surname)
		{
			countFIO++;
		}
		if (group[i].FN.patherName == fathername)
		{
			countFIO++;
		}

		if (countFIO == 3) { countOfSimillarStudents++; haveStudent = true; indexOfStudent = group[i].index; }
	}

	if (haveStudent == false) 
	{
		throw runtime_error("������� � ���������� ������� �� ������.");
	}

	if (countOfSimillarStudents > 1)
	{
		throw runtime_error("� ������ ������� ��������� ����� � ������������ �������");
	}

	return indexOfStudent;
}

short studentsGroup::srhStudent_DayOfBirth(short day, short month, short year)
{
	int countOfSimillarStudents = 0;
	int countDB = 0;
	short indexOfStudent;
	bool haveStudent = false;
	for (int i = 0; i < size; i++)
	{

		if (group[i].DB.day == day)
		{
			countDB++;
		}
		if (group[i].DB.month == month)
		{
			countDB++;
		}
		if (group[i].DB.year == year)
		{
			countDB++;
		}

		if (countDB == 3) { countOfSimillarStudents++; haveStudent = true; indexOfStudent = group[i].index; }
	}

	if (haveStudent == false)
	{
		throw runtime_error("������� � ���������� ������� �� ������.");
	}

	if (countOfSimillarStudents > 1)
	{
		throw runtime_error("� ������ ������� ��������� ����� � ����������� �������");
	}

	return indexOfStudent;
}

short studentsGroup::srhStudent_PhoneNumber(string phone)
{
	short indexOfStudent;
	for (int i = 0; i < size; i++)
	{

		if (group[i].NP.num == phone)
		{
			return group[i].index;
		}

	}

	throw runtime_error("������� � ���������� ������� �� ������.");
}

ostream& operator<<(std::ostream& out, const studentsGroup& Group)
{
	out << "The group " << Group.nameGroup << ". Here is " << Group.size << " students." << endl;
	if (Group.size != EMPTY) 
	{
		for (short i = 0; i < Group.size; ++i) { out << i << "	" << Group.group[i] << endl << endl; }
	}
	return out;
}

