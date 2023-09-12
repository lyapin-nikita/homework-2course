



#include "functions.h"



uint16_t createSize()
{
	uint16_t size;
	cout << "enter the size: " << endl;
	cin >> size;
	return size;
}

float* createMas(uint16_t size)
{
	float* mas = new float[size];
	cout << "enter the numbers: " << endl;
	for (uint16_t i = 0; i < size; ++i) { cin >> mas[i]; }
	printMas(mas, size);
	return mas;
}

void func(float* mas, uint16_t size)
{
	for (uint16_t i = 0; i < size; ++i) { (mas[i] >= 10) ? (mas[i] = pow(mas[i], 2)) : false; }
	printMas(mas, size);
}

void printMas(float* mas, uint16_t size)
{
	for (uint16_t i = 0; i < size; ++i) { cout << mas[i] << "   "; }
	cout << endl;
}
