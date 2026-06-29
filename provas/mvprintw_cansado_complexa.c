#include "jogos.h"
int mvwprintw_cansado_complexa(WINDOW *janela, int Yprova, int Xprova, const char *prova, int cansando)// não estava funcionando com prova[151], tive que por *prova, como um ponteiro que aponta pro primeiro tamanho do prova, por algum motivo...
{ 
    if (Yprova < 0 || Yprova >= LINES) return 0;// eu add isso aqui, pq a prova tava bugando qnd ia pra cima dms, ela printava tudo torto

    int tamanho = strlen(prova);
    char cansaco[13] = {'?', '?', '~', '#', '@', '$', '%', '&', '*', '_', '+', '=', '-'};
    int caractere_aleatorio;
    int i;


    for(i = 0; i < tamanho; i++)// esse tmb confere se ta dentro do limite da tela, mas pro x
    {
        int Xatual = Xprova + i;

    if (Xatual >= 0 && Xatual < COLS)
        {
            mvwaddch(janela, Yprova, Xprova + i, ' '); // aqui é pra printar os espaços
        }
    }

    for(i=0;i<tamanho;i++)
    {
        int Xatual = Xprova + i;
        if (Xatual >= 0 && Xatual < COLS)
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
    return 0;
}