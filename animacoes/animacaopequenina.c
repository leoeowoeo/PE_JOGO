#include"jogos.h"
    void animacaopequenina(int yselecao,int xselecao)
    {
        int altura=1;
        int passo=0;
        int lugar=-3;
for(int i=0;i<7;i++,passo++)
    {
        if(passo%2==0)
        {
            altura=lugar;
            mvprintw(yselecao+5+altura++, xselecao+4, "    ..                     ..     ");
            mvprintw(yselecao+5+altura++, xselecao+4, "  pd' .g8\"\"8q.     .g8\"\"8q. `bq   ");
            mvprintw(yselecao+5+altura++, xselecao+4, " 6P .dP'    `YM. .dP'    `YM. YA  ");
            mvprintw(yselecao+5+altura++, xselecao+4, "6M' dM'      `MM dM'      `MM `Mb ");
            mvprintw(yselecao+5+altura++, xselecao+4, "MN  MM        MM MM        MM  8M ");
            mvprintw(yselecao+5+altura++, xselecao+4, "MN  MM.      ,MP MM.      ,MP  8M ");
            mvprintw(yselecao+5+altura++, xselecao+4, "YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ");
            mvprintw(yselecao+5+altura++, xselecao+4, " Mb   `\"bmmd\"'     `\"bmmd\"'   dM  ");
            mvprintw(yselecao+5+altura++, xselecao+4, "  Yq.                       .pY   ");
            mvprintw(yselecao+5+altura++, xselecao+4, "    ``                     ''     "); 
        }
        else
        {
            altura=lugar;
            mvprintw(yselecao+5+altura++, xselecao+4, "    ..                    ..      "); 
            mvprintw(yselecao+5+altura++, xselecao+4, "  pd'                      `bq    ");
            mvprintw(yselecao+5+altura++, xselecao+4, " 6P                          YA   ");
            mvprintw(yselecao+5+altura++, xselecao+4, "6M'                          `Mb  ");
            mvprintw(yselecao+5+altura++, xselecao+4, "MN                            8M  ");
            mvprintw(yselecao+5+altura++, xselecao+4, "MN mmmmmmmmmmm    mmmmmmmmmmm 8M  ");
            mvprintw(yselecao+5+altura++, xselecao+4, "YM.                          ,M9  ");
            mvprintw(yselecao+5+altura++, xselecao+4, " Mb                          dM   ");
            mvprintw(yselecao+5+altura++, xselecao+4, "  Yq.                      .pY    ");
            mvprintw(yselecao+5+altura++, xselecao+4, "    ``                    ''      ");
        }
                mvprintw(yselecao+16,xselecao-8,"While(playing)");
                mvprintw(yselecao+17,xselecao-8,"{!studying(oo);}");
                mvprintw(yselecao+20,xselecao-8,"JOGAR");
        mvprintw(yselecao+20+2,xselecao-8,"OPCOES");
        mvprintw(yselecao+20+4,xselecao-8,"CREDITOS");
        mvprintw(yselecao+20+6,xselecao-8,"CUSTOMIZACAO");
        mvprintw(yselecao+20+8,xselecao-8,"SAIR");
        refresh();
        napms(300);
    }
int andar=xselecao;
int descer=0;
for(int i=0;i<3;i++,passo++)
    {
        mvprintw(yselecao+descer+17,andar, "     ");
        mvprintw(yselecao+descer+18,andar, "     ");

        descer++;
        if(passo%2==0)
        {
            mvprintw(yselecao+descer+17,andar, " (oo)");
            mvprintw(yselecao+descer+18,andar, "  |\\");
        }
        else
        {
            mvprintw(yselecao+descer+17,andar, " (oo)");
            mvprintw(yselecao+descer+18,andar, "  /|");
        }
        mvprintw(yselecao+16,xselecao-8,"While(playing)");
                mvprintw(yselecao+17,xselecao-8,"{!studying    ;}");
        wrefresh(stdscr);
        napms(50);
    }
                mvprintw(yselecao+16,xselecao-8,"While(playing)");
                mvprintw(yselecao+17,xselecao-8,"{!studying    ;}");
                mvprintw(yselecao+20,xselecao-8,"JOGAR");
                mvprintw(yselecao+20+2,xselecao-8,"OPCOES");
                mvprintw(yselecao+20+4,xselecao-8,"CREDITOS");
                mvprintw(yselecao+20+6,xselecao-8,"CUSTOMIZACAO");
                mvprintw(yselecao+20+8,xselecao-8,"SAIR");
for(int i=0;i<=COLS+3;i++,passo++)
    {
        if (andar + 6 >= COLS)
        {
            mvprintw(yselecao+descer+17,andar, "     ");
            mvprintw(yselecao+descer+18,andar, "     ");
            break;
        }

        mvprintw(yselecao+descer+17,andar, "     ");
        mvprintw(yselecao+descer+18,andar, "     ");

        andar++;    
        if(passo%2==0)
        {
            mvprintw(yselecao+descer+17,andar, " (oo)");
            mvprintw(yselecao+descer+18,andar, "  |\\");
        }
        else
        {
            mvprintw(yselecao+descer+17,andar, " (oo)");
            mvprintw(yselecao+descer+18,andar, "  /|");
        }
        wrefresh(stdscr);
        if(i<=1.5*(COLS/3))
        napms(25);
        else
        napms(50);
    }

mvprintw(yselecao+descer+17,andar, "     ");
mvprintw(yselecao+descer+18,andar, "     ");

andar=0;
for(int i=0;i<xselecao-13;i++,passo++)
    {
        if (andar + 6 >= COLS)
        {
            mvprintw(yselecao+20,andar, "     ");
            mvprintw(yselecao+21,andar, "     ");
            break;
        }

        mvprintw(yselecao+20,andar, "     ");
        mvprintw(yselecao+21,andar, "     ");

        andar++;
        if(passo%2==0)
        {
            mvprintw(yselecao+20,andar, " (oo)");
            mvprintw(yselecao+21,andar, "  |\\");
        }
        else
        {
            mvprintw(yselecao+20,andar, " (oo)");
            mvprintw(yselecao+21,andar, "  /|");
        }
        
        wrefresh(stdscr);
        napms(50);
    }
mvprintw(yselecao+20,andar, "     ");
mvprintw(yselecao+21,andar, "     ");
wrefresh(stdscr);
}