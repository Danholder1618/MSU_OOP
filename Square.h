#pragma once

#include <stdio.h>
#include "Shape.h"


class Square : public Shape
{
private:
	float storona;
public:
	float calcArea() override;
	float calcLength() override;
	void printShape() override;

	class NegativStorona : public NegativValue {};
	
	void* operator new(size_t size);
	void operator delete(void* pointer, size_t size);

	Square(int x, int y, float storona) : Shape(x, y), storona(storona)
	{
		if (storona < 0) throw NegativStorona();
		this->storona = storona;
	}
};
