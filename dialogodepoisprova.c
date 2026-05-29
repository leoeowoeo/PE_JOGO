#include <ncurses.h>
#include "jogos.h"

void dialogodepoisprova(int *acertos, int *maexinga, int *epilepsia)
{
    
    int Xall = (COLS / 2) - 57;
    int Yall = 3;
    int linha_atual = Yall;
    int marcar_resposta=0;
    int tecla_cena=0;
    
    erase();
    nodelay(stdscr, FALSE);
    keypad(stdscr, TRUE);

    // --- ENTRADA DA HISTÓRIA BASEADA NA NOTA ---

    // Ajustado para englobar de 0 a 6 (Caminho 1 - Nota Vermelha)
    if ((*acertos)*2 >= 0 && (*acertos)*2 <= 5)
    {
        // --- CAMINHO 1: NOTA RUIM ---
        slow_mvwprintw(stdscr, "Voce vem caminhando da escola arrastando os pes...", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual++;
        slow_mvwprintw(stdscr, "O chao parece mais pesado a cada passo ate o portao de casa.", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual++;
        slow_mvwprintw(stdscr, "Ao abrir a porta da sala, sua mae esta de pe, bracos cruzados,", linha_atual, Xall);
        linha_atual++;
        slow_mvwprintw(stdscr, "batendo o pe no chao com o telefone fixo a na outra mao.", linha_atual, Xall);
        refresh(); napms(2500);

        linha_atual += 2;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "Mae- O diretor acabou de me ligar.", linha_atual, Xall);
        wattroff(stdscr, A_BOLD);
        refresh(); napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Ele me ligou para dizer que o meu filho conseguiu a proeza de fracassar.", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Me diz... o que voce tem na cabeca? Agua?!", linha_atual, Xall);
        refresh(); napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Eu trabalho o dia inteiro, me mato para te dar as coisas,", linha_atual, Xall);
        linha_atual++;
        slow_mvwprintw(stdscr, "     para voce sentar a bunda na cadeira da escola e nao acertar metade de uma prova?!", linha_atual, Xall);
        refresh(); napms(2500);

        // --- SE O JOGADOR MENTIU NO ATO I ---
        if (*maexinga == 1)
        {
            linha_atual += 2;
            wattron(stdscr, A_BOLD);
            slow_mvwprintw(stdscr, "Mae- E O PIOR! Voce mentiu para mim! Olhou nos meus olhos e disse que tinha estudado!", linha_atual, Xall);
            wattroff(stdscr, A_BOLD);
            refresh(); napms(2500);

            linha_atual++;
            slow_mvwprintw(stdscr, "Mae- Alem de nao estudar, virou um mentiroso de M#%%D@!", linha_atual, Xall);
            refresh(); napms(2000);

            linha_atual++;
            slow_mvwprintw(stdscr, "Mae- Pois agora voce vai para o quarto, e nao vai sair ate saber mais do que Pitagoras.", linha_atual, Xall);
            refresh(); napms(2200);

            linha_atual++;
            wattron(stdscr, A_BOLD);
            slow_mvwprintw(stdscr, "Mae- VOCE VAI FICAR LA ATE APRENDER!", linha_atual, Xall);
            wattroff(stdscr, A_BOLD);
            refresh(); napms(3000);
        }
        else
        {
            // --- SE O JOGADOR NÃO MENTIU MAS TIROU NOTA VERMELHA ---
            linha_atual += 2;
            slow_mvwprintw(stdscr, "Mae- Voce tinha me dito que nao tinha estudado muito, mas isso?!", linha_atual, Xall);
            refresh(); napms(2000);

            linha_atual++;
            slow_mvwprintw(stdscr, "Mae- Isso eh a pura incompetencia! Ficou que nem um vagabundo na sala!", linha_atual, Xall);
            refresh(); napms(2200);

            linha_atual++;
            wattron(stdscr, A_BOLD);
            slow_mvwprintw(stdscr, "Mae- Acabou a palhacada. Sem celular, sem diversao ate que voce cumpra com as obrigacoes!", linha_atual, Xall);
            wattroff(stdscr, A_BOLD);
            refresh(); napms(3000);
        }
    }
    else if ((*acertos)*2 >= 6 && (*acertos)*2 <= 9)
    {
        // --- CAMINHO 2: NOTA MEDIANA ---
        slow_mvwprintw(stdscr, "Voce entra em casa em silencio, deixando a mochila no sofa.", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual++;
        slow_mvwprintw(stdscr, "Sua mae sai da cozinha limpando as maos em um pano de prato.", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Voce chegou... E ai? Como foi naquela bendita prova de matematica?", linha_atual, Xall);
        refresh(); napms(2000);


        linha_atual += 2;
        while (1)
        {
            if (marcar_resposta == 0)   wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual, Xall + 2, "[ Garoto- Foi facil ]");
            if (marcar_resposta == 0) wattroff(stdscr, A_REVERSE);

            if (marcar_resposta == 1)   wattron(stdscr, A_REVERSE);
            mvprintw(linha_atual + 1, Xall + 2, "[ Garoto- ... ]");
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
        if(marcar_resposta)
        {
            mvwprintw(stdscr,linha_atual, Xall, "                                                                 ");
            linha_atual++;
            mvwprintw(stdscr,linha_atual, Xall, "                                                                 ");
            linha_atual--;
            slow_mvwprintw(stdscr, "Garoto- ...",linha_atual, Xall);


        }
        else
        {
            mvwprintw(stdscr,linha_atual, Xall, "                                                                 ");
            linha_atual++;
            mvwprintw(stdscr,linha_atual, Xall, "                                                                 ");
            linha_atual--;
            slow_mvwprintw(stdscr, "Garoto- Foi facil", linha_atual, Xall);
        }

        linha_atual+=2;
        slow_mvwprintw(stdscr,"Mae- Me da logo esse papel, deixa eu ver o resultado com os meus proprios olhos.",linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Voce tira a prova amassada do bolso e entrega para ela.", linha_atual, Xall);
        refresh(); napms(2000);

        erase();
        linha_atual = Yall;

        slow_mvwprintw(stdscr, "Ela ajeita a postura, distancia a prova com os bracos esticados, cerra os olhos e analisa a folha por longos segundos...", linha_atual, Xall);
        refresh(); napms(2500);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Mae- Um ", linha_atual, Xall);
        wattron(stdscr, A_BOLD);
        mvprintw(linha_atual, Xall + 9, "%d", (*acertos) * 2);
        wattroff(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "... Hum.", linha_atual, Xall + 12);
        refresh(); napms(1500);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Nao eh uma nota para se orgulhar.", linha_atual, Xall);
        refresh(); napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Eu nao disse ontem bem claro que era para GABARITAR?!", linha_atual, Xall);
        refresh(); napms(2200);

        if (*maexinga == 1)
        {
            linha_atual += 2;
            slow_mvwprintw(stdscr, "Mae- Voce mente para mim e nem serve pra manter a mentira ", linha_atual, Xall);
            refresh(); napms(2000);
            linha_atual++;
            slow_mvwprintw(stdscr, "Mae- Se vai vacilar comigo, acerta em alguma coisa pelo menos.", linha_atual, Xall);
            refresh(); napms(1800);
        }

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Mae- Agora, vai pro seu quarto, vai ficar sem nada ate que voce aprenda tudo daqueles livros.", linha_atual, Xall);
        refresh(); napms(2500);
    }
    else if ((*acertos)*2 == 10)
    {
        // --- CAMINHO 3: GABARITOU ---
        slow_mvwprintw(stdscr, "Voce abre a porta de casa com um sorriso de soslaio!", linha_atual, Xall);
        refresh(); napms(1800);

        linha_atual++;
        slow_mvwprintw(stdscr, "Voce chega na sala e diz em voz alta:", linha_atual, Xall);
        refresh(); napms(1500);

        linha_atual += 2;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "Garoto- MAE! MAE! EU GABARITEI! EU TIREI DEZ NA PROVA DE MATEMATICA!!", linha_atual, Xall);
        wattroff(stdscr, A_BOLD);
        refresh(); napms(2000);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Sua mae aparece na sala, olha para voce sem esbocar nenhuma reacao.", linha_atual, Xall);
        refresh(); napms(2500);

        linha_atual++;
        slow_mvwprintw(stdscr, "Ela pega o papel da sua mao, confere o carimbo do professor e solta um suspiro.", linha_atual, Xall);
        refresh(); napms(2200);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Hm... Realmente eh um dez.", linha_atual, Xall);
        refresh(); napms(1500);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Ta vendo? Quando voce quer, voce consegue fazer as coisas direito.", linha_atual, Xall);
        refresh(); napms(1800);

        linha_atual++;
        wattron(stdscr, A_BOLD);
        slow_mvwprintw(stdscr, "Mae- A nota eh boa, mas nao fez mais que a sua obrigacao.", linha_atual, Xall);
        wattroff(stdscr, A_BOLD);
        refresh(); napms(2200);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Estudar eh a unica coisa que voce tem que fazer.", linha_atual, Xall);
        refresh(); napms(2000);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- Entao nao ache que esse dez vai te dar permissao pra ficar acordado ate tarde.", linha_atual, Xall);
        refresh(); napms(2500);

        linha_atual += 2;
        slow_mvwprintw(stdscr, "Mae- Fecha a porta que voce deixou escancarada e tira o sapato que ta sujando a sala que eu limpei hoje.", linha_atual, Xall);
        refresh(); napms(2500);

        linha_atual++;
        slow_mvwprintw(stdscr, "Mae- E lave suas maos para almocar.", linha_atual, Xall);
        refresh(); napms(2500);
    }


    
    napms(4000);
    transicao(epilepsia); // Corrigido: Removido o '&' de ponteiro repetido
}
