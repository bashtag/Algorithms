#include <stdio.h>
#include <stdlib.h>

// not finished yet
int bowling(int **xd, int x, int y, int d, int n)
{
	int result = 0;
	xd = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		xd[i] = calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
			xd[i][j] = 1;
	}

	xd[x][y] = 0;
	if (d == 0)
	{
		result += n * (n - y - 1);
	}
	return result;
}

int main(void)
{
	int n, x, y, d;
	scanf("%d", &n);
	int **map;
	scanf("%d %d", &x, &y);
	scanf("%d", &d);
	
	int result = bowling(map, x, y, d, n);

	return (0);
}