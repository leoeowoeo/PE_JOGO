#include "jogos.h"
void desenhar_hud(int ybarra, int xbarra, int cor, SAVE *save, int jogarcelular5, int encararespelho, int dormircama, int jogartodosjogos, int ler1jogar3, int ler3jogatodos, int ler3dormir, char *quests[])
{
    wattroff(stdscr, COLOR_PAIR(9));
    mvprintw(ybarra-1, xbarra, "Cansaco.");
    mvprintw(ybarra, xbarra, "+-----------+");
    if (save->atividade_sono >= 1) mvprintw(ybarra+1, xbarra+1, "##");
    if (save->atividade_sono >= 2) mvprintw(ybarra+1, xbarra+3, "##");
    if (save->atividade_sono >= 3) mvprintw(ybarra+1, xbarra+5, "##");
    if (save->atividade_sono >= 4) { if (cor == 1) attron(COLOR_PAIR(4)); mvprintw(ybarra+1, xbarra+7, "##"); attroff(COLOR_PAIR(4)); }
    if (save->atividade_sono >= 5) { if (cor == 1) attron(COLOR_PAIR(4)); mvprintw(ybarra+1, xbarra+9, "##"); attroff(COLOR_PAIR(4)); }
    mvprintw(ybarra+2, xbarra, "+-----------+");
    mvprintw(ybarra+1, xbarra, "|");
    mvprintw(ybarra+1, xbarra+12, "|");
    if ((jogarcelular5 != 5 || encararespelho != 1 || dormircama != 1 || jogartodosjogos != 6 || ler1jogar3 != 4 || ler3jogatodos != 4 || ler3dormir != 3) && save->depoisprova == 0)
    {
        wattron(stdscr, A_BOLD);
        mvprintw(ybarra, xbarra+30, "Quest: %s", quests[save->quest]);
        wattroff(stdscr, A_BOLD);
    }
}