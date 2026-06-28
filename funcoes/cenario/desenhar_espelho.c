#include "jogos.h"
void desenhar_espelho(int Xall, int Yall, int cor, int par)
{
    int espelhoy = 3 + Yall, espelhox = 63 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(11));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
    mvprintw(espelhoy, espelhox, " ,_,_,_,_,");
    mvprintw(espelhoy+1, espelhox, " {|");
    mvprintw(espelhoy+2, espelhox, " {|");
    mvprintw(espelhoy+3, espelhox, " {|");
    mvprintw(espelhoy+4, espelhox, " {|");
    mvprintw(espelhoy+1, espelhox+8, "|}     ");
    mvprintw(espelhoy+2, espelhox+8, "|}     ");
    mvprintw(espelhoy+3, espelhox+8, "|}     ");
    mvprintw(espelhoy+4, espelhox+8, "|}    ");
    mvprintw(espelhoy+5, espelhox, " \"=\"=\"=\"=\" ");
    wattroff(stdscr, COLOR_PAIR(par));
    wattroff(stdscr, COLOR_PAIR(11));
}