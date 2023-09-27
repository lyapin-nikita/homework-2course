


#include "stdafx.h"
using namespace std;

my3mVector::my3mVector()
{
	numbers[0] = numbers[1] = numbers[2] = 0;
	length = 0.0;
}

my3mVector::my3mVector(float n1, float n2, float n3)
{
	numbers[0] = n1;
	numbers[1] = n2;
	numbers[2] = n3;
	countLength();
}

my3mVector::my3mVector(const my3mVector& vec)
{
	numbers[0] = vec.numbers[0];
	numbers[1] = vec.numbers[1];
	numbers[2] = vec.numbers[2];
	length = vec.length;
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
 
double my3mVector::operator*(my3mVector& other)
{
	return this->numbers[0]*other.numbers[0] + this->numbers[1] * other.numbers[1] + this->numbers[2] * other.numbers[2];
}

void my3mVector::countLength()
{
	length = sqrt(pow(numbers[0], 2) + pow(numbers[1], 2) + pow(numbers[2], 2));
}

float my3mVector::getLength()
{
	return this->length;
}

const my3mVector& my3mVector::operator=(const my3mVector& other)
{
	if (this == &other) { return *this; }
	for (int i = 0; i < 3; ++i){ this->numbers[i] = other.numbers[i]; }
	countLength();
	return *this;
}

float my3mVector::vectorCos(my3mVector& other)
{
	if (this->length == 0 || other.length == 0) { throw - 5; }
	return ((*this * other) / (this->length * other.length));
}

std::ostream& operator<<(std::ostream& stream, const my3mVector& vec)
{
	stream << "vector: " << endl;
	for (int i = 0; i < 3; i++)
	{
		stream << vec.numbers[i];
		if (i != 2)
		{
			stream << ", ";
		}
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, my3mVector& vec)
{
	stream >> vec.numbers[0];
	stream >> vec.numbers[1];
	stream >> vec.numbers[2];
	vec.countLength();
	return stream;
}

