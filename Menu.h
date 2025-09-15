#ifndef MENU_H
#define MENU_H

enum Modes  {
                NONE,
                TORUS_ARR,
                EXIT,
                STAND_ARR
            };

Modes ChooseMode(void); // Возвращает значение выбранного режима

void ShowMenu(void); // Показывает меню

void StartMode(Modes mode); // Включает нужный режим

#endif