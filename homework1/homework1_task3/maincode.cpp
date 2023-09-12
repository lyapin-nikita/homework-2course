



#include "func_task3.h"



void main()
{
	uint16_t size = createSize();
	int* mas = createMas(size);
	printMas(mas, size);
	int newSize;
	int* newMas = func(mas, size, newSize);
	printMas(newMas, newSize);
}