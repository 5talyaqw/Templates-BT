/*#include "BSNode.hpp"
#include <iostream>

template <typename T>
void printArray(const T arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int i;
	int arr[15] = { 12, 5, 8, 15, 1, 7, 13, 9, 4, 11, 3, 10, 2, 14, 6 };
	std::string strArr[15] = { "bana", "adwq", "vcqwk", "the", "yj", "few", "jrt", "jt", "yu", "ca", "vea", "jnrt", "be", "k7", "fw" };

	//creating bst
	BSNode<int> intTree(arr[0]);
	BSNode<std::string> strTree(strArr[0]);

	//adding values
	for (i = 1; i < 15; i++)
	{
		intTree.insert(arr[i]);
	}

	for ( i = 1; i < 15; i++)
	{
		strTree.insert(strArr[i]);
	}
	//printing values

	std::cout << "\nSorted int array: ";
	intTree.printNodes();
	std::cout << std::endl;

	std::cout << "Sorted string array: ";
	strTree.printNodes();
	std::cout << std::endl;

	return 0;
}
*/