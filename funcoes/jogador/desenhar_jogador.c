#include "jogos.h"
void desenhar_jogador(SAVE *save, int vira, int passo, int pisca, int cor, int selecao_face, int selecao_olhos, int selecao_pernas)
{
    char *olhos[10] = {"##", "@@", "**", "$$", "vv", "><", "XX", "OO", "00", "oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >", "d  b"};
    char *pernas[4] = {"/|", "|\\", "<v", "v>"};

    if (save->celularpickup == 0)
    {
        if (vira % 2 == 0)
        {
            if (pisca % 2 == 1) { mvprintw(save->y, save->x, "%s", faces[selecao_face]); mvprintw(save->y, save->x+1, "%s", olhos[selecao_olhos]); }
            else { mvprintw(save->y, save->x, "%s", faces[selecao_face]); mvprintw(save->y, save->x+1, "--"); }
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
        else if (vira % 2 == 1)
        {
            mvprintw(save->y, save->x, "%s", faces[selecao_face]);
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
    }
    if (save->celularpickup == 1)
    {
        if (vira % 2 == 0)
        {
            if (pisca % 2 == 1) { mvprintw(save->y, save->x, "%s[]", faces[selecao_face]); mvprintw(save->y, save->x+1, "%s", olhos[selecao_olhos]); }
            else { mvprintw(save->y, save->x, "%s[]", faces[selecao_face]); mvprintw(save->y, save->x+1, "--"); }
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
        else if (vira % 2 == 1)
        {
            mvprintw(save->y, save->x-2, "[]%s", faces[selecao_face]);
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
    }
    if (save->revistapickup == 1 || save->livropickup == 1)
    {
        if (vira % 2 == 0)
        {
            if (pisca % 2 == 1) { mvprintw(save->y, save->x, "%s[I]", faces[selecao_face]); mvprintw(save->y, save->x+1, "%s", olhos[selecao_olhos]); }
            else { mvprintw(save->y, save->x, "%s[I]", faces[selecao_face]); mvprintw(save->y, save->x+1, "--"); }
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
        else if (vira % 2 == 1)
        {
            mvprintw(save->y, save->x-3, "[I]%s", faces[selecao_face]);
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
    }
}
