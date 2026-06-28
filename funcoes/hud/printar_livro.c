#include "jogos.h"
void printar_livro(int livropickup, int *abrindolivro, int livro1, int livro2, int livro3, int livroY, int livroX )
{
if (livropickup == 1)
    {
        if (*abrindolivro == 1) 
        {
            abrirlivro(&livro1, &livro2, &livro3); 
            abrindolivro = 0; 
            werase(stdscr); 
        }
        if (livro1 == 1 && livro2 == 0 && livro3 == 0)
        {
            mvwprintw(stdscr, livroY, livroX, " ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1, livroX, "|CAPITULO I:EQUACOES |CAPITULO II:Silogismo|");
            mvwprintw(stdscr, livroY+2, livroX, "|Exemplo Pratico     |Diagramas de         |");
            mvwprintw(stdscr, livroY+3, livroX, "|de Isolamento:      |Conjuntos(Venn):     |");
            mvwprintw(stdscr, livroY+4, livroX, "|Seja a equacao      |Se todo elemento de  |");
            mvwprintw(stdscr, livroY+5, livroX, "|Ax - B = Cx + D     |A esta em B e todos  |");
            mvwprintw(stdscr, livroY+6, livroX, "|1)Isola os termos   |de B estao em A, logo|");
            mvwprintw(stdscr, livroY+7, livroX, "|com 'x':            |B=A                  |");
            mvwprintw(stdscr, livroY+8, livroX, "|Ax - Cx = D + B     |Simbolismos:         |");
            mvwprintw(stdscr, livroY+9, livroX, "|2)Evidencie x:      |Se 2 enunciados sao  |");
            mvwprintw(stdscr, livroY+10, livroX, "|x * (A - C) = D + B |iguais, tem-se uma   |");
            mvwprintw(stdscr, livroY+11, livroX, "| x = (D + B)/(A - C)|tautologia=verdadeiro|");
            mvwprintw(stdscr, livroY+12, livroX, "|____________________|_____________________|");
        }
        else if (livro2 == 1 && livro1 == 0 && livro3 == 0)
        {
            mvwprintw(stdscr, livroY, livroX, " ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1, livroX, "|CAPITULO III:MATRIZ |CAPITULO IV: AREAS   |");
            mvwprintw(stdscr, livroY+2, livroX, "|Contagem Absoluta de|PLANAS               |");
            mvwprintw(stdscr, livroY+3, livroX, "|Elementos           |Calculo em figuras   |");
            mvwprintw(stdscr, livroY+4, livroX, "|O numero de itens em|vazadas:             |");
            mvwprintw(stdscr, livroY+5, livroX, "|uma matriz eh dado  |Seja um retangulo    |");
            mvwprintw(stdscr, livroY+6, livroX, "|da seguinte forma:  |que possui uma figura|");
            mvwprintw(stdscr, livroY+7, livroX, "|                    |inscrita(FI), a area |");
            mvwprintw(stdscr, livroY+8, livroX, "|   N = i x j        |do retangulo externo |");
            mvwprintw(stdscr, livroY+9, livroX, "|Onde i eh o numero  |sera:                |");
            mvwprintw(stdscr, livroY+10, livroX, "|de linhas e j o de  |   A=(B*H) - Ai      |");
            mvwprintw(stdscr, livroY+11, livroX, "|colunas             |Ai:Area da FI        |");
            mvwprintw(stdscr, livroY+12, livroX, "|____________________|_____________________|");
        }
        else if (livro3 == 1 && livro1 == 0 && livro2 == 0)
        {
            mvwprintw(stdscr, livroY, livroX, " ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1, livroX, "|CAPITULO V:GRAFICOS |                     |");
            mvwprintw(stdscr, livroY+2, livroX, "|O pico de um grafico|  Morte de golfinhos |");
            mvwprintw(stdscr, livroY+3, livroX, "|pode ser visualemnte|  no Atlantico       |");
            mvwprintw(stdscr, livroY+4, livroX, "|percebido, bem como |                     |");
            mvwprintw(stdscr, livroY+5, livroX, "|em que momento,que  |500 |          /\\    |");
            mvwprintw(stdscr, livroY+6, livroX, "|eh normalmente o    |90  |    /\\   /  \\   |");
            mvwprintw(stdscr, livroY+7, livroX, "|eixo X, esse pico   |0   +----+----+----+ |");
            mvwprintw(stdscr, livroY+8, livroX, "|foi alcançado      |       T1   T2   T3  |");
            mvwprintw(stdscr, livroY+9, livroX, "|                    |                     |");
            mvwprintw(stdscr, livroY+10, livroX, "|                    | Pico:T3             |");
            mvwprintw(stdscr, livroY+11, livroX, "|                    |                     |");
            mvwprintw(stdscr, livroY+12, livroX, "|____________________|_____________________|");
        }
    }
}