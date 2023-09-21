#include <stdio.h>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Vector.h"

int main()
{
	try
	{
		Circle circle_1(1, 1, 3);
		Square square_1(1, 1, 3);

		printf(" Circle area: %f ", circle_1.calcArea());
		printf(" Circle length: %f ", circle_1.calcLength());
		printf("\n");
		printf(" Square area: %f ", square_1.calcArea());
		printf(" Square length: %f ", square_1.calcLength());
		printf("\n");

		Shape* figures[10];
		
		for (int i = 0; i < 5; i += 2)
		{
			figures[i] = new Circle(1, 1, 2 + i);
			figures[i + 1] = new Square(1, 1, 4 + i);
		}

		for (int i = 0; i < 5; i += 2)
		{
			figures[i]->printShape();
			figures[i + 1]->printShape();
			printf("\n");
		}


		Vector v;

		v[0] = new Circle(1, 1, 5);
		v[1] = new Square(1, 1, 5);
		printf("\n");
		v[0]->printShape();
		v[1]->printShape();
		printf("\n");
	}

	catch (Circle::NegativRadius)
	{
		printf("Radius of circle can`t be negativ!");
		return 0;
	}

	catch (Square::NegativStorona)
	{
		printf("Storona of square can`t be negativ!");
		return 0;
	}
	return 0;
}