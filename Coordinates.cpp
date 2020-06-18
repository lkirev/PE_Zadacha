#include "Coordinates.h"

Coordinates::Coordinates() //default �����������
{
	this->SetX(0);
	this->SetY(0);
	this->name = "Default";
}

Coordinates::Coordinates(double x, double y, string name)//����������� � ������ ����-����������
{
	this->SetX(x);
	this->SetY(y);
	this->SetName(name);
}

Coordinates::~Coordinates()//�� ���������� Heap, �� �� ����� ����� �� ����������
{
}

// Getters and Setters
double Coordinates::GetX()
{
	return this->x;
}

double Coordinates::GetY()
{
	return this->y;
}

string Coordinates::GetName()
{
	return this->name;
}

void Coordinates::SetX(double newVal)
{
	this->x = newVal;
}

void Coordinates::SetY(double newVal)
{
	this->y = newVal;
}

void Coordinates::SetName(string newName)
{
	this->name = newName;
}
