#include <iostream>
#include "Ellipse.h"

int main()
{
	const int colorsCount = 5;//инициализираме колко цветове ще са възможни

	//създаваме масива с възможни цветове
	char** colors = new char* [colorsCount] { new char[6]{ "Green" }, new char[5]{ "Blue" }, new char[6]{ "White" }, new char[6]{ "Black" }};

	const int maxXSize = 100;    //дефинираме границите на координатната система
	const int maxYSize = 100;
	const int maxRadiusSize = 15;

	const int ellipsesCount = 10;//дефинираме броя на елипсите


	Ellipse** ellipses = new Ellipse * [ellipsesCount];//създаваме масив от елипси


	for (int i = 0; i < ellipsesCount; i++)
	{
		int xCenterCoordinate = rand() % maxXSize;
		int yCenterCoordinate = rand() % maxYSize;

		double bigAxis = rand() % maxRadiusSize + 5;//добавяме 5 отгоре, за имаме и по-малки числа
		double smallAxis = 1;
		do
		{
			smallAxis = rand() % maxRadiusSize + 1;//добавяме 1, за да избегнем нули;
		} while (bigAxis <= smallAxis);

		char* color = colors[rand() % colorsCount];//задаваме цвят

		ellipses[i] = new Ellipse(xCenterCoordinate, yCenterCoordinate, "Name " + to_string(i), bigAxis, smallAxis, color);//създаваме елипсите
	}


	for (int i = 0; i < ellipsesCount; i++)//използвайки предефенирания оператор "<<" визуализираме всички елипси
	{
		cout << "ID " << i + 1 << ": " << *(ellipses[i]) << endl;
	}


	int input;//потребителски избор

	do
	{
		cout << "Choose the ID of one of the ellipses." << endl;
		cout << "ID of ellipse (0 to exit): ";
		cin >> input;
		if (input == 0){ break; }
		Ellipse* ellipse = ellipses[input - 1];//избираме елипсата, избрана от потребителя
		cout << "Choosen elipse: " << *(ellipse) << endl;

		double x;
		double y;
		do//цикъл за въвеждане на потребителската точка
		{
			cout << "Choose x-coordinate x[0, 99]: ";
			cin >> x;
		} while (x < 0 || x > 99);
		do
		{
			cout << "Choose y-coordinate y[0, 99]: ";
			cin >> y;
		} while (y < 0 || y > 99);

		Coordinates* coords = new Coordinates(x, y, "Point");//създаваме точката
		double distance = ellipse->GetDistanceToCenter(coords);//пресмятаме разстоянието
		delete coords;//изтриваме на точката координатите

		// izpisvame razstoqnieto
		cout << "The distance is: " << distance << endl;

	} while (input != 0);

	for (int i = 0; i < ellipsesCount; i++)//добра практика е да се освобождава паметта след като сме приключили
	{
		delete ellipses[i];
	}

	delete[] ellipses;

	return 0;
}