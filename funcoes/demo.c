#include<ncurses.h>
#include "jogos.h"
void demo()// delimita onde o jogador pode acessar, já que não temos todos os modos de jogo que serão feitos prontos e disponiveis na integridade
{
    initscr();
    nodelay(stdscr,TRUE);
    int cont=0;
    while(cont<300){
        werase(stdscr);
        mvprintw(LINES / 4,COLS / 4,"O JOGO AINDA ESTA EM DESENVOLVIMENTO E NAO POSSUI TODAS AS FUNCOES");
        wrefresh(stdscr);
        napms(10);
        cont++;

    }
    endwin();
}