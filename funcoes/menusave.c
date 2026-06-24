#include<ncurses.h>
#include"jogos.h"
#include<string.h>
void menusave(int *cor,SAVE *save_atual, int *jogar){
    initscr();
    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    init_pair(4,COLOR_WHITE,-1);
    int xselecao=60,yselecao=10;
    int tecla, selecao=0;
    int sair=1;
    int selecao_salvar=1;
    int INICIAR=0;
    int savey=15,savex=60;
    int salvo=0;
    iniciar(0,save_atual);
    iniciar(1,save_atual);
    iniciar(2,save_atual);
    int tam = strlen(save_atual->momento);
    while(sair){
        erase();
        tecla=getch();
        mvprintw(yselecao,xselecao-16," SLOT 1");
        mvprintw(yselecao,xselecao," SLOT 2");
        mvprintw(yselecao,xselecao+16," SLOT 3");
        if(selecao==0){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao-16,">SLOT 1");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        else if(selecao==1){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao,">SLOT 2");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        else if(selecao==2){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao+16,">SLOT 3");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        switch(tecla)
        {
            case KEY_LEFT:
            selecao--;
            if(selecao<0)
                selecao=2;
            break;
            case KEY_RIGHT:
            selecao++;
            if(selecao>2)
                selecao=0;
            break;
            case '\n':
            flushinp();
            while(tecla!='p')
            {
                tecla=getch();
                erase();
                mvprintw(yselecao,xselecao-8,"VSLOT %d",selecao+1);
                if(salvo)
                {
                    mvwprintw(stdscr,yselecao+2,xselecao-8," SALVOU!!!");
                    wrefresh(stdscr);
                    for(int j=0;j<60;j++)
                    {
                        napms(24);
                    }
                    salvo=0;
                }
                for(int i=0;i<tam;i++)
                {
                    mvwprintw(stdscr,yselecao+10,xselecao-8+i,"%c",save_atual->momento[i]);
                }
                mvprintw(yselecao+2,xselecao-8," SALVAR");
                mvprintw(yselecao+4,xselecao-8," INICIAR");
                if(selecao_salvar==1)
                {
                wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                mvprintw(yselecao+2,xselecao-8,">SALVAR");
                wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                }
                if(selecao_salvar==2)
                { 
                wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                mvprintw(yselecao+4,xselecao-8,">INICIAR");
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
                        gravar(selecao,save_atual);
                        
                        salvo=1;
                        break;
                        //chamar funçao gravar pra salvar no slot "selecao"(variavel)
                    }
                    if(selecao_salvar==2){
                        recarregar(selecao,save_atual);
                        INICIAR=1;

                        break;
                        //chamar funçao reINICIAR o slot "selecao"(variavel)
                    }
                    break;
                }
                if(INICIAR==1)
                {
                    sair=0;
                    break;
                }
                refresh();
                napms(30);

            }
            break;
        }
        flushinp();
        if(tecla=='p')
        {
            *jogar=0;
            sair=0;
            nodelay(stdscr,FALSE);
        }
        refresh();
        napms(30);
    }
}