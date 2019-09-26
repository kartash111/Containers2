#pragma once

class Container
{
protected:
	int size;
public:
	virtual int getSize() const = 0; 			//���������� ���������� ��������� � ����������
	virtual int getCapacity() const = 0;		//���������� ����������� ��������� ���������� ��������� � ����������
	virtual void show() const = 0;				//������� �������� ��������� ���������� � �������, ����� ������

	virtual void addCapacity(int n) = 0;		//����������� ����������� ��������� ����������� ���������� �� n ��������� (��� ������ ������)


	virtual ~Container();					    //����������� ���������� ������
};
