#include<ncurses.h>
#include"jogos.h"

void dialogoprovac()
{
    int Xall=(COLS/2)-57, Yall=3;
    int tecla=0, x=22+Xall, y=10+Yall;
    int marcar_arrumar = 0;
    int marcar_resposta = 0;
    int tecla_cena = 0;
    int linha_atual = Yall;

    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(90);
    
    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(90);
    
    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(90);
    
    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- Ah, naooo, a prova", linha_atual, Xall);
    refresh(); napms(900);
    
    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- preciso me arrumar", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual++;
    slow_mvwprintw(stdscr, "Voce se arruma bem e sai do quarto, triste", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- Bom dia filho, ta pro-?", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- nossa! Alguem morreu?", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual += 2;
    nodelay(stdscr, FALSE); 
    keypad(stdscr, TRUE);
flushinp();
    while (1)
    {
        if (marcar_resposta == 0) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual, Xall + 2, "[ Eu, vou morrer hoje com essa prova... ]");
        if (marcar_resposta == 0) wattroff(stdscr, A_REVERSE);

        if (marcar_resposta == 1) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 1, Xall + 2, "[ an? porque??? ]");
        if (marcar_resposta == 1) wattroff(stdscr, A_REVERSE);

        refresh();
        tecla_cena = getch();

        if (tecla_cena == KEY_UP || tecla_cena == KEY_DOWN)
        {
            marcar_resposta = !marcar_resposta;
        }
        else if (tecla_cena == '\n' || tecla_cena == ' ')
        {
            break;
        }
    }

    erase();
    linha_atual = Yall;

    if (marcar_resposta == 0)
    {
        slow_mvwprintw(stdscr, "Mae- Meu deus, o que foi?", linha_atual, Xall);
        refresh(); napms(900);
    }
    else
    {
        slow_mvwprintw(stdscr, "Mae- porque? olha a sua cara de morte!", linha_atual, Xall);
        refresh(); napms(900);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Garoto- Ah, e porque eu tenho prova hoje", linha_atual, Xall);
        refresh(); napms(900);
    }

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- Hmmm, foi dormir tarde ne?", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- Naoo! Eu dormi num horario bom, so nao estudei muito...", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- ", linha_atual, Xall);
    
    wattron(stdscr, A_BOLD);
    slow_mvwprintw(stdscr, "P0&&@ ", linha_atual, Xall + 6);
    wattroff(stdscr, A_BOLD);
    
    slow_mvwprintw(stdscr, "sabia!", linha_atual, Xall + 12);
    refresh(); napms(950);


    linha_atual += 2;
    slow_mvwprintw(stdscr, "Voce vai tomar cafe, com tempo sobrando", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual++;
    slow_mvwprintw(stdscr, "Voce se arruma e sai para escola, triste", linha_atual, Xall);
    refresh(); napms(900);

    erase();
    linha_atual = Yall; 

    slow_mvwprintw(stdscr, "Professor- A prova ta facil, a materia que a gente viu em sala", linha_atual, Xall);
    linha_atual++;
    slow_mvwprintw(stdscr, "e a que eu marquei para voces lerem nos livros em casa", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual += 2;
    slow_mvwprintw(stdscr, "Professor- Pega a prova e passa pra traz", linha_atual, Xall);
    refresh(); napms(90);
    linha_atual++;
    slow_mvwprintw(stdscr, "Professor- Pega a prova e passa pra traz", linha_atual, Xall);
    refresh(); napms(90);
    linha_atual++;
    slow_mvwprintw(stdscr, "Professor- Pega a prova e passa pra traz...", linha_atual, Xall);
    refresh(); napms(900);

    linha_atual += 2;
    slow_mvwprintw(stdscr, "Todos pegam as suas provas se arrumam e o professor diz:", linha_atual, Xall);
    refresh(); napms(900);
    
    linha_atual++;
    slow_mvwprintw(stdscr, "Podem virar as provas...", linha_atual, Xall);
    refresh(); napms(900);

}