#pragma once
#include <cassert>
#include <iostream>
#include "MyVector.h"
#include "Container.h"
#include "MyArray.h"

MyVector::MyVector()
{
	capacity = 0;
}

MyVector::MyVector(int n)
{
	assert(n > 0);
	size = n;
	capacity = n;
	this->ar = new int[size];
	for (int i = 0; i < n; ++i)
	{
		this->ar[i] = 0;
	}
}

MyVector::MyVector(int n, int value)
{
	assert(n > 0);
	size = n;
	capacity = n;
	this->ar = new int[size];
	for (int i = 0; i < n; ++i)
	{
		this->ar[i] = value;
	}
}

MyVector::MyVector(const MyVector& vec)
{
	capacity = vec.capacity;
	size = vec.size;
	this->ar = new int[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		this->ar[i] = vec.ar[i];
	}
}

int MyVector::getCapacity() const
{
	return capacity;
}

void MyVector::addCapacity(int n)
{
	assert(n > 0);
	capacity += n;
	int* _ar = new int[capacity] {0};

	for (int i = 0; i < size; ++i)
	{
		_ar[i] = this->ar[i];
	}

	delete[] this->ar;

	this->ar = _ar;

	for (int i = size; i < capacity; ++i)
	{
		_ar[i] = 0;
	}

}

void MyVector::pushBack(int val)
{
	if (size < capacity)
	{
		size +=1;
		ar[size] = val;
	}

	else
	{
		addCapacity(1);
		size +=1;
		ar[size] = val;
	}
}

int MyVector::popBack()
{
	size -= 2;
	return ar[size + 1];
}

void MyVector::insert(int index, int val)
{
	assert(index > 0);
	int t = 0;

	if (index < capacity)
	{
		for (int i = size; i > index; --i)
		{
			ar[size] = ar[size - 1];

		}

		ar[index] = val;
		size += 1;
	}



	else
	{
		addCapacity(index - capacity + 1);

		ar[index] = val;
		size = size + (index - capacity);
	}
}

int MyVector::remove(int index)
{
	for (int i = index; i < size; i++)
	{
		ar[i] = ar[i + 1];
	}
	ar[size] = 0;
	size -=1;

	return ar[index];
}

MyVector& MyVector::operator=(const MyVector& vec)
{
	if (this == &vec) return *this;

	size = vec.size;
	delete[] this->ar;
	this->ar = new int[capacity];
	for (int i = 0; i < size; ++i)
	{
		this->ar[i] = vec.ar[i];
	}

	if (capacity > size)
	{
		for (int i = size; i < capacity; ++i)
		{
			this->ar[i] = 0;
		}
	}

	return *this;
}

MyVector::~MyVector()
{
	std::cout << "myvector\n";
	delete[] ar;
}