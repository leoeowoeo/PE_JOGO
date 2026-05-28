#include <ncurses.h>

int main(){
    initscr();
    curs_set(0);
    WINDOW *stdscr = newwin(LINES, COLS, 0, 0);
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);
    
    // Posições base globais
    int Xall = 40, Yall = 3;
    int tecla = 0, i, j;
    int marcar = 0;
    int marcar_confirmacao = 0; 
    int acerto=0;
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
    
    while (tecla != 'p')
    {

        // Reseta as variáveis de desenho para a base da folha a cada frame
        int Yprova = Yall;
        int Xprova = Xall;
        
        tecla = getch();
        werase(stdscr); 
        
        // --- CABEÇALHO ---
        mvwprintw(stdscr, Yprova++, Xprova, "|=================================================================================|");     
        mvwprintw(stdscr, Yprova++, Xprova, "|                                     UFRRJ                                       |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                              PROVA DE MATEMATICA                                |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 1 ---
        mvwprintw(stdscr, Yprova++, Xprova, "| QUESTAO 1: Ache 'x' na equacao abaixo:                                          |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                             4x  -  7  =  2x  +  5                               |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [A] x = 3                                                                       |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [B] x = 6                                                                       |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [C] x = 2                                                                       |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [D] x = 8                                                                       |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [E] ta ali o, achei                                                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 2 ---
        mvwprintw(stdscr, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| QUESTAO 2: Calcule a area da figura:                                            |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                           +-----------------------+                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                           |       +-------+       |                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                         5 |       | Q = 4 |       |                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                           |       +-------+       |                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                           +-----------------------+                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                       10                                        |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [A] Area = 46                                                                   |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [B] Area = 50                                                                   |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [C] Area = 42                                                                   |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [D] Area = 34                                                                   |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [E] Area = 510                                                                  |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 3 ---
        mvwprintw(stdscr, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| QUESTAO 3: Se todo bixo da Rural e ansioso, e alguns ansiosos                   |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| gostam de programacao, podemos afirmar que:                                     |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [A] Todo bixo gosta de programacao.                                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [B] Nenhum bixo gosta de programacao.                                           |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [C] E possivel que algum bixo goste de programacao.                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [D] Se bixo da rural gosta de programacao ele e ansioso                         |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [E] Eu estou ansioso agora                                                      |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 4 ---
        mvwprintw(stdscr, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| QUESTAO 4: Um algoritmo precisa processar uma matriz quadrada 5x5.              |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| Quantos elementos no total essa matriz possui?                                  |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [A] 10 elementos                                                                |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [B] 25 elementos                                                                |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [C] 5 elementos                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [D] 20 elementos                                                                |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [E] Alguns elementos ai                                                         |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        
        // --- QUESTÃO 5 ---
        mvwprintw(stdscr, Yprova++, Xprova, "|=================================================================================|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| QUESTAO 5: O grafico abaixo representa o desespero de um estudante pelo         |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| numero de semanas de aula. Qual o valor aproximado no pico?                     |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                               Nivel |                                           |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                100  |          /\\                               |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                 50  |    /\\   /  \\                              |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                  0  +----+----+----+                            |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                               Semana: 0    2    4                               |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [A] Desespero = 0                                                               |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [B] Desespero = 50                                                              |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [C] Desespero = 100                                                             |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [D] O desespero nao pode ser medido in numeros decimais                         |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "| [E] Nao mensuravel                                                              |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|---------------------------------------------------------------------------------|"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|                                                                                 |"); 
        mvwprintw(stdscr, Yprova++, Xprova, "|=================================================================================|"); 

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

        // --- RENDERIZAÇÃO E SELEÇÃO DAS ALTERNATIVAS ---
        if(resposta_dada < 5)
        {
            if(resposta_dada == 0)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        wattron(stdscr, A_REVERSE);
                        mvwprintw(stdscr, Yall + 10 + i, Xall + 2, "%s", questao1[i]);
                        wattroff(stdscr, A_REVERSE);
                    }
                }
            }
            else if(resposta_dada == 1)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        wattron(stdscr, A_REVERSE);
                        mvwprintw(stdscr, Yall + 28 + i, Xall + 2, "%s", questao2[i]);
                        wattroff(stdscr, A_REVERSE);
                    }
                }
            }
            else if(resposta_dada == 2)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        wattron(stdscr, A_REVERSE);
                        mvwprintw(stdscr, Yall + 40 + i, Xall + 2, "%s", questao3[i]);
                        wattroff(stdscr, A_REVERSE);
                    }
                }
            }
            else if(resposta_dada == 3)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        wattron(stdscr, A_REVERSE);
                        mvwprintw(stdscr, Yall + 52 + i, Xall + 2, "%s", questao4[i]);
                        wattroff(stdscr, A_REVERSE);
                    }
                }
            }
            else if(resposta_dada == 4)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        wattron(stdscr, A_REVERSE);
                        mvwprintw(stdscr, Yall + 69 + i, Xall + 2, "%s", questao5[i]);
                        wattroff(stdscr, A_REVERSE);
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
        
        wrefresh(stdscr); 
        napms(30);

        // --- TELA DE CONFIRMAÇÃO ---
        if (resposta_dada == 5 && confirmando == 1)
        {
            int Ycentro = Yall + 35; // Posiciona a caixa mais ou menos no meio da folha
            int Xcentro = Xall + 5;

            // Desenha uma caixinha de aviso estilizada por cima do texto
            mvwprintw(stdscr, Ycentro,     Xcentro, "/====================================================\\");
            mvwprintw(stdscr, Ycentro + 1, Xcentro, "|      TEM CERTEZA DAS SUAS DECOSOES?                |");
            mvwprintw(stdscr, Ycentro + 2, Xcentro, "|                                                    |");
            mvwprintw(stdscr, Ycentro + 4, Xcentro, "\\====================================================/");
            
            mvwprintw(stdscr, Ycentro + 3, Xcentro, "|   ");
            
            if (marcar_confirmacao == 0) wattron(stdscr, A_REVERSE);
            wprintw(stdscr, "%s", confirmacao[0]);
            if (marcar_confirmacao == 0) wattroff(stdscr, A_REVERSE);
            
            wprintw(stdscr, "   ");

            if (marcar_confirmacao == 1) wattron(stdscr, A_REVERSE);
            wprintw(stdscr, "%s", confirmacao[1]);
            if (marcar_confirmacao == 1) wattroff(stdscr, A_REVERSE);

            wprintw(stdscr, "  |");
            wrefresh(stdscr);

            // Captura as respostas específicas para essa tela
            switch(tecla)
            {
                case KEY_UP:
                case 'w':
                case KEY_DOWN:
                case 's':
                    marcar_confirmacao = !marcar_confirmacao;
                    break;

                case '\n':
                    if (marcar_confirmacao == 0) {
                        // O jogador confirmou! Avança para o Ato III (Castigo) ou calcula o C.H.U.T.E.
                        confirmando = 2; // Faz virar 5, saindo do bloco de perguntas // Desliga o aviso
                    } else {
                        // O jogador amarelou. Volta para a prova para ele revisar.
                        resposta_dada = 4;
                        marcar = 0;
                        confirmando = 0; // Desliga o aviso e o jogo volta ao normal
                    }
                    break;
            }

            if (confirmando == 2) {
                break;
            }
        }
    }

    for(i=0;i<5;i++)
    {
        if(resposta[i]==respostacerta[i])
            acerto++;
    }
    
    werase(stdscr);
    mvprintw(0,0,"%d",acerto);
    wrefresh(stdscr);
    
    nodelay(stdscr, FALSE);
    getch();

    delwin(stdscr);
    endwin();
    return 0;
}
/*
B
A
C
B
C
*/