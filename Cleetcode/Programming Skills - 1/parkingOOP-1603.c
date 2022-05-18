#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int big;
    int medium;
    int small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *parkingSystem = (ParkingSystem *)calloc(1, sizeof(ParkingSystem));
    
    parkingSystem->big = big;
    parkingSystem->medium = medium;
    parkingSystem->small = small;
    
    return (parkingSystem);
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (carType == 1 && obj->big != 0)
    {
        obj->big--;
        return (true);
    }
    else if (carType == 2 && obj->medium != 0)
    {
        obj->medium--;
        return (true);
    }
    if (carType == 3 && obj->small != 0)
    {
        obj->small--;
        return (true);
    }
    
    return (false);
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/