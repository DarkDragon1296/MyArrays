#ifndef TORUS_ARR_H
#define TORUS_ARR_H

const int TORUS_MAJOR_D = 39;
const int TORUS_MINOR_D = 21;

struct TorusArrParameters
{
    int **arr_ptr = {};
    int arr_size_ptr_ptr[TORUS_MAJOR_D][TORUS_MAJOR_D] = {};
    int ***arr_ptr_ptr = {};
};

void RunTorusArr(void);

void GenerateTorus(TorusArrParameters * tor_parameters, const int major, const int minor); // Создает массив

void ShowTorus(const TorusArrParameters * tor_parameters, const int major, const int minor); // Показывает форму торуса



#endif