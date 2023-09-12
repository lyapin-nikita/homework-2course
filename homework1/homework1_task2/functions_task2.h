#pragma once



#include <iostream>
using namespace std;



uint16_t createEvenSize();
float* createMas(uint16_t size);
void printMas(float* mas, uint16_t size);
void replaceMas(float* mas, int ind1, int ind2);
void func(float* mas, uint16_t size);