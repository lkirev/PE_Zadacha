#include "Ellipse.h"
#include <iostream>

using namespace std;


Ellipse::Ellipse()//default ����������� � default ���������
{
	this->SetCenterCoordinates(new Coordinates(0, 0, "Default"));
	this->SetBigAxis(0);
	this->SetSmallAxis(0);
	this->SetColor(new char[8]{ "Default" });
}


Ellipse::Ellipse(int xCenter, int yCenter, string name, double bigAxis, double smallAxis, char* color)//������ ����������� � ������ ����-����������
{
	this->SetCenterCoordinates(new Coordinates(xCenter, yCenter, name));
	this->SetBigAxis(bigAxis);
	this->SetSmallAxis(smallAxis);
	this->SetColor(color);
}

Ellipse::Ellipse(const Ellipse& ellipse)//������� �����������
{
	this->SetCenterCoordinates(new Coordinates(ellipse.CenterCoordinates->GetX(), ellipse.CenterCoordinates->GetY(), ellipse.CenterCoordinates->GetName()));
	this->SetBigAxis(ellipse.BigAxis);
	this->SetSmallAxis(ellipse.SmallAxis);
	this->SetColor(ellipse.color);
}

Ellipse::~Ellipse()//��������� �� heap ������� ����� �� ����������� ���������� � ������ �� �������
{
	delete this->CenterCoordinates;
	delete[] this->color;
}

double Ellipse::GetDistanceToCenter(Coordinates* coords)//���������� ������������ �� ������� �� �������� �����
{
	double xOffset = abs(this->GetCenterCoordinates()->GetX() - coords->GetX());
	double yOffset = abs(this->GetCenterCoordinates()->GetY() - coords->GetY());

	double distance = sqrt((xOffset * xOffset) + (yOffset * yOffset));//�������� ������������ � ������������ ������� c^2=a^2+b^2
	return distance;
}


ostream& operator<<(ostream& outputStream, const Ellipse& ellipse)//������������� �� << �� �������; �� �� ����������� ��������
{
	outputStream << "X axis: " << ellipse.CenterCoordinates->GetX() << " ";
	outputStream << "Y axis: " << ellipse.CenterCoordinates->GetY() << " ";
	outputStream << "Name of coordinates: " << ellipse.CenterCoordinates->GetName() << " ";
	outputStream << "Big Axis: " << ellipse.BigAxis << " ";
	outputStream << "Small Axis: " << ellipse.SmallAxis << " ";
	outputStream << "Color: " << ellipse.color << " ";

	return outputStream;
}

// Getters and Setters
Coordinates* Ellipse::GetCenterCoordinates()
{
	return this->CenterCoordinates;
}

double Ellipse::GetBigAxis()
{
	return this->BigAxis;
}

double Ellipse::GetSmallAxis()
{
	return this->SmallAxis;
}

char* Ellipse::GetColor()
{
	return this->color;
}

void Ellipse::SetCenterCoordinates(Coordinates* coords)
{
	this->CenterCoordinates = coords;
}

void Ellipse::SetBigAxis(double newAxis)
{
	this->BigAxis = newAxis;
}

void Ellipse::SetSmallAxis(double newAxis)
{
	this->SmallAxis = newAxis;
}

void Ellipse::SetColor(char* newColor)
{
	// Copira imeto za cveta
	int size = sizeof(newColor);
	this->color = new char[size];
	strcpy_s(this->color, size, newColor);
}