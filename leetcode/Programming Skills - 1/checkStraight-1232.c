#include <stdbool.h>

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){

	// check if the tangent of the slope is infinite
    bool flag = true;
    for (int i = 0; i < coordinatesSize; i++)
    {
        if (coordinates[0][0] != coordinates[i][0]) flag = false;
    }
    if (flag) return (true);
    
    // slope must be the same along straight line
	double slope = ((double)coordinates[1][1] - (double)coordinates[0][1]) /
        ((double)coordinates[1][0] - (double)coordinates[0][0]);
    
    for (int i = 2; i < coordinatesSize; i++)
    {
        if (slope != ((double)coordinates[i][1] - (double)coordinates[i - 1][1]) /
        ((double)coordinates[i][0] - (double)coordinates[i - 1][0]))
            return (false);
    }
    
    return (true);
}