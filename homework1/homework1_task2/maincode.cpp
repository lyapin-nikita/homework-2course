//task1 ����������� ������� ������� �������� ��� �������� ������ ������ �� �� ���������� ������
//task2 ����������� ������� ������� ������ ������� �������� �������
//task3 ����������� ������� ������� ����������� �� �������� � �������

#include "functions_task2.h"


void main()
{
	uint16_t size = createEvenSize();
	float* mas = createMas(size);
	printMas(mas, size);
	func(mas, size);
	printMas(mas, size);
}