#include"jogos.h"
void desenhar_gato(int Xall, int Yall, int armarioX, int armarioY, int vontadedepisca, int depoisprova)
{
    int gatoy = armarioY + 13, gatox = armarioX + 10;
    if (depoisprova == 0)
    {
        mvprintw(gatoy, gatox, "(\\   /)");
        mvprintw(gatoy+1, gatox, "(=*.*=)");
        mvprintw(gatoy+2, gatox, " (\") (\")_/");
        if (vontadedepisca >= 300 && vontadedepisca <= 390)
        {
            static int meow = 0;
            meow++;
            if (meow >= 3 && meow <= 4) { mvprintw(gatoy-1, gatox+3, "MEOW"); meow = 0; }
        }
    }
}