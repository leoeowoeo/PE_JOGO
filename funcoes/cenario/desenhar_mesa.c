#include "jogos.h"
void desenhar_mesa(int Xall, int Yall, int cor)
{
    int mesaY = 8 + Yall, mesaX = 74 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    mvprintw(mesaY, mesaX, " ____");
    mvprintw(mesaY+1, mesaX, "|    |");
    mvprintw(mesaY+2, mesaX, "|____|");
    mvprintw(mesaY+3, mesaX, " T  T ");
    wattroff(stdscr, COLOR_PAIR(6));
}