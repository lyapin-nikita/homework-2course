#pragma once

#include "stdafx.h"

//Дописать реализацию операторов


template <typename obj>
class myVector
{
private:
	uint16_t size;
	obj* vec;
public:
	myVector();
	myVector(uint16_t size);
	myVector(const myVector <obj>& other);
	myVector <obj> operator+ (const myVector <obj> other);
	myVector <obj> operator- (const myVector <obj>& other);
	double operator* (const myVector <obj>& other);S
	double countLength();
	bool operator==(const myVector <obj>& other);
	bool operator!=(const myVector <obj>& other);
	myVector <obj> operator= (const myVector <obj>& other);
	~myVector();
	friend std::istream& operator>>(std::istream& in, myVector<obj> vec);
	friend std::ostream& operator<<(std::ostream& out, const myVector<obj> vec);
};

template<typename obj>
inline myVector<obj>::myVector()
{
	this->size = 0;
	this->vec = nullptr;
}

template<typename obj>
inline myVector<obj>::myVector(uint16_t size)
{
	this->size = size;
	vec = new obj[size];
	for (uint16_t i = 0; i < size; ++i) { vec[i] = NULL; }
}

template<typename obj>
inline myVector<obj>::myVector(const myVector<obj>& other)
{
	this->size = size;
	vec = new obj[size];
	for (uint16_t i = 0; i < size; ++i) { vec[i] = other.vec[i]; }
}

template<typename obj>
inline myVector<obj> myVector<obj>::operator+(const myVector<obj> other)
{
	if (this->size != other.size) { throw -1; }
	myVector <obj> result(this->size);
	for (uint16_t i = 0; i < this->size; ++i) { result.vec[i] = other.size[i] + this->vec[i]; }
	return result;
}

template<typename obj>
inline myVector<obj>::~myVector()
{
	delete[] vec;
}
