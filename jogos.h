#ifndef JOGOS_H
#define JOGOS_H

#include <ncurses.h>

int inicio(int *selecao_olhos, int *selecao_face,int *selecao_pernas, int *cor, int *interage, int *selecaocor,int *iniciar,int *epilepsia);
void pedrapapeltesoura(int *cor,int *encararespelho);
int cobra(int *cor, int *jogarcelular5);
void dormir();
void cair_no_sono();
int prova_simples(int *cor,int *acertos);
int prova_cansado_simples(int *cor,int *acertos);
int prova_complexa(int *cor,int *acertos);
int prova_cansado_complexa(int *cor,int *acertos);
int mvwprintw_cansado(WINDOW *janela, int Yprova, int Xprova, const int*prova, int cansando);
int mvwprintw_cansado_complexa(WINDOW *janela, int Yprova, int Xprova, const int*prova, int cansando);
void abrirlivro(int *livro1,int *livro2,int *livro3);
void dialogoprovas();
void dialogoprovac();
void dialogoprovacs();
void dialogoprovacc();
int dialogofinal(int *finais_alcancados);
int dialogoMae(int *maexinga);
int personalizar(int *selecao_olhos, int *selecao_face,int *selecao_pernas, int xselecao, int yselecao);
void slow_mvwprintw(WINDOW* win, char* fala, const int y, int x);
void transicao(int *epilepsia);
void dialogodepoisprova(int *acertos,int *maexinga,int *epilepsia);
void demo();



#endif