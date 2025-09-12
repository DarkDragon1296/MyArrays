#include <stdio.h>
#include "StandArr.h"
#include "OtherOperations.h"

void RunStandArr(void)
{
    int arr[STAND_ARR_SIZE_Y][STAND_ARR_SIZE_X] = {};

    StandArrFill(arr, STAND_ARR_SIZE_Y, STAND_ARR_SIZE_X);

    printf("%d", arr[1][2]);

    return;
}

void StandArrFill(int arr[][STAND_ARR_SIZE_X], int size_y, int size_x)
{
    int x = 0, y = 0;
    
    for (; y < size_y; y++)
        for (x = 0; x < size_x; x++)
        {
            while (true)
            {
                printf("[%d, %d] : ", y, x);

                int scanf_success = scanf("%d", &(arr[y][x]));

                ClearInput();

                if (scanf_success)
                    break;
            }
        }

    return;
}
