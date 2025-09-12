#include <stdio.h>
#include "OtherOperations.h"

void ClearInput(void)
{
    char ch = 0;

    while (ch != '\n' && ch != EOF)
        ch = getchar();

    return;
}
