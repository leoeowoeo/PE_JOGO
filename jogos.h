#ifndef JOGOS_H
#define JOGOS_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SAVE_
{
        int atividade_sono;
        int celularpickup;
        int celularpos;
        int livropickup;
        int livro1;
        int livro2;
        int livro3;
        int revistapickup;
        int maepistola;
        int maepistoladef;
        int janelaaberta;
        int depoisprova;
        char momento[64];
        char imagem[6][13];
        int iniciado;
        int x;
        int y;
        int estagio;
        int quest;
        char *faces[5];
        char *olhos[10];
        char *pernas[4];


        /*
        dialogoinicial
        dialogomae
        dialogodasprovas
        prova
        
        */
}SAVE;

int inicio(int *selecao_olhos, int *selecao_face,int *selecao_pernas, int *cor, int *interage, int *selecaocor,int *iniciar,int *epilepsia,SAVE *save_atual,int *iniciado,int *jogar,int estanoquarto);
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
int dialogofinal(int *finais_alcancados,int *acertos);
int dialogoMae(int *maexinga);
int personalizar(int *selecao_olhos, int *selecao_face,int *selecao_pernas, int xselecao, int yselecao);
void slow_mvwprintw(WINDOW* win, char* fala, const int y, int x);
void transicao(int *epilepsia);
void dialogodepoisprova(int *acertos,int *maexinga,int *epilepsia);
void demo();
void iniciar(int slot,SAVE *save_atual,int *selecao_olhos, int *selecao_face,int *selecao_pernas);
int gravar(int slot,SAVE *save_atual);
int recarregar(int slot,SAVE *save_atual);
void menusave(int*cor,SAVE *save_atual,int *jogar,int *selecao_olhos, int *selecao_face,int *selecao_pernas,int *iniciado,int estanoquarto);
void gravar_imagem_do_momento(int xdogaroto, int ydogaroto,char imagem_do_momento[6][13]);
void printar_imagem_do_momento(int x, int y, char imagem_do_momento[6][13]);
void desenha_borda(int x, int y);
void animacaomenu(int yselecao,int xselecao);
void animacaopequenina(int yselecao,int xselecao);
void inicializar_cores(int cor, int interage, int selecaocor, int *par);
void desenhar_cama(int Xall, int Yall, int cor, int interagirCam, int par);
void desenhar_estante(int Xall, int Yall, int cor, int interagirEst, int par, SAVE *save, int celularX, int celularY);
void desenhar_mesa(int Xall, int Yall, int cor);
void desenhar_armario(int Xall, int Yall, int cor, int armarioaberto, int interagirArm, int par);
void desenhar_espelho(int Xall, int Yall, int cor, int par);
void desenhar_janela(int Xall, int Yall, int cor, int janelaaberta, int interagirJan, int par,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check);
void desenhar_porta(int Xall, int Yall, int cor, int depoisprova, int maepistoladef, int maexinga, int acertos);
void desenhar_lixo(int Xall, int Yall, int cor);
void desenhar_tapete(int Xall, int Yall, int cor);
void desenhar_rodape(int Xall, int Yall, int cor);
void desenhar_gato(int Xall, int Yall, int armarioX, int armarioY, int vontadedepisca, int depoisprova);
void desenhar_celular_chao(int Xall, int Yall, int cor, SAVE *save, int celularX, int celularY, int interagirCel, int par);
void desenhar_chuva(int Xall, int Yall, int cor, int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check);
void desenhar_jogador(SAVE *save, int vira, int passo, int pisca, int cor, int selecao_face, int selecao_olhos, int selecao_pernas);
void desenhar_hud(int ybarra, int xbarra, int cor, SAVE *save, int jogarcelular5, int encararespelho, int dormircama, int jogartodosjogos, int ler1jogar3, int ler3jogatodos, int ler3dormir, char *quests[]);
void movimentar_jogador(int tecla, int *xf, int *yf, int *passo, int *lado, int *vira, int Xall, int Yall);
void processar_colisoes(int *xf, int *yf, SAVE *save, int camaX, int camaY, int estanteX, int estanteY, int armarioX, int armarioY, int mesaX, int mesaY, int lixoX, int lixoY);
void processar_interacoes(SAVE *save, int tecla, int Xall, int Yall, int espelhox, int espelhoy, int camaX, int camaY, int armarioX, int armarioY, int janelaX, int janelaY, int celularX, int celularY, int *espelho, int *dormindo, int *armarioaberto, int *interagirCam, int *interagirArm, int *interagirJan, int *interagirCel, int *interagirEst, int *marcar, int *jogarcelular5, int cor, int *revista_linha, int *revista_coluna, int *livro1, int *livro2, int *livro3, int *abrindolivro, int *estudo, int *estudando, int *acertos, int vira, int estanteX, int estanteY);
void espelhaogaroto(SAVE save, int espelhox, int espelhoy, int pisca, char **faces, char **olhos, char **pernas,int selecao_face,int selecao_pernas, int selecao_olhos,int passo,int vira);
void printar_celular(SAVE save,int celularX,int celularY);
void printar_livro(int livropickup, int *abrindolivro, int livro1, int livro2, int livro3, int livroY, int livroX );

#endif