#include "students_group.h"

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

void studentsGroup::addStudent()
{
	
}
