#include "jogos.h"
void desenhar_cama(int Xall, int Yall, int cor, int interagirCam, int par)
{
    int camaY = 8 + Yall, camaX = 80 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(1));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(4));
    if (interagirCam == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(camaY, camaX, "._______.");
    mvprintw(camaY+1, camaX, "|~~     |");
    mvprintw(camaY+2, camaX, "|       |");
    mvprintw(camaY+3, camaX, "|    ~~ |");
    mvprintw(camaY+4, camaX, "|_______|");
    wattroff(stdscr, COLOR_PAIR(4));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (interagirCam == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(camaY+5, camaX, "||     ||");
    wattroff(stdscr, COLOR_PAIR(6));
    mvprintw(camaY+1, camaX+2, "(   )");
    wattroff(stdscr, COLOR_PAIR(12));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(7));
}