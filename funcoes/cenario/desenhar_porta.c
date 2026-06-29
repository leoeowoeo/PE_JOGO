#include"jogos.h"
void desenhar_porta(int Xall, int Yall, int cor, int depoisprova, int maepistoladef, int maexinga, int acertos)
{
    int portaY = 3 + Yall, portaX = 11 + Xall;
    if (depoisprova == 0)
    {
        if (maepistoladef == 1)
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY+1, portaX+11, "_______");
            mvprintw(portaY+2, portaX+11, "|     |");
            mvprintw(portaY+3, portaX+11, "|     |");
            mvprintw(portaY+4, portaX+11, "|*    |");
            mvprintw(portaY+5, portaX+11, "|     |");
            mvprintw(portaY+6, portaX+11, "I_____I");
            wattroff(stdscr, COLOR_PAIR(6));
        }
        else
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY, portaX+1,   "                   ");
            mvprintw(portaY+1, portaX+1, "          _______  ");
            mvprintw(portaY+2, portaX+1, "          |     |\\");
            mvprintw(portaY+3, portaX+1, "          |     | |");
            mvprintw(portaY+4, portaX+1, "          |(00) | |");
            mvprintw(portaY+5, portaX+1, "          | ||  |*|");
            mvprintw(portaY+6, portaX+11,          "I_____I |");
            mvprintw(portaY+7, portaX+18,                "\\|");
            wattroff(stdscr, COLOR_PAIR(6));
            if (maexinga)
            {
                mvprintw(portaY, portaX+1,   " ________");
                mvprintw(portaY+1, portaX+1, "|00&!@&@C|");
                mvprintw(portaY+2, portaX+1, "|________|");
                mvprintw(portaY+3, portaX+10, "\\  \\/");
                mvprintw(portaY+4, portaX+12, "(00) ");
                mvprintw(portaY+5, portaX+13, "||  ");
            }
            else
            {
                mvprintw(portaY, portaX-1,   " __________");
                mvprintw(portaY+1, portaX-1, "|vai dormir|");
                mvprintw(portaY+2, portaX-1, "|__________|");
                mvprintw(portaY+3, portaX+10, "\\| \\/");
                mvprintw(portaY+4, portaX+12, "(00) ");
                mvprintw(portaY+5, portaX+13, "||  ");
            }
        }
    }
    else if (acertos < 5 && depoisprova == 1)
    {
        if (maepistoladef == 1)
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY+1, portaX+11, "_______");
            mvprintw(portaY+2, portaX+11, "|     |");
            mvprintw(portaY+3, portaX+11, "|     |");
            mvprintw(portaY+4, portaX+11, "|*    |");
            mvprintw(portaY+5, portaX+11, "|     |");
            mvprintw(portaY+6, portaX+11, "I_____I");
            wattroff(stdscr, COLOR_PAIR(6));
        }
        else
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY, portaX+1, "                   ");
            mvprintw(portaY+1, portaX+1, "          _______  ");
            mvprintw(portaY+2, portaX+1, "          |     |\\");
            mvprintw(portaY+3, portaX+1, "          |     | |");
            mvprintw(portaY+4, portaX+1, "          |(00) | |");
            mvprintw(portaY+5, portaX+1, "          | ||  |*|");
            mvprintw(portaY+6, portaX+11,          "I_____I |");
            mvprintw(portaY+7, portaX+18,                 "\\|");
            wattroff(stdscr, COLOR_PAIR(6));
            if (acertos < 2)
            {
                if (maexinga)
                {
                    mvprintw(portaY, portaX+1,   " ________________");
                    mvprintw(portaY+1, portaX-3, "|SEU INCOMPETENTE|");
                    mvprintw(portaY+2, portaX-3, "|________________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                }
                else
                {
                    mvprintw(portaY, portaX+1,   " ________");
                    mvprintw(portaY+1, portaX+1, "|00&!@&@C|");
                    mvprintw(portaY+2, portaX+1, "|________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                }
            }
            else
            {
                mvprintw(portaY, portaX-1,   " ___________");
                mvprintw(portaY+1, portaX-1, "|vai estudar|");
                mvprintw(portaY+2, portaX-1, "|___________|");
                mvprintw(portaY+3, portaX+10, "\\  \\/");
                mvprintw(portaY+4, portaX+12, "(00) ");
                mvprintw(portaY+5, portaX+13, "||  ");
            }
        }
    }
}