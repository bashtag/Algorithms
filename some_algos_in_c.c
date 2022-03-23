#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// the sum of two terms must be equal to target
// return this two indeces
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
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

bool isPalindrome(int x)
{
	if (x < 0)
		return (false);

	char *num = (char *)calloc(11, sizeof(char));
	// num = itoa(x, 10);
	int len = strlen(num);

	for (int i = 0; i < len; i++)
		if (num[i] != num[len - i - 1])
			return (false);
	return (true);
}

//

// time limit exceeded
int tl_minDominoRotations(int *tops, int topsSize, int *bottoms, int bottomsSize)
{
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

	if (!flag)
		return (-1);

	for (i = 0; i < topsSize; i++)
	{
		if (tops[i] == search && bottoms[i] != search)
			c_top++;

		if (tops[i] != search && bottoms[i] == search)
			c_bottom++;
	}

	if (c_top < c_bottom)
		return (c_top);
	else
		return (c_bottom);
}

int minDominoRotations(int *tops, int topsSize, int *bottoms, int bottomsSize)
{
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
			else if (tops[i] != search && bottoms[i] != search)
			{
				c_top = 0;
				c_bottom = 0;
				break;
			}

			if (i == topsSize - 1)
			{
				if (c_top < c_bottom)
					return (c_top);
				else
					return (c_bottom);
			}
		}
	}
	return (-1);
}

// roman to the integer value
int romanToInt(char *s)
{
	int counter = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i + 1] && s[i] == 'I' && s[i + 1] == 'V')
		{
			counter += 4;
			i++;
		}
		else if (s[i + 1] && s[i] == 'I' && s[i + 1] == 'X')
		{
			counter += 9;
			i++;
		}
		else if (s[i + 1] && s[i] == 'X' && s[i + 1] == 'L')
		{
			counter += 40;
			i++;
		}
		else if (s[i + 1] && s[i] == 'X' && s[i + 1] == 'C')
		{
			counter += 90;
			i++;
		}
		else if (s[i + 1] && s[i] == 'C' && s[i + 1] == 'D')
		{
			counter += 400;
			i++;
		}
		else if (s[i + 1] && s[i] == 'C' && s[i + 1] == 'M')
		{
			counter += 900;
			i++;
		}
		else if (s[i] == 'I')
			counter++;
		else if (s[i] == 'V')
			counter += 5;
		else if (s[i] == 'X')
			counter += 10;
		else if (s[i] == 'L')
			counter += 50;
		else if (s[i] == 'C')
			counter += 100;
		else if (s[i] == 'D')
			counter += 500;
		else if (s[i] == 'M')
			counter += 1000;
	}
	return (counter);
}

// char *first_partition(char *s, int *remainder)
// {

// }

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* partitionLabels(char * s, int* returnSize){

// }

// sumOfDivided codewars problem.
int nextPrime(int prime)
{
	bool isPrime = true;
	int buf = prime;
	while (isPrime == false || buf == prime)
	{
		isPrime = true;
		prime++;
		for (int i = 2; i < prime; i++)
		{
			if (prime % i == 0)
			{
				isPrime = false;
			}
		}
	}
	return (prime);
}

void create_sum(char *result, int prime, int term)
{
	char *p_buff = (char *)calloc(25, sizeof(char));
	char *t_buff = (char *)calloc(25, sizeof(char));
	sprintf(p_buff, "%d", prime);
	sprintf(t_buff, "%d", term);
	strcat(result, "(");
	strcat(result, p_buff);
	strcat(result, " ");
	strcat(result, t_buff);
	strcat(result, ")");
}

char *sumOfDivided(int *lst, int l)
{
	int prime = 2;
	int total;
	int max = lst[0];
	bool flag = false;

	for (int i = 0; i < l; i++)
		if (max < lst[i])
			max = lst[i];

	char *result = (char *)calloc(256 * 256 * 256, sizeof(char));
	while (prime <= max)
	{
		flag = false;
		total = 0;
		for (int i = 0; i < l; i++)
		{
			if (lst[i] % prime == 0)
			{
				total += lst[i];
				flag = true;
			}
		}
		if (flag)
			create_sum(result, prime, total);
		prime = nextPrime(prime);
	}
	return result;
}

// odd counter in this range
int countOdds(int low, int high)
{
	bool isHighOdd = false;
	bool isLowOdd = false;
	int counter = 0;

	if (high % 2 == 1)
		isHighOdd = true;
	if (low % 2 == 1)
	{
		isLowOdd = true;
		counter++;
	}
	if ((high - low) % 2 == 0)
		counter += (high - low) / 2;
	else if (isHighOdd)
		counter += (high - low + 1) / 2;
	else
		counter += (high - low - 1) / 2;
	return (counter);
}

// Number of 1 bits
int hammingWeight(unsigned int n)
{ // u_int_32
	int counter = 0;
	while (n)
	{
		if (n % 2 == 1)
			counter++;
		n /= 2;
	}
	return (counter);
}

// faster code than previous
int faster_hammingWeight(unsigned int n)
{ // u_int_32
	int w = 0;
	while (n != 0)
	{
		w += n & 0b1;
		n >>= 1;
	}
	return w;
}

int subtractProductAndSum(int n)
{
	// char *number = (char *)calloc(7, sizeof(char));
	// sprintf(number, "%d", n);
	int total = 0;
	int product = 1;

	while (n)
	{
		total += n % 10;
		product *= n % 10;
		n /= 10;
	}
	return (product - total);
}

// It worked. But it was slow
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

int largestPerimeter(int *nums, int numsSize)
{
	insertionSort(nums, numsSize);

	for (int i = numsSize - 3; i >= 0; i--)
	{
		if (nums[i] + nums[i + 1] > nums[i + 2])
			return (nums[i] + nums[i + 1] + nums[i + 2]);
	}
	return (0);
}

// quickSort is very fast for big arrays that contains too many terms.
int comp(const void *a, const void *b)
{
	const int *i = a;
	const int *j = b;
	return *i - *j;
}

int fastest_largestPerimeter(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), comp);
	for (int i = numsSize - 3; i >= 0; i--)
	{
		if (nums[i] + nums[i + 1] > nums[i + 2])
		{
			return nums[i] + nums[i + 1] + nums[i + 2];
		}
	}
	return 0;
}


// the smallest manhatten distance from current location

int nearestValidPoint(int x, int y, int **points, int pointsSize, int *pointsColSize)
{
	int result = 0xffffffff / 2;
	int count, index = 0;
	bool is_there = false;

	for (int i = 0; i < pointsSize; i++)
	{
		if (points[i][0] == x || points[i][1] == y)
		{
			is_there = true;
			count = abs(x - points[i][0]) + abs(y - points[i][1]);
			if (result > count)
			{
				result = count;
				index = i;
			}
		}
	}
	if (!is_there) return (-1);
	return (index);
}

int main(void)
{


	// // main of nearest valid point
	// int arr[5][2] = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
	// int *size;
	// printf("%d\n", nearestValidPoint(3, 4, arr, 5, size));

	// enum bilal {nevsehir=50, nigde='9' + 1, tokat, ankara = nevsehir, istanbul};
	// enum bilal city = 50;
	// printf("%s\n", city);

	// // largest perimeter
	// int nums[10] = {2,2,1};
	// printf("%d\n", fastest_largestPerimeter(nums,3));

	// // subtraction between product and sum of number
	// printf("%d\n", subtractProductAndSum(253));

	// // main of number of 1 bits
	// printf("%d\n", hammingWeight(2));

	// // main of countOdds
	// printf("%d\n", countOdds(21, 22));

	// // main of sumOfDivided;
	// int d1[10] = {15, 30, -45};
	// char *bil = sumOfDivided(d1, 3);
	// printf("result: %s\n", bil);

	// // romanToInt's main
	// printf("%d\n", romanToInt("MCMXCIV"));

	// main of minDominoRotations
	// // tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
	// int tops[6] = {1,2,3,4,6};
	// int bottoms[6] = {6,6,6,6,5};

	// printf("min dom_rot: %d\n", minDominoRotations(tops, 5, bottoms, 5));

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