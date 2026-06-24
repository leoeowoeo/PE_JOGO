#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "jogos.h"

// A implementação função fica aqui
void pedrapapeltesoura(int *cor,int *encararespelho)
// a função implementa um pedra papel tesoura ( em dialogos )
{
    curs_set(0);
    WINDOW *espelho = newwin(LINES, COLS, 0, 0);

    keypad(espelho, TRUE);
    
    int olhoY = 25 / 2 - 5;
    int olhoX = 50;
    int v=-70,vo=3;
    int ganhou=0;
    int tecla;

    mvwprintw(espelho,4,10,"Use scroll do mouse pra escolher");
    mvwprintw(espelho,6,10,"aperte \"enter\" para selecionar");
    mvwprintw(espelho, 8, 10, "nao aperte varios botoes de uma vez");
    mvwprintw(espelho, 10, 10, "tudo certo? ( aperte qualquer tecla para continuar)");
        tecla = wgetch(espelho);
    for(int i = 0; i < 4; i++,v=-50,vo*=5)
    {

    box(espelho, 0, 0);
    werase(espelho);// Limpa a janela para desenhar o olho
    mvwprintw(espelho, olhoY,     olhoX, "       _....,_            _,...._");
    mvwprintw(espelho, olhoY + 1, olhoX, "   _.-` _,..,_'.        .'_,..,_ `-._");
    mvwprintw(espelho, olhoY + 2, olhoX, "    _,-`/ o \\ '.        .' / o \\`-,_");
    mvwprintw(espelho, olhoY + 3, olhoX, "     '-.\\___/.-`        `-.\\___/.-'" );
    mvwprintw(espelho, olhoY + 5, olhoX + 5, "Voce encara seu reflexo...");
    mvwprintw(espelho, olhoY + 6, olhoX + 5, "Ele quer jogar algo...");
    wrefresh(espelho);
    napms(110+v+vo);
        box(espelho, 0, 0);
    werase(espelho);// Limpa a janela para desenhar o olho fechando
    mvwprintw(espelho, olhoY,     olhoX,   "       _....,_            _,...._");
    mvwprintw(espelho, olhoY + 1, olhoX, "   _.-`       '.        .'       `-._");
    mvwprintw(espelho, olhoY + 2, olhoX, "    _,--_,..,_'.        .'_,..,_--,_");
    mvwprintw(espelho, olhoY + 3, olhoX, "     '-.\\___/.-`        `-.\\___/.-'" );
    mvwprintw(espelho, olhoY + 5, olhoX + 5, "Voce encara seu reflexo...");
    mvwprintw(espelho, olhoY + 6, olhoX + 5, "Ele quer jogar algo...");
    wrefresh(espelho);
    napms(210+v+vo);
        box(espelho, 0, 0);
    werase(espelho);// Limpa a janela para desenhar o olho fechado
    mvwprintw(espelho, olhoY,     olhoX, "       _....,_            _,...._");
    mvwprintw(espelho, olhoY + 1, olhoX, "   _.-`       '.        .'       `-._");
    mvwprintw(espelho, olhoY + 2, olhoX, "    _,-,.____ ,.-      -., ____.,-,_");
    mvwprintw(espelho, olhoY + 3, olhoX, "     '--. _ _\"            \"_ _ .--'");
    mvwprintw(espelho, olhoY + 4, olhoX + 5, "    \" \"                \" \"");
    mvwprintw(espelho, olhoY + 5, olhoX + 5, "Voce encara seu reflexo...");
    mvwprintw(espelho, olhoY + 6, olhoX + 5, "Ele quer jogar algo...");
    wrefresh(espelho);
    napms(210+v+vo); // Espera 2 segundos
        box(espelho, 0, 0);
        werase(espelho);
    mvwprintw(espelho, olhoY,     olhoX,   "       _....,_            _,...._");
    mvwprintw(espelho, olhoY + 1, olhoX, "   _.-`       '.        .'       `-._");
    mvwprintw(espelho, olhoY + 2, olhoX, "    _,--_,..,_'.        .'_,..,_--,_");
    mvwprintw(espelho, olhoY + 3, olhoX, "     '-.\\___/.-`        `-.\\___/.-'" );
    mvwprintw(espelho, olhoY + 5, olhoX + 5, "Voce encara seu reflexo...");
    mvwprintw(espelho, olhoY + 6, olhoX + 5, "Ele quer jogar algo...");
    wrefresh(espelho);
    napms(210+v+vo);
        box(espelho, 0, 0);
        werase(espelho);// Limpa a janela para desenhar o olho
    mvwprintw(espelho, olhoY,     olhoX, "       _....,_            _,...._");
    mvwprintw(espelho, olhoY + 1, olhoX, "   _.-` _,..,_'.        .'_,..,_ `-._");
    mvwprintw(espelho, olhoY + 2, olhoX, "    _,-`/ o \\ '.        .' / o \\`-,_");
    mvwprintw(espelho, olhoY + 3, olhoX, "     '-.\\___/.-`        `-.\\___/.-'" );
    mvwprintw(espelho, olhoY + 5, olhoX + 5, "Voce encara seu reflexo...");
    mvwprintw(espelho, olhoY + 6, olhoX + 5, "Ele quer jogar algo...");
    wrefresh(espelho);
    napms(110+v+vo);
    }
        int turno=0;
        box(espelho, 0, 0);// Desenha uma borda na janela, o tamanho da borda é definido pelos caracteres 0, que são os caracteres padrão para bordas. O primeiro 0 é para as bordas horizontais e o segundo 0 é para as bordas verticais.
        wrefresh(espelho);
        char *escolher[3] = {"Pedra", "Papel", "Tesoura"};// Opções do jogo, armazenadas em um array de strings. O jogador vai escolher uma dessas opções e o computador vai escolher aleatoriamente uma delas também.
        int escolha=0;
        int reflexo; //Nos primeiros jogos, por ser um espelho, o jogador vai escolher a opção que o computador escolheu, ou seja, a mesma opção que ele escolheu. Por exemplo, se o jogador escolher Pedra, o computador vai escolher Pedra, e assim por diante. Depois, nos próximos jogos, o jogador vai escolher a opção que ele quiser, e o computador vai escolher aleatoriamente uma opção também.
        int marcar=0; // Variável para marcar a escolha do jogador

    while ((ganhou!=1)&&tecla!='p')// Loop para esperar o usuário
    {
        mvwprintw(espelho, LINES-2, 5, "nao aperte varios botoes de uma vez");
        
        mvwprintw(espelho, LINES-4, 5, "aperte p para sair");

        mvwprintw(espelho, 6, 5, "Pedra papel tesoura, seu reflexo te encara...");

        mvwprintw(espelho, 8, 5, "selecione com as setas ou scroll do mouse");


        for(int i = 0; i < 3; i++) 
        {
            if(i==marcar)
                wattron(espelho, A_REVERSE); // Destaca a opção selecionada. wattron ativa o destaque, wattroff desativa. A_REVERSE é o destaque de inversão de cores.
            mvwprintw(espelho, 10 + i, 10,"%s", escolher[i]);
            wattroff(espelho,A_REVERSE);
        }
        wrefresh(espelho);
        tecla = wgetch(espelho);
        switch(tecla)
        {
            case KEY_UP: 
                marcar--;
                if(marcar==-1)
                marcar=2;
                break;

            case KEY_DOWN: 
                marcar++;
                if(marcar>2)
                marcar=0;
                break;
            
            case '\n':
                escolha=marcar;
                turno++;
                werase(espelho);
                box(espelho,0,0);
                switch(turno)
                {
                    case 1:
                    //primeiro++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        switch(escolha)
                        {
                        case 0:
                            mvwprintw(espelho,10,40,"Garoto- Pedra!!!");
                            wrefresh(espelho);
                            napms(1000);
                            mvwprintw(espelho,12,40,"O reflexo jogou pedra.");
                            wrefresh(espelho);
                            napms(2000);
                            break;
                        case 1:
                            mvwprintw(espelho,10,40,"Garoto- Papel!!!");
                            wrefresh(espelho);
                            napms(1000);
                            mvwprintw(espelho,12,40,"O reflexo jogou Papel.");
                            wrefresh(espelho);
                            napms(2000);
                            break;
                        case 2: 
                            mvwprintw(espelho,10,40,"Garoto- Tesoura!!!");
                            wrefresh(espelho);
                            napms(1000);
                            mvwprintw(espelho,12,40,"O reflexo jogou tesoura.");
                            wrefresh(espelho);
                            napms(2000);
                            break;
                        }
                        mvwprintw(espelho,14,40,"Isso é empate...");
                        wrefresh(espelho);
                        napms(2000);
                        mvwprintw(espelho,16,40,"O reflexo eh um oponente... persistente, mas tal qual ele, voce tambem eh");
                        wrefresh(espelho);
                        napms(3000);
                        werase(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        break;
                        
                    case 2:
                    //segundo++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        switch(escolha)
                        {
                            case 0:
                                mvwprintw(espelho,10,40,"Voce jogou Pedra!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou Pedra tambem...");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 1:
                                mvwprintw(espelho,10,40,"Voce jogou Papel!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou Papel...");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 2: 
                                mvwprintw(espelho,10,40,"Voce jogou Tesoura!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou Tesoura...");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                        }
                        mvwprintw(espelho,16,40,"Empate...");
                        wrefresh(espelho);
                        napms(1500);
                        mvwprintw(espelho,16,40,"Empate...de novo");
                        wrefresh(espelho);
                        napms(2000);
                        mvwprintw(espelho,18,40,"Garoto- Ele ta lendo a minha mente!?!?");
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        napms(2000);
                        mvwprintw(espelho,20,40,"Hmmmmm");
                        wrefresh(espelho);
                        napms(1000);
                        mvwprintw(espelho,20,40,"Hmmmmm, reflexo tambem parece estar indignado..");
                        wrefresh(espelho);
                        napms(1000);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        break;
                    case 3:
                    //terceir++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        switch(escolha)
                        {
                            case 0:
                                mvwprintw(espelho,10,40,"Garoto- Pedra!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou Pedra.");
                                wrefresh(espelho); // ta ai?
                                napms(2000);
                                break;
                            case 1:
                                mvwprintw(espelho,10,40,"Garoto- Papel!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou Papel.");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 2: 
                                mvwprintw(espelho,10,40,"Garoto- Tesoura!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou Tesoura.");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                        }
                        mvwprintw(espelho,14,40,"Empate...");
                        wrefresh(espelho);
                        napms(1000);
                        mvwprintw(espelho,14,40,"Empate...mais uma vez");
                        napms(1500);
                        wrefresh(espelho);
                        mvwprintw(espelho,16,40,"Voce encara o reflexo com uma hostilidade avida!");
                        wrefresh(espelho);
                        napms(2000);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,18,40,"O reflexo te devolve o olhar na mesma intensidade...");
                        wrefresh(espelho);
                        napms(1000);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        break;
                    case 4:
                    //quarto++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
                        switch(escolha)
                            {
                                case 0:
                                    mvwprintw(espelho,10,40,"Voce imediatamente joga Pedra!!!");
                                    wrefresh(espelho);
                                    napms(1000);
                                    mvwprintw(espelho,12,40,"Mas o reflexo espelha a jogada tao rapido quanto...");
                                    wrefresh(espelho);
                                    napms(2000);
                                    break;
                                case 1:
                                    mvwprintw(espelho,10,40,"Voce imediatamente joga Papel!!!");
                                    wrefresh(espelho);
                                    napms(1000);
                                    mvwprintw(espelho,12,40,"Mas o reflexo espelha a jogada tao rapido quanto...");
                                    wrefresh(espelho);
                                    napms(2000);
                                    break;
                                case 2: 
                                    mvwprintw(espelho,10,40,"Voce imediatamente joga Tesoura!!!");
                                    wrefresh(espelho);
                                    napms(1000);
                                    mvwprintw(espelho,12,40,"Mas o reflexo espelha a jogada tao rapido quanto...");
                                    wrefresh(espelho);
                                    napms(2000);
                                    break;
                            }
                        mvwprintw(espelho,14,40,"Novidade...");
                        wrefresh(espelho);
                        napms(1000);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"Outro empate...");
                        wrefresh(espelho);
                        napms(1000);
                        mvwprintw(espelho,16,40,"O reflexo começa a ficar cansado");
                        wrefresh(espelho);
                        napms(1000);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        break;
                    case 5:
                        switch(escolha)
                        {
                            case 0:
                                mvwprintw(espelho,10,40,"Garoto- Que tal Pedra!!!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo copia: Pedra.");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 1:
                                mvwprintw(espelho,10,40,"Garoto- Que tal Papel!!!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo copia: Papel.");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 2: 
                                mvwprintw(espelho,10,40,"Garoto- Que tal Tesoura!!!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo copia: Tesoura.");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                        }
                        mvwprintw(espelho,14,40,"...");
                        wrefresh(espelho);
                        napms(1000);
                        box(espelho, 0, 0);
                        mvwprintw(espelho,14,43,"Empate...");
                        wrefresh(espelho);
                        napms(1000);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,20,40,"Garoto- Ele ta mais devagar!...");
                        mvwprintw(espelho,16,40,"talvez agora eu consiga!!");
                        wrefresh(espelho);
                        napms(1000);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        break;
                    case 6:
                        switch(escolha)
                        {
                            case 0:
                                mvwprintw(espelho,10,40,"Agora voce jogou Pedra!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo empata com pedra(de novo?).");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 1:
                                mvwprintw(espelho,10,40,"Agora voce jogou Papel!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo empata com Papel(de novo?).");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 2: 
                                mvwprintw(espelho,10,40,"Agora voce jogou Tesoura!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo empata com tesoura(de novo?).");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            }
                            mvwprintw(espelho,14,40,"...");
                            napms(1000);
                            wrefresh(espelho);
                            box(espelho, 0, 0);
                            wrefresh(espelho);
                            mvwprintw(espelho,14,40,"......");
                            napms(1000);
                            wrefresh(espelho);
                            box(espelho, 0, 0);
                            wrefresh(espelho);
                            mvwprintw(espelho,16,40,"Garoto- Quase! na proxima eu pego ele!!");
                            napms(1000);
                            wrefresh(espelho);
                            box(espelho, 0, 0);
                            wrefresh(espelho);
                            break;
                    case 7:
                        switch(escolha)
                        {
                            case 0:
                                mvwprintw(espelho,10,40,"Garoto- (intensamente grita) PEDRAAAA!!!!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo joga tesoura?");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 1:
                                mvwprintw(espelho,10,40,"Garoto- (intensamente grita) PAAAPEEEEEELLL!!!!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou Pedra?");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                            case 2: 
                                mvwprintw(espelho,10,40,"Garoto- (intensamente grita) TESOURAAAAAA!!!!!!");
                                wrefresh(espelho);
                                napms(1000);
                                mvwprintw(espelho,12,40,"O reflexo jogou papel?");
                                wrefresh(espelho);
                                napms(2000);
                                break;
                        }
                        mvwprintw(espelho,14,40,"E mais um em-");
                        wrefresh(espelho);
                        napms(2000);
                        werase(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"???");
                        napms(500);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"??????");
                        napms(500);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"?????????");
                        napms(500);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"!?????");
                        napms(100);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"!!????");
                        napms(50);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        napms(50);
                        werase(espelho);
                        mvwprintw(espelho,14,40,"!!!???");
                        napms(100);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"!!!!??");
                        napms(100);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"!!!!!?");
                        napms(100);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        wrefresh(espelho);
                        mvwprintw(espelho,14,40,"!!!!!!");
                        napms(500);
                        wrefresh(espelho);
                        box(espelho, 0, 0);
                        werase(espelho);
                        napms(2000);
                        mvwprintw(espelho,20,32,"Garoto- EEU GANHEI!!!");
                        wrefresh(espelho);
                        napms(3000);
                        box(espelho, 0, 0);
                            ganhou++;
                            break;
                            default:
                            break;
                }
                        break;
                }
            }
    werase(espelho);
    mvwprintw(espelho,olhoY+5,olhoX+5, "Voce se toca que ainda esta no quarto.");
    wrefresh(espelho);
    napms(4000);
    *encararespelho=1;

}