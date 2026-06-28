#include "jogos.h"
void desenhar_tapete(int Xall, int Yall, int cor)
{
    int tapetey = 18 + Yall, tapetex = 45 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(8));
    mvprintw(tapetey, tapetex, "  I~~~~~~~~~~~~~I ");
    mvprintw(tapetey+1, tapetex, "  |    ~~~      | ");
    mvprintw(tapetey+2, tapetex, "  |       ~~~~  | ");
    mvprintw(tapetey+3, tapetex, "  |  ~~~        | ");
    mvprintw(tapetey+4, tapetex, "  |      ~~~~   | ");
    mvprintw(tapetey+5, tapetex, "  I~~~~~~~~~~~~~I ");
    wattroff(stdscr, COLOR_PAIR(8));
}