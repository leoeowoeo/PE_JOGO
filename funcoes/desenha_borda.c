#include "jogos.h"
void desenha_borda(int x, int y)// essa função printa a borda da caixa onde aparece a imagem do momento nos salvamentos dos slots
{
    mvaddch(y, x, ACS_ULCORNER);
    for(int i = 1; i < 13; i++) mvaddch(y, x + i, ACS_HLINE);
    mvaddch(y, x + 13, ACS_URCORNER);
    
    for(int i = 1; i < 7; i++) {
        mvaddch(y + i, x, ACS_VLINE);
        mvaddch(y + i, x + 13, ACS_VLINE);
    }
    
    mvaddch(y + 7, x, ACS_LLCORNER);
    for(int i = 1; i < 13; i++) mvaddch(y + 7, x + i, ACS_HLINE);
    mvaddch(y + 7, x + 13, ACS_LRCORNER);
}
// essas palavras estranhas são Alternative Character Sets, que tem alguns caracteres só da Ncurses adicionados a parte
