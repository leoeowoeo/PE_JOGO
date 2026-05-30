#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int mvwprintw_cansado_complexa(WINDOW *janela, int Yprova, int Xprova, const char *prova, int cansando);

int prova_cansado_complexa(int *cor,int *acertos) 
{
    initscr();
    curs_set(0);
    WINDOW *prova_cansado_complexa = newwin(LINES, COLS, 0, 0);
    keypad(prova_cansado_complexa,TRUE);
    nodelay(prova_cansado_complexa,TRUE);
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_WHITE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_GREEN,COLOR_WHITE);
    init_pair(4,COLOR_RED,COLOR_WHITE);
    init_pair(5,COLOR_YELLOW,COLOR_WHITE);
    init_pair(6,COLOR_BLACK,COLOR_WHITE);
    
    int Xall = 40, Yall = 0;
    int tecla = 0, i, j;
    int marcar = 0;
    int marcar_confirmacao = 0; 
    int certeza=0;
    int confirmando = 0; 
    int resposta_dada = 0;
    int cansando=2;
    int resposta[5],respostacerta[5]={1,1,4,2,0}; 

    char *questao1[5] = {
        " *[A] 0,4886                                                                      ",    
        " *[B] 0,5112                                                                      ", 
        " *[C] 0,5193                                                                      ", 
        " *[D] 0,5224                                                                      ", 
        " *[E] 0,5385                                                                      "
    };
    
    char *questao2[5] = {
        " *[A] -10                                                                         ",     
        " *[B] -8                                                                          ", 
        " *[C] -6                                                                          ", 
        " *[D] -4                                                                          ", 
        " *[E] -2                                                                          "
    };
    
    char *questao3[5] = {
        " *[A] pi^2                                                                     ", 
        " *[B] pi^4/324                                                                    ", 
        " *[C] pi^2/50                                                                     ", 
        " *[D] pi^2/16                                                                     ", 
        " *[E] pi^2/18                                                                     "
    };

    char *questao4[5] = {
        " *[A] Det(M) = 0                                                                  ", 
        " *[B] Det(M) = sin(2x)                                                            ", 
        " *[C] Det(M) = 1                                                                  ", 
        " *[D] Det(M) = cos(2x)                                                            ", 
        " *[E] Det(M) = cos(x/2)                                                           "
    };

    char *questao5[5] = {
        " *[A] 1 cor                                                                       ", 
        " *[B] 2 cores                                                                     ", 
        " *[C] 3 cores                                                                     ", 
        " *[D] 4 cores                                                                     ", 
        " *[E] 5 cores                                                                     "
    };
    
    char *confirmacao[2] = {
        " [S] Sim, entregar a prova                                                       ", 
        " [N] Nao, quero rever                                                            "
    };
    
    mvwprintw(prova_cansado_complexa, Yall-1, Xall,"Droga");
    wrefresh(prova_cansado_complexa);
    napms(300);

        mvwprintw(prova_cansado_complexa, Yall-1, Xall+5,",Droga");
    wrefresh(prova_cansado_complexa);
    napms(300);

        mvwprintw(prova_cansado_complexa, Yall-1, Xall+10,",Droga!");
    wrefresh(prova_cansado_complexa);
    napms(500);

    mvwprintw(prova_cansado_complexa, Yall, Xall,"Eu não estudei e...");
    wrefresh(prova_cansado_complexa);
    napms(1000);

    mvwprintw(prova_cansado_complexa, Yall+1, Xall,"Eu to...");
    wrefresh(prova_cansado_complexa);
    napms(1500);
    
    mvwprintw(prova_cansado_complexa, Yall+1, Xall+8,"meio...");
    wrefresh(prova_cansado_complexa);
    napms(1500);
    
    mvwprintw(prova_cansado_complexa, Yall+1, Xall+15,"cansado    ");
    wrefresh(prova_cansado_complexa);
    napms(2000);

    werase(prova_cansado_complexa);
    while (tecla != 'p')
    {
        int Yprova = Yall;
        int Xprova = Xall;
        
        tecla = wgetch(prova_cansado_complexa);
        werase(prova_cansado_complexa); 
        
        // --- CABEÇALHO ---
        if(*cor==1) wattron(prova_cansado_complexa, COLOR_PAIR(1));
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|=================================================================================|",cansando);     
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                     UFRRJ                                       |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                        PROVA DE MATEMATICA AVANCADA                             |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        
        // --- QUESTÃO 1 ---
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| QUESTAO 1: Considerando o log de 13,72 na base 45 = 0,6880 e                    |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|           e o log  de 6125 na base 45 = 2,2908, a alternativa                   |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|           que mais se aproxima da representacao decimal do log                  |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|           de 7 na base 45?                                                      |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [A] 0,4886                                                                      |",cansando); //Yall+16
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [B] 0,5112                                                                      |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [C] 0,5193                                                                      |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [D] 0,5224                                                                      |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [E] 0,5385                                                                      |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        
        // --- QUESTÃO 2 ---
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| QUESTAO 2: Seja p(x) = x^3+bx^2+cx+d um polinomio com coeficientes reais        |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|            se todas as raizes de p(x)=-p(2-x),                                  |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|            entao o menor valor para p(0) e:                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [A] -10                                                                         |",cansando);//Yall+31
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [B] -8                                                                          |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [C] -6                                                                          |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [D] -4                                                                          |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [E] -2                                                                          |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 

        // --- QUESTÃO 3 ---
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| QUESTAO 3: sejam x,y pertencentes a ]0,pi/2[ satisfazendo as equacoes:          |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|     tan(y).tan(y/2)=cos(2x).sec(y)                                              |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|     sen(y)/cos(x)+cos(x)/sen(y)=2                                               |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|     O produto de todos os valores de x e y desse sistema e:                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [A] pi^2/24                                                                     |",cansando); //Yall+52
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [B] pi^4/324                                                                    |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [C] pi^2/50                                                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [D] pi^2/16                                                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [E] pi^2/18                                                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 

        // --- QUESTÃO 4 ---
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| QUESTAO 4: Um vetor no plano e rotacionado por uma matriz de transformacao.     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| Calcule o determinante da matriz de rotacao M dada abaixo:                      |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                             |  cos(x)   -sin(x)  |                              |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                         M = |                    |                              |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                             |  sin(x)    cos(x)  |                              |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [A] Det(M) = 0                                                                  |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [B] Det(M) = sin(2x)                                                            |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [C] Det(M) = 1                                                                  |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [D] Det(M) = cos(2x)                                                            |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [E] Det(M) = cos(x/2)                                                           |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 

        // --- QUESTÃO 5 ---
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| QUESTAO 5: Seja A = {1,2,3,4,5,7,8}                                             |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| A quantidade de bijecoes F:A->A que satisfazem:F(1)<F(5)<F(3)<F(7)<F(2)         |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [A] 1 cor                                                                       |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [B] 2 cores                                                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [C] 3 cores                                                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [D] 4 cores                                                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "| [E] 5 cores                                                                     |",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado_complexa(prova_cansado_complexa, Yprova++, Xprova, "|=================================================================================|",cansando); 
        
        wattroff(prova_cansado_complexa, COLOR_PAIR(1));

        // --- MOVIMENTAÇÃO DA PÁGINA (WASD) ---
        if (!confirmando) {
            switch(tecla)
            {
                case 'a': Xall--; break;
                case 'd': Xall++; break;
                case 's': Yall--; break;
                case 'w': Yall++; break;
            }
        }

        // --- SELEÇÃO DAS ALTERNATIVAS ---
        if(resposta_dada < 5)
        {
            if(resposta_dada == 0)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_cansado_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_cansado_complexa, Yall + 15 + i, Xall, "%s", questao1[i]);
                        wattroff(prova_cansado_complexa, COLOR_PAIR(2));
                        
                    }
                }
            }
            else if(resposta_dada == 1)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_cansado_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_cansado_complexa, Yall + 30 + i, Xall, "%s", questao2[i]);
                        wattroff(prova_cansado_complexa, COLOR_PAIR(2));
                        
                    }
                }
            }
            else if(resposta_dada == 2)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_cansado_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_cansado_complexa, Yall + 50 + i, Xall , "%s", questao3[i]);
                        wattroff(prova_cansado_complexa, COLOR_PAIR(2));
                        
                    }
                }
            }
            else if(resposta_dada == 3)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_cansado_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_cansado_complexa, Yall + 66 + i, Xall, "%s", questao4[i]);
                        wattroff(prova_cansado_complexa, COLOR_PAIR(2));
                        
                    }
                }
            }
            else if(resposta_dada == 4)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_cansado_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_cansado_complexa, Yall + 84 + i, Xall, "%s", questao5[i]);
                        wattroff(prova_cansado_complexa, COLOR_PAIR(2));
                        /* REMOVIDO EM CAIXA ALTA: O BLOCO IF(MARCAR==0&&TECLA=='\n') QUE INCREMENTAVA ACERTO FOI RETIRADO DAQUI */
                    }
                }
            }

            switch(tecla)
            {
                case KEY_UP: 
                    marcar--;
                    if(marcar < 0) marcar = 4;
                    break;

                case KEY_DOWN: 
                    marcar++;
                    if(marcar > 4) marcar = 0;
                    break;
                
                case '\n':
                    resposta[resposta_dada] = marcar;
                    if (resposta_dada == 4) {
                        confirmando = 1;
                        marcar_confirmacao = 0;
                        resposta_dada++; 
                        tecla = 0; 
                    } else {
                        resposta_dada++; 
                        marcar = 0;      
                    }     
                    break;
            }
        }
        
        wrefresh(prova_cansado_complexa); 
        napms(30);

        // --- TELA  ---
        int confirmacaoDEF = 2;
        if (confirmando == 1)
        {
            confirmacaoDEF = 2;
            int Ycentro = Yall + 35; 
            int Xcentro = Xall + 5;
            mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro,     Xcentro, "/====================================================\\",cansando);
            mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro + 1, Xcentro, "|      Tem certeza? Vai entregar a prova?            | ",cansando);
            mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro + 2, Xcentro, "|                                                    | ",cansando);
            mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro + 4, Xcentro, "\\====================================================/",cansando);
            
            mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro + 3, Xcentro, "|   ",cansando);
            
            if (marcar_confirmacao == 0) if(*cor==1) wattron(prova_cansado_complexa, A_REVERSE);
                mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro + 3, Xcentro + 4, confirmacao[0], cansando);

            if (marcar_confirmacao == 0) wattroff(prova_cansado_complexa, A_REVERSE);
            
            wprintw(prova_cansado_complexa, "   ");

            if (marcar_confirmacao == 1) if(*cor==1) wattron(prova_cansado_complexa, A_REVERSE);
                mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro + 3, Xcentro + 30, confirmacao[1], cansando);
            if (marcar_confirmacao == 1) wattroff(prova_cansado_complexa, A_REVERSE);

            mvwprintw_cansado_complexa(prova_cansado_complexa, Ycentro + 3, Xcentro + 53, "|",cansando);
            wrefresh(prova_cansado_complexa);

            switch(tecla)
            {
                case KEY_LEFT:
                case 'a':
                    marcar_confirmacao = 0;
                    break;
                case KEY_RIGHT:
                case 'd':
                    marcar_confirmacao = 1;
                    break;

                case '\n':
                    if (marcar_confirmacao == 0) {
                        tecla = 'p'; // Quebra o laço principal para finalizar
                    } else {
                        resposta_dada = 4;
                        marcar = 0;
                        confirmando = 0; 
                    }
                    break;
            }
        }
    }

    *acertos = 0; 
    for(i = 0; i < 5; i++) 
    {
        if(resposta[i] == respostacerta[i]) 
        {
            (*acertos)++;
        }
    }
    
    werase(prova_cansado_complexa);
    mvwprintw(prova_cansado_complexa, 7, 5, "Acertos: %d", *acertos);
    wrefresh(prova_cansado_complexa);
    
    // ALTERADO EM CAIXA ALTA: MUDADO DE FALSE PARA DESATIVAR O MODO NODELAY DA JANELA PROVA_CANSADO_COMPLEXA ESPECIFICAMENTE ANTES DE TRAVAR A TELA
    nodelay(prova_cansado_complexa, FALSE); /* ALTERADO: AGORA DESATIVA O NODELAY DIRETAMENTE NA JANELA QUE ESTÁ SENDO USADA */
    
    // ALTERADO EM CAIXA ALTA: MUDADO DE GETCH() PARA WGETCH(PROVA_CANSADO_COMPLEXA) PARA GARANTIR QUE O TERMINAL PARE DE VERDADE NESSA TELA E SÓ FECHE QUANDO UMA TECLA FOR PRESSIONADA
    wgetch(prova_cansado_complexa); /* ALTERADO: TRAVA A TELA DE ACERTOS E SÓ FECHA QUANDO O JOGADOR APERTAR QUALQUER TECLA */

    delwin(prova_cansado_complexa);
    endwin();
}

int mvwprintw_cansado_complexa(WINDOW *janela, int Yprova, int Xprova, const char *prova, int cansando)// não estava funcionando com prova[151], tive que por *prova, como um ponteiro que aponta pro primeiro tamanho do prova, por algum motivo...
{ 
    if (Yprova < 0 || Yprova >= LINES) return 0;// eu add isso aqui, pq a prova tava bugando qnd ia pra cima dms, ela printava tudo torto

    int tamanho = strlen(prova);
    char cansaco[13] = {'?', '?', '~', '#', '@', '$', '%', '&', '*', '_', '+', '=', '-'};
    int caractere_aleatorio;
    int i;


    for(i = 0; i < tamanho; i++)// esse tmb confere se ta dentro do limite da tela, mas pro x
    {
        int Xatual = Xprova + i;

    if (Xatual >= 0 && Xatual < COLS)
        {
            mvwaddch(janela, Yprova, Xprova + i, ' '); // aqui é pra printar os espaços
        }
    }

    for(i=0;i<tamanho;i++)
    {
        int Xatual = Xprova + i;
        if (Xatual >= 0 && Xatual < COLS)
        {
            if(rand()%400<=cansando)
            {
                caractere_aleatorio= rand() % 13;
                mvwaddch(janela,Yprova, Xprova+i,cansaco[caractere_aleatorio]);
            }
            else
                
                mvwaddch(janela,Yprova, Xprova+i,prova[i]);
        }
    }
    return 0;
}



/*gabarito 

B
B
E
C
A
*/