#include <ncurses.h>
int main(){
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr,TRUE);
    int x=0,y=0;
    char quit,tecla;
    while((quit=getch()) != 'q'){
        clear();
        if(tecla=getchar()== KEY_RIGHT)
        {
            x++;
        }
        else if(tecla=getchar()== KEY_LEFT)
        { 
            x--;
        }
        else if(tecla=getchar()== KEY_UP)
        {   
            y--;
        }
        else if(tecla=getchar()== KEY_DOWN)
        {
            y++;
        }
            mvprintw(y,x,"0");
            refresh();

    }
    endwin();
    return 0;
}