#include<ncurses.h>
#include "jogos.h"
int dialogofinal(int *finais_alcancados,int *acertos)
{
    int skipado = 0;
    int Xall = (COLS / 2) - 57;
    int Yall = 3;
    int linha_atual;
    erase();

    if(*acertos==5)
    {
        slow_mvwprintw(stdscr, "Voce entra no seu quarto e fecha a porta devagar", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        slow_mvwprintw(stdscr, "Deita na cama e olha para o teto...", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Garoto- Cara... deu muito trabalho, mas que bom que eu consegui", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Minha mae nao expressou tanto, mas deu pra ver que ela se surpreendeo com a minha nota", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Voce, aos poucos, vai sentindo seus olhos pesados", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Que sono...", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Acho que vou dormir um pouco, vai ser bom descansar depois dessa prova", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Nenhum deus da matematica vai conseguir me afetar agora", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual += 2;
        finais_alcancados++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "--- Final bom alcançado ---", linha_atual, Xall + 10, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(4000);
    }
    else
    {
        int opcao_retorno = 0;
        int tecla_cena = 0;
        linha_atual=Yall;
        erase();
        slow_mvwprintw(stdscr, "Voce joga a cabeca no travesseiro, exausto e frustrado...", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Droga, eu odeio ter que fazer prova.", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Por que meus professores sempre fazem elas tao dificeis???", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Por que???", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Por que tao dificeis???", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Acho que vou dormir um pouco agora, essa prova horrivel me deu muito sono", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        slow_mvwprintw(stdscr, "Seus olhos estao pesados e ficar consciente eh dificil", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        erase();
        linha_atual=Yall;
        mvwprintw(stdscr,linha_atual,Xall,".");
        refresh(); napms(700);
        mvwprintw(stdscr,linha_atual,Xall,". .");
        refresh(); napms(700);
        mvwprintw(stdscr,linha_atual,Xall,". . .");
        refresh(); napms(700);
        erase();
        flash();

        linha_atual = Yall;
        slow_mvwprintw(stdscr, "De repente, voce acorda em um lugar. . . estranho?", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        linha_atual++;
        slow_mvwprintw(stdscr, "Voce olha em volta e ve varios. . . triangulos retangulos. . . e angulos retos?", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);
        linha_atual+=2;
        slow_mvwprintw(stdscr, "Entao, voce ouve uma voz. . .", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual += 2;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "#########- Saudacoes, jovem matematico.", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);
        erase();
        linha_atual++;
        slow_mvwprintw(stdscr, "Garoto- Quem eh voce?!", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        slow_mvwprintw(stdscr, "Garoto- Quem eh voce?! Onde eu to??", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "#########- Sou aquele que voce ignorou enquanto jogava ou dormia.", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);
        linha_atual++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "#########- Aquele que voce nunca deu atencao.", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);

        linha_atual++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "#########- EU SOU...", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);
        linha_atual++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "PITAGORAS!!", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);
        erase();
        linha_atual=Yall;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "Pitagoras(o solitario)- Minha alma foi invocada pelos diversos crimes matematicos que voce cometeu naquela prova.", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Garoto- Ate voce veio me humilhar? Ja nao basta a minha mae?", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        refresh(); napms(700);

        linha_atual++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "Pitagoras(o solitario)- Nao vim lhe humilhar. Vim lhe mostrar que o universo eh feito de numeros, eh impossivel fugir deles.", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        linha_atual++;
        slow_mvwprintw(stdscr, "Pitagoras(o solitario)- E a sua nota atual eh um numero que...", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);

        napms(300);
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "fere...", linha_atual, Xall+63, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);

        linha_atual++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "Pitagoras(o solitario)- Sua nota atual eh um numero que fere a minha existencia.", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);

        linha_atual += 2;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "Pitagoras(o solitario)- Voce quer aceitar a realidade ou desafiar o destino e refazer as coisas da forma correta?", linha_atual, Xall, &skipado);
        if (skipado) return 0;
        wattroff(stdscr, A_BOLD);
        refresh(); napms(700);

        linha_atual += 2;
        nodelay(stdscr, FALSE);
        keypad(stdscr, TRUE);
        flushinp();

        while (1)
        {
            if (opcao_retorno == 0) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual, Xall + 2, "[ Voltar ao dia anterior e estudar de verdade ]");
            if (opcao_retorno == 0) wattroff(stdscr, A_REVERSE);

            if (opcao_retorno == 1) wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual + 1, Xall + 2, "[ Aceitar minha incompetencia e desistir ]");
            if (opcao_retorno == 1) wattroff(stdscr, A_REVERSE);

            refresh();
            tecla_cena = getch();

            if (tecla_cena == KEY_UP || tecla_cena == KEY_DOWN)
            {
                opcao_retorno = !opcao_retorno;
            }
            else if (tecla_cena == '\n' || tecla_cena == ' ')
            {
                break;
            }
        }

        if (opcao_retorno == 0)
        {
            erase();
            linha_atual = Yall;
            wattron(stdscr, A_BOLD);
            slow_mvwprintw(stdscr, "Pitagoras(o solitario)- Assim seja. Que as hipotenusas iluminem seu caminho e te guiem...", linha_atual, Xall, &skipado);
            if (skipado) return 0;
            wattroff(stdscr, A_BOLD);
            refresh(); napms(700);
            linha_atual++;
            wattron(stdscr, A_BOLD);
            slow_mvwprintw(stdscr, "Pitagoras(o solitario)- PARA VITORIA!!!", linha_atual, Xall, &skipado);
            if (skipado) return 0;
            wattroff(stdscr, A_BOLD);
            refresh(); napms(700);
            flash();
            napms(100);
            flash();
            napms(100);
            flash();
            return 1;
        }
        else
        {
            erase();
            linha_atual = Yall;
            wattron(stdscr, A_BOLD);
            slow_mvwprintw(stdscr, "Pitagoras(o solitario)- Uma pena. A ignorancia eh uma bencao mesmo, mas ela se tornara a sua ruina... essa decisao eh apenas sua.", linha_atual, Xall, &skipado);
            if (skipado) return 0;
            wattroff(stdscr, A_BOLD);
            refresh(); napms(700);
            linha_atual++;
            wattron(stdscr, A_BOLD);
            slow_mvwprintw(stdscr, "Pitagoras(o solitario)- Entao, que assim seja, sinto muito, jovem...", linha_atual, Xall, &skipado);
            if (skipado) return 0;
            wattroff(stdscr, A_BOLD);
            refresh(); napms(700);
            exit(0);
            return 0;
        }
    }
}