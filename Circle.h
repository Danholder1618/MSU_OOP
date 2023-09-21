#pragma once

#include <stdio.h>
#include "Shape.h"


static const float pi = 3.14159265;

class Circle: public Shape
{
private:
	float radius;
public:
	float calcArea() override;
	float calcLength() override;
	void printShape() override;

	class NegativRadius : public NegativValue {};

	void* operator new(size_t size);
	void operator delete(void* pointer, size_t size);
	
	Circle(int x, int y, float radius) : Shape(x,y), radius(radius)
	{
		if (radius < 0) throw NegativRadius();
		this->radius = radius;
	}
};
