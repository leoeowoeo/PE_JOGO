#include<ncurses.h>
#include"jogos.h"
void menusave(int *cor,SAVE *save_atual){
    initscr();
    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    init_pair(4,COLOR_WHITE,-1);
    int xselecao=60,yselecao=10;
    int tecla, selecao=1,selecao_opcoes=1,selecao_aparencia=0;
    int piscar=0;
    int indicacao=0;
    int jogar=0,sair=0;
    int selecao_salvar=1;

    while(tecla!='p'){
        erase();
        tecla=getch();
        mvprintw(yselecao,xselecao-16," SLOT 1");
        mvprintw(yselecao,xselecao," SLOT 2");
        mvprintw(yselecao,xselecao+16," SLOT 3");
        if(selecao==1){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao-16,">SLOT 1");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        else if(selecao==2){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao,">SLOT 2");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        else if(selecao==3){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao+16,">SLOT 3");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        switch(tecla){
            case KEY_LEFT:
            selecao--;
            if(selecao<1)
                selecao=3;
            break;
            case KEY_RIGHT:
            selecao++;
            if(selecao>3)
                selecao=1;
            break;
            case '\n':
            flushinp();
            while(tecla!='p')
            {
                tecla=getch();
                erase();

                mvprintw(yselecao,xselecao-8,"VSLOT %d",selecao);
                mvprintw(yselecao+2,xselecao-8," SALVAR");
                mvprintw(yselecao+4,xselecao-8," CARREGAR");
                if(selecao_salvar==1)
                {
                wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                mvprintw(yselecao+2,xselecao-8,">SALVAR");
                wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                }
                if(selecao_salvar==2)
                { 
                wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                mvprintw(yselecao+4,xselecao-8,">CARREGAR");
                wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                }
                switch(tecla)
                {
                    case KEY_UP:
                    selecao_salvar--;
                    if(selecao_salvar<1)
                        selecao_salvar=2;
                    break;
                    case KEY_DOWN:
                    selecao_salvar++;
                    if(selecao_salvar>2)
                        selecao_salvar=1;
                    break;
                    case '\n':
                    if(selecao_salvar==1){
                        //chamar funçao gravar pra salvar no slot "selecao"(variavel)
                    }
                    if(selecao_salvar==2){
                        //chamar funçao recarregar o slot "selecao"(variavel)
                    }
                    break;
                }
                refresh();
                napms(30);
                
            }
            break;
            
        }
        refresh();
        napms(30);
    }
}