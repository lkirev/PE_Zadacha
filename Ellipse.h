#pragma once
#include "Coordinates.h"

class Ellipse
{
private:
	Coordinates* CenterCoordinates;//променлива за централната точка на елипсата
	double BigAxis;//инициализация на голямата ос
	double SmallAxis;//инициализация на малката ос
	char* color;// pointer от тип char за цвета по усл.


public:
	Ellipse();
	Ellipse(int xCenter, int yCenter, string name, double bigAxis, double smallAxis, char* color);
	Ellipse(const Ellipse& ellipse);// копиращ конструктор

	virtual ~Ellipse();

	friend ostream& operator<<(ostream& outputStream, const Ellipse& ellipse);//Предефиниране на оператор "<<"

	double GetDistanceToCenter(Coordinates* coords);//Пресмята разстояние от точката, която подадем до центъра


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

