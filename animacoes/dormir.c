#include <ncurses.h>
void dormir()// a função roda a animação de dormir na cama
{
    #include<ncurses.h>
void cair_no_sono();
{
    int Xall=(COLS/2)-57, Yall=3;
    int olhosonoY=Yall+10, olhosonoX=Xall;
    curs_set(0);
    WINDOW *dormindu = newwin(LINES, COLS, 0, 0);

    box(dormindu, 0, 0);
    werase(dormindu);// Limpa a janela para desenhar o olho
    mvwprintw(dormindu, olhosonoY,     olhosonoX, "       _....,_            _,...._");
    mvwprintw(dormindu, olhosonoY + 1, olhosonoX, "   _.-` _,..,_'.        .'_,..,_ `-._");
    mvwprintw(dormindu, olhosonoY + 2, olhosonoX, "    _,-`/ o \\ '.        .' / o \\`-,_");
    mvwprintw(dormindu, olhosonoY + 3, olhosonoX, "     '-.\\___/.-`        `-.\\___/.-'" );

    wrefresh(dormindu);
    napms(1100);
        box(dormindu, 0, 0);
    werase(dormindu);// Limpa a janela para desenhar o olho fechando
    mvwprintw(dormindu, olhosonoY,     olhosonoX,   "       _....,_            _,...._");
    mvwprintw(dormindu, olhosonoY + 1, olhosonoX, "   _.-`       '.        .'       `-._");
    mvwprintw(dormindu, olhosonoY + 2, olhosonoX, "    _,--_,..,_'.        .'_,..,_--,_");
    mvwprintw(dormindu, olhosonoY + 3, olhosonoX, "     '-.\\___/.-`        `-.\\___/.-'" );

    wrefresh(dormindu);
    napms(1000);
        box(dormindu, 0, 0);
    werase(dormindu);// Limpa a janela para desenhar o olho fechado
    mvwprintw(dormindu, olhosonoY,     olhosonoX, "       _....,_            _,...._");
    mvwprintw(dormindu, olhosonoY + 1, olhosonoX, "   _.-`       '.        .'       `-._");
    mvwprintw(dormindu, olhosonoY + 2, olhosonoX, "    _,-,.____ ,.-      -., ____.,-,_");
    mvwprintw(dormindu, olhosonoY + 3, olhosonoX, "     '--. _ _\"            \"_ _ .--'");
    mvwprintw(dormindu, olhosonoY + 4, olhosonoX + 5, "    \" \"                \" \"");
    wrefresh(dormindu);
    napms(3000);

        mvwprintw(dormindu, olhosonoY-2,     olhosonoX, "Voce se deita para domir, a cama é aconchegante ne?");
        wrefresh(dormindu);
        napms(3000);
        mvwprintw(dormindu, olhosonoY-1,     olhosonoX, "Voce finalmente dorme, bons sonhos");
        wrefresh(dormindu);
        napms(3000);
}
}