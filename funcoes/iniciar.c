#include <stdio.h>
#include <string.h>
#include "jogos.h"

void iniciar(int slot, SAVE *save_atual)
{

    save_atual->atividade_sono = 0;//(*save_atual).atividade_sono = 0;
    save_atual->celularpickup = 0;
    save_atual->livropickup = 0;
    save_atual->revistapickup = 0;
    save_atual->maepistola = 0;
    save_atual->maepistoladef = 0;
    save_atual->janelaaberta = 0;
    save_atual->depoisprova = 0;
    strcpy(save_atual->momento, "Dialogo com a mae ");//SALVO
    strcpy(save_atual->imagem, "inicial");


    gravar(slot, save_atual);
}