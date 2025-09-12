#include <stdio.h>
#include "Menu.h"

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
            printf("Try again!!!");
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

void ClearInput(void)
{
    char ch = 0;

    while (ch != '\n' && ch != EOF)
        ch = getchar();

    return;
}