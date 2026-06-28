#include "jogos.h"
void desenhar_rodape(int Xall, int Yall, int cor)
{
    int rodapey = 9 + Yall, rodapex = 21 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(9));
    mvprintw(rodapey, rodapex, "_____________");
    mvprintw(rodapey+21, rodapex, "_____________________________________________________________________");
    for (; rodapex < 63 + Xall; rodapex++)
    {
        mvprintw(rodapey, rodapex+27, "_");
        if (rodapex == 46 + Xall) rodapex = 61 + Xall;
    }
    wattroff(stdscr, COLOR_PAIR(9));

    int rodape2y = 10 + Yall, rodape2x = 20 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(9));
    for (; rodape2y < 31 + Yall; rodape2y++)
    {
        if (rodape2y < 31 + Yall) mvprintw(rodape2y, rodape2x, "|");
        mvprintw(rodape2y, rodape2x+70, "|");
    }
    wattroff(stdscr, COLOR_PAIR(9));
}