//task1 реализовать функцию которая заменяет все эелменты больше десяти на их квадратный корень
//task2 реализовать функцию которая меняет местами половины массива
//task3 реализовать функцию которая избавляется от повторов в массиве

#include "functions_task2.h"


void main()
{
	uint16_t size = createEvenSize();
	float* mas = createMas(size);
	printMas(mas, size);
	func(mas, size);
	printMas(mas, size);
}