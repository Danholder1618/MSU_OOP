#include <stdio.h>
#include <malloc.h>
#include "Circle.h"

float Circle::calcArea()
{
	return pi * radius * radius;
}

float Circle::calcLength() 
{
	return 2 * pi * radius;
}

void Circle::printShape()
{
	printf("radius = %f ", radius);
}

template <class T>
class memoryManager
{
private:
	T** arr;
public:
	int unavailableSize = 0;
	T* giveMemory(size_t size)
	{
		return arr[unavailableSize++];
	}
	void clearMemory(void* pointer, size_t size)
	{
		for (int i = 0; i < unavailableSize; i++)
		{
			if (arr[i] == pointer)
			{
				for (int j = i; j < unavailableSize - 1; j++)
				{
					arr[j] = arr[j + 1];
				}
				unavailableSize--;
				return;
			}
		}
	}
	memoryManager()
	{
		arr = (T**)malloc(1024 * sizeof(T*));
		for (int i = 0; i < 1024; i++)
		{
			arr[i] = (T*)malloc(sizeof(T));
		}
	}
};

memoryManager<Circle> m;

void* Circle::operator new(size_t size)
{
	return m.giveMemory(size);
}

void Circle::operator delete(void* pointer, size_t size)
{
	m.clearMemory(pointer, size);
}