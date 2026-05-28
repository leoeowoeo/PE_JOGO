#include<ncurses.h>
int dialogoprovas()
{
        int Xall=(COLS/2)-57, Yall=3;
    int tecla=0, x=22+Xall, y=10+Yall;
    int marcar_arrumar = 0;
    int marcar_resposta = 0;
    int tecla_cena = 0;
    int linha_atual = Yall;

    erase();
    mvprintw(linha_atual, Xall, "alarme- BEEP\a BEEP\a BEEP\a");
    beep(); refresh(); napms(500);
    
    erase();
    mvprintw(linha_atual, Xall, "alarme- BEEP BEEP BEEP");
    beep(); refresh(); napms(500);
    
    erase();
    mvprintw(linha_atual, Xall, "alarme- BEEP BEEP BEEP");
    beep(); refresh(); napms(500);
    

    linha_atual++;
    mvprintw(linha_atual, Xall, "Garoto- Ah, sim, a prova");
    refresh(); napms(1000);
    
    linha_atual++;
    mvprintw(linha_atual, Xall, "Garoto- preciso me arrumar");
    refresh(); napms(1000);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Voce se arruma bem arrumado e sai do quarto");
    refresh(); napms(1500);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Mae- Bom dia filho, ta pronto?");
    refresh(); napms(1200);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Garoto- Bom dia! Estou sim, me desculpa por ontem, pra recuperar eu estudei antes de ir dormir");
    refresh(); napms(2000);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Mae- Hmmm, foi dormir tarde ne?");
    refresh(); napms(1200);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Garoto- Naoo! Eu dormi num horario bom, eu tendo prova preciso descansar");
    refresh(); napms(1800);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Mae- Finalmente levou jeito?");
    refresh(); napms(1500);


    //RESPOSTA

    linha_atual += 2;
    nodelay(stdscr, FALSE); 
    keypad(stdscr, TRUE);

    while (1)
    {
        if (marcar_resposta == 0)   wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual, Xall + 2, "[ Sim, parece que sim ]");
        if (marcar_resposta == 0) wattroff(stdscr, A_REVERSE);

        if (marcar_resposta == 1)   wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 1, Xall + 2, "[ Com certeza!(mentir) ]");
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
        //VERDADE
        mvprintw(linha_atual, Xall, "Mae- Ah, gracas a Deus, finalmente, esperei tanto por isso");
        refresh(); napms(2000);
    }
    else
    {
        //MENTIRA
        mvprintw(linha_atual, Xall, "Mae- nao senti muita verdade na sua fala... ");
        refresh(); napms(1500);

        linha_atual++;
        mvprintw(linha_atual, Xall, "Mae- vou ficar de ");
        
        wattron(stdscr, A_BOLD);
        wprintw(stdscr, "olho em voce ");
        wattroff(stdscr, A_BOLD);
        
        wprintw(stdscr, "em");
        refresh(); napms(2000);
    }

    //TOMAR CAFÉ
    linha_atual += 2;
    mvprintw(linha_atual, Xall, "Voce vai tomar cafe, com tempo sobrando");
    refresh(); napms(2000);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Voce se arruma e sai para escola");
    refresh(); napms(2500);

    erase();
    linha_atual = Yall;

    mvprintw(linha_atual, Xall, "Professor- A prova ta facil, a materia que a gente viu em sala");
    linha_atual++;
    mvprintw(linha_atual, Xall, "e a que eu marquei para voces lerem nos livros em casa");
    refresh(); napms(3500);

    linha_atual += 2;
    mvprintw(linha_atual, Xall, "Professor- Pega a prova e passa pra traz");
    refresh(); napms(800);
    linha_atual++;
    mvprintw(linha_atual, Xall, "Professor- Pega a prova e passa pra traz");
    refresh(); napms(800);
    linha_atual++;
    mvprintw(linha_atual, Xall, "Professor- Pega a prova e passa pra traz...");
    refresh(); napms(1500);

    linha_atual += 2;
    mvprintw(linha_atual, Xall, "Todos pegam as suas provas se arrumam e o professor diz:");
    refresh(); napms(2000);
    
    linha_atual++;
    mvprintw(linha_atual, Xall, "Podem virar as provas...");
    refresh(); napms(4000);
    return 0;

}