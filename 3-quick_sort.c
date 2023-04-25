#include "sort.h"

void swap(int *i, int *j);
void quick_sort(int *array, size_t size);
void lom_sort(int *array, size_t size, int left, int right);
int lom_partition(int *array, size_t size, int left, int right);

/**
 * swap - swap 2 ints in an array
 * @i: first int
 * @j: second int
 * Return: void
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * lom_partition - Order a subset of an array of ints according to
 *                 the lomuto partition scheme (last element as pivot)
 * @array: array of ints
 * @size: array size
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 * Return: The final partition index
 */
int lom_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lom_sort - Implement the quicksort algorithm through recursion
 * @array: array of ints
 * @size: array size
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 * Description: Uses the Lomuto partition scheme
 */
void lom_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lom_partition(array, size, left, right);
		lom_sort(array, size, left, part - 1);
		lom_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sort an array of ints in ascending
 *              order using the quicksort algorithm
 * @array: array of ints
 * @size: array size
 * Description: Use the Lomuto partition scheme. Print
 *              the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lom_sort(array, size, 0, size - 1);
}

