#include<ncurses.h>
#include "jogos.h"
void demo(){
    initscr();
    nodelay(stdscr,TRUE);
    int cont=0;
    while(cont<300){
        werase(stdscr);
        mvprintw(LINES / 2,COLS / 2,"O JOGO AINDA ESTA EM DESENVOLVIMENTO E NAO POSSUI TODAS AS FUNCOES");
        wrefresh(stdscr);
        napms(10);
        cont++;

    }
    endwin();
}