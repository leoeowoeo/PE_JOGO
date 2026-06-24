#ifndef JOGOS_H
#define JOGOS_H

#include <ncurses.h>
typedef struct SAVE_
{
        int atividade_sono;
        int celularpickup;
        int livropickup;
        int revistapickup;
        int maepistola;
        int maepistoladef;
        int janelaaberta;
        int depoisprova;
        char momento[64];
        char imagem[6][13];
}SAVE;

int inicio(int *selecao_olhos, int *selecao_face,int *selecao_pernas, int *cor, int *interage, int *selecaocor,int *iniciar,int *epilepsia,SAVE *save_atual);
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

void iniciar(int slot,SAVE *save_atual,int *selecao_olhos, int *selecao_face,int *selecao_pernas);
int gravar(int slot,SAVE *save_atual);
int recarregar(int slot,SAVE *save_atual);
void menusave(int*cor,SAVE *save_atual,int *jogar,int *selecao_olhos, int *selecao_face,int *selecao_pernas);
void gravar_imagem_do_momento(int xdogaroto, int ydogaroto,char imagem_do_momento[6][12]);
void printar_imagem_do_momento(int x, int y, char imagem_do_momento[6][12]);



#endif