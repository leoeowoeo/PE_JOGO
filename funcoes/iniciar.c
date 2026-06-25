#include <stdio.h>
#include <string.h>
#include "jogos.h"

void iniciar(int slot, SAVE *save_atual,int *selecao_olhos, int *selecao_face,int *selecao_pernas)
//a função inicia o struct atual quando o struct ainda não foi rodado
{
    char *olhos[10] = {"##", "@@", "**", "$$", "vv", "><", "XX", "OO", "00", "oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >", "d  b"};
    char *pernas[4] = {"/|", "|\\", "<v", "v>"};

    save_atual->atividade_sono = 0;//(*save_atual).atividade_sono = 0;
    save_atual->celularpickup = 0;
    save_atual->livropickup = 0;
    save_atual->revistapickup = 0;
    save_atual->maepistola = 0;
    save_atual->maepistoladef = 0;
    save_atual->janelaaberta = 0;
    save_atual->depoisprova = 0;
    strcpy(save_atual->momento, "Dialogo com a mae ");//SALVO

    strcpy(save_atual->imagem[0], "     \\/    ");
    strcpy(save_atual->imagem[1], "    (00)   ");
    strcpy(save_atual->imagem[2], "     ||    ");
    strcpy(save_atual->imagem[3], "           ");
    strcpy(save_atual->imagem[4], "           ");
    strcpy(save_atual->imagem[5], "           ");
    


    gravar(slot, save_atual);
}