#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

bool    isVisited(struct Node *root, struct Node **visited)
{
	bool flag = 0;
	for (int i = 0; visited[i]; i++)
		if (visited[i] == root)
			flag = 1;
	
	return (flag);
}

void    addVisited(struct Node *root, struct Node **visited, int *count)
{
	if (!isVisited(root, visited))
	{
		visited[*count] = root;
		(*count)++;
	}
}

void    dfsUtil(struct Node *root, struct Node **visited, int *count, int *result)
{
	addVisited(root, visited, count);
	
	result[(*count) - 1] = root->val;
		
	for (int i = 0; i < root->numChildren; i++)
		if (!isVisited(root->children[i], visited))
			dfsUtil(root->children[i], visited, count, result);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
	int *result = (int *)calloc(10000, sizeof(int));
	int *count = (int *)calloc(1, sizeof(int));
	struct Node **visited = (struct Node **)calloc(10000, sizeof(struct Node*));
	
	*returnSize = 0;
	if (root != NULL)
		dfsUtil(root, visited, returnSize, result);

	return (result);
}