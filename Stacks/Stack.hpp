#pragma once
#include <iostream>
#include<assert.h>
#include"Array.hpp"

template<typename T>

class Stack
{
private:
	ArrayA<T>* _array;
	int top;
	int _size;
	int GrowSize;

	bool Expand()
	{
		if (GrowSize <= 0)
		{
			return false;
		}
		ArrayA<T>* temp = new ArrayA<T>(_size + GrowSize);
		memcpy(temp, _array, sizeof(ArrayA<T>) * _size);

		delete[] _array;
		_array = temp;
		_size += GrowSize;
		return true;
	}

public:
	Stack(int size, int growBy = 1) : top(-1), _array(0), _size(0),GrowSize(0)
	{
		if (size)
		{
			_size = size;
			_array = new ArrayA<T>(_size);
			GrowSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~Stack()
	{
		delete[] _array;
		_array = NULL;
		top = -1;
		_size = 0;
		GrowSize = 0;
	}

	void Push(ArrayA<T> val)
	{
		assert(_array != NULL);
		if (isFull())
		{
			Expand();
		}

		_array[++top] = val;
	}

	void Pop()
	{
		if (!IsEmpty())
		{
			ArrayA<T> temp = _array[top];
			_array[top] = 0;
			top--;
			_size--;
		}
	}

	const ArrayA<T>* Top()
	{
		assert(_array != NULL);
		assert(top >= 0);

		return &_array[top];
	}

	int IsEmpty()
	{
		return (top == -1);
	}

	int isFull()
	{
		return (top == _size + 1);
	}
};