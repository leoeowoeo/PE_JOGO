#include <ncurses.h>
void slow_mvwprintw(WINDOW* win, char* fala, const int y, int x)
{
    int delay_ms=50;
    for(int i=0;fala[i]!='\0';i++)
    {
        mvwaddch(win, y, x + i, fala[i]);
        wrefresh(win);
        napms(delay_ms);
    }
}