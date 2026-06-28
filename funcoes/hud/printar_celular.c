#include "jogos.h"
void printar_celular(SAVE save,int celularX,int celularY)
{   

    if(save.celularpickup==1&&save.depoisprova==0)
    {
        
                        mvprintw(celularY,      celularX+18, "  _______________ ");
                        mvprintw(celularY+1,    celularX+18, " | _____________ |");        
                        mvprintw(celularY+2,    celularX+18, " ||      O      ||");
                        mvprintw(celularY+3,    celularX+18, " ||             ||");
                        mvprintw(celularY+4,    celularX+18, " ||             ||");
                        mvprintw(celularY+5,    celularX+18, " ||             ||");
                        mvprintw(celularY+6,    celularX+18, " ||             ||");
                        mvprintw(celularY+7,    celularX+18, " ||             ||");
                        mvprintw(celularY+8,    celularX+18, " ||             ||");
                        mvprintw(celularY+9,    celularX+18, " ||             ||");
                        mvprintw(celularY+10,   celularX+18, " ||_____________||");
                        mvprintw(celularY+11,   celularX+18, " | ===  [ ]  <-- |");
                        mvprintw(celularY+12,   celularX+18, " \\===============/");
    }
}
