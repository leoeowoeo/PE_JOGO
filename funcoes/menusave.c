#include<ncurses.h>
#include"jogos.h"
#include<string.h>
void menusave(int *cor,SAVE *save_atual, int *jogar,int *selecao_olhos, int *selecao_face,int *selecao_pernas,int *iniciado)
// a função mostra o menu de save e torna possivel a escolha de salvar e dar load para jogar em cada save ( salvar sobreescreve )
{
    initscr();
    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    init_pair(4,COLOR_WHITE,-1);
    int xselecao=60,yselecao=10;
    int tecla, selecao=0,i,j;
    int sair=1;
    int selecao_salvar=1;
    int INICIAR=0;
    int savey=15,savex=60;
    int salvo=0;
    int carregoOUsalvo=0;
    SAVE slots[3] = {0};// esse aqui não é o save atual e não vai pro save atual... deveria né?
    if(!*iniciado)
    {
        for(i=0; i<3; i++)
        {
            iniciar(i + 1, &slots[i], selecao_olhos, selecao_face, selecao_pernas);// aqui eu inicio todos os saves com o momento e a imagem
        }
        *iniciado=1;
    }
    while(sair)
    {
        erase();
        tecla=getch();
        mvprintw(yselecao,xselecao-16," SLOT 1");
        mvprintw(yselecao,xselecao," SLOT 2");
        mvprintw(yselecao,xselecao+16," SLOT 3");
        if(selecao==0){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao-16,">SLOT 1");
            desenha_borda(xselecao-17,yselecao+1);
            printar_imagem_do_momento(yselecao+2,xselecao-16,slots[0].imagem);
            mvprintw(yselecao+21,xselecao-16,"%s",slots[0].momento);
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        else if(selecao==1){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao,">SLOT 2");
            desenha_borda(xselecao-1,yselecao+1);
            printar_imagem_do_momento(yselecao+2,xselecao,slots[1].imagem);
            mvprintw(yselecao+21,xselecao,"%s",slots[1].momento);
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }
        else if(selecao==2){
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao+16,">SLOT 3");
            desenha_borda(xselecao+15,yselecao+1);
            printar_imagem_do_momento(yselecao+2,xselecao+16,slots[2].imagem);
            mvprintw(yselecao+21,xselecao+16,"%s",slots[2].momento);
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
                mvprintw(yselecao,xselecao-8,"SLOT %d",selecao+1);
                desenha_borda(xselecao-8,yselecao+1);
                printar_imagem_do_momento(yselecao+2,xselecao-7,slots[0].imagem);
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
                mvwprintw(stdscr,yselecao+7+10,xselecao-8,"%s",slots[selecao].momento);
                mvprintw(yselecao+7+2,xselecao-8," SALVAR");
                mvprintw(yselecao+7+4,xselecao-8," INICIAR");
                if(selecao_salvar==1)
                {
                wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                mvprintw(yselecao+7+2,xselecao-8,">SALVAR");
                wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                }
                if(selecao_salvar==2)
                { 
                wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                mvprintw(yselecao+7+4,xselecao-8,">INICIAR");
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
                        gravar(selecao + 1, &slots[selecao]);
                        recarregar(selecao + 1, &slots[selecao]);
                        salvo=1;
                        save_atual=&slots[selecao];
                        break;
                        //chamar funçao gravar pra salvar no slot "selecao"(variavel)
                    }
                    if(selecao_salvar==2){
                        recarregar(selecao + 1,&slots[selecao]);
                        INICIAR=1;
                        save_atual=&slots[selecao];
                        break;
                        //chamar funçao reINICIAR o slot "selecao"(variavel)
                    }
                    save_atual=&slots[selecao];
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
            carregoOUsalvo=1;
            recarregar(1, &slots[0]);
            recarregar(2, &slots[1]);
            recarregar(3, &slots[2]);
            break;
        }
        flushinp();
        if(tecla=='p' && !carregoOUsalvo)
        {
            *jogar=0;
            sair=0;
            nodelay(stdscr,FALSE);
        }
        carregoOUsalvo=0;
        refresh();
        napms(30);
    }
}