#include <stdio.h>
#include "Menu.h"

int main(void)
{
    Modes mode = NONE;

    printf("This program handles arrays of different shapes\n");

    while (mode != EXIT)
    {
        mode = ChooseMode();

        StartMode(mode);
    }



}