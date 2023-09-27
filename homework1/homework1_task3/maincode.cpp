



#include "func_task3.h"



void main()
{
	uint16_t size = createSize();
	int* mas = createMas(size);
	printMas(mas, size);
	int newSize = unique(mas, size);
	cout << newSize << endl;
	int* newMas = func(mas, size, newSize);
	printMas(newMas, newSize);


	//int* newMas = func(mas, size, newSize);
	//printMas(newMas, newSize);
}