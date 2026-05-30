#include<ncurses.h>
#include "jogos.h"


int dialogoMae(int *maexinga)
{
    int Xall = (COLS/2) - 57;
    int Yall = 3;
    int marcar_resposta = 0;
    int tecla_cena = 0;
    int linha_atual = Yall;

    erase();

    slow_mvwprintw(stdscr, "Voce esta na sala, tomando nescau, comendo bisnaguinha", linha_atual, Xall);
    linha_atual++;
    slow_mvwprintw(stdscr, "e assistindo desenho", linha_atual, Xall);
    refresh();
    napms(3500);

    linha_atual++;
    // --- MÃE CHAMA O NOME (ANIMAÇÃO PROGRESSIVA) ---
    slow_mvwprintw(stdscr, "A sua mae chama o seu nome", linha_atual, Xall);
    refresh(); 
    napms(1200);

    wattron(stdscr, A_BOLD);
    slow_mvwprintw(stdscr, "completo", linha_atual, Xall + 27);
    wattroff(stdscr, A_BOLD);
    refresh(); 
    napms(1000);

    mvprintw(linha_atual, Xall, "A sua mae chama o seu nome ");
    wattron(stdscr, A_BOLD);
    mvprintw(linha_atual, Xall + 27, "completo");
    wattroff(stdscr, A_BOLD);
    slow_mvwprintw(stdscr, "pronunciando ", linha_atual, Xall + 36);
    refresh(); 
    napms(1000);

    // --- SILABAÇÃO DO NOME ---

    wattron(stdscr, A_BOLD);
    slow_mvwprintw(stdscr, "ca", linha_atual, Xall + 49);
    wattroff(stdscr, A_BOLD);
    refresh(); 
    napms(600);

    wattron(stdscr, A_BOLD);
    // Sobrescreve limpando/atualizando visualmente conforme o original
    mvprintw(linha_atual, Xall + 49, "ca-da"); 
    wattroff(stdscr, A_BOLD);
    refresh(); 
    napms(600);

    wattron(stdscr, A_BOLD);
    mvprintw(linha_atual, Xall + 49, "ca-da si");
    wattroff(stdscr, A_BOLD);
    refresh(); 
    napms(600);

    wattron(stdscr, A_BOLD);
    mvprintw(linha_atual, Xall + 49, "ca-da si-la");
    wattroff(stdscr, A_BOLD);
    refresh(); 
    napms(600);

    wattron(stdscr, A_BOLD);
    mvprintw(linha_atual, Xall + 49, "ca-da si-la-ba");
    wattroff(stdscr, A_BOLD);
    refresh(); 
    napms(600);

    wattron(stdscr, A_BOLD);
    mvprintw(linha_atual, Xall + 49, "ca-da si-la-ba,");
    wattroff(stdscr, A_BOLD);

    linha_atual++;
    slow_mvwprintw(stdscr, "ela esta furiosa.", linha_atual, Xall);
    refresh(); 
    napms(1500);

    linha_atual += 2;

    slow_mvwprintw(stdscr, "Pensamento do garoto- meu deus, sera que foi porque", linha_atual, Xall);
    refresh(); 
    napms(1000);

    linha_atual++;
    nodelay(stdscr, FALSE);
    keypad(stdscr, TRUE);

    // --- ESCOLHA DE CULPA ---
    while (1)
    {
        if (marcar_resposta == 0) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual, Xall + 2, "[ nao lavei os pratos ]");
        if (marcar_resposta == 0) wattroff(stdscr, A_REVERSE);

        if (marcar_resposta == 1) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 1, Xall + 2, "[ nao estudei ]");
        if (marcar_resposta == 1) wattroff(stdscr, A_REVERSE);

        if (marcar_resposta == 2) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 2, Xall + 2, "[ to acordado ate tarde ]");
        if (marcar_resposta == 2) wattroff(stdscr, A_REVERSE);

        refresh();
        tecla_cena = getch();

        if (tecla_cena == KEY_UP)
        {
            marcar_resposta--;
            if (marcar_resposta < 0) marcar_resposta = 2;
        }
        else if (tecla_cena == KEY_DOWN)
        {
            marcar_resposta++;
            if (marcar_resposta > 2) marcar_resposta = 0;
        }
        else if (tecla_cena == '\n' || tecla_cena == ' ')
        {
            break;
        }
    }

    erase();
    linha_atual = Yall;

    slow_mvwprintw(stdscr, "Voce vai ate ela.", linha_atual, Xall);
    refresh(); 
    napms(1500);

    linha_atual++;
    slow_mvwprintw(stdscr, "Mae- Voce esta ate agora acordado, nao lavou a louca, e...", linha_atual, Xall);
    refresh(); 
    napms(1800);

    linha_atual++;
    slow_mvwprintw(stdscr, "     voce ja estudou para a prova?", linha_atual, Xall);
    refresh(); 
    napms(1500);

    linha_atual += 2;

    // --- ESCOLHA ---
    marcar_resposta = 0;
    while (1)
    {
        if (marcar_resposta == 0) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual, Xall + 2, "[ ja mae, claro que sim ");
        wattron(stdscr, A_BOLD);
        mvprintw(linha_atual, Xall + 25, "(mentir)");
        wattroff(stdscr, A_BOLD);
        mvprintw(linha_atual, Xall + 33, "]");
        if (marcar_resposta == 0) wattroff(stdscr, A_REVERSE);

        if (marcar_resposta == 1) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 1, Xall + 2, "[ nao... ainda nao ]");
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
        // --- SE MENTIR ---
        slow_mvwprintw(stdscr, "Mae-", linha_atual, Xall);
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "JA ESTUDOU A SUA CARA, SEU F!1#0 0@ !#!@", linha_atual, Xall+5);
        wattroff(stdscr, A_BOLD);
        refresh(); 
        napms(1900);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- TA ACHANDO O QUE? QUE EU NAO SEI QUE VOCE ESTA", linha_atual, Xall);
        refresh(); 
        napms(1600);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- O DIA INTEIRO ASSISTINDO DESENHO MESMO TENDO", linha_atual, Xall);
        refresh(); 
        napms(1600);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- PROVA NO DIA SEGUINTE?", linha_atual, Xall);
        refresh(); 
        napms(1900);

        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- mas ma-", linha_atual, Xall);
        refresh(); 
        napms(1200);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- MAS NADA, VAI PRO SEU QUARTO AGORA!", linha_atual, Xall);
        refresh(); 
        napms(2300);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- E SE VOCE NAO GABARITAR ESSA PROVA, EU QUEBRO AQUELE ESPELHO NA SUA CARA!", linha_atual, Xall);
        *maexinga=1;
        refresh(); 
        napms(3000);
    }
    else
    {
        // --- SE NÃO MENTIR ---
        slow_mvwprintw(stdscr, "Mae- Eu sabia, voce nao faz nada alem de assistir desenho o dia todo", linha_atual, Xall);
        refresh(); 
        napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Depois fica igual um maluco conversando com aquele espelho ridiculo.", linha_atual, Xall);
        refresh(); 
        napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Quer saber, desliga a tv-", linha_atual, Xall);
        refresh(); 
        napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Naaaooo maaaeeee-", linha_atual, Xall);
        refresh(); 
        napms(1600);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Eu nao estou pedindo, estou mandando, vai agora!", linha_atual, Xall);
        refresh(); 
        napms(1700);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Desliga a televisao e vai dormir, e se voce nao", linha_atual, Xall);
        refresh(); 
        napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- for bem na prova ", linha_atual, Xall);
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "voce vai se ver comigo em", linha_atual, Xall + 22);
        wattroff(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "!", linha_atual, Xall + 49);
        *maexinga=0;
        refresh(); 
        napms(4000);
    }

    // --- PRIMERA ETAPA: SELEÇÃO DO PENSAMENTO GERAL ---
    erase();
    linha_atual = Yall;
    
    slow_mvwprintw(stdscr, "Pensamento do garoto-", linha_atual, Xall);
    linha_atual += 2;
    
    int opcao_principal = 0;
    while (1)
    {
        if (opcao_principal == 0) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual, Xall + 2, "[ Meu deus, que chata, eu nao vou dormir eh nada,]");
        if (opcao_principal == 0) wattroff(stdscr, A_REVERSE);

        if (opcao_principal == 1) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 1, Xall + 2, "[ Droga, acho melhor eu dormir ]");
        if (opcao_principal == 1) wattroff(stdscr, A_REVERSE);

        if (opcao_principal == 2) wattron(stdscr, A_REVERSE);
        mvprintw(linha_atual + 2, Xall + 2, "[ AAAH, Q SACO, AGORA EU TENHO QUE ESTUDAR??? ]");
        if (opcao_principal == 2) wattroff(stdscr, A_REVERSE);

        refresh();
        tecla_cena = getch();

        if (tecla_cena == KEY_UP)
        {
            opcao_principal--;
            if (opcao_principal < 0) opcao_principal = 2;
        }
        else if (tecla_cena == KEY_DOWN)
        {
            opcao_principal++;
            if (opcao_principal > 2) opcao_principal = 0;
        }
        else if (tecla_cena == '\n' || tecla_cena == ' ')
        {
            break;
        }
    }

    // --- SEGUNDA ETAPA: ROTEAMENTO PARA OS IF / ELSE PRÓPRIOS COM VALORES FIXOS DE RETURN ---
    erase();
    linha_atual = Yall;
    int sub_opcao = 0;

    if (opcao_principal == 0)
    {
        // --- if opção1: ---
        slow_mvwprintw(stdscr, "Pensamento do garoto-", linha_atual, Xall);
        linha_atual += 2;
        
        while (1)
        {
            if (sub_opcao == 0) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual, Xall + 2, "[ vou eh jogar no meu celular ]");
            if (sub_opcao == 0) wattroff(stdscr, A_REVERSE);

            if (sub_opcao == 1) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual + 1, Xall + 2, "[ vou eh fazer tudo daquela revista que eu peguei dela ]");
            if (sub_opcao == 1) wattroff(stdscr, A_REVERSE);

            refresh();
            tecla_cena = getch();

            if (tecla_cena == KEY_UP || tecla_cena == KEY_DOWN)
            {
                sub_opcao = !sub_opcao;
            }
            else if (tecla_cena == '\n' || tecla_cena == ' ')
            {
                nodelay(stdscr, TRUE);
                erase();
                refresh();

                if (sub_opcao == 0)
                {
                    return 0;
                }
                if (sub_opcao == 1)
                {
                    return 1;
                }
            }
        }
    }
    else if (opcao_principal == 1)
    {
        // --- if opção2: ---
        slow_mvwprintw(stdscr, "Pensamento do garoto-", linha_atual, Xall);
        linha_atual += 2;
        
        while (1)
        {
            if (sub_opcao == 0) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual, Xall + 2, "[ to com muito sono, se eu nao dormir vou ficar todo ferrado amanha ]");
            if (sub_opcao == 0) wattroff(stdscr, A_REVERSE);

            if (sub_opcao == 1) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual + 1, Xall + 2, "[ hmmmm, mas e se eu jogar so um pouco... ]");
            if (sub_opcao == 1) wattroff(stdscr, A_REVERSE);

            refresh();
            tecla_cena = getch();

            if (tecla_cena == KEY_UP || tecla_cena == KEY_DOWN)
            {
                sub_opcao = !sub_opcao;
            }
            else if (tecla_cena == '\n' || tecla_cena == ' ')
            {
                nodelay(stdscr, TRUE);
                erase();
                refresh();

                if (sub_opcao == 0)
                {
                    return 2;
                }
                if (sub_opcao == 1)
                {
                    return 3;
                }
            }
        }
    }
    else if (opcao_principal == 2)
    {
        // --- if opção3: ---
        slow_mvwprintw(stdscr, "Pensamento do garoto-", linha_atual, Xall);
        linha_atual += 2;
        *maexinga=1;
        
        while (1)
        {
            if (sub_opcao == 0) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual, Xall + 2, "[ Vou dar uma olhada rapida nos livros pra dizer que estudei e ai eu jogo algo ]");
            if (sub_opcao == 0) wattroff(stdscr, A_REVERSE);

            if (sub_opcao == 1) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual + 1, Xall + 2, "[ Vou estudar mesmo, melhor para eu ir bem, mas depois eu jogo ]");
            if (sub_opcao == 1) wattroff(stdscr, A_REVERSE);

            if (sub_opcao == 2) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual + 2, Xall + 2, "[ Vou estudar mesmo, melhor eu ir bem pra prova, ai eu durmo ]");
            if (sub_opcao == 2) wattroff(stdscr, A_REVERSE);

            refresh();
            tecla_cena = getch();

            if (tecla_cena == KEY_UP)
            {
                sub_opcao--;
                if (sub_opcao < 0) sub_opcao = 2;
            }
            else if (tecla_cena == KEY_DOWN)
            {
                sub_opcao++;
                if (sub_opcao > 2) sub_opcao = 0;
            }
            else if (tecla_cena == '\n' || tecla_cena == ' ')
            {
                nodelay(stdscr, TRUE);
                erase();
                refresh();

                if (sub_opcao == 0)
                {
                    return 4;
                }
                if (sub_opcao == 1)
                {
                    return 5;
                }
                if (sub_opcao == 2)
                {
                    return 6;
                }
            }
        }
    }

    nodelay(stdscr, TRUE);
    erase();
    refresh();
    return 0;
}