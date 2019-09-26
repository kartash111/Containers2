#include "Container.h"

class MyArray : public Container
{
	int* ar;
public:
	MyArray();
	MyArray(int n);								//������� ������ �� n ������� ���������
	MyArray(const MyArray& ar);					//�������� ������ � ����������� �������� ������ ar

	int getSize() const;						//���������� size
	int getCapacity() const;					//���������� size
	void show() const;

	void addCapacity(int n);					// ����������� ����������� ��������� ����������� ���������� �� n (�������) ���������(��� ������ ������)

	int& operator[](int index);					//������ � i-��� ��������
	MyArray& operator=(const MyArray& ar);		//������� ������ �������� �������, �������� ������ ������ � ����������� �������� ������ ar

	~MyArray();
};