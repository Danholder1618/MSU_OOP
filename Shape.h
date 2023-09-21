#pragma once

#include <stdio.h>

class Shape
{
private:
	int x, y;
public:
	virtual float calcArea() = 0;
	virtual float calcLength() = 0;
	virtual void printShape() = 0;

	class NegativValue {};

	Shape(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};