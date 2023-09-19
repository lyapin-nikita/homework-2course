#pragma once



class my3mVector
{
private:
	int numbers[3];
	float length;



public:
	my3mVector();
	my3mVector(int n1, int n2, int n3);


	void printVector();
	void printLength();
	float vectorCos(const my3mVector& other);


	my3mVector operator+(const my3mVector& other);
	my3mVector operator-(const my3mVector& other);
	my3mVector& operator=(const my3mVector& other);
	long operator*(const my3mVector& other); 

private:
	void countLength();
};
