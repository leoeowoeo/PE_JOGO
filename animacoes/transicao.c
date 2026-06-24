#include <ncurses.h>
void transicao(int *epilepsia)// a função roda uma transição colorida e piscante pra definir bem os momentos do jogo ( sem ela os dialogos pareciam se misturar)
{
    if(*epilepsia==0)
    {for(int i=0;i<LINES;i++){
        for(int j=0;j<COLS;j++){
            wattron(stdscr,COLOR_PAIR(10));
            mvprintw(i,j,"   ");
            wattroff(stdscr,COLOR_PAIR(10));
            refresh();
        }
    }
    napms(60);
    for(int i=0;i<LINES;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            wattron(stdscr,COLOR_PAIR(16));
            mvprintw(i,j,"   ");
            wattroff(stdscr,COLOR_PAIR(16));
            refresh();
        }
    }
    napms(60);
    for(int i=0;i<LINES;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            wattron(stdscr,COLOR_PAIR(17));
            mvprintw(i,j,"   ");
            wattroff(stdscr,COLOR_PAIR(17));
            refresh();
        }
    }
    napms(60);
    for(int i=0;i<LINES;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            wattron(stdscr,COLOR_PAIR(18));
            mvprintw(i,j,"   ");
            wattroff(stdscr,COLOR_PAIR(18));
            refresh();
        }
    }
    napms(60);
    for(int i=0;i<LINES;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            wattron(stdscr,COLOR_PAIR(19));
            mvprintw(i,j,"   ");
            wattroff(stdscr,COLOR_PAIR(19));
            refresh();
        }
    }
        napms(60);
    for(int i=0;i<LINES;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            wattron(stdscr,COLOR_PAIR(20));
            mvprintw(i,j,"   ");
            wattroff(stdscr,COLOR_PAIR(20));
            refresh();
        }
    }
    napms(200);}
}