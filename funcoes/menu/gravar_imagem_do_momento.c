#include"jogos.h"
void gravar_imagem_do_momento(int xdogaroto, int ydogaroto, char imagem_do_momento[6][13])

{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            imagem_do_momento[i][j] = mvinch(ydogaroto - 3 + i, xdogaroto - 5 + j);
        }
    }
}