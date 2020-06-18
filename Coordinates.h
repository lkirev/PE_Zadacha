#pragma once
#include "string"

using namespace std;

class Coordinates // Създаваме клас, който ще дефинира координатите
{
private:
	double x;
	double y;//двете точки, които ще бъдат двуизмерни координати. Избран е float заради размера му, въпреки по-голямата неточност
	string name;////име на координатата

public:

	Coordinates();//default constructor
	Coordinates(double x, double y, string name);//попълнен конструктор
	virtual ~Coordinates();//деструктор

	// Getters and Setters
	double GetX();
	double GetY();
	string GetName();

	void SetX(double newVal);
	void SetY(double newVal);
	void SetName(string newName);

};

