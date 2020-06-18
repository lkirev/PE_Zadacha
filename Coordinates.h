#pragma once
#include "string"

using namespace std;

class Coordinates // ��������� ����, ����� �� �������� ������������
{
private:
	double x;
	double y;//����� �����, ����� �� ����� ���������� ����������. ������ � float ������ ������� ��, ������� ��-�������� ���������
	string name;////��� �� ������������

public:

	Coordinates();//default constructor
	Coordinates(double x, double y, string name);//�������� �����������
	virtual ~Coordinates();//����������

	// Getters and Setters
	double GetX();
	double GetY();
	string GetName();

	void SetX(double newVal);
	void SetY(double newVal);
	void SetName(string newName);

};

