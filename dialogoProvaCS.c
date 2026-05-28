#include<ncurses.h>
int dialogoprovacs()
{
    int Xall=(COLS/2)-57, Yall=3;
    int tecla=0, x=22+Xall, y=10+Yall;
    int marcar_arrumar = 0;
    int marcar_resposta = 0;
    int tecla_cena = 0;
    int linha_atual = Yall;

    // --- ALARME ---
    erase();
    mvprintw(linha_atual, Xall, "alarme- BEEP BEEP BEEP");
    beep(); refresh(); napms(500);
    
    erase();
    mvprintw(linha_atual, Xall, "alarme- BEEP BEEP BEEP");
    beep(); refresh(); napms(500);
    
    erase();
    mvprintw(linha_atual, Xall, "alarme- BEEP BEEP BEEP");
    beep(); refresh(); napms(500);

    // --- DIÁLOGO INICIAL ---
    erase();
    mvprintw(linha_atual, Xall, "Garoto- Nossa, eu cai no sono... to  todo ferrado");
    refresh(); napms(1500);
    
    linha_atual++;
    mvprintw(linha_atual, Xall, "Garoto- Ah e");
    refresh(); napms(1000);
    
    mvprintw(linha_atual, Xall, "Garoto- Ah e, eu tenho prova, preciso me arrumar");
    refresh(); napms(2000);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Voce demora pra levantar por estar lerdo");
    refresh(); napms(1000);

    linha_atual += 2;
    mvprintw(linha_atual, Xall, "Como voce vai se arrumar?");
    
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
            marcar_arrumar = !marcar_arrumar; // Alterna entre 0 e 1
        }
        else if (tecla_cena == '\n' || tecla_cena == ' ')
        {
            break; // Jogador confirmou a escolha
        }
    }

    erase();
    linha_atual = Yall;

    if (marcar_arrumar == 0)
    {
        //SE ARRUMAR RÁPIDO
        mvprintw(linha_atual, Xall, "Voce se arruma correndo, sai jogando as roupas para o alto");
        refresh(); napms(1200);
        
        linha_atual++;
        mvprintw(linha_atual, Xall, "pega o que ve pela frente que eh vestivel e sai");
        refresh(); napms(2000);

        linha_atual += 2;
        mvprintw(linha_atual, Xall, "Mae- Meu deus, o que aconteceu com voce?");
        refresh(); napms(1500);

        linha_atual++;
        mvprintw(linha_atual, Xall, "Mae- Que cara e essa toda marcada? E porque voce");
        refresh(); napms(1200);
        
        linha_atual++;
        mvprintw(linha_atual, Xall+5, "ta com duas meias diferentes e sem cinto?");
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
            mvprintw(linha_atual, Xall, "Mae- Estilo? desfaz esse estilo, pelo amor de deus");
            refresh(); napms(2000);
        }
        else
        {
            mvprintw(linha_atual, Xall, "Mae- Percebe-se, vai jogar uma agua no rosto e escovar esse dente");
            linha_atual++;
            mvprintw(linha_atual, Xall, "    to sentindo o bafo daqui...");
            refresh(); napms(2500);
        }

        linha_atual += 2;
        mvprintw(linha_atual, Xall, "Garoto- Ta bem...");
        refresh(); napms(1200);
        
        linha_atual++;
        mvprintw(linha_atual, Xall, "Voce volta pra acertar as coisas");
        refresh(); napms(2000);
        linha_atual++;
        mvprintw(linha_atual, Xall, "Passa um tempo");
        refresh(); napms(2000);
        linha_atual++;
        mvprintw(linha_atual, Xall, "...");
        refresh(); napms(2000);
    }
    else
    {
        //SE ARRUMAR DEVAGAR
        mvprintw(linha_atual, Xall, "Voce se arruma len"); refresh(); napms(1000);
        mvprintw(linha_atual, Xall, "Voce se arruma lenta"); refresh(); napms(1000);
        mvprintw(linha_atual, Xall, "Voce se arruma lentamen"); refresh(); napms(1000);
        mvprintw(linha_atual, Xall, "Voce se arruma lentamente"); refresh(); napms(1000);
        mvprintw(linha_atual, Xall, "Voce se arruma lentamente, escolhendo cada roupa...");refresh(); napms(2000);
        
        linha_atual++;
        mvprintw(linha_atual, Xall, "Claro, voce chega atrasado, mas nao feio");
        refresh(); napms(2000);

        linha_atual += 2;
        mvprintw(linha_atual, Xall, "Mae- Olha que voce vai se atrasar!!!");
        refresh(); napms(1500);
        
        linha_atual++;
        mvprintw(linha_atual, Xall, "Garoto- Ta mae, eu to so colocando a blusa!");
        refresh(); napms(1800);
        
        linha_atual++;
        mvprintw(linha_atual, Xall, "Voce nao esta so colocando a blusa, voce esta escolhendo ela ainda...");
        refresh(); napms(2500);
        
        linha_atual++;
        mvprintw(linha_atual, Xall, "...");
        refresh(); napms(1500);
        
        linha_atual++;
        mvprintw(linha_atual, Xall, "Voce faz seu cafe, depois de demorar pra se arrumar e enquanto voce esta comen-");
        refresh(); napms(2000);
    }

    erase();
    linha_atual = Yall;


    mvprintw(linha_atual, Xall, "Mae- Voce vai se atrasar ");
    
    wattron(stdscr, A_BOLD);
    wprintw(stdscr, "P0&&@");
    wattroff(stdscr, A_BOLD);
    

    wprintw(stdscr, ", acelera O ");
    

    wattron(stdscr, A_BOLD);
    wprintw(stdscr, "C@%%@l#0 !");
    wattroff(stdscr, A_BOLD);


    refresh(); 
    napms(2500);

    linha_atual += 2;
    mvprintw(linha_atual, Xall, "Voce engole a comida rapidamente e vira um nescau gelado que ate doi o ceu da boca");
    refresh(); napms(2500);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Garoto- ...");
    refresh(); napms(1500);
    linha_atual++;
    mvprintw(linha_atual, Xall, "Mae- Meu deus, ta todo acabado, eu te levo hoje, se nao voce se atrasa");
    refresh(); napms(2500);

    linha_atual++;
    mvprintw(linha_atual, Xall, "Voces saem e a sua mae te leva pra escola");
    refresh(); napms(6000);


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
    refresh(); napms(6000);
    return 0;
}