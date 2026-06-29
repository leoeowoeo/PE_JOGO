#include"jogos.h"
void desenhar_celular_mesa(int Xall, int Yall,SAVE *save, int celularX, int celularY, int interagirCel, int par)
{
    if (save->celularpickup == 0)
    {
        if (save->depoisprova == 0)
        {
            if (interagirCel == 1 && save->cor == 1) wattron(stdscr, COLOR_PAIR(par));
            if (save->celularpos == 1) mvprintw(celularY, celularX, "[]");
            else if (save->celularpos == 2) mvprintw(celularY+1, celularX, "[]");
            else if (save->celularpos == 3) mvprintw(celularY+1, celularX-1, "[]");
            wattroff(stdscr, COLOR_PAIR(par));
        }
    }
}