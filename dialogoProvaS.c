#include<ncurses.h>
#include"jogos.h"
void dialogoprovas()
{
    int Xall=(COLS/2)-57, Yall=3;
    int tecla=0, x=22+Xall, y=10+Yall;
    int marcar_arrumar = 0;
    int marcar_resposta = 0;
    int tecla_cena = 0;
    int linha_atual = Yall;

    // --- ALARME ---
    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP\a BEEP\a BEEP\a", linha_atual, Xall);
    beep(); refresh(); napms(500);
    
    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(500);
    
    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(500);
    

    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- Ah, sim, a prova", linha_atual, Xall);
    refresh(); napms(1000);
    
    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- preciso me arrumar", linha_atual, Xall);
    refresh(); napms(1000);

    linha_atual++;
    slow_mvwprintw(stdscr, "Voce se arruma bem arrumado e sai do quarto", linha_atual, Xall);
    refresh(); napms(1500);

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- Bom dia filho, ta pronto?", linha_atual, Xall);
    refresh(); napms(1200);

    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- Bom dia! Estou sim, me desculpa por ontem, pra recuperar eu estudei antes de ir dormir", linha_atual, Xall);
    refresh(); napms(2000);

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- Hmmm, foi dormir tarde ne?", linha_atual, Xall);
    refresh(); napms(1200);

    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- Naoo! Eu dormi num horario bom, eu tendo prova preciso descansar", linha_atual, Xall);
    refresh(); napms(1800);

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- Finalmente levou jeito?", linha_atual, Xall);
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
        slow_mvwprintw(stdscr, "Mae- Ah, gracas a Deus, finalmente, esperei tanto por isso", linha_atual, Xall);
        refresh(); napms(2000);
    }
    else
    {
        //MENTIRA
        slow_mvwprintw(stdscr, "Mae- nao senti muita verdade na sua fala... ", linha_atual, Xall);
        refresh(); napms(1500);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- vou ficar de ", linha_atual, Xall);
        
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "olho em voce ", linha_atual, Xall + 18); // 18 caracteres de recuo para alinhar após "Mae- vou ficar de "
        wattroff(stdscr, A_BOLD);
        
        slow_mvwprintw(stdscr, "em", linha_atual, Xall + 31); // 18 + 13 de "olho em voce "
        refresh(); napms(2000);
    }

    //TOMAR CAFÉ
    linha_atual += 2;
    slow_mvwprintw(stdscr, "Voce vai tomar cafe, com tempo sobrando", linha_atual, Xall);
    refresh(); napms(2000);

    linha_atual++;
    slow_mvwprintw(stdscr, "Voce se arruma e sai para escola", linha_atual, Xall);
    refresh(); napms(2500);

    erase();
    linha_atual = Yall;

    slow_mvwprintw(stdscr, "Professor- A prova ta facil, a materia que a gente viu em sala", linha_atual, Xall);
    linha_atual++;
    slow_mvwprintw(stdscr, "e a que eu marquei para voces lerem nos livros em casa", linha_atual, Xall);
    refresh(); napms(3500);

    linha_atual += 2;
    slow_mvwprintw(stdscr, "Professor- Pega a prova e passa pra traz", linha_atual, Xall);
    refresh(); napms(800);
    linha_atual++;
    slow_mvwprintw(stdscr, "Professor- Pega a prova e passa pra traz", linha_atual, Xall);
    refresh(); napms(800);
    linha_atual++;
    slow_mvwprintw(stdscr, "Professor- Pega a prova e passa pra traz...", linha_atual, Xall);
    refresh(); napms(1500);

    linha_atual += 2;
    slow_mvwprintw(stdscr, "Todos pegam as suas provas se arrumam e o professor diz:", linha_atual, Xall);
    refresh(); napms(2000);
    
    linha_atual++;
    slow_mvwprintw(stdscr, "Podem virar as provas...", linha_atual, Xall);
    refresh(); napms(4000);
}