
// if we see a small value then we carry that value at the beginning of the array
void insertionSort(int *nums, int numsSize)
{
	int key, j;

	for (int i = 1; i < numsSize; i++)
	{
		key = nums[i];
		j = i - 1;

		while (j >= 0 && nums[j] > key)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}
}