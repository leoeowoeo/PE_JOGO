#include "jogos.h"
void desenhar_lixo(int Xall, int Yall, int cor)
{
    int lixoY = 27 + Yall, lixoX = 84 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(15));
    mvprintw(lixoY+1, lixoX,  "|###|");
    mvprintw(lixoY+2, lixoX, " \\#/");
    if (cor == 1) wattroff(stdscr, COLOR_PAIR(15));
}