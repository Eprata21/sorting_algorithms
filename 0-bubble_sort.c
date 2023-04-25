#include "sort.h"
void bubble_sort(int *array, size_t size)
{

	size_t j, i, tmp = 0;

	if (size < 2)
		return;
	for (j = 0; j < size; j++)
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1] && array[i + 1])
			{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			print_array(array, size);
			}
		}
}
