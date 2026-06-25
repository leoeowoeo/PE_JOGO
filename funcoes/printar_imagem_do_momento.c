#include<ncurses.h>
void printar_imagem_do_momento(int y, int x, char imagem_do_momento[6][12])
// a função deve printar embaixo do slot ( talvez eu mude o lugar onde printa ou tire ela se for muito trabalhoso)
// a imagem em torno do personagem na hora em que o jogo foi salvo
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<12;j++)
        {
            mvprintw(y+i,x+j,"%c", imagem_do_momento[i][j]);
        }
    }
}