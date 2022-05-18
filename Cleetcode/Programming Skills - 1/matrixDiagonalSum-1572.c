// Runtime: 16 ms, faster than 90.50% of C online submissions
// Memory Usage: 6.7 MB, less than 60.34% of C online submissions

int diagonalSum(int** mat, int matSize, int* matColSize){
    int total = 0;

    for (int i = 0; i < matSize; i++)
        total += mat[i][i] + mat[i][matSize - i - 1];
    
    // if matSize % 2 != 0
    if (matSize & 1) total -= mat[matSize / 2][matSize / 2];
    
    return (total);
}