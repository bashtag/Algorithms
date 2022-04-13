#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
	int *result = (int *)calloc(nums1Size, sizeof(int));
	bool flag = false;

	for (int i = 0; i < nums1Size; i++)
	{
		for (int j = 0; j < nums2Size; j++)
		{
			flag = false;
			if (nums1[i] == nums2[j])
			{
				if (j == nums2Size - 1)
				{
					result[i] = -1;
					break;
				}
				for (int k = j + 1; k < nums2Size; k++)
				{
					if (nums2[j] < nums2[k])
					{
						result[i] = nums2[k];
						flag = true;
						break;
					}
				}
				if (!flag)
					result[i] = -1;
				break;
			}
		}
	}
	*returnSize = nums1Size;
	return (result);
}