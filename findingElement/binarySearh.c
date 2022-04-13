#include <stdio.h>

int	binary_search(int *array, int x, int low, int high)
{
	int mid;

	while (low <= high)
	{	
		mid = (high + low) / 2;

		if (array[mid] == x) return (mid);
		else if (array[mid] < x) low = mid + 1;
		else high = mid - 1;
	}

	return (-1);
}