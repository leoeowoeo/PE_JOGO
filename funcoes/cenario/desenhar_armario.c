#include "jogos.h"
void desenhar_armario(int Xall, int Yall, int cor, int armarioaberto, int interagirArm, int par)
{
    int armarioY = 14 + Yall, armarioX = 19 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (armarioaberto == 1)
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(armarioY+1, armarioX, " |\"\"\"\"|/|");
        mvprintw(armarioY+2, armarioX, " |    | |");
        mvprintw(armarioY+3, armarioX, " |    | |  ");
        mvprintw(armarioY+4, armarioX, " |    |/ ");
        mvprintw(armarioY+5, armarioX, " |\"\"\"\"|  ");
        mvprintw(armarioY+6, armarioX, " |    |\\");
        mvprintw(armarioY+7, armarioX, " |    | |");
        mvprintw(armarioY+8, armarioX, " |    |[|");
        mvprintw(armarioY+9, armarioX, " |____|\\|");
    }
    else
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(armarioY+1, armarioX, " |\"\"\"\"|");
        mvprintw(armarioY+2, armarioX, " |    |");
        mvprintw(armarioY+3, armarioX, " |    |");
        mvprintw(armarioY+4, armarioX, " |    |]");
        mvprintw(armarioY+5, armarioX, " |\"\"\"\"|");
        mvprintw(armarioY+6, armarioX, " |    |]");
        mvprintw(armarioY+7, armarioX, " |    |");
        mvprintw(armarioY+8, armarioX, " |    |");
        mvprintw(armarioY+9, armarioX, " |____|");
    }
    wattroff(stdscr, COLOR_PAIR(par));
    wattroff(stdscr, COLOR_PAIR(6));
}
