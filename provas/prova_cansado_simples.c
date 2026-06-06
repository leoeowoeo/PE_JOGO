#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

// Função que substitui mvwprintw e gera o efeito de desmoronamento
int mvwprintw_cansado(WINDOW *janela, int Yprova, int Xprova, const char *prova, int cansando);

int prova_cansado_simples(int *cor,int *acertos)
{
    initscr();
    start_color();
    curs_set(0);
    WINDOW *provacansado_simples = newwin(LINES, COLS, 0, 0);
    keypad(provacansado_simples,TRUE);
    nodelay(provacansado_simples,TRUE);
    
    init_pair(1,COLOR_BLACK,COLOR_WHITE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_GREEN,COLOR_WHITE);
    init_pair(4,COLOR_RED,COLOR_WHITE);
    init_pair(5,COLOR_YELLOW,COLOR_WHITE);
    init_pair(6,COLOR_BLACK,COLOR_WHITE);
flushinp();
    
    // Posições base globais
    int Xall = 40, Yall = 3;
    int tecla = 0, i=0, j;
    int marcar = 0;
    int marcar_confirmacao = 0; 
    int confirmado = 0; 
    int resposta_dada = 0;
    int resposta[5],respostacerta[5]={1,0,2,1,2};
    int cansando=2;
    char *confirmacao[2] = {"[S] Sim, entregar a prova", "[N] Nao, quero rever"};
    
    // Vetores atualizados exatamente com os textos modificados da prova
    char *questao1[5] = {
        "*[A] 7 = 3                                    ",
        "*[B] 14 = 12                                  ",
        "*[C] 8 = infinito de lado                     ",
        "*[D] 0 = oito                                 ",
        "*[E] 13 . 4 = 664                             "
    };
    char *questao2[5] = {
        "*[A] Arestaaas = 46                           ",
        "*[B] Ar                                       ",
        "*[C] AREa = 42                                ",
        "*[D] A r e a = 3 4                            ",
        "*[E] Area = 5 10 toneladas                    "
    };
    char *questao3[5] = {
        "*[A] gosta de soninnho.                       ",
        "*[B] Nenhum bixo.                             ",
        "*[C] E pssveiol mprraaogr.                    ",
        "*[D] Ele eh ansioso                           ",
        "*[E] Eu eoust  ansiaoa  sgo  or               "
    };
    char *questao4[5] = {
        "*[A] tosemen      25 ele                      ",
        "*[B] m10 eluns s aientos                      ",
        "*[C] 5ntos   0 eleme                          ",
        "*[D] 2nto elemes      elemento                ",
        "*[E] Algum ai                                 "
    };
    char *questao5[5] = {
        "*[A] pero 0Deses ? =                          ",
        "*[B] De = or s  50   oo esperad               ",
        "*[C] Desesperoooooooooooo = 100               ",
        "*[D] O desespspro ero ero desesperedesdesespeo",
        "*[E] Nao mensuraaaaaaaveeeeeeeeel             "
    };
    
    
    //cansado...
    mvwprintw(provacansado_simples, Yall, Xall,"Eu to...");
    wrefresh(provacansado_simples);
    napms(1500);
    
    mvwprintw(provacansado_simples, Yall, Xall+8,"meio...");
    wrefresh(provacansado_simples);
    napms(1500);
    
    mvwprintw(provacansado_simples, Yall, Xall+15,"cansado    ");
    wrefresh(provacansado_simples);
    napms(2000);
    werase(provacansado_simples);
    

    while(tecla != 'p' && confirmado != 1)
    {
        int Yprova = Yall;
        int Xprova = Xall;
        
        tecla = wgetch(provacansado_simples);
        werase(provacansado_simples); 
        
        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(1));
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|=================================================================================|",cansando);     
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                     RURJR                                       |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                            PROOOVA DE MATETICA                                  |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 
        
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++QUESTÃO 1+++++++++++++++++++++++++++++++++++++++++++++
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| QUESTAO 1: Ache '7' na equacao abaixo:                                          |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                             4x  -  7  =  2x  +  5                               |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [A] 7 = 3                                                                       |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [B] 14 = 12                                                                     |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [C] 8 = infinito de lado                                                        |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [D] 0 = oito                                                                    |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [E] 13 . 4 = 664                                                                |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 
        
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++QUESTÃO 2+++++++++++++++++++++++++++++++++++++++++++++
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++QUESTÃO 2+++++++++++++++++++++++++++++++++++++++++++++
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|=================================================================================|", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| QUES ?: CaLKulE area dA FiGuRa:                                                 |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                        +----------------   -------+                             |", cansando); 
        
        // Linha 1 do hachurado integrado ao mvwprintw_cansado
        mvwprintw_cansado(provacansado_simples, Yprova,   Xprova, "|                           |                       |                             |", cansando); 
        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(4));
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova+33, "+---- ---  ---+", cansando); 
        wattroff(provacansado_simples, COLOR_PAIR(4));
        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(1));

        // Linha 2 do hachurado: O texto central "A = 4" (ou corrompido!)
        mvwprintw_cansado(provacansado_simples, Yprova,   Xprova, "|                        |          |     |           |                           |", cansando); 
        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(4));
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova+36, "    |       |", cansando); 
        wattroff(provacansado_simples, COLOR_PAIR(4));
        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(1));

        // Linha 3 do hachurado: Fechamento da caixinha interna
        mvwprintw_cansado(provacansado_simples, Yprova,   Xprova, "|                           |       +-------+     |                               |", cansando); 
        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(4));
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova+36, "+- --    ---  -+", cansando); 
        wattroff(provacansado_simples, COLOR_PAIR(4));
        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(1));

        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                        +---   --------------------+                             |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                       10101010                                  |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [A] Arestaaas = 46                                                              |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [B] Ar                                                                          |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [C] AREa = 42                                                                   |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [D] A r e a = 3 4                                                               |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [E] Area = 5 10 toneladas                                                       |", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|", cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |", cansando);
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++QUESTÃO 3+++++++++++++++++++++++++++++++++++++++++++++
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|======================================+==================_+======================|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| QUESTAO 3: Se todo ad Ruura e asioooso, e algnnss sisoooooo                     |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| gostam de soninho bom, afirmativamente que:                                     |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [A] gosta de soninnho.                                                          |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [B] Nenhum bixo.                                                                |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [C] E pssveiol mprraaogr.                                                       |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [D] Ele eh ansioso                                                              |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [E] Eu eoust  ansiaoa  sgo  or                                                  |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++QUESTÃO 4+++++++++++++++++++++++++++++++++++++++++++++
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| QUE:STAO 4 Um raitlgomo ispreroca pcear uma mssatra 5xiz quad5.dra              |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| ntos Quaelemenl e trtospo no totaii?ssa mazssu                                  |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [A] tosemen      25 ele                                                         |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [B] m10 eluns s aientos                                                         |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [C] 5ntos   0 eleme                                                             |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [D] 2nto elemes      elemento                                                   |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [E] Algum ai                                                                    |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++QUESTÃO 5+++++++++++++++++++++++++++++++++++++++++++++
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|=================================================================================|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| QUESTAO 5: O grafico abaixo representa o desespero de um estudante pelo         |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| numero de semanas de aula. Qual o valor aproximado no pico?                     |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                 |                               |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                               Nivel |           |                               |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                100  |          /                                |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                 50  |    /    /                                 |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                  0  +----+----+----+                            |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                               Semana: 0    2    4                               |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [A] pero 0Deses ? =                                                             |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [B] De = or s  50   oo esperad                                                  |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [C] Desesperoooooooooooo = 100                                                  |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [D] O desespspro ero ero desesperedesdesespeo                                   |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "| [E] Nao mensuraaaaaaaveeeeeeeeel                                                |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|---------------------------------------------------------------------------------|",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|                                                                                 |",cansando); 
        mvwprintw_cansado(provacansado_simples, Yprova++, Xprova, "|=================================================================================|",cansando); 
        wrefresh(provacansado_simples);
        wattroff(provacansado_simples, COLOR_PAIR(1));
        
        if(i/1000==1)
        {
            i=0;
            cansando++;
        }
        i++;
        
        // --- MOVIMENTAÇÃO
        if (confirmado == 0) {
            switch(tecla)
            {
                case 'a': Xall--; break;
                case 'd': Xall++; break;
                case 's': Yall--; break;
                case 'w': Yall++; break;
            }
        }

        //SELEÇÃO DAS ALTERNATIVAS
        if(resposta_dada < 5)
        {
            if(resposta_dada == 0)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(2));
                        mvwprintw_cansado(provacansado_simples, Yall + 10 + i, Xall + 1, questao1[i],cansando);
                        wattroff(provacansado_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 1)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(2));
                        mvwprintw_cansado(provacansado_simples, Yall + 28 + i, Xall + 1, questao2[i],cansando);
                        wattroff(provacansado_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 2)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(2));
                        mvwprintw_cansado(provacansado_simples, Yall + 42 + i, Xall + 1, questao3[i],cansando);
                        wattroff(provacansado_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 3)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(2));
                        mvwprintw_cansado(provacansado_simples, Yall + 54 + i, Xall + 1, questao4[i],cansando);
                        wattroff(provacansado_simples, COLOR_PAIR(2));
                    }
                }
            }
            else if(resposta_dada == 4)
            {
                for(int i = 0; i < 5; i++) 
                {
                    if(i == marcar)
                    {
                        if(*cor==1) wattron(provacansado_simples, COLOR_PAIR(2));
                        mvwprintw_cansado(provacansado_simples, Yall + 71 + i, Xall + 1, questao5[i],cansando);
                        wattroff(provacansado_simples, COLOR_PAIR(2));
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
                        confirmado = 2; // Inicia a verificação de confirmação numérica de forma segura
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
        
        wrefresh(provacansado_simples); 
        napms(30);// a parte da prova acaba aqui

        //CONFIRMAÇÃO
        if(confirmado != 0 && confirmado != 1)
        {
            int Ycentro = Yall + 35; 
            int Xcentro = Xall + 5;
            mvwprintw_cansado(provacansado_simples, Ycentro,     Xcentro, "/====================================================\\",cansando/4);
            mvwprintw_cansado(provacansado_simples, Ycentro + 1, Xcentro, "|      Tem certeza? Vai entregar a prova?            | ",cansando/4);
            mvwprintw_cansado(provacansado_simples, Ycentro + 2, Xcentro, "|                                                    | ",cansando/4);
            mvwprintw_cansado(provacansado_simples, Ycentro + 4, Xcentro, "\\====================================================/",cansando/4);
            
            mvwprintw(provacansado_simples, Ycentro + 3, Xcentro, "|   ");
            
            wmove(provacansado_simples, Ycentro + 3, Xcentro + 4);
            if (marcar_confirmacao == 0) if(*cor==1) wattron(provacansado_simples, A_REVERSE);
            mvwprintw_cansado(provacansado_simples, Ycentro + 3, Xcentro + 4, confirmacao[0],cansando/4);
            if (marcar_confirmacao == 0) wattroff(provacansado_simples, A_REVERSE);
            
            wprintw(provacansado_simples, "   ");

            wmove(provacansado_simples, Ycentro + 3, Xcentro + 30);
            if (marcar_confirmacao == 1) if(*cor==1) wattron(provacansado_simples, A_REVERSE);
            mvwprintw_cansado(provacansado_simples, Ycentro + 3, Xcentro + 30, confirmacao[1],cansando/4);
            if (marcar_confirmacao == 1) wattroff(provacansado_simples, A_REVERSE);

            mvwprintw(provacansado_simples, Ycentro + 3, Xcentro + 53, "|");
            wrefresh(provacansado_simples);

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
                        confirmado = 1; 
                        tecla = 'p';
                    } else {
                        resposta_dada = 4;
                        marcar = 0;
                        confirmado = 0; 
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
    
    werase(provacansado_simples);
    mvwprintw(provacansado_simples, 0, 0, "Acertos: %d", *acertos);
    wrefresh(provacansado_simples);
    
    nodelay(provacansado_simples, FALSE);
    wgetch(provacansado_simples);

    delwin(provacansado_simples);
    endwin();
}

int mvwprintw_cansado(WINDOW *janela, int Yprova, int Xprova, const char *prova, int cansando)// não estava funcionando com prova[151], tive que por *prova, como um ponteiro que aponta pro primeiro tamanho do prova, por algum motivo...
{ 
    int tamanho = strlen(prova);
    char cansaco[13] = {'?', '?', '~', '#', '@', '$', '%', '&', '*', '_', '+', '=', '-'};
    int caractere_aleatorio;
    int i;

    for(i = 0; i < tamanho; i++)
    {
        mvwaddch(janela, Yprova, Xprova + i, ' '); 
    }

    for(i=0;i<tamanho;i++)
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
/*
initscr = iniciar screen
curs_set = setar cursor
mvwprintw = move window print window
wrefresh = window refresh
napms = nap(dormir), milissegundos
werase = window erase
nodelay = no(não) delay(atraso)
getch = get char (pegar caractere
mvwaddch = move window adicionar char
if(cor==1) wattron = window atribuir ON
wattroff = window atribuir OFF




        [ mvwprintw_cansado(..., "PROVA")]
                        │
                        ▼
        [string lenght pega o tamanho do "prova" ex(5 letras)]
                        │
                        ▼
        [Inicia um laço 'for' de 0 a 4]
                        │
        ┌───────────────┴───────────────┐
        ▼                               ▼
    [Letra 'P']                     [Letra 'R']
Sorteia o dado (%) :             Sorteia o dado (%) :
Deu 85 (Maior que 4)            Deu 2 (Menor que 4!)
        │                               │
        ▼                               ▼
    (Cai no else)                    (Cai no if)
Mantém a letra real              Sorteia um símbolo caos
        │                               │
        ▼                               ▼
Usa a função 'mvwaddch'          Usa a função 'mvwaddch'
para desenho her 'P' em X=40        para desenho her '?' em X=41



void mvwprintw_cansado(WINDOW *win, int y, int x, const char *texto) {  nisso aqui ele definiu uma função quase igual ao mvwpintw

    int tam = strlen(texto); // qui ele ta definindo o tamanho do "texto que ele quer mecher", com o string lenght.
    char carac_caos[] = "@#$?*!01X%&Z[+";
    
    for (int i = 0; i < tam; i++) {
        // 4% de chance de o caractere se corromper no frame atual
        // Protegemos as bordas estruturais '|' e os colchetes das opções para manter o HUD jogável
        if (rand() % 100 < 4 && texto[i] != '|' && texto[i] != ' ' && texto[i] != '[' && texto[i] != ']') {
            int r = rand() % 14;
            mvwaddch(win, y, x + i, carac_caos[r]);
        } else {
            mvwaddch(win, y, x + i, texto[i]);
        }
    }
}*/