#include <ncurses.h>

int prova_simples(int *cor, int *acertos){
    initscr();
    curs_set(0);
    WINDOW *prova_simples = newwin(LINES, COLS, 0, 0);
    keypad(prova_simples,TRUE);
    nodelay(prova_simples,TRUE);
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
    int resposta[5],respostacerta[5]={1,0,2,1,2};
    
    char *questao1[5] = {"[A] X = 3",    "[B] X = 6", "[C] X = 2", "[D] X = 8", "[E] ta ali o, achei"};
    char *questao2[5] = {"[A] Area = 46",     "[B] Area = 50", "[C] Area = 42", "[D] Area = 34", "[E] Area = 510"};
    char *questao3[5] = {"[A] Todo bixo gosta de programacao.", "[B] Nenhum bixo gosta de programacao.", "[C] E possivel que algum bixo goste de programacao.", "[D] Se bixo da rural gosta de programacao ele e ansioso", "[E] Eu estou ansioso agora"};
    char *questao4[5] = {"[A] 10 elementos",  "[B] 25 elementos", "[C] 5 elementos", "[D] 20 elementos", "[E] Alguns elementos ai"};
    char *questao5[5] = {"[A] Desespero = 0", "[B] Desespero = 50", "[C] Desespero = 100", "[D] O desespero nao pode ser medido in numeros decimais", "[E] Nao mensuravel"};
    
    char *confirmacao[2] = {"[S] Sim, entregar a prova", "[N] Nao, quero rever"};
    werase(prova_simples);
        mvwprintw(prova_simples, Yall-1, Xall,"hmmmm");
    wrefresh(prova_simples);
    napms(1000);

        mvwprintw(prova_simples, Yall-1, Xall+5,",estudei");
    wrefresh(prova_simples);
    napms(2000);

        mvwprintw(prova_simples, Yall-1, Xall+13,",e dormi bem, acho que ta tudo certo entao!");
    wrefresh(prova_simples);
    napms(2000);
    
    while (tecla != 'p')
    {

        int Yprova = Yall;
        int Xprova = Xall;
        
        tecla = wgetch(prova_simples);
        werase(prova_simples); 
        
        // --- CABEÇALHO ---
        if(*cor==1) wattron(prova_simples, COLOR_PAIR(1));
        mvwprintw(prova_simples, Yprova++, Xprova, "|=================================================================================|");     
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                     UFRRJ                                       |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                              PROVA DE MATEMATICA                                |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 1 ---
        mvwprintw(prova_simples, Yprova++, Xprova, "| QUESTAO 1: Ache 'x' na equacao abaixo:                                          |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                             4x  -  7  =  2x  +  5                               |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [A] X = 3                                                                       |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [B] X = 6                                                                       |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [C] X = 2                                                                       |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [D] X = 8                                                                       |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [E] ta ali o, achei                                                             |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 2 ---
        mvwprintw(prova_simples, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| QUESTAO 2: Calcule a area da figura nao vermelha:                               |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                           +-----------------------+                             |"); 
        mvwprintw(prova_simples, Yprova,   Xprova, "|                           |                       |                             |"); 
        wattron(prova_simples, COLOR_PAIR(4));
        mvwprintw(prova_simples, Yprova++, Xprova+36,                                 "+-------+"); 
        wattroff(prova_simples, COLOR_PAIR(4));
        wattron(prova_simples, COLOR_PAIR(1));
        mvwprintw(prova_simples, Yprova,   Xprova, "|                         5 |                       |                             |"); 
        wattron(prova_simples, COLOR_PAIR(4));
        mvwprintw(prova_simples, Yprova++, Xprova+36,                                 "| A = 4 |"); 
        wattroff(prova_simples, COLOR_PAIR(4));
        wattron(prova_simples, COLOR_PAIR(1));
        mvwprintw(prova_simples, Yprova,   Xprova, "|                           |                       |                             |"); 
        wattron(prova_simples, COLOR_PAIR(4));
        mvwprintw(prova_simples, Yprova++, Xprova+36,                                 "+-------+"); 
        wattroff(prova_simples, COLOR_PAIR(4));
        wattron(prova_simples, COLOR_PAIR(1));

        mvwprintw(prova_simples, Yprova++, Xprova, "|                           +-----------------------+                             |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                       10                                        |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [A] Area = 46                                                                   |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [B] Area = 50                                                                   |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [C] Area = 42                                                                   |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [D] Area = 34                                                                   |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [E] Area = 510                                                                  |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 

        
        // --- QUESTÃO 3 ---
        mvwprintw(prova_simples, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| QUESTAO 3: Se todo bixo da Rural eh ansioso, e alguns ansiosos                  |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| gostam de programacao, podemos afirmar que:                                     |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [A] Todo bixo gosta de programacao.                                             |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [B] Nenhum bixo gosta de programacao.                                           |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [C] E possivel que algum bixo goste de programacao.                             |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [D] Se bixo da rural gosta de programacao ele eh ansioso                        |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [E] Eu estou ansioso agora                                                      |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 4 ---
        mvwprintw(prova_simples, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| QUESTAO 4: Um algoritmo precisa processar uma matriz quadrada 5x5.              |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| Quantos elementos no total essa matriz possui?                                  |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [A] 10 elementos                                                                |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [B] 25 elementos                                                                |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [C] 5 elementos                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [D] 20 elementos                                                                |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [E] Alguns elementos ai                                                         |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 5 ---
        mvwprintw(prova_simples, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| QUESTAO 5: O grafico abaixo representa o desespero de um estudante pelo         |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| numero de semanas de aula. Qual o valor aproximado no pico?                     |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                               Nivel |                                           |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                100  |          /\\                               |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                 50  |    /\\   /  \\                              |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                  0  +----+----+----+                            |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                               Semana: 0    2    4                               |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [A] Desespero = 0                                                               |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [B] Desespero = 50                                                              |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [C] Desespero = 100                                                             |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [D] O desespero nao pode ser medido in numeros decimais                         |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "| [E] Nao mensuravel                                                              |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(prova_simples, Yprova++, Xprova, "|=================================================================================|"); 


        wattroff(prova_simples, COLOR_PAIR(1));

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
                        if(*cor==1) wattron(prova_simples, COLOR_PAIR(2));
                        mvwprintw(prova_simples, Yall + 10 + i, Xall + 2, "%s", questao1[i]);
                        wattroff(prova_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 1)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_simples, COLOR_PAIR(2));
                        mvwprintw(prova_simples, Yall + 28 + i, Xall + 2, "%s", questao2[i]);
                        wattroff(prova_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 2)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_simples, COLOR_PAIR(2));
                        mvwprintw(prova_simples, Yall + 40 + i, Xall + 2, "%s", questao3[i]);
                        wattroff(prova_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 3)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_simples, COLOR_PAIR(2));
                        mvwprintw(prova_simples, Yall + 52 + i, Xall + 2, "%s", questao4[i]);
                        wattroff(prova_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 4)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(prova_simples, COLOR_PAIR(2));
                        mvwprintw(prova_simples, Yall + 69 + i, Xall + 2, "%s", questao5[i]);
                        wattroff(prova_simples, COLOR_PAIR(2));
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
        
        wrefresh(prova_simples); 
        napms(30);

        // --- TELA DE CONFIRMAÇÃO ---
        if (confirmando == 1)
        {
            int Ycentro = Yall + 35;
            int Xcentro = Xall + 5;

            mvwprintw(prova_simples, Ycentro,     Xcentro, "/====================================================\\");
            mvwprintw(prova_simples, Ycentro + 1, Xcentro, "|      TEM CERTEZA DAS SUAS DECOSOES?                |");
            mvwprintw(prova_simples, Ycentro + 2, Xcentro, "|                                                    |");
            mvwprintw(prova_simples, Ycentro + 4, Xcentro, "\\====================================================/");
            
            mvwprintw(prova_simples, Ycentro + 3, Xcentro, "|   ");
            
            wmove(prova_simples, Ycentro + 3, Xcentro + 4);
            if (marcar_confirmacao == 0) if(*cor==1) wattron(prova_simples, A_REVERSE);
            wprintw(prova_simples, "%s", confirmacao[0]);
            if (marcar_confirmacao == 0) wattroff(prova_simples, A_REVERSE);
            
            wprintw(prova_simples, "   ");

            wmove(prova_simples, Ycentro + 3, Xcentro + 30);
            if (marcar_confirmacao == 1) if(*cor==1) wattron(prova_simples, A_REVERSE);
            wprintw(prova_simples, "%s", confirmacao[1]);
            if (marcar_confirmacao == 1) wattroff(prova_simples, A_REVERSE);

            mvwprintw(prova_simples, Ycentro + 3, Xcentro + 53, "|");
            wrefresh(prova_simples);

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
                        tecla = 'p';
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
    
    werase(prova_simples);
    mvwprintw(prova_simples, 7, 5, "Acertos: %d", *acertos);
    wrefresh(prova_simples);
    
    nodelay(prova_simples, FALSE);
    wgetch(prova_simples);

    delwin(prova_simples);
    endwin();
}
/*
Gabarito
B
A
C
B
C
*/