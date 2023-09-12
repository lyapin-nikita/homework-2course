


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

int* func(int* nums, int size, int& newSize)
{
    int* result = new int[size];
    int index = 0;

    for (int i = 0; i < size; ++i)
    {
        bool isDuplicate = false;

        for (int j = 0; j < index; ++j)
        {
            if (nums[i] == result[j])
            {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            result[index] = nums[i];
            ++index;
        }
    }

    newSize = index;
    return result;
}