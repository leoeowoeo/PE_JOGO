#include <ncurses.h>
#include <stdlib.h>
#include "jogos.h"
int personalizar(int *selecao_olhos, int *selecao_face,int *selecao_pernas, int xselecao, int yselecao)
//a função abre a area de personalização do personagem, possibilitando mudar somente a aparência, já que só temos um atributo ( a inteligencia ),
// que só é adiquirivel pelo estudo, o personagem não nasce com 
{


    
    int tecla = 0;
    int selecao_aparencia = 1;
    int tecla_item = 0;

    char *olhos[10]={"##","@@", "**","$$","vv","><","XX","OO","00","oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >","d  b"};
    char *pernas[6] = {"/|","|\\","<v", "v>"};

    while (tecla != 'p' && tecla != 'P') 
    {
        erase();
        
        mvwprintw(stdscr,yselecao, xselecao, "Defina sua aparencia");
        mvwprintw(stdscr,yselecao + 2, xselecao, "Olhos");
        mvwprintw(stdscr,yselecao + 4, xselecao, "Cabeca");
        mvwprintw(stdscr,yselecao + 6, xselecao, "Pernas");
        mvwprintw(stdscr,yselecao + 9, xselecao, "Aperte 'P' para voltar ao menu");

        mvwprintw(stdscr, yselecao + 4, xselecao - 18, "PREVIA: %s", faces[*selecao_face]);
        mvwprintw(stdscr, yselecao + 4, xselecao - 9, "%s", olhos[*selecao_olhos]);
        mvwprintw(stdscr, yselecao + 5, xselecao - 9, "%s", pernas[*selecao_pernas]);
        
        if (selecao_aparencia == 1) { 
            wattron(stdscr, COLOR_PAIR(4) | A_BOLD);
            mvwprintw(stdscr,yselecao + 2, xselecao, "Olhos"); 
            wattroff(stdscr, COLOR_PAIR(4) | A_BOLD);
        } 
        else if (selecao_aparencia == 2) {
            wattron(stdscr, COLOR_PAIR(4) | A_BOLD);
            mvwprintw(stdscr,yselecao + 4, xselecao, "Cabeca"); 
            wattroff(stdscr, COLOR_PAIR(4) | A_BOLD);
        } 
        else if (selecao_aparencia == 3) {
            wattron(stdscr, COLOR_PAIR(4) | A_BOLD);
            mvwprintw(stdscr,yselecao + 6, xselecao, "Pernas"); 
            wattroff(stdscr, COLOR_PAIR(4) | A_BOLD);
        } 

        timeout(200);
        tecla = getch();
        
        switch (tecla) {
            case 'w':
            case KEY_UP:
                selecao_aparencia--;
                if (selecao_aparencia < 1) selecao_aparencia = 4;
                break;

            case 's':
            case KEY_DOWN:
                selecao_aparencia++;
                if (selecao_aparencia > 4) selecao_aparencia = 1;
                break;

            case '\n':
                if (selecao_aparencia == 1) 
                {
                    tecla_item = 0;
                    
                    while (tecla_item != '\n') 
                    {
                        erase();
                        mvwprintw(stdscr,yselecao, xselecao, "Escolha os olhos ('A' / 'D' e ENTER para confirmar):");
                        
                        
                        mvwprintw(stdscr,yselecao + 2, xselecao, "Olhos atuais: %s", olhos[*selecao_olhos]);
                        refresh();

                        timeout(-1);
                        tecla_item = getch();

                        switch (tecla_item) 
                        {
                            case 'd':
                            case 'D':
                            case KEY_RIGHT:
                                (*selecao_olhos)++;
                                if (*selecao_olhos > 9) *selecao_olhos = 0;
                                break;
                            case 'a':
                            case 'A':
                            case KEY_LEFT:
                                (*selecao_olhos)--;
                                if (*selecao_olhos < 0) *selecao_olhos = 9;
                                break;
                        }
                    }
                }
                else if (selecao_aparencia == 2) 
                {
                    tecla_item = 0;
                    while (tecla_item != '\n') 
                    {
                        erase();
                        mvwprintw(stdscr,yselecao, xselecao, "Escolha a cabeca ('A' / 'D' e ENTER para confirmar):");
                        
                        mvwprintw(stdscr,yselecao + 2, xselecao, "Cabeca atual: %s", faces[*selecao_face]);
                        refresh();

                        timeout(-1);
                        tecla_item = getch();

                        switch (tecla_item) 
                        {
                            case 'd':
                            case 'D':
                            case KEY_RIGHT:
                                (*selecao_face)++;
                                if (*selecao_face > 4) *selecao_face = 0;
                                break;
                            case 'a':
                            case 'A':
                            case KEY_LEFT:
                                (*selecao_face)--;
                                if (*selecao_face < 0) *selecao_face = 4;
                                break;
                        }
                    }
                }
                else if (selecao_aparencia == 3) {
                    tecla_item = 0;
                    while (tecla_item != '\n') 
                    {
                        erase();
                        mvwprintw(stdscr,yselecao, xselecao, "Escolha as pernas ('A' / 'D' e ENTER para confirmar):");
                        
                        mvwprintw(stdscr,yselecao + 2, xselecao, "Pernas atuais: %s", pernas[*selecao_pernas]);
                        refresh();

                        timeout(-1);
                        tecla_item = getch();

                        switch (tecla_item) 
                        {
                            case 'd':
                            case 'D':
                            case KEY_RIGHT:
                                (*selecao_pernas)+=2;
                                if (*selecao_pernas > 3) *selecao_pernas = 0;
                                break;
                        }
                    }
                }
        }
        refresh();
    }
    return 0;
}