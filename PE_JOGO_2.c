#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define TARGET_FRAME_MS 30
#define COR_MARROM         8
#define COR_JANELA         9
#define COR_FUNDO_CHUVA    10
#define COR_CHUVA          11
#define COR_CHAO           12
#define COR_ESTANTE        13
#define COR_TAPETE_OPCAO1  14
#define COR_RODAPE         15
#define COR_BANCO          16
#define COR_ESPELHO        17
#define COR_CIANO          18
#define COR_CINZAESCURO    19
#include "jogos.h"
// ==================== MAIN ====================
int main()
{
    FILE *entrada, *saida;
    curs_set(0);
    initscr();
    cbreak();
    noecho();
    int Xall = (COLS/2)-57, Yall = 3;
    SAVE save;
    save.atividade_sono = 0;
    save.celularpickup = 0;
    save.livropickup = 0;
    save.revistapickup = 0;
    save.maepistola = 0;
    save.maepistoladef = 0;
    save.janelaaberta = 0;
    save.depoisprova = 0;
    save.iniciado = 0;
    save.x = 22 + Xall;
    save.y = 10 + Yall;
    save.celularpos = 2;
    save.quest = 0;
    save.estagio = 0;
    save.cor = 1; 
    save.selecao_face =0;
    save.selecao_olhos=9;
    save.selecao_pernas=0;
    save.selecao_cor=0;

    int tecla = 0;
    int xf = 22 + Xall, yf = 10 + Yall, lado = 0;
    int janelaY = 4 + Yall, janelaX = 50 + Xall;
    int celularY = 9 + Yall, celularX = 76 + Xall;
    int armarioY = 14 + Yall, armarioX = 19 + Xall, armarioaberto = 0, pertocama = 0, dormindo = 0;
    int revistax = celularX, revistay = celularY, meow = 0;
    int livroX = celularX + 17, livroY = celularY, abrindolivro = 0;
    int livro1 = 0, livro2 = 0, livro3 = 0, estudando = 0;
    int jogarcelular = 0;
    int acertos = 0;
    int interagirCel = 0, interagirEst = 0, interagirArm = 0, interagirJan = 0, interagirCam = 0;
    int tecla_selecao, interage = 0,par = 0;
    int jogarcelular5 = 0, encararespelho = 0, dormircama = 0, jogartodosjogos = 0, ler1jogar3 = 0, ler3dormir = 0, ler3jogatodos = 0;
    char *quests[8] = {
        "Ganhar 5 jogos no celular",
        "Encarar o espelho",
        "Dormir na cama",
        "Jogar todos os jogos uma vez",
        "Ler um livro e jogar 3 jogos",
        "Ler 3 livros e jogar todos os jogos do celular",
        "Ler 3 livros e . . .dormir?",
        "Leia 3 livros e durma bem"
    };
    int finais_alcancados;
    char *revista[9] = {"1", "2", "3", "4", "5", "6"};
    int passo = 0, vira = 0;
    int check = 0;
    int espelho = 0;
    int marcar = 0;
    int xbarra = 3, ybarra = 3;
    int j, i;
    int maexinga = 0;
    int epilepsia = 0;
    int estudo = 0;
    int validador = 1;
    int fechar = 0;
    int voltar_inicio = 0;
    int jogar = 0;
    int debug = 1;
    int revista_coluna = 0;
    int revista_linha = 0;
    int iniciar = 0;
    int estanoquarto = 0;

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    erase();
    move(0, 0);
    curs_set(0);

    while (1) // menu
    {
        estanoquarto = 0;
        if (save.depoisprova == 0)
        {
            inicio(&interage, &iniciar, &epilepsia, &save, &jogar, estanoquarto);
            //inicio(&save.selecao_olhos, &save.selecao_face, &save.selecao_pernas, &save.cor, &interage, &save.selecao_cor, &iniciar, &epilepsia, &save, &save.iniciado, &jogar, estanoquarto);
            noraw();
            cbreak();
        }
        if (epilepsia == 1) mvprintw(LINES-5, 5, "MODO DE EPILEPSIA");

        erase();
        refresh();
        inicializar_cores(save, interage, save.selecao_cor, &par);
        //void inicializar_cores(int cor, int interage, int selecaocor, int *par)
        napms(30);

        if ((iniciar == 0 || save.depoisprova == 0) && save.estagio == 0)
        {
            /*keypad(stdscr, FALSE);
            mvprintw(Yall, Xall, "Mova-se com \"WASD\" - saia com a tecla q");
            refresh(); napms(4000); erase();
            mvprintw(Yall, Xall, "Para uma boa gameplay, dentro dos jogos nao saia apertando todos os botoes");
            mvprintw(Yall+1, Xall, "Ou movendo a janela do terminal, pode ocasionar em bugs");
            refresh(); napms(4000);
            mvprintw(Yall+3, Xall, "Fora dos jogos aperte \"Q\" para sair*");
            refresh(); napms(5000); erase();
            mvprintw(Yall, Xall, "Esse projeto ainda esta sendo desenvolvido");
            refresh(); napms(4000); erase();
            mvprintw(Yall, Xall, "Bom jogo!");
            refresh(); napms(4000);*/
            save.estagio++;
            erase();
            transicao(&epilepsia);
            save.quest = dialogoMae(&maexinga);
            keypad(stdscr, TRUE);
        }

        int pisca = 1, vontadedepisca = 0;
        int chuvax = 53 + Xall, chuvay = 5 + Yall, pos = 0, pos2 = 1, pos3 = 2;

        while (1)
        {
            if (save.depoisprova == 1) { save.x = 22 + Xall; save.y = 10 + Yall; }
            while (1)
            {
                if (save.atividade_sono >= 0 && save.depoisprova == 1) save.atividade_sono = 3;
                dormindo = 0;
                while (1)
                {
                    estanoquarto = 1;
                    gravar_imagem_do_momento(save.x, save.y, save.imagem);
                    if (tecla == 'm') menusave(&save, &jogar,estanoquarto);
                    if (save.depoisprova == 1 && validador == 1) { save.maepistola = 0; save.maepistoladef = 0; validador = 0; }
                    fechar = 0;
                    clock_t frame_start = clock();

                    if (save.depoisprova == 0)
                    {
                        if (save.estagio == 0) strcpy(save.momento, "Dialogo com a mae");
                        else if (save.estagio == 1) strcpy(save.momento, "Quarto");
                        else if (save.estagio == 2) strcpy(save.momento, "Prova");
                    }
                    else
                    {
                        if (save.estagio == 3) strcpy(save.momento, "Quarto(depois da prova)");
                        else if (save.estagio == 4) strcpy(save.momento, "Dialogo final");
                    }

                    vontadedepisca++;
                    nodelay(stdscr, TRUE);
                    if (vontadedepisca <= 500) pisca = 1;
                    else if (vontadedepisca > 500 && vontadedepisca <= 505) pisca = 0;
                    else vontadedepisca = 0;
                    erase();

                    // ===== DESENHO DO QUARTO =====
                    int camaY = 8 + Yall, camaX = 80 + Xall;
                    int estanteY = 5 + Yall, estanteX = 34 + Xall;
                    int mesaY = 8 + Yall, mesaX = 74 + Xall;
                    int lixoY = 27 + Yall, lixoX = 84 + Xall;
                    int tapetey = 18 + Yall, tapetex = 45 + Xall;
                    int rodapey = 9 + Yall, rodapex = 21 + Xall;
                    int espelhoy = 3 + Yall, espelhox = 63 + Xall;
                    int portaY = 3 + Yall, portaX = 11 + Xall;
                    int gatoy = armarioY + 13, gatox = armarioX + 10;
                    //==========================DESENHA O QUARTO===========================
                    desenhar_cama(Xall, Yall,save.cor, interagirCam, par);
                    desenhar_estante(Xall, Yall,save.cor, interagirEst, par, &save, celularX, celularY);
                    desenhar_mesa(Xall, Yall,save.cor);
                    desenhar_armario(Xall, Yall,save.cor, armarioaberto, interagirArm, par);
                    espelhaogaroto(&save, espelhox, espelhoy, pisca,save.selecao_face,save.selecao_pernas,save.selecao_olhos,passo,vira);
                    desenhar_espelho(Xall, Yall,save.cor, par);
                    desenhar_janela(Xall, Yall,save.cor,save.janelaaberta, interagirJan, par,chuvax, chuvay, &pos, &pos2, &pos3,check);
                    //void desenhar_janela(int Xall, int Yall, int cor, int janelaaberta, int interagirJan, int par,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check)
                    desenhar_rodape(Xall, Yall,save.cor);
                    desenhar_porta(Xall, Yall,save.cor,save.depoisprova,save.maepistoladef,maexinga, acertos);
                    //void desenhar_porta(int Xall, int Yall, int cor, int depoisprova, int maepistoladef, int maexinga, int acertos)
                    desenhar_lixo(Xall, Yall,save.cor);
                    desenhar_tapete(Xall, Yall,save.cor);
                    desenhar_gato(Xall, Yall, armarioX, armarioY, vontadedepisca, save.depoisprova);
                    desenhar_celular_mesa(Xall, Yall,&save, celularX, celularY, interagirCel, par);
                    desenhar_jogador(&save, vira, passo, pisca,save.cor, save.selecao_face, save.selecao_olhos, save.selecao_pernas);
                    desenhar_hud(ybarra, xbarra,save.cor, &save, jogarcelular5, encararespelho, dormircama, jogartodosjogos, ler1jogar3, ler3jogatodos, ler3dormir, quests);
                    if(save.celularpickup==1) printar_celular(save,celularX,celularY);
                    check++;//fazer chover
                    if(save.maepistola>150)
                        save.maepistoladef=1;
                    save.maepistola++;//mae fechar a porta
                    // ===== MOVIMENTAÇÃO =====
                    tecla = getch();
                    movimentar_jogador(tecla, &xf, &yf, &passo, &lado, &vira, Xall, Yall);
                    check++;
                    if (check > 100) { check = 0; passo = 0; }

                    processar_colisoes(&xf, &yf, &save, camaX, camaY, estanteX, estanteY, armarioX, armarioY, mesaX, mesaY, lixoX, lixoY);
                    save.x = xf; save.y = yf;
                    check++;
                    if (check > 100) { check = 0; passo = 0; }

                    // ===== INTERAÇÕES =====
                    processar_interacoes(&save, tecla, Xall, Yall, espelhox, espelhoy, camaX, camaY, armarioX, armarioY, janelaX, janelaY, celularX, celularY, &espelho, &dormindo, &armarioaberto, &interagirCam, &interagirArm, &interagirJan, &interagirCel, &interagirEst, &marcar, &jogarcelular5,save.cor, &revista_linha, &revista_coluna, &livro1, &livro2, &livro3, &abrindolivro, &estudo, &estudando, &acertos, vira, estanteX, estanteY);

                    desenhanafrente( Xall,  Yall,  save.cor,  armarioaberto,  interagirArm,  par, lixoY,  lixoX);
                    // ===== ESPELHO MINIGAME =====
                    if (espelho == 1)
                    {
                        nodelay(stdscr, FALSE);
                        pedrapapeltesoura(&save.cor, &encararespelho);
                        espelho = 0;
                        nodelay(stdscr, TRUE);
                        erase();
                        save.atividade_sono++;
                    }
                    // ===== LIVRO ABERTO =====
                    printar_livro(save.livropickup, &abrindolivro, livro1, livro2, livro3, livroY, livroX);
                    

                    // ===== CELULAR MENU =====
                    if (save.celularpickup == 1)
                    {
                        char *jogar[3] = {"cobrinha", "2048", "batalha naval"};
                        for (int i = 0; i < 3; i++)
                        {
                            if (i == marcar) attron(A_REVERSE);
                            mvprintw(celularY + 4 + i, celularX + 21, "%s", jogar[i]);
                            attroff(A_REVERSE);
                        }
                        switch (tecla)
                        {
                            case KEY_UP: marcar--; if (marcar == -1) marcar = 2; break;
                            case KEY_DOWN: marcar++; if (marcar > 2) marcar = 0; break;
                            case '\n':
                                if (marcar == 0) { cobra(&save.cor, &jogarcelular5); save.atividade_sono++; marcar = 0; }
                                if (marcar == 1 || marcar == 2) { demo(); marcar = 0; }
                                break;
                        }
                    }

                    // ===== REVISTA MENU =====
                    if (save.revistapickup == 1)
                    {
                        attron(A_REVERSE);
                        mvprintw(revistay + 5 + revista_linha, revistax + 18 + revista_coluna + 3, "%s", revista[marcar]);
                        attroff(A_REVERSE);
                        switch (tecla)
                        {
                            case KEY_RIGHT: marcar--; revista_coluna += 2;
                                if (revista_coluna > 4 && revista_linha == 0) revista_coluna = 0;
                                else if (revista_linha == 1) { if (revista_coluna > 6) marcar = 0; if (revista_coluna > 12) revista_coluna = 0; }
                                if (marcar == -1) marcar = 5; break;
                            case KEY_LEFT: marcar++; if (marcar > 5) marcar = 0; break;
                            case KEY_DOWN: revista_linha++; if (revista_linha > 2) revista_linha = 0; break;
                            case KEY_UP: if (revista_coluna >= 6) revista_linha--; break;
                            case '\n': if (marcar == 0 || marcar) demo(); break;
                        }
                    }

                    // ===== ESTUDAR LIVRO =====
                    if (livro1 || livro2 || livro3)
                    {
                        wattron(stdscr, A_BOLD);
                        mvprintw(Yall+33, Xall+47, "Estudar livro?:R");
                        wattroff(stdscr, A_BOLD);
                        if (tecla == 'r' || tecla == 'R')
                        {
                            estudando = 1;
                            int cont = 0;
                            nodelay(stdscr, TRUE);
                            while (tecla != 'p' && tecla != 'P')
                            {
                                tecla = getch();
                                wattron(stdscr, A_BOLD);
                                mvprintw(LINES-10, COLS-25, "Parar de estudar?: P");
                                wattroff(stdscr, A_BOLD);
                                if (cont > 13000)
                                {
                                    wattron(stdscr, A_BOLD);
                                    mvprintw(LINES-10, COLS-30, "Liberta-lo do sofrimento?: P");
                                    wattroff(stdscr, A_BOLD);
                                }
                                if ((cont / 300) % 6 == 0) mvprintw(save.y-2, save.x-8, "estudando... ");
                                else if ((cont / 300) % 6 == 1) mvprintw(save.y-2, save.x-8, "estudando.. .");
                                else if ((cont / 300) % 6 == 2) mvprintw(save.y-2, save.x-8, "estudando. ..");
                                else if ((cont / 300) % 6 == 3) mvprintw(save.y-2, save.x-8, "estudando ...");
                                else if ((cont / 300) % 6 == 4) mvprintw(save.y-2, save.x-8, "estudando. ..");
                                else mvprintw(save.y-2, save.x-8, "estudando.. .");

                                if (livro1)
                                {
                                    if (cont > 5000 && cont <= 15000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- isso vai demorar...                              ");
                                        mvprintw(9, 7, "eu poderia estar jogando agora                           ");
                                    }
                                    else if (cont > 15000 && cont <= 30000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- quantas paginas tem isso aqui?                   ");
                                        mvprintw(8, 7, "nossa, ainda estou em um 1/3...                          ");
                                        mvprintw(9, 7, "Eu poderia jogar agora...                                ");
                                    }
                                    else if (cont > 30000 && cont <= 45000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Aperta \"P\", por favor, isso aqui...            ");
                                        mvprintw(8, 7, "isso aqui e um saco, silogismo... to so na metade        ");
                                        mvprintw(9, 7, "Eu nao quero fazer diagrama de Venn...                   ");
                                        refresh(); 
                                    }
                                    else if (cont > 45000 && cont <= 60000) 
                                    {
                                        mvprintw(7, 7, "Garoto- Nao vou falar mais nada nao, seu...              ");
                                        mvprintw(8, 7, "SEU BOBOCA!!! EH, BOBOCA, voce nao me deixa              ");
                                        mvprintw(9, 7, "saiiiiir, eu quero jogar =(, nao ver equacoes            ");
                                    }
                                }
                                else if (livro2)
                                {
                                    if (cont > 5000 && cont <= 15000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Geometria? Serio mesmo?                          ");
                                        mvprintw(8, 7, "Pra que eu quero saber o tamanho de um poligono?         ");
                                    }
                                    else if (cont > 15000 && cont <= 30000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- 'Calcule a area da figura hachurada...'          ");
                                        mvprintw(8, 7, "Isso aqui parece um labirinto bizarro!                   ");
                                        mvprintw(9, 7, "Minha cabeca ta comecando a doer...                      ");
                                    }
                                    else if (cont > 30000 && cont <= 45000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Ei, voce ai controlando o teclado...              "); 
                                        mvprintw(8, 7, "Se eu ver mais um triangulo retangulo na minha frente    ");
                                        mvprintw(9, 7, "eu vou quebrar esse terminal, juro por Deus!             ");
                                    }
                                    else if (cont > 45000 && cont <= 60000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Cateto oposto, hipotenusa, blablabla...          ");
                                        mvprintw(8, 7, "Corta essa! Me deixa voltar pro celular!                 ");
                                        mvprintw(9, 7, "Voce gosta de me ver sofrer, e isso?                     ");
                                    }
                                }
                                else if (livro3)
                                {
                                    if (cont > 5000 && cont <= 15000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Ah nao, algebra linear...                        ");
                                        mvprintw(8, 7, "Matrizes 5x5 cheias de zeros e uns. Que tedio.           ");
                                    }
                                    else if (cont > 15000 && cont <= 30000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- 'Um algoritmo deterministico...'                 ");
                                        mvprintw(8, 7, "Eu sou um personagem de um jogo em C, sabia?             ");
                                        mvprintw(9, 7, "Estudar programacao dentro de um programa e meta demais. ");
                                    }
                                    else if (cont > 30000 && cont <= 45000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Querido jogador introspectivo...                 ");
                                        mvprintw(8, 7, "A essa altura, a cobrinha do celular parece              ");
                                        mvprintw(9, 7, "a oitava maravilha do mundo. APERTA \"R\" POR FAVOR!       ");
                                    }
                                    else if (cont > 45000 && cont <= 60000) 
                                    { 
                                        mvprintw(7, 7, "Garoto- Se eu nao passar nessa prova amanha...           ");
                                        mvprintw(8, 7, "A culpa vai ser inteiramente sua e desse loop...         ");
                                        mvprintw(9, 7, "Aperta 'P' e finge que a gente leu tudo! Vai!            ");
                                    }
                                }
                                if (cont > 60000 && cont <= 75000)
                                { 
                                    mvprintw(7, 7, "Garoto- ...                                              "); 
                                    mvprintw(8, 7, "                                                         ");
                                    mvprintw(9, 7, "                                                         "); 
                                }
                                else if (cont > 75000) 
                                { 
                                    mvprintw(7, 7, "Garoto- FINALMENTE!!!                                    ");
                                    refresh(); napms(1500); estudo++; save.atividade_sono++; break; 
                                }
                                refresh(); napms(100); cont += 50;
                            }
                            mvprintw(5, 10, "                                                         ");
                            mvprintw(6, 10, "                                                         ");
                            mvprintw(7, 10, "                                                         ");
                            mvprintw(save.y-2, save.x-8, "              ");
                            refresh();
                        }
                    }

                    // ===== FRAME RATE =====
                    refresh();
                    clock_t frame_end = clock();
                    double elapsed_ms = (double)(frame_end - frame_start) * 1000.0 / CLOCKS_PER_SEC;
                    int sleep_ms = (int)(TARGET_FRAME_MS - elapsed_ms);
                    if (sleep_ms > 0) napms(sleep_ms);

                    nodelay(stdscr, TRUE);
                    if (save.atividade_sono > 5) { iniciar = 0; voltar_inicio = 0; break; }
                    if (dormindo == 1) { iniciar = 0; dormindo = 0; voltar_inicio = 0; break; }
                    if (tecla == 'q') { voltar_inicio = 1; break; }
                }
                if (voltar_inicio == 1) break;
                if (save.depoisprova == 0)
                {
                    save.estagio++;
                    strcpy(save.momento, "Prova");
                    save.celularpickup = 0; save.livropickup = 0; save.revistapickup = 0;
                    save.x = COLS/2; save.y = LINES/2;
                    if (save.atividade_sono > 5 && estudo >= 3) { cair_no_sono(); dialogoprovacs(); prova_cansado_simples(&save, &acertos); }
                    if (save.atividade_sono <= 5 && estudo >= 3) { dormir(); dialogoprovas(); prova_simples(&save, &acertos); }
                    if (save.atividade_sono > 5 && estudo < 3) { cair_no_sono(); dialogoprovacc(); prova_cansado_complexa(&save, &acertos); }
                    if (save.atividade_sono <= 5 && estudo < 3) { dormir(); dialogoprovac(); prova_complexa(&save, &acertos); }
                    save.depoisprova = 1;
                    dialogodepoisprova(&acertos, &maexinga, &epilepsia);
                }
                else break;
            }
            if (voltar_inicio == 1) break;
            if (acertos < 5 && save.depoisprova == 1) save.depoisprova = 1;
            else { save.estagio++; strcpy(save.momento, "Fim"); }
            if (dialogofinal(&finais_alcancados, &acertos))
            {
                save.atividade_sono = 0; save.celularpickup = 0; save.livropickup = 0;
                save.revistapickup = 0; save.maepistola = 0; save.maepistoladef = 0;
                save.janelaaberta = 0; save.depoisprova = 0;
                save.x = 22 + Xall; save.y = 10 + Yall; save.celularpos = 2;
                save.revistapickup = 0; save.estagio = 0;
                strcpy(save.momento, "Dialogo com a mae ");
                strcpy(save.imagem[0], "      \\/    ");
                strcpy(save.imagem[1], "     (00)   ");
                strcpy(save.imagem[2], "      ||    ");
                strcpy(save.imagem[3], "            ");
                strcpy(save.imagem[4], "            ");
                strcpy(save.imagem[5], "            ");
                save.quest = 7;
            }
            
        }
    }
    demo();
    napms(3000);
    endwin();
    return 0;
}




































