#include <stdio.h>
#include "StandArr.h"
#include "OtherOperations.h"
#include <assert.h>

void RunStandArr(void)
{
    int arr[STAND_ARR_SIZE_Y][STAND_ARR_SIZE_X] = {};

    assert(STAND_ARR_SIZE_X >= 1 && STAND_ARR_SIZE_Y >= 1);

    StandArrFill(arr, STAND_ARR_SIZE_Y, STAND_ARR_SIZE_X);

    StandArrShow(arr, STAND_ARR_SIZE_Y, STAND_ARR_SIZE_X);

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

void StandArrShow(const int arr[][STAND_ARR_SIZE_X], int size_y, int size_x)
{
    int x = 0, y = 0;

    for (; y < size_y; y++)
    {
        for (x = 0; x < size_x; x++)
        {
            printf("%-5d ", arr[y][x]);
        }   

        printf("\n");
    }

    return;
}

int StandArrMin(const int arr[][STAND_ARR_SIZE_X], int size_y, int size_x)
{
    int x = 0, y = 0, min = arr[0][0];

    for (; y < size_y; y++)
    {
        for (x = 0; x < size_x; x++)
        {
            if (arr[y][x] < min)
                min = arr[y][x];
        }   

        printf("\n");
    }

    return min;
}

int StandArrMax(const int arr[][STAND_ARR_SIZE_X], int size_y, int size_x)
{
    int x = 0, y = 0, max = arr[0][0];

    for (; y < size_y; y++)
    {
        for (x = 0; x < size_x; x++)
        {
            if (arr[y][x] > max)
                max = arr[y][x];
        }   

        printf("\n");
    }

    return max;
}