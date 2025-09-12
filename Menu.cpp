#include <stdio.h>
#include "Menu.h"
#include "StandArr.h"
#include "OtherOperations.h"

Modes ChooseMode(void)
{
    Modes choose_mode = NONE;
    int choice = 0;
    while (choose_mode == NONE)
    {
        ShowMenu();

        scanf("%d", &choice);
        ClearInput();

        switch (choice)
        {
            case 1:
                choose_mode = STAND_ARR;
                break;
            case 2:
                choose_mode = EXIT;
                break;
        }

        if (choose_mode == NONE)
            printf("Try again!!!\n");
    }

    return choose_mode;
}

void ShowMenu(void)
{
    printf("Select the array you are interested in:\n");
    printf("Modes:\n");
    printf("1) Standart\n");
    printf("2) Exit\n");

    return;
}

void StartMode(Modes mode)
{
    switch (mode)
    {
        case STAND_ARR:
            RunStandArr();
            break;
    }
}