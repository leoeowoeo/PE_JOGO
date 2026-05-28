#include <ncurses.h>
#include <stdlib.h>
#include "jogos.h"
    #define COR_CIANO          1
    #define COR_CINZAESCURO    2
    #define COR_VERDEFOLHA    3
    #define COR_VERDECOBRA    10


int cobra(int *cor,int *jogarcelular){

        if(cor==1)
    {

        start_color();
    use_default_colors(); 

    init_color(COR_CIANO, 0, 1000, 1000);

    init_color(COR_CINZAESCURO, 900, 900, 900);

    init_color(COR_VERDEFOLHA, 333, 900, 560);

        init_color(COR_VERDECOBRA, 233, 800, 460);


    init_pair(2, COR_CINZAESCURO,-1);
    init_pair(3, COR_VERDEFOLHA,-1);
    init_pair(4, COR_VERDECOBRA,-1);
    init_pair(5, COLOR_RED, -1); 
}
    curs_set(0);
    WINDOW *cobra = newwin(LINES, COLS, 0, 0);
    keypad(cobra,TRUE);
    nodelay(cobra,TRUE);

    int Xallcobra=80,Yallcobra=5;
    int i, tecla, tecla2 = 0;
    int trofeux=Xallcobra,trofeuy=Yallcobra+22;
    
//cobra
    // Ajustado para nascer no meio do mapa em função de Xallcobra e Yallcobra
    int cobrax=Xallcobra+30, cobray=Yallcobra+12, cobraX[100], cobraY[100],velocidade=5;
    cobraX[0] = cobrax;
    cobraY[0] = cobray;
//--------------
//mecanica
    int derrota=0, quit=0;
    int cont=0, velocidad=5;

    int altura=30, largura=30;

    
    // Ajustado para nascer em função de Xallcobra e Yallcobra
    int maçãx = Xallcobra + 2 + ((rand() % 28) * 2);
    int maçãy = Yallcobra + 1 + (rand() % 22);
    int maçãpegar=0;
    int score=0;
//---------------------------------------- 

    while(tecla!='p'){
        werase(cobra); 
        mvwprintw(cobra, Yallcobra-1, Xallcobra, "Pontuacao:%d", score);
        mvwprintw(cobra, Yallcobra-1, Xallcobra+20, "mova-se com WASD");
        if(score<1)
            mvwprintw(cobra, Yallcobra-1, Xallcobra+40, "acostume-se");
        else if(score<2)
            mvwprintw(cobra, Yallcobra-1, Xallcobra+40, "acostumou?");    
        else
            mvwprintw(cobra, Yallcobra-1, Xallcobra+40, "valendo");
        mvwprintw(cobra, Yallcobra+26, Xallcobra+43, "Aperte P para sair");

        for(i=0;i<=60;i++)
            mvwprintw(cobra, Yallcobra, Xallcobra+i, "-");
        for(i=0;i<=25;i++) 
            mvwprintw(cobra, Yallcobra+i, Xallcobra, "|");
        for(i=1;i<=60;i++) 
            mvwprintw(cobra, Yallcobra+25, Xallcobra+i, "-");
        for(i=0;i<=25;i++) 
            mvwprintw(cobra, Yallcobra+i, Xallcobra+60, "|");

        //movimentação
        tecla=getch();
        if(tecla == 'w')    
            tecla2=1;
        if(tecla == 's')  
            tecla2=2;
        if(tecla == 'a')  
            tecla2=3;
        if(tecla == 'd') 
            tecla2=4;

        if (cont>=velocidade) {
            for (i = score+3; i > 0; i--) 
            {
                cobraX[i] = cobraX[i-1];
                cobraY[i] = cobraY[i-1];
            }

            if (tecla2 == 1) 
                cobray--;
            if (tecla2 == 2) 
                cobray++;
            if (tecla2 == 3) 
                cobrax-=2;
            if (tecla2 == 4) 
                cobrax+=2;
            
            cobraX[0] = cobrax;
            cobraY[0] = cobray;
            

            for(i = 1; i <= score; i++) {
                if(cobrax == cobraX[i] && cobray == cobraY[i]) 
                    derrota = 1;
            }

            cont = 0;
        }
        cont++;
        if(cor==1) wattron(cobra, COLOR_PAIR(3));
            mvwprintw(cobra, maçãy-1, maçãx, "~");
        if(cor==1) wattroff(cobra, COLOR_PAIR(3));
        for (i = 0; i <= score+3; i++) {
            
            if (i == 0)
            {
                if(cor==1) wattron(cobra, COLOR_PAIR(4));
                mvwprintw(cobra, cobraY[i], cobraX[i], "0");
                if(cor==1) wattroff(cobra, COLOR_PAIR(4));
            }
            else 
            {
                if(cor==1) wattron(cobra, COLOR_PAIR(4));
                mvwprintw(cobra, cobraY[i], cobraX[i], "o");
                if(cor==1) wattroff(cobra, COLOR_PAIR(4));
            }
    
        }
        //----------------------
        
        //mecanica
        if(cor==1) wattron(cobra, COLOR_PAIR(5));
        mvwprintw(cobra, maçãy, maçãx, "()");
        if(cor==1) wattroff(cobra, COLOR_PAIR(5));
        
        if(cobrax == maçãx && cobray == maçãy) {   
            maçãpegar=1;
            score++;
        }

        if(maçãpegar==1) {
            // Ajustado para reposicionar em função de Xallcobra e Yallcobra
            maçãx = Xallcobra + 2 + ((rand() % 28) * 2);
            maçãy = Yallcobra + 1 + (rand() % 22);
            maçãpegar=0;
        }

        // Colisão com as paredes ajustada para os limites de Xallcobra e Yallcobra
        if(cobray <= Yallcobra || cobray >= Yallcobra+25 || cobrax <= Xallcobra || cobrax >= Xallcobra+60) 
            derrota=1;

        if(tecla=='p' || derrota == 1){
            quit=1;
            break;
        }
        if(score==10){
            quit=0;
            derrota=0;
            break;
        }
        

        //---------------------

        wrefresh(cobra);
        napms(30);
    }
    
    wclear(cobra);
    if(derrota==1 && quit==1)
    {

        mvwprintw(cobra, Yallcobra+5,Xallcobra+14,"  ______");
        mvwprintw(cobra, Yallcobra+6,Xallcobra+14," /       \\");
        mvwprintw(cobra, Yallcobra+7,Xallcobra+14,"|  x   x  |");
        mvwprintw(cobra, Yallcobra+8,Xallcobra+14,"|    ^    |");
        mvwprintw(cobra, Yallcobra+9,Xallcobra+14," \\_______/ ");
        mvwprintw(cobra, Yallcobra+10, Xallcobra+14, "VOCE PERDEU");
        wrefresh(cobra);
        napms(2000);
    }
    else if(derrota==0 && quit==0) 
    {   
        while(trofeuy!=trofeuy-1)
        {
        erase();
        mvwprintw(cobra, trofeuy,Xallcobra,  "    _____ _          ");
        mvwprintw(cobra, trofeuy+1,Xallcobra,"   '.=====.'         "); 
        mvwprintw(cobra, trofeuy+2,Xallcobra," .-\\:      /-.    ");
        mvwprintw(cobra, trofeuy+3,Xallcobra," | (|:.     |) |   ");
        mvwprintw(cobra, trofeuy+4,Xallcobra,"  '-|:.     |-'     ");
        mvwprintw(cobra, trofeuy+5,Xallcobra,"   \\::.    /      ");
        mvwprintw(cobra, trofeuy+6,Xallcobra,"    '::. .'        ");
        mvwprintw(cobra, trofeuy+7,Xallcobra,"      ) (           ");
        mvwprintw(cobra, trofeuy+8,Xallcobra,"     .' '.           ");
        mvwprintw(cobra, trofeuy+9,Xallcobra,"    -------          ");
        
        mvwprintw(cobra, Yallcobra+10,Xallcobra,"VOCE GANHOU!");
        mvwprintw(cobra,Yallcobra+11,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+12,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+13,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+14,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+15,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+16,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+17,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+18,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+19,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+20,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+21,Xallcobra,"                                 ");
        mvwprintw(cobra,Yallcobra+22,Xallcobra,"                                 ");
        trofeuy--;
        wrefresh(stdscr);
    }
    napms(2000);
        wrefresh(cobra);
        (*jogarcelular)++;
        napms(3000);
    }


    wrefresh(cobra);
    nodelay(cobra, FALSE);
    tecla=getch();
    if(tecla=='p')
        endwin();

    return 1;
}