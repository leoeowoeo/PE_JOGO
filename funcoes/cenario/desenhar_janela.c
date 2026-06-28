#include"jogos.h"
void desenhar_janela(int Xall, int Yall, int cor, int janelaaberta, int interagirJan, int par,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check)
{
    int janelaY = 4 + Yall, janelaX = 50 + Xall;
    if (janelaaberta == 0)
    {
        
        if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
        if (interagirJan == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(janelaY, janelaX, "|\\ _______ /| ");
        mvprintw(janelaY+1, janelaX, "| |       | | ");
        mvprintw(janelaY+2, janelaX, "| |       | | ");
        mvprintw(janelaY+3, janelaX, " \\|       |/  ");
        mvprintw(janelaY+4, janelaX, "  ---------   ");
        wattroff(stdscr, COLOR_PAIR(2));
        wattroff(stdscr, COLOR_PAIR(par));
        desenhar_chuva(Xall, Yall, cor, chuvax, chuvay, pos, pos2, pos3, check);
    }
    else
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
        if (interagirJan == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(janelaY, janelaX, "   _______    ");
        mvprintw(janelaY+1, janelaX, "  |   |   |   ");
        mvprintw(janelaY+2, janelaX, "  |   |   |   ");
        mvprintw(janelaY+3, janelaX, "  |   |   |   ");
        mvprintw(janelaY+4, janelaX, "  ---------");
        wattroff(stdscr, COLOR_PAIR(par));
        wattroff(stdscr, COLOR_PAIR(2));
    }
}