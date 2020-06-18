#pragma once
#include "Coordinates.h"

class Ellipse
{
private:
	Coordinates* CenterCoordinates;//���������� �� ����������� ����� �� ��������
	double BigAxis;//������������� �� �������� ��
	double SmallAxis;//������������� �� ������� ��
	char* color;// pointer �� ��� char �� ����� �� ���.


public:
	Ellipse();
	Ellipse(int xCenter, int yCenter, string name, double bigAxis, double smallAxis, char* color);
	Ellipse(const Ellipse& ellipse);// ������� �����������

	virtual ~Ellipse();

	friend ostream& operator<<(ostream& outputStream, const Ellipse& ellipse);//������������� �� �������� "<<"

	double GetDistanceToCenter(Coordinates* coords);//�������� ���������� �� �������, ����� ������� �� �������


	// Getters and Setters
	Coordinates* GetCenterCoordinates();
	double GetBigAxis();
	double GetSmallAxis();
	char* GetColor();

	void SetCenterCoordinates(Coordinates* coords);
	void SetBigAxis(double newAxis);
	void SetSmallAxis(double newAxis);
	void SetColor(char* newColor);
};

