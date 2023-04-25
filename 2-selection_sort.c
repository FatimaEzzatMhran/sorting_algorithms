#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 *                  order using the Selection sort algorithm.
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, idx, temp;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = min;
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
