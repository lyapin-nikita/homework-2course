



#include "functions_task2.h"



uint16_t createEvenSize()
{
	uint16_t size;
	do 
	{
		cout << "enter the size: " << endl;
		cin >> size;
	} while (size % 2 != 0);
	return size;
}

float* createMas(uint16_t size)
{
	float* mas = new float[size];
	cout << "enter the numbers: " << endl;
	for (uint16_t i = 0; i < size; ++i) { cin >> mas[i]; }
	return mas;
}

void printMas(float* mas, uint16_t size)
{
	for (uint16_t i = 0; i < size; ++i) { cout << mas[i] << "   "; }
	cout << endl;
}

void replaceMas(float* mas, int ind1, int ind2)
{
	float tmp = mas[ind1];
	mas[ind1] = mas[ind2];
	mas[ind2] = tmp;
}

void func(float* mas, uint16_t size)
{
	for (uint16_t i = 0; i < size / 2; ++i) { replaceMas(mas, i, size - 1 - i); }
}