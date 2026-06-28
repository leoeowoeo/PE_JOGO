#include "jogos.h"
void espelhaogaroto(SAVE save,int espelhox, int espelhoy, int pisca, char **faces, char **olhos, char **pernas,int selecao_face,int selecao_pernas, int selecao_olhos,int passo,int vira)
{
    if (save.x >= espelhox - 6 && save.x <= espelhox + 20 && save.y < espelhoy + 13 && vira % 2 == 1)
                    {
                        int reflexx = save.x;
                        int distancia = save.y - espelhoy;
                        int reflexy = (espelhoy + 4) - (distancia / 3);
                        if (reflexy < espelhoy + 1) reflexy = espelhoy + 1;
                        if (reflexy > espelhoy + 4) reflexy = espelhoy + 4;
                        if (reflexx < espelhox) reflexx = espelhox;
                        if (reflexx > espelhox + 9) reflexx = espelhox + 9;
                        if (vira % 2 == 1 && save.x >= espelhox && save.x <= espelhox + 7)
                        {
                            int borda1 = espelhox, borda2 = espelhox + 10;
                            if (reflexx >= borda1 && reflexx <= borda2)
                            {
                                if (save.celularpickup == 1)
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx-2, "[]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx-2, "[]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                else if (save.revistapickup == 1 || save.livropickup == 1)
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx-3, "[I]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx-3, "[I]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                else
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx, "%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx, "%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                if (passo % 2 == 0) mvprintw(reflexy+1, reflexx+1, "%s", pernas[selecao_pernas]);
                                else mvprintw(reflexy+1, reflexx+1, "%s", pernas[selecao_pernas+1]);
                            }
                        }
                    }
}