#ifndef MENU_H
#define MENU_H

enum Modes  {
                NONE,
                EXIT,
                STAND_ARR
            };

Modes ChooseMode(void); // Возвращает значение выбранного режима

void ShowMenu(void); // Показывает меню

void ClearInput(void); // Очищает входной поток

#endif