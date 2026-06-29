#include <stdio.h>
#include <string.h>
#include "jogos.h"

void iniciar(int slot, SAVE *save_atual,int *selecao_olhos, int *selecao_face,int *selecao_pernas)
//a função inicia o struct atual quando o struct ainda não foi rodado
{
    int Xall=(COLS/2)-57, Yall=3;
    char *olhos[10] = {"##", "@@", "**", "$$", "vv", "><", "XX", "OO", "00", "oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >", "d  b"};
    char *pernas[4] = {"/|", "|\\", "<v", "v>"};

    save_atual->atividade_sono = 0;
    save_atual->celularpickup = 0;
    save_atual->livropickup = 0;
    save_atual->revistapickup = 0;
    save_atual->maepistola = 0;
    save_atual->maepistoladef = 0;
    save_atual->janelaaberta = 0;
    save_atual->depoisprova = 0;
    save_atual->x=22+Xall;
    save_atual->y=10+Yall;
    save_atual->celularpos=2;
    save_atual->revistapickup=0;
    save_atual->estagio=0;
    save_atual->quest=0;
    save_atual->selecao_face=0;
    save_atual->selecao_olhos=10;
    save_atual->selecao_pernas=0;
    save_atual->selecao_cor=4;
    
    strcpy(save_atual->momento, "Dialogo com a mae ");

    strcpy(save_atual->imagem[0], "      \\/    ");
    strcpy(save_atual->imagem[1], "     (00)   ");
    strcpy(save_atual->imagem[2], "      ||    ");
    strcpy(save_atual->imagem[3], "            ");
    strcpy(save_atual->imagem[4], "            ");
    strcpy(save_atual->imagem[5], "            ");
    
    const char *olhos_[10] = {"##", "@@", "**", "$$", "vv", "><", "XX", "OO", "00", "oo"};
    const char *faces_[5]  = {"(  )", "[  ]", "{  }", "<  >", "d  b"};
    const char *pernas_[4] = {"/|", "|\\", "<v", "v>"};

    for (int i = 0; i < 10; i++) strcpy(save_atual->olhos[i], olhos_[i]);
    for (int i = 0; i < 5;  i++) strcpy(save_atual->faces[i], faces_[i]);
    for (int i = 0; i < 4;  i++) strcpy(save_atual->pernas[i], pernas_[i]);


    gravar(slot, save_atual);
    
    /*strcpy(save_atual->imagem[0], "_I_____[__!!");
    strcpy(save_atual->imagem[1], "       [_||!");
    strcpy(save_atual->imagem[2], "    (oo)_!!_");
    strcpy(save_atual->imagem[3], "     /|     ");
    strcpy(save_atual->imagem[4], "            ");
    strcpy(save_atual->imagem[5], "            ");*/
}

/*
_I_____[__!!
       [_||!
    (oo)_!!_
     /|     
              */
            
                        