#ifndef TORUS_ARR_H
#define TORUS_ARR_H

const int TORUS_MAJOR_D = 243;
const int TORUS_MINOR_D = 147;

struct TorusArrParameters
{
    int arr_size_ptr_ptr[TORUS_MAJOR_D][TORUS_MAJOR_D] = {};
    int *arr_ptr_ptr_ptr[TORUS_MAJOR_D][TORUS_MAJOR_D] = {};
};

void RunTorusArr(void);

int GenerateTorus(TorusArrParameters * tor_parameters, const int major, const int minor);
// Создает массив

void ShowTorus(const TorusArrParameters * tor_parameters, const int major, const int minor);
// Показывает форму торуса

void ShowTorusArr(const TorusArrParameters * tor_parameters, const int major, const int minor);

void ClearTorus(const TorusArrParameters * tor_parameters, const int major, const int success_calloc);
// Очищает память

int SumTorusArr(const TorusArrParameters * tor_parameters, const int major, const int minor);
// Сумма Элементов

double WhyIsTorusArrCool(const TorusArrParameters * tor_parameters, const int major, const int minor);
// Доказывает, что этот массив не бесполезен

#endif