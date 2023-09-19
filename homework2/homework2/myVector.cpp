


#include "stdafx.h"


my3mVector::my3mVector()
{
	numbers[0] = numbers[1] = numbers[2] = 0;
	length = 0.0;
}

my3mVector::my3mVector(int n1, int n2, int n3)
{
	numbers[0] = n1;
	numbers[1] = n2;
	numbers[2] = n3;
	countLength();
}

my3mVector my3mVector::operator+(const my3mVector& other)
{
	my3mVector result(numbers[0] + other.numbers[0], numbers[1] + other.numbers[1], numbers[2] + other.numbers[2]);
	return result;
}

my3mVector my3mVector::operator-(const my3mVector& other)
{
	my3mVector result(numbers[0] - other.numbers[0], numbers[1] - other.numbers[1], numbers[2] - other.numbers[2]);
	return result;
}
 
long my3mVector::operator*(const my3mVector& other)
{
	return this->numbers[0]*other.numbers[0] + this->numbers[1] * other.numbers[1] + this->numbers[2] * other.numbers[2];
}

void my3mVector::countLength()
{
	length = sqrt(pow(numbers[0], 2) + pow(numbers[1], 2) + pow(numbers[2], 2));
}

my3mVector& my3mVector::operator=(const my3mVector& other)
{
	if (this == &other) { return *this; }
	for (int i = 0; i < 3; ++i){ this->numbers[i] = other.numbers[i]; }
	countLength();
	return *this;
}

float my3mVector::vectorCos(const my3mVector& other)
{
	return acos((*this * other) / (this->length * other.length)) * 180 / M_PI;
}

void my3mVector::printVector()
{
	int i = 0;
	while (i < 3) { cout << numbers[i] << " "; ++i; }
}

void my3mVector::printLength()
{
	cout << length;
}

std::ostream& operator<<(std::ostream& stream, const my3mVector& vec)
{
	stream << "numbers: ";
	for (int i = 0; i < 3; i++) {
		stream << vec.numbers[i];
		if (i != 2) {
			stream << ", ";
		}
	}
	return stream;
}

