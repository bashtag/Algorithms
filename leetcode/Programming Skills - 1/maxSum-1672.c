// Runtime: 4 ms, faster than 93.34% of C online submissions
// Memory Usage: 6.4 MB, less than 15% of C online submissions

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize)
{
	int max = 0;

	for (int i = 0; i < accountsSize; i++)
	{
		int wealth = 0;
		for (int j = 0; j < *accountsColSize; j++)
			wealth += accounts[i][j];

		if (max < wealth)
			max = wealth;
	}

	return (max);
}