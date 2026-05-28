#include <ncurses.h>

int prova_complexa(int *cor,int *acertos) 
{
    initscr();
    curs_set(0);
    WINDOW *prova_complexa = newwin(LINES, COLS, 0, 0);
    keypad(prova_complexa,TRUE);
    nodelay(prova_complexa,TRUE);
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_WHITE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_GREEN,COLOR_WHITE);
    init_pair(4,COLOR_RED,COLOR_WHITE);
    init_pair(5,COLOR_YELLOW,COLOR_WHITE);
    init_pair(6,COLOR_BLACK,COLOR_WHITE);
    
    
    // Posições base globais
    int Xall = 40, Yall = 3;
    int tecla = 0, i, j;
    int marcar = 0;
    int marcar_confirmacao = 0; 
    int certeza=0;
    int confirmando = 0; 
    int resposta_dada = 0;
    
    int resposta[5],respostacerta[5]={1,1,4,2,0};
    char *confirmacao[2]={ "sim, entregar","não, revisar"};
    //RODA PRA TESTAR
    // Vetores com o espaçamento exato embutido (81 caracteres entre as barras)
// --- DECLARAÇÃO DAS OPÇÕES (Com 81 espaços exatos para referência no seu código) ---
    
    char *questao1[5] = {
        " [A] 0,4886                                                                      ",    
        " [B] 0,5112                                                                      ", 
        " [C] 0,5193                                                                      ", 
        " [D] 0,5224                                                                      ", 
        " [E] 0,5385                                                                      "
    };
    
    
    char *questao2[5] = {
        " [A] -10                                                                         ",     
        " [B] -8                                                                          ", 
        " [C] -6                                                                          ", 
        " [D] -4                                                                          ", 
        " [E] -2                                                                          "
    };
    
    
    char *questao3[5] = {
        " [A] pi^2                                                                     ", 
        " [B] pi^4/324                                                                    ", 
        " [C] pi^2/50                                                                     ", 
        " [D] pi^2/16                                                                     ", 
        " [E] pi^2/18                                                                     "
    };

    char *questao4[5] = {
        " [A] Det(M) = 0                                                                  ", 
        " [B] Det(M) = sin(2x)                                                            ", 
        " [C] Det(M) = 1                                                                  ", 
        " [D] Det(M) = cos(2x)                                                            ", 
        " [E] Det(M) = cos(x/2)                                                           "
    };

    char *questao5[5] = {
        " [A] 1 cor                                                                       ", 
        " [B] 2 cores                                                                     ", 
        " [C] 3 cores                                                                     ", 
        " [D] 4 cores                                                                     ", 
        " [E] 5 cores                                                                     "
    };
        mvwprintw(prova_complexa, Yall-1, Xall,"Droga");
    wrefresh(prova_complexa);
    napms(400);

        mvwprintw(prova_complexa, Yall-1, Xall+5,",Droga");
    wrefresh(prova_complexa);
    napms(400);

        mvwprintw(prova_complexa, Yall-1, Xall+10,",Droga!");
    wrefresh(prova_complexa);
    napms(1500);

    mvwprintw(prova_complexa, Yall, Xall,"Eu não estudei...");
    wrefresh(prova_complexa);
    napms(3000);
    while (tecla != 'p')
    {
        int Yprova = Yall;
        int Xprova = Xall;
        
        tecla = wgetch(prova_complexa);
        werase(prova_complexa); 
        
        // --- CABEÇALHO ---
        if(*cor==1) wattron(prova_complexa, COLOR_PAIR(1));
        mvwprintw(prova_complexa, Yprova++, Xprova, "|=================================================================================|");     
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                     UFRRJ                                       |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                        PROVA DE MATEMATICA AVANCADA                             |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 1 ---
        mvwprintw(prova_complexa, Yprova++, Xprova, "| QUESTAO 1: Considerando o log de 13,72 na base 45 = 0,6880 e                    |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|           e o log  de 6125 na base 45 = 2,2908, a alternativa                   |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|           que mais se aproxima da representacao decimal do log                  |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|           de 7 na base 45?                                                      |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [A] 0,4886                                                                      |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [B] 0,5112                                                                      |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [C] 0,5193                                                                      |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [D] 0,5224                                                                      |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [E] 0,5385                                                                      |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 2 ---
        mvwprintw(prova_complexa, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| QUESTAO 2: Seja p(x) = x^3+bx^2+cx+d um polinomio com coeficientes reais        |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|            se todas as raizes de p(x)=-p(2-x),                                  |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|            entao o menor valor para p(0) e:                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [A] -10                                                                         |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [B] -8                                                                          |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [C] -6                                                                          |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [D] -4                                                                          |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [E] -2                                                                          |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 

        // --- QUESTÃO 3 ---
        mvwprintw(prova_complexa, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| QUESTAO 3: sejam x,y pertencentes a ]0,pi/2[ satisfazendo as equacoes:          |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|     tan(y).tan(y/2)=cos(2x).sec(y)                                              |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|     sen(y)/cos(x)+cos(x)/sen(y)=2                                               |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|     O produto de todos os valores de x e y desse sistema e:                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [A] pi^2/24                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [B] pi^4/324                                                                    |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [C] pi^2/50                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [D] pi^2/16                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [E] pi^2/18                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 

        // --- QUESTÃO 4 ---
        mvwprintw(prova_complexa, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| QUESTAO 4: Um vetor no plano e rotacionado por uma matriz de transformacao.     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| Calcule o determinante da matriz de rotacao M dada abaixo:                      |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                             |  cos(x)   -sin(x)  |                              |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                         M = |                    |                              |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                             |  sin(x)    cos(x)  |                              |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [A] Det(M) = 0                                                                  |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [B] Det(M) = sin(2x)                                                            |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [C] Det(M) = 1                                                                  |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [D] Det(M) = cos(2x)                                                            |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [E] Det(M) = cos(x/2)                                                           |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 

        // --- QUESTÃO 5 ---
        mvwprintw(prova_complexa, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| QUESTAO 5: Seja A = {1,2,3,4,5,7,8}                                             |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| A quantidade de bijecoes F:A->A que satisfazem:F(1)<F(5)<F(3)<F(7)<F(2)         |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [A] 1 cor                                                                       |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [B] 2 cores                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [C] 3 cores                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [D] 4 cores                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "| [E] 5 cores                                                                     |"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_complexa, Yprova++, Xprova, "|=================================================================================|"); 
        
        wattroff(prova_complexa, COLOR_PAIR(1));

        if (!confirmando) {
            switch(tecla)
            {
                case 'a': Xall--; break;
                case 'd': Xall++; break;
                case 's': Yall--; break;
                case 'w': Yall++; break;
            }
        }

        if(resposta_dada < 5)
        {
            if(resposta_dada == 0)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_complexa, Yall + 15 + i, Xall + 1, "%s", questao1[i]);
                        wattroff(prova_complexa, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 1)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_complexa, COLOR_PAIR(2));
                        
                        
                        mvwprintw(prova_complexa, Yall + 30 + i, Xall + 1, "%s", questao2[i]);
                        wattroff(prova_complexa, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 2)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_complexa, COLOR_PAIR(2));
                        
                        
                        mvwprintw(prova_complexa, Yall + 50 + i, Xall + 1, "%s", questao3[i]);
                        wattroff(prova_complexa, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 3)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_complexa, Yall + 66 + i, Xall + 1, "%s", questao4[i]);
                        wattroff(prova_complexa, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 4)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_complexa, COLOR_PAIR(2));
                        mvwprintw(prova_complexa, Yall + 84 + i, Xall + 1, "%s", questao5[i]);
                        wattroff(prova_complexa, COLOR_PAIR(2));
                    }
                }
            }

            // Controle do Seletor
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
        
        wrefresh(prova_complexa); 
        napms(30);

        // --- TELA DE CONFIRMAÇÃO ---
        int estado_confirmacao = 2; // Variável inteira dedicada criada para sanar o erro do Lvalue
        if (confirmando == 1)
        {
            estado_confirmacao = 2;
            int Ycentro = Yall + 35; 
            int Xcentro = Xall + 5;
            mvwprintw(prova_complexa, Ycentro,     Xcentro, "/====================================================\\");
            mvwprintw(prova_complexa, Ycentro + 1, Xcentro, "|      Tem certeza? Vai entregar a prova?            | ");
            mvwprintw(prova_complexa, Ycentro + 2, Xcentro, "|                                                    | ");
            mvwprintw(prova_complexa, Ycentro + 4, Xcentro, "\\====================================================/");
            
            mvwprintw(prova_complexa, Ycentro + 3, Xcentro, "|   ");
            
            wmove(prova_complexa, Ycentro + 3, Xcentro + 4);
            if (marcar_confirmacao == 0) if(*cor==1) wattron(prova_complexa, A_REVERSE);
            wprintw(prova_complexa, "%s", confirmacao[0]);
            if (marcar_confirmacao == 0) wattroff(prova_complexa, A_REVERSE);

            wprintw(prova_complexa, "   ");

            wmove(prova_complexa, Ycentro + 3, Xcentro + 30);
            if (marcar_confirmacao == 1) if(*cor==1) wattron(prova_complexa, A_REVERSE);
            wprintw(prova_complexa, "%s", confirmacao[1]);
            if (marcar_confirmacao == 1) wattroff(prova_complexa, A_REVERSE);

            mvwprintw(prova_complexa, Ycentro + 3, Xcentro + 53, "|");
            wrefresh(prova_complexa);

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
    for(i=0;i<5;i++)
    {
        if(resposta[i]==respostacerta[i])
            (*acertos)++;
    }
    
    werase(prova_complexa);
    
    
    mvwprintw(prova_complexa, 7, 5, "Acertos: %d", *acertos);
    wrefresh(prova_complexa);
    
    nodelay(prova_complexa, FALSE);
    
    
    wgetch(prova_complexa);

    delwin(prova_complexa);
    endwin();
}