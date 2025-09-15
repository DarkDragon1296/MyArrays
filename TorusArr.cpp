#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "TorusArr.h"

void RunTorusArr(void)
{
    TorusArrParameters tor_parameters;

    GenerateTorus(&tor_parameters, TORUS_MAJOR_D, TORUS_MINOR_D);

    ShowTorus(&tor_parameters, TORUS_MAJOR_D, TORUS_MINOR_D);

    return;
}

void GenerateTorus(TorusArrParameters * tor_parameters, const int major, const int minor)
{

    for (int l = 0; l < major; l++)
        for (int j = 0; j < major; j++)
            for (int i = 0; i < (major - minor) / 2.0; i++)
            {
                double middle = (minor + major) / 4.0;
                double len = pow(sqrt(pow(major / 2.0 - l - 0.5, 2) + pow(major / 2.0 - j - 0.5, 2)) - middle, 2);
                len += pow((major - minor) / 4.0 - i - 0.5, 2);
                len -= pow((major - minor) / 4.0, 2);
                if (len < 0)
                    tor_parameters->arr_size_ptr_ptr[l][j] += 1;
            }



    return;
}

void ShowTorus(const TorusArrParameters * tor_parameters, const int major, const int minor)
{
    for (int layer = 0; layer < (major - minor) / 2.0 + 1; layer++)
    {
        for (int l = 0; l < major; l++)
        {
            for (int j = 0; j < major; j++)
            {
                //printf("%2d", tor_parameters->arr_size_ptr_ptr[l][j]);
                tor_parameters->arr_size_ptr_ptr[l][j] >= abs((int) (major - minor) / 2 - 2 * layer) ? printf("[]") : printf("  ");        
            }

            printf("\n");
        }

        printf("\n");
    }

    return;
}