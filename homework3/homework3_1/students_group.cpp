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
	out << Student.FN.surname << " ";
	out << Student.FN.name << " ";
	out << Student.FN.patherName << " ";
	out << Student.DB.day << " ";
	out << Student.DB.month << " ";
	out << Student.DB.year << " ";
	out << Student.NP.num << " ";
	out << Student.index << endl;

	return out;
}

student::student()
{
	FN.name = "EMPTYNAME";
	FN.surname = "EMPTYSURNAME";
	FN.patherName = "EMPTYLASTNAME";

	DB.day = 1;
	DB.month = 1;
	DB.year = 1990;

	NP.num = "00000000000";

	index = 0;
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

	if (!FILESTREAM.is_open())
	{
		cerr << "Не удалось открыть файл." << endl;
	}

	string line;
	size = 0;

	while (getline(FILESTREAM, line)) {
		size++;
	}

	group = new student[size];
	FILESTREAM.clear();
	FILESTREAM.seekg(0, ios::beg);

	for (short i = 0; i < size; ++i) {
		getline(FILESTREAM, line);
		istringstream stringStream(line);
		string word;
		short count = 0;

		while (stringStream >> word) {
			count++;
			if (count == 1)
				group[i].FN.surname = word;
			else if (count == 2)
				group[i].FN.name = word;
			else if (count == 3)
				group[i].FN.patherName = word;
			else if (count == 4)
				group[i].DB.day = std::stoi(word);
			else if (count == 5)
				group[i].DB.month = std::stoi(word);
			else if (count == 6)
				group[i].DB.year = std::stoi(word);
			else if (count == 7)
				group[i].NP.num = word;
			else if (count == 8)
				group[i].index = std::stoi(word);
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

void studentsGroup::addStudent(const student& newStudent)
{
	student* newGroup = new student[size+1];
	for (short i = 0; i < size; ++i) { newGroup[i] = group[i]; }
	newGroup[size] = newStudent;
	size++;
	delete[] group;
	group = newGroup;
	
	FILESTREAM.seekg(0, std::ios::end);
	FILESTREAM << newStudent << endl;
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

	// Поиск студента по заданному индексу
	int i;
	for (i = 0; i < size; i++)
	{
		if (group[i].index == index)
		{
			found = true;

			// Удаляем найденного студента и создаем новый массив студентов
			for (int j = i; j < size - 1; j++)
			{
				group[j] = group[j + 1];
			}
			size--;

			break;
		}
	}

	if (!found) {
		throw runtime_error("Студент с указанным индексом не найден.");
	}


	/*Для удаления строчки реализую следующий алгоритм
	Создам временный файл
	Запишу туда все строчки, пропустив выбранную
	Удалю исходный файл
	Переименуем временный файл*/

	//1
	fstream TMP1("tmp.txt", fstream::in | fstream::out | fstream::app | fstream::trunc);
	if (!TMP1.is_open())
	{
		cerr << "Не удалось создать временный файл!" << endl;
	}

	//2
	FILESTREAM.seekg(0, ios::beg);
	string tmpline;
	int currentLine = 1;
	while (getline(FILESTREAM, tmpline))
	{
		currentLine++;
		if (currentLine != (i + 2))
		{
			TMP1 << tmpline << endl;
		}
	}

	//3
	FILESTREAM.close();
	string path = "studentsData.txt";
	if (remove(path.c_str()) != 0)
	{
		cerr << "Не удалось удалить исходный файл!";
	}

	//4
	if (rename("tmp.txt", path.c_str()) != 0)
	{
		cerr << "Не удалось переименовать временный файл!" << endl;
	}

	FILESTREAM.open(path, fstream::in | fstream::out | fstream::app);
	TMP1.close();
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
		throw runtime_error("Студент с указанными данными не найден.");
	}

	if (countOfSimillarStudents > 1)
	{
		throw runtime_error("В группе имеются несколько людей с индентичными данными");
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
		throw runtime_error("Студент с указанными данными не найден.");
	}

	if (countOfSimillarStudents > 1)
	{
		throw runtime_error("В группе имеются несколько людей с идентичными данными");
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

	throw runtime_error("Студент с указанными данными не найден.");
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

