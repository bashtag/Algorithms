#include <stdlib.h>

// Runtime: 28 ms, faster than 99.23% of C online submissions
// Memory Usage: 10.2 MB, less than 83.08% of C online submissions

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    if (!(r > 0 && c > 0) || !(r * c == matSize * (*matColSize)) ||
       (r == matSize && c == *matColSize))
    {
        *returnSize = matSize;
        *returnColumnSizes = (int *)calloc(matSize, sizeof(int));
        
        for (int m = 0; m < matSize; m++) 
            *(*returnColumnSizes + m) = *matColSize;

        return (mat);
    }

    int **returnMat = (int *)calloc(r, sizeof(int *));
    int i = 0, j = 0;

//  Same loop for two arrays.
    for (int k = 0; k < r; k++)
    {
        returnMat[k] = (int *)calloc(c, sizeof(int));
        for (int l = 0; l < c; l++)
        {
            returnMat[k][l] = mat[i][j];
            if (j < *matColSize - 1) j++;
            else if (i < matSize) // overflow problem is solved
            {
                i++;
                j = 0;
            }
        }
    }
    
    *returnSize = r;
    *returnColumnSizes = (int *)calloc(r, sizeof(int));
    
    for (i = 0; i < r; i++) *(*returnColumnSizes + i) = c;
    
    return (returnMat);
}