#pragma once



#include <iostream>
using namespace std;



uint16_t createSize();
int* createMas(uint16_t size);
void printMas(int* mas, uint16_t size);
int unique(int* mas, uint16_t size);
int* func(int* nums, int size, int& newSize);
