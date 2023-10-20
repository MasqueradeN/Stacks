#include <assert.h>

template <class T>

class ArrayA
{
private:
	T* m_array;
	int _maxSize;
	int _numElements;
	int _growSize;

public:
	ArrayA(int size, int growBy = 1) : m_array(NULL), _maxSize(0), _growSize(0), _numElements(0)
	{
		if (size)
		{
			_maxSize = size;
			m_array = new T[_maxSize];
			memset(m_array, 0, sizeof(T) * _maxSize);
			_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~ArrayA()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	virtual void Push(T val)
	{
		assert(m_array != NULL);

		if (search(val) == -1)
		{
			if (_numElements >= _maxSize)
			{
				Expand();
			}

			m_array[_numElements] = val;
			_numElements++;
		}
		else
		{
			return;
		}
	}

	void Pop()
	{
		if (_numElements > 0)
		{
			_numElements--;
		}
	}

	void Remove(int index)
	{
		assert(m_array != NULL);

		if (index >= _maxSize)
		{
			return;
		}

		for (int i = index; i < _maxSize - 1; i++)
		{
			m_array[i] = m_array[i + 1];
		}

		_maxSize--;

		if (_numElements >= _maxSize)
		{
			_numElements = _maxSize - 1;
		}
	}

	virtual T& operator[] (int index)
	{
		return m_array[index];
	}

	bool Expand()
	{
		if (_growSize <= 0)
		{
			return false;
		}

		T* temp = new T[_maxSize + _growSize];
		memcpy(temp, m_array, sizeof(T) * _maxSize);
		delete[] m_array;
		m_array = temp;
		_maxSize += _growSize;
		return true;
	}

	virtual int search(T searchKey)
	{
		if (!m_array)
		{
			return -1;
		}

		int lowerBound = 0;
		int upperBound = _numElements - 1;
		int current = 0;

		while (1)
		{
			current = (lowerBound + upperBound) >> 1;

			if (m_array[current] == searchKey)
			{
				return current;
			}
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}
	}

	void clear()
	{
		-_numElements = 0;
	}

	int getSize()
	{
		return _numElements;
	}

	int getMaxSize()
	{
		return _maxSize;
	}

	int getGrowSize()
	{
		return _growSize;
	}

	void setGrowSize(int val)
	{
		_growSize = val;
	}
};