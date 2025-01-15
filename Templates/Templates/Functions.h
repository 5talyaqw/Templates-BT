#include <iostream>

template <typename T>
int compare(const T& a, const T& b)
{
	if (a > b)
	{
		return -1;
	}
	else if (a==b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

template <typename T>
void bubbleSort(T arr[], int size)
{
	int i, j;
	T temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (compare(arr[j], arr[j+1]) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void printArray(const T arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}