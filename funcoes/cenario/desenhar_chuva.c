#include "jogos.h"
void desenhar_chuva(int Xall, int Yall, int cor, int chuvax, int chuvay, int *pos, int *pos2, int *pos3,int check)
{
    
        if (cor == 1) wattron(stdscr, COLOR_PAIR(5));
        mvprintw(chuvay+*pos, chuvax, ",;';,,;");
        mvprintw(chuvay+*pos2, chuvax, " ';.;.'");
        mvprintw(chuvay+*pos3, chuvax, ".,.,'' ");
        wattroff(stdscr, COLOR_PAIR(5));
     if(check%5==0)  
            {(*pos)++; (*pos2)++; (*pos3)++;}
        if((*pos)>2) {*pos=0;} 
        if((*pos2)>2){*pos2=0;} 
        if((*pos3)>2){*pos3=0;}
            
}