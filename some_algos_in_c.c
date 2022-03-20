#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// the sum of two terms must be equal to target
// return this two indeces
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *result = (int *)malloc(2 * sizeof(int));
	int flag = 1;
	
	*returnSize = 2;
	for (int i = 0; i < numsSize && flag; i++)
	{
		for (int j = i + 1; j < numsSize && flag; j++)
		{
			if (nums[i] + nums[j] == target) 
			{
				result[0] = i;
				result[1] = j;
				flag = 0;
			}
		}
	}
	return result;
}

//

// char* itoa(int val, int base){
// 	static char buf[32] = {0};
// 	int i = 30;
// 	for(; val && i ; --i, val /= base)
// 		buf[i] = "0123456789abcdef"[val % base];
// 	return &buf[i+1];	
// }

bool isPalindrome(int x){
	if (x < 0) return (false);
	
	char *num = (char *)calloc(11, sizeof(char));
	// num = itoa(x, 10);
	int len = strlen(num);

	for (int i = 0; i < len; i++)
		if (num[i] != num[len -i -1]) return (false);
	return (true);
}


//	

// time limit exceeded
int tl_minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
	int i, buf = 0;
	int search = 0;
	int c_top = 0;
	int c_bottom = 0;
	bool flag = false;

	for (i = 0; i < topsSize; i++)
	{
		buf = tops[i];
		for (int j = 0; j < topsSize; j++)
		{
			if (tops[j] != buf && bottoms[j] != buf)
				break;
			if (j == topsSize - 1)
			{
				search = buf;
				flag = true;
			}
		}
	}

	if (!flag) return (-1);

	for (i = 0; i < topsSize; i++)
	{
		if (tops[i] == search && bottoms[i] != search)
			c_top++;

		if (tops[i] != search && bottoms[i] == search)
			c_bottom++;
	}

	if (c_top < c_bottom) return (c_top);
	else return (c_bottom);
}

int	minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
	int c_top = 0;
	int c_bottom = 0;
	int search = 0;

	for (int j = 0; j < topsSize; j++)
	{
		search = tops[j];
		for (int i = 0; i < topsSize; i++)
		{
			if (tops[i] == search && bottoms[i] != search)
				c_top++;
			else if (tops[i] != search && bottoms[i] == search)
				c_bottom++;
			else if (i == topsSize - 1)
			{		
				if (c_top < c_bottom) return (c_top);
				else return (c_bottom);
			}
			else if (tops[i] != search && bottoms[i] != search)
			{
				c_top = 0;
				c_bottom = 0;
				break;
			}
		}
	}
	return (-1);
}

// roman to integer value
int romanToInt(char * s){
	return (0);
}

int main(void)
{
	// tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
	int tops[6] = {1,2,3,4,6};
	int bottoms[6] = {6,6,6,6,5};

	printf("min dom_rot: %d\n", minDominoRotations(tops, 6, bottoms, 6));

	// main of isPalindrome
	// printf("%d\n", isPalindrome(250));


	// main of twoSums problem

	// int nums[4] = {2, 7, 11, 15};
	// int a;
	// int *rsize = &a;

	// int *result = twoSum(nums, 4, 9, rsize);
	// for (int i = 0; i < 2; i++)
	// {
	//     printf("%d\n", result[i]);
	// }
	return (0);
}