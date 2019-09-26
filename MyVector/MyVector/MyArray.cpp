#pragma once
#include "MyArray.h"
#include "Container.h"
#include <cassert>
#include <iostream>



MyArray::MyArray()
{
	ar = nullptr;
	size = 0;
}

MyArray::MyArray(int n)
{
	size = n;
	ar = new int[size];
	for (int i = 0; i < size; ++i) 
	{
		ar[i] = 0;
	}
}

MyArray::MyArray(const MyArray& ar)
{
	size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < size; ++i)
	{
		this->ar[i] = ar.ar[i];
	}
}

int MyArray::getSize() const
{
	return size;
}

int MyArray::getCapacity() const
{
	return size;
}

void MyArray::show() const
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << ar[i] << " ";
	}
}

void MyArray::addCapacity(int n)
{
	size += n;

	int* _ar = new int[size] {0};

	for (int i = 0; i < size - n; ++i) 
	{

		_ar[i] = this->ar[i];

	}

	//ar = _ar;

	delete[] this->ar;
	this->ar = new int[size];
	for (int i = 0; i < size; ++i)
	{
		this->ar[i] = _ar[i];
	}

	for (int i = size - n; i < size; ++i) 
	{

		_ar[i] = 0;

	}

}

int& MyArray::operator[](int index)
{
	return ar[index];
}

MyArray& MyArray::operator=(const MyArray& ar)
{
	if (this == &ar)
		return *this;
	size = ar.size;
	delete[] this->ar;
	this->ar = new int[size];
	for (int i = 0; i < size; ++i) 
	{
		this->ar[i] = ar.ar[i];
	}
	return *this;
}

MyArray::~MyArray()
{
	std::cout << "myarray\n";
	delete[] ar;
}