#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include "TorusArr.h"

void RunTorusArr(void)
{
    assert((TORUS_MAJOR_D - TORUS_MINOR_D) % 2 == 0);
    
    int success_calloc = 0;
    TorusArrParameters tor_parameters;

    success_calloc = GenerateTorus(&tor_parameters, TORUS_MAJOR_D, TORUS_MINOR_D);

    if (success_calloc == TORUS_MAJOR_D * TORUS_MAJOR_D)
        ShowTorusArr(&tor_parameters, TORUS_MAJOR_D, TORUS_MINOR_D);
    
    printf("sum = %d\n", SumTorusArr(&tor_parameters, TORUS_MAJOR_D, TORUS_MINOR_D));

    printf("It's save the %.1lf%% of memory!!!\n", 100 * WhyIsTorusArrCool(&tor_parameters, TORUS_MAJOR_D, TORUS_MINOR_D));


    ClearTorus(&tor_parameters, TORUS_MAJOR_D, success_calloc);

    return;
}

int GenerateTorus(TorusArrParameters * tor_parameters, const int major, const int minor)
{
    int success_calloc = 0; // Число успешных calloc()

    for (int l = 0; l < major; l++) // Создаёт двумерный массив с высотами торуса в заданных координатак горизонтального сечения
        for (int j = 0; j < major; j++)
            for (int i = 0; i < (major - minor) / 2; i++)
            {
                double middle = (minor + major) / 4.0;
                double len = pow(sqrt(pow(major / 2.0 - l - 0.5, 2) + pow(major / 2.0 - j - 0.5, 2)) - middle, 2);
                len += pow((major - minor) / 4.0 - i - 0.5, 2);
                len -= pow((major - minor) / 4.0, 2);
                if (len < 0)
                    tor_parameters->arr_size_ptr_ptr[l][j] += 1;
            }

    for (int j = 0; j < major; j++)
    {
        for (int i = 0; i < major; i++)
        {
            tor_parameters->arr_ptr_ptr_ptr[j][i] = NULL;

            if (tor_parameters->arr_size_ptr_ptr[j][i] > 0) // Выделяем память под массив
                tor_parameters->arr_ptr_ptr_ptr[j][i] = (int *)calloc(tor_parameters->arr_size_ptr_ptr[j][i], sizeof(int *));

            if (tor_parameters->arr_ptr_ptr_ptr[j][i] || tor_parameters->arr_size_ptr_ptr[j][i] == 0)
                success_calloc++;
            else
                return success_calloc;
        }
    }

    srand(time(NULL));

    for (int l = 0; l < major; l++) // Заполняем случайными числами [0, 9]
        for (int j = 0; j < major; j++)
            for (int i = 0; i < tor_parameters->arr_size_ptr_ptr[l][j]; i++)
            {
                tor_parameters->arr_ptr_ptr_ptr[l][j][i] = rand() % 10;
            } 

    return success_calloc;
}

void ShowTorus(const TorusArrParameters * tor_parameters, const int major, const int minor)
{
    for (int layer = 0; layer < (major - minor) / 2.0; layer++)
    {
        for (int l = 0; l < major; l++)
        {
            for (int j = 0; j < major; j++) // Выводим на экран модель торуса
                tor_parameters->arr_size_ptr_ptr[l][j] >= abs((int) (major - minor) / 2 - 2 * layer) && tor_parameters->arr_size_ptr_ptr[l][j] != 0 ? printf("[]") : printf("  ");        

            printf("\n");
        }

        printf("\n");
    }

    return;
}

void ClearTorus(const TorusArrParameters * tor_parameters, const int major, const int success_calloc)
{
    int counter_success = 0;

    for (int l = 0; l < major; l++)
        for (int i = 0; i < major && counter_success < success_calloc; i++)
        {
            if (tor_parameters->arr_size_ptr_ptr[l][i] != 0)
            
                free(tor_parameters->arr_ptr_ptr_ptr[l][i]);
        
            counter_success++;
        }

    return;
}

void ShowTorusArr(const TorusArrParameters * tor_parameters, const int major, const int minor)
{
    for (int layer = 0; layer < (major - minor) / 2; layer++)
    {
        for (int l = 0; l < major; l++)
        {
            for (int j = 0; j < major; j++) // Выводим на экран модель торуса
                if (tor_parameters->arr_size_ptr_ptr[l][j] >= abs((int) (major - minor) / 2 - 2 * layer - 1) && tor_parameters->arr_size_ptr_ptr[l][j] != 0)
                {       
                    printf("%2d", tor_parameters->arr_ptr_ptr_ptr[l][j][layer - ((major - minor) / 2 - tor_parameters->arr_size_ptr_ptr[l][j]) / 2]);
                }
                else 
                {
                    printf("  ");     
                }   

            printf("\n");
        }

        printf("\n");
    }

    return;
}

int SumTorusArr(const TorusArrParameters * tor_parameters, const int major, const int minor)
{
    int result =0;

    for (int layer = 0; layer < (major - minor) / 2; layer++)
        for (int l = 0; l < major; l++)
            for (int j = 0; j < major; j++) // Выводим на экран модель торуса
                if (tor_parameters->arr_size_ptr_ptr[l][j] >= abs((int) (major - minor) / 2 - 2 * layer - 1) && tor_parameters->arr_size_ptr_ptr[l][j] != 0)     
                    result += tor_parameters->arr_ptr_ptr_ptr[l][j][layer - ((major - minor) / 2 - tor_parameters->arr_size_ptr_ptr[l][j]) / 2];

    return result;
}

double WhyIsTorusArrCool(const TorusArrParameters * tor_parameters, const int major, const int minor)
{
    size_t sum_1 = 0, sum_2 = 0;

    for (int l = 0; l < major; l++)
        for (int i = 0; i < major; i++)
            sum_1 += tor_parameters->arr_size_ptr_ptr[l][i] * sizeof(int);

    sum_1 += major * major * sizeof(int *);

    sum_2 += major * major * (major - minor) * sizeof(int) / 2;

    return (double) (sum_2 - sum_1) / sum_2;
}