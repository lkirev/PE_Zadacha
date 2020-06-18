#include <iostream>
#include "Ellipse.h"

int main()
{
	const int colorsCount = 5;//�������������� ����� ������� �� �� ��������

	//��������� ������ � �������� �������
	char** colors = new char* [colorsCount] { new char[6]{ "Green" }, new char[5]{ "Blue" }, new char[6]{ "White" }, new char[6]{ "Black" }};

	const int maxXSize = 100;    //���������� ��������� �� ������������� �������
	const int maxYSize = 100;
	const int maxRadiusSize = 15;

	const int ellipsesCount = 10;//���������� ���� �� ��������


	Ellipse** ellipses = new Ellipse * [ellipsesCount];//��������� ����� �� ������


	for (int i = 0; i < ellipsesCount; i++)
	{
		int xCenterCoordinate = rand() % maxXSize;
		int yCenterCoordinate = rand() % maxYSize;

		double bigAxis = rand() % maxRadiusSize + 5;//�������� 5 ������, �� ����� � ��-����� �����
		double smallAxis = 1;
		do
		{
			smallAxis = rand() % maxRadiusSize + 1;//�������� 1, �� �� �������� ����;
		} while (bigAxis <= smallAxis);

		char* color = colors[rand() % colorsCount];//�������� ����

		ellipses[i] = new Ellipse(xCenterCoordinate, yCenterCoordinate, "Name " + to_string(i), bigAxis, smallAxis, color);//��������� ��������
	}


	for (int i = 0; i < ellipsesCount; i++)//����������� �������������� �������� "<<" ������������� ������ ������
	{
		cout << "ID " << i + 1 << ": " << *(ellipses[i]) << endl;
	}


	int input;//������������� �����

	do
	{
		cout << "Choose the ID of one of the ellipses." << endl;
		cout << "ID of ellipse (0 to exit): ";
		cin >> input;
		if (input == 0){ break; }
		Ellipse* ellipse = ellipses[input - 1];//�������� ��������, ������� �� �����������
		cout << "Choosen elipse: " << *(ellipse) << endl;

		double x;
		double y;
		do//����� �� ��������� �� ��������������� �����
		{
			cout << "Choose x-coordinate x[0, 99]: ";
			cin >> x;
		} while (x < 0 || x > 99);
		do
		{
			cout << "Choose y-coordinate y[0, 99]: ";
			cin >> y;
		} while (y < 0 || y > 99);

		Coordinates* coords = new Coordinates(x, y, "Point");//��������� �������
		double distance = ellipse->GetDistanceToCenter(coords);//���������� ������������
		delete coords;//��������� �� ������� ������������

		// izpisvame razstoqnieto
		cout << "The distance is: " << distance << endl;

	} while (input != 0);

	for (int i = 0; i < ellipsesCount; i++)//����� �������� � �� �� ����������� ������� ���� ���� ��� ����������
	{
		delete ellipses[i];
	}

	delete[] ellipses;

	return 0;
}