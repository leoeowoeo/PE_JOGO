#include<ncurses.h>
#include"jogos.h"
void dialogoprovacs()
{
    int Xall=(COLS/2)-57, Yall=3;
    int tecla=0, x=22+Xall, y=10+Yall;
    int marcar_arrumar = 0;
    int marcar_resposta = 0;
    int tecla_cena = 0;
    int linha_atual = Yall;


    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(500);
    
    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(500);
    
    erase();
    slow_mvwprintw(stdscr, "alarme- BEEP BEEP BEEP", linha_atual, Xall);
    beep(); refresh(); napms(500);


    erase();
    slow_mvwprintw(stdscr, "Garoto- Nossa, eu cai no sono... to  todo ferrado", linha_atual, Xall);
    refresh(); napms(1500);
    
    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- Ah e", linha_atual, Xall);
    refresh(); napms(1000);
    
    slow_mvwprintw(stdscr, "Garoto- Ah e, eu tenho prova, preciso me arrumar", linha_atual, Xall);
    refresh(); napms(2000);

    linha_atual++;
    slow_mvwprintw(stdscr, "Voce demora pra levantar por estar lerdo", linha_atual, Xall);
    refresh(); napms(1000);

    linha_atual += 2;
    slow_mvwprintw(stdscr, "Como voce vai se arrumar?", linha_atual, Xall);
    
    nodelay(stdscr, FALSE); 
    keypad(stdscr, TRUE);

    while (1)
    {
        if (marcar_arrumar == 0) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 2, Xall + 2, "[ Se arrumar rapido ]");
        if (marcar_arrumar == 0) wattroff(stdscr, A_REVERSE);

        if (marcar_arrumar == 1) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 3, Xall + 2, "[ Se arrumar bonitinho ]");
        if (marcar_arrumar == 1) wattroff(stdscr, A_REVERSE);

        refresh();
        tecla_cena = getch();

        if (tecla_cena == KEY_UP || tecla_cena == KEY_DOWN)
        {
            marcar_arrumar = !marcar_arrumar;
        }
        else if (tecla_cena == '\n' || tecla_cena == ' ')
        {
            break;
        }
    }

    erase();
    linha_atual = Yall;

    if (marcar_arrumar == 0)
    {
        //SE ARRUMAR RÁPIDO
        slow_mvwprintw(stdscr, "Voce se arruma correndo, sai jogando as roupas para o alto", linha_atual, Xall);
        refresh(); napms(1200);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "pega o que ve pela frente que eh vestivel e sai", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Mae- Meu deus, o que aconteceu com voce?", linha_atual, Xall);
        refresh(); napms(1500);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Que cara e essa toda marcada? E porque voce", linha_atual, Xall);
        refresh(); napms(1200);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "ta com duas meias diferentes e sem cinto?", linha_atual, Xall + 5);
        refresh(); napms(2000);

        // RESPOSTA PARA A MÃE
        linha_atual += 2;
        while (1)
        {
            if (marcar_resposta == 0) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual, Xall + 2, "[ Garoto- Ah, e estilo ]");
            if (marcar_resposta == 0) wattroff(stdscr, A_REVERSE);

            if (marcar_resposta == 1) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual + 1, Xall + 2, "[ Garoto- Mae, nao dormi bem... ]");
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
            slow_mvwprintw(stdscr, "Mae- Estilo? desfaz esse estilo, pelo amor de deus", linha_atual, Xall);
            refresh(); napms(2000);
        }
        else
        {
            slow_mvwprintw(stdscr, "Mae- Percebe-se, vai jogar uma agua no rosto e escovar esse dente", linha_atual, Xall);
            linha_atual++;
            slow_mvwprintw(stdscr, "    to sentindo o bafo daqui...", linha_atual, Xall);
            refresh(); napms(2500);
        }

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Garoto- Ta bem...", linha_atual, Xall);
        refresh(); napms(1200);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "Voce volta pra acertar as coisas", linha_atual, Xall);
        refresh(); napms(2000);
        linha_atual++;
        slow_mvwprintw(stdscr, "Passa um tempo", linha_atual, Xall);
        refresh(); napms(2000);
        linha_atual++;
        slow_mvwprintw(stdscr, "...", linha_atual, Xall);
        refresh(); napms(2000);
    }
    else
    {
        slow_mvwprintw(stdscr, "Voce se arruma lentamente, escolhendo cada roupa...", linha_atual, Xall);
        refresh(); napms(2000);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "Claro, voce chega atrasado, mas nao feio", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Mae- Olha que voce vai se atrasar!!!", linha_atual, Xall);
        refresh(); napms(1500);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Ta mae, eu to so colocando a blusa!", linha_atual, Xall);
        refresh(); napms(1800);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "Voce nao esta so colocando a blusa, voce esta escolhendo ela ainda...", linha_atual, Xall);
        refresh(); napms(2500);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "...", linha_atual, Xall);
        refresh(); napms(1500);
        
        linha_atual++;
        slow_mvwprintw(stdscr, "Voce faz seu cafe, depois de demorar pra se arrumar e enquanto voce esta comen-", linha_atual, Xall);
        refresh(); napms(2000);
    }

    erase();
    linha_atual = Yall;

    slow_mvwprintw(stdscr, "Mae- Voce vai se atrasar ", linha_atual, Xall);
    
    wattron(stdscr, A_BOLD);
    slow_mvwprintw(stdscr, "P0&&@", linha_atual, Xall + 25);
    wattroff(stdscr, A_BOLD);
    
    slow_mvwprintw(stdscr, ", acelera O ", linha_atual, Xall + 30);
    
    wattron(stdscr, A_BOLD);
    slow_mvwprintw(stdscr, "C@%%@l#0 !", linha_atual, Xall + 42);
    wattroff(stdscr, A_BOLD);

    refresh(); 
    napms(2500);

    linha_atual += 2;
    slow_mvwprintw(stdscr, "Voce engole a comida rapidamente e vira um nescau gelado que ate doi o ceu da boca", linha_atual, Xall);
    refresh(); napms(2500);

    linha_atual++;
    slow_mvwprintw(stdscr, "Garoto- ...", linha_atual, Xall);
    refresh(); napms(1500);
    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- Meu deus, ta todo acabado, eu te levo hoje, se nao voce se atrasa", linha_atual, Xall);
    refresh(); napms(2500);

    linha_atual++;
    slow_mvwprintw(stdscr, "Voces saem e a sua mae te leva pra escola", linha_atual, Xall);
    refresh(); napms(6000);

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
    refresh(); napms(6000);
    keypad(stdscr, FALSE);
    
}