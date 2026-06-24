#include<ncurses.h>
void gravar_imagem_do_momento(int xdogaroto, int ydogaroto,char imagem_do_momento[6][13])
// a função deve gravar a matriz de caracteres em torno do personagem pra
// ficar visivel o save que ele esta na hora da seleção
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<12;j++)
        {
            imagem_do_momento[i][j] = '\0';
        }
        mvinnstr(ydogaroto-3+i, xdogaroto-5, imagem_do_momento[i], 12);
        imagem_do_momento[i][12] = '\0';
    }
}
