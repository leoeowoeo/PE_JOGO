#include "jogos.h"
void desenhar_estante(int Xall, int Yall, int cor, int interagirEst, int par, SAVE *save, int celularX, int celularY)
{
    int estanteY = 5 + Yall, estanteX = 34 + Xall;
    if (interagirEst == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(estanteY, estanteX, " ____________ ");
    mvprintw(estanteY+1, estanteX, "[____!!__||__]");
    mvprintw(estanteY+2, estanteX, "[||____!!_!!_]");
    mvprintw(estanteY+3, estanteX, "[!!_!!__||_!!]");
    mvprintw(estanteY+4, estanteX, "[__!!_!!___!!]");
    mvprintw(estanteY+5, estanteX, "[_||!!___!!||]");
    mvprintw(estanteY+6, estanteX, "[_!!_!!______]");
    wattroff(stdscr, COLOR_PAIR(7));
    wattroff(stdscr, COLOR_PAIR(par));
    gravar_imagem_do_momento(save->x, save->y, save->imagem);
    printar_imagem_do_momento(celularX+18, celularY, save->imagem);
}