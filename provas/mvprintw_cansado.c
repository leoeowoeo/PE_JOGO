#include"jogos.h"
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
