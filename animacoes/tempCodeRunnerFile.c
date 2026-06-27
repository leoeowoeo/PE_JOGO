void animacaopequenina(int yselecao,int xselecao)
    {
        int altura=1;
        int passo=0;
        int lugar=-3;
        int espacamento=0; 
for(int i=0;i<5;i++,passo++)
    {
        if(passo%2==0)
        {
            altura=lugar;
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ..                     ..     ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  pd' .g8\"\"8q.     .g8\"\"8q. `bq   ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " 6P .dP'    `YM. .dP'    `YM. YA  ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "6M' dM'      `MM dM'      `MM `Mb ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN  MM        MM MM        MM  8M ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN  MM.      ,MP MM.      ,MP  8M ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " Mb   `\"bmmd\"'     `\"bmmd\"'   dM  ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  Yq.                       .pY   ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ``                     ''     "); 
        }
        else
        {
            altura=lugar;
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ..                    ..      "); 
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  pd'                      `bq    ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " 6P                          YA   ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "6M'                          `Mb  ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN                            8M  ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN mmmmmmmmmmm    mmmmmmmmmmm 8M  ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "YM.                          ,M9  ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " Mb                          dM   ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  Yq.                      .pY    ");
            mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ``                    ''      ");
        }
    }
}