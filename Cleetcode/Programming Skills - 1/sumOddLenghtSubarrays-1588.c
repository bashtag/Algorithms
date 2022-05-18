// Runtime: 2 ms, faster than 79.63% of C online submissions for Sum of All Odd Length Subarrays.
// Memory Usage: 6.1 MB, less than 35.19% of C online submissions for Sum of All Odd Length Subarrays.

int sumOddLengthSubarrays(int* arr, int arrSize){
    int total = 0;
    int product;
    
    for (int n = 1; n <= arrSize; n += 2) // odd lenght subarrays
    {
        for (int i = 0; i < arrSize; i++)
        {
            product = n;
            if (i < n - 1) product = i + 1; // left side of the array
            else if (i > arrSize - n) product = arrSize - i; // right side of the array
            
            if (product > arrSize - n + 1) product = arrSize - n + 1; // max value of product
            
            total += product * arr[i];
        }
    }
    return (total);
}