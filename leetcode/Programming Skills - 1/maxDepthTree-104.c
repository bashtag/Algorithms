#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
	int	val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

void    calculateDepth(struct TreeNode* root, int *result, int *depth)
{
    (*depth)++;
    if (*result < *depth)
        *result = *depth;
    
    if (root->left) calculateDepth(root->left, result, depth);
    if (root->right) calculateDepth(root->right, result, depth);
    (*depth)--;
}

int maxDepth(struct TreeNode* root){
    int *result = (int *)calloc(1, sizeof(int));
    int *depth = (int *)calloc(1, sizeof(int));
    
    if (root) calculateDepth(root, result, depth);
    
    return (*result);
}