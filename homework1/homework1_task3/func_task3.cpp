


#include "func_task3.h"



uint16_t createSize()
{
	uint16_t size;
	cout << "enter the size: " << endl;
	cin >> size;
	return size;
}

int* createMas(uint16_t size)
{
	int* mas = new int[size];
	cout << "enter the numbers: " << endl;
	for (uint16_t i = 0; i < size; ++i) { cin >> mas[i]; }
	return mas;
}

void printMas(int* mas, uint16_t size)
{
	for (uint16_t i = 0; i < size; ++i) { cout << mas[i] << "   "; }
	cout << endl;
}

int unique(int* mas, uint16_t size)
{
    int result(0);
    bool isDublicate(false);
    for (uint16_t i(0); i < size; ++i)
    {
        isDublicate = false;
        for (uint16_t j(0); j < i; ++j)
        {
            if (mas[j] == mas[i]) { isDublicate = true; break; }
        }
        
        if (isDublicate == false) { result++; };
    }
    return result;
}

int* func(int* nums, int size, int& newSize)
{
    int* result = new int[newSize];
    int index(0);
    bool isDublicate(false);
    for (uint16_t i(0); i < size; ++i)
    {
        isDublicate = false;
        for (uint16_t j(0); j < i; ++j)
        {
            if (nums[j] == nums[i]) { isDublicate = true; break; }
        }

        if (isDublicate == false) { result[index] = nums[i]; index++; }
    }
    return result;
}