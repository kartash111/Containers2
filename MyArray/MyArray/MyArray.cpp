#pragma once
#include "Container.h"
#include "MyArray.h"
#include <cassert>
#include <iostream>


MyArray::MyArray() //����������� �� ���������
{
	ar = nullptr;
}

MyArray::MyArray(int n) //������ ������ ����� �� n-���������
{
	size = n;
	ar = new int[size];
	for (int i = 0; i < size; ++i) ar[i] = 0;

}

MyArray::MyArray(const MyArray& ar) //����������� �����������
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
	std::cout << "������� ���������� ��������� � ����������:" << std::endl;
	return size;
}

int MyArray::getCapacity() const
{
	std::cout << "������������ ���������� ��������� � ����������:" << std::endl;
	return size;
}

void MyArray::show() const
{
	std::cout << std::endl << "�������� � ����������:" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << this->ar[i] << " ";
		if ((i > 0) && ((i + 1) % 5) == 0) std::cout << std::endl; // ����� ���������� �� 5 � �������
	}
}

void MyArray::addCapacity(int n) //����������� ������ �������
{
	size = size + n;

	int* _ar = new int[size];

	for (int i = 0; i < size - n; ++i) {

		_ar[i] = this->ar[i];

	}

	ar = _ar;

	for (int i = size - n; i < size; ++i) {

		_ar[i] = 0;

	}

}

int& MyArray::operator[](int index)
{
	return ar[index];
}

MyArray& MyArray::operator=(const MyArray& ar)
{
	if (this == &ar) return *this;
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
	delete[] ar;
}
