#pragma once

#include <stdio.h>
#include "Shape.h"

class Vector
{
private:
	Shape* arr[100];
public:
	Shape*& operator[] (int index)
	{
		return arr[index];
	}
};