#include "IntArray.h"
IntArray::IntArray()
{
	array.push_back(13);
	array.push_back(14);
	array.push_back(15);
}

void IntArray::display() const
{
	for (int i = 0; i < array.size(); i++)
		cout << '\t' << array[i] << "\n";
}

void IntArray::displayIndex(int index)
{
	if (index < 0 || index > array.size() - 1)
		throw IndexOutOfRange();
	else
		cout << "\n\tNumber at index " << index << ": " << array[index] << "\n";
}

