#include<ncurses.h>
void printar_imagem_do_momento(int x, int y, char imagem_do_momento[6][12])
{
    for(int i=0;i<6;i++)
    {
        mvprintw(y+i, x, "%s", imagem_do_momento[i]);
    }
}