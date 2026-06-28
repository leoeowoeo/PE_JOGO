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

// ==================== PROTÓTIPOS ====================
void inicializar_cores(int cor, int interage, int selecaocor, int *par);
void desenhar_cama(int Xall, int Yall, int cor, int interagirCam, int par);
void desenhar_estante(int Xall, int Yall, int cor, int interagirEst, int par, SAVE *save, int celularX, int celularY);
void desenhar_mesa(int Xall, int Yall, int cor);
void desenhar_armario(int Xall, int Yall, int cor, int armarioaberto, int interagirArm, int par);
void desenhar_espelho(int Xall, int Yall, int cor, int par);
void desenhar_janela(int Xall, int Yall, int cor, int janelaaberta, int interagirJan, int par,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check);
void desenhar_porta(int Xall, int Yall, int cor, int depoisprova, int maepistoladef, int maexinga, int acertos);
void desenhar_lixo(int Xall, int Yall, int cor);
void desenhar_tapete(int Xall, int Yall, int cor);
void desenhar_rodape(int Xall, int Yall, int cor);
void desenhar_gato(int Xall, int Yall, int armarioX, int armarioY, int vontadedepisca, int depoisprova);
void desenhar_celular_chao(int Xall, int Yall, int cor, SAVE *save, int celularX, int celularY, int interagirCel, int par);
void desenhar_chuva(int Xall, int Yall, int cor, int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check);
void desenhar_jogador(SAVE *save, int vira, int passo, int pisca, int cor, int selecao_face, int selecao_olhos, int selecao_pernas);
void desenhar_hud(int ybarra, int xbarra, int cor, SAVE *save, int jogarcelular5, int encararespelho, int dormircama, int jogartodosjogos, int ler1jogar3, int ler3jogatodos, int ler3dormir, char *quests[]);
void movimentar_jogador(int tecla, int *xf, int *yf, int *passo, int *lado, int *vira, int Xall, int Yall);
void processar_colisoes(int *xf, int *yf, SAVE *save, int camaX, int camaY, int estanteX, int estanteY, int armarioX, int armarioY, int mesaX, int mesaY, int lixoX, int lixoY);
void processar_interacoes(SAVE *save, int tecla, int Xall, int Yall, int espelhox, int espelhoy, int camaX, int camaY, int armarioX, int armarioY, int janelaX, int janelaY, int celularX, int celularY, int *espelho, int *dormindo, int *armarioaberto, int *interagirCam, int *interagirArm, int *interagirJan, int *interagirCel, int *interagirEst, int *marcar, int *jogarcelular5, int cor, int *revista_linha, int *revista_coluna, int *livro1, int *livro2, int *livro3, int *abrindolivro, int *estudo, int *estudando, int *acertos, int vira, int estanteX, int estanteY);
void espelhaogaroto(SAVE save, int espelhox, int espelhoy, int pisca, char **faces, char **olhos, char **pernas,int selecao_face,int selecao_pernas, int selecao_olhos,int passo,int vira);
void printar_celular(SAVE save,int celularX,int celularY);
void printar_livro(int livropickup, int *abrindolivro, int livro1, int livro2, int livro3, int livroY, int livroX );
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
    int selecaocor = 4, tecla_selecao, interage = 0, cor = 1, par = 0;
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
    char *olhos[10] = {"##", "@@", "**", "$$", "vv", "><", "XX", "OO", "00", "oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >", "d  b"};
    char *pernas[4] = {"/|", "|\\", "<v", "v>"};
    char *revista[9] = {"1", "2", "3", "4", "5", "6"};
    int selecao_olhos = 9, selecao_face = 0, selecao_pernas = 0;
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
            inicio(&selecao_olhos, &selecao_face, &selecao_pernas, &cor, &interage, &selecaocor, &iniciar, &epilepsia, &save, &save.iniciado, &jogar, estanoquarto);
            noraw();
            cbreak();
        }
        if (epilepsia == 1) mvprintw(LINES-5, 5, "MODO DE EPILEPSIA");

        erase();
        refresh();
        inicializar_cores(cor, interage, selecaocor, &par);
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
            save.quest =1;/* dialogoMae(&maexinga);*/
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
                    if (tecla == 'm') menusave(&cor, &save, &jogar, &selecao_olhos, &selecao_face, &selecao_pernas, &save.iniciado, estanoquarto);
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
                    desenhar_cama(Xall, Yall, cor, interagirCam, par);
                    desenhar_estante(Xall, Yall, cor, interagirEst, par, &save, celularX, celularY);
                    desenhar_mesa(Xall, Yall, cor);
                    desenhar_armario(Xall, Yall, cor, armarioaberto, interagirArm, par);
                    espelhaogaroto(save, espelhox, espelhoy, pisca, faces, olhos, pernas,selecao_face,selecao_pernas,selecao_olhos,passo,vira);
                    desenhar_espelho(Xall, Yall, cor, par);
                    desenhar_janela(Xall, Yall, cor, save.janelaaberta, interagirJan, par,chuvax, chuvay, &pos, &pos2, &pos3,check);
                    desenhar_rodape(Xall, Yall, cor);
                    desenhar_porta(Xall, Yall, cor, save.depoisprova, save.maepistoladef, maexinga, acertos);
                    desenhar_lixo(Xall, Yall, cor);
                    desenhar_tapete(Xall, Yall, cor);
                    desenhar_gato(Xall, Yall, armarioX, armarioY, vontadedepisca, save.depoisprova);
                    desenhar_celular_chao(Xall, Yall, cor, &save, celularX, celularY, interagirCel, par);
                    desenhar_jogador(&save, vira, passo, pisca, cor, selecao_face, selecao_olhos, selecao_pernas);
                    desenhar_hud(ybarra, xbarra, cor, &save, jogarcelular5, encararespelho, dormircama, jogartodosjogos, ler1jogar3, ler3jogatodos, ler3dormir, quests);
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
                    processar_interacoes(&save, tecla, Xall, Yall, espelhox, espelhoy, camaX, camaY, armarioX, armarioY, janelaX, janelaY, celularX, celularY, &espelho, &dormindo, &armarioaberto, &interagirCam, &interagirArm, &interagirJan, &interagirCel, &interagirEst, &marcar, &jogarcelular5, cor, &revista_linha, &revista_coluna, &livro1, &livro2, &livro3, &abrindolivro, &estudo, &estudando, &acertos, vira, estanteX, estanteY);

                    // ===== ESPELHO MINIGAME =====
                    if (espelho == 1)
                    {
                        nodelay(stdscr, FALSE);
                        pedrapapeltesoura(&cor, &encararespelho);
                        espelho = 0;
                        nodelay(stdscr, TRUE);
                        erase();
                        save.atividade_sono++;
                    }

                    // ===== REFLEXO NO ESPELHO =====
                    
                    

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
                                if (marcar == 0) { cobra(&cor, &jogarcelular5); save.atividade_sono++; marcar = 0; }
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
                                    if (cont > 5000 && cont <= 15000) { mvprintw(7, 7, "Garoto- isso vai demorar...                              "); mvprintw(9, 7, "eu poderia estar jogando agora                           "); }
                                    else if (cont > 15000 && cont <= 30000) { mvprintw(7, 7, "Garoto- quantas paginas tem isso aqui?                   "); mvprintw(8, 7, "nossa, ainda estou em um 1/3...                          "); mvprintw(9, 7, "Eu poderia jogar agora...                                "); }
                                    else if (cont > 30000 && cont <= 45000) { mvprintw(7, 7, "Garoto- Aperta \"P\", por favor, isso aqui...            "); mvprintw(8, 7, "isso aqui e um saco, silogismo... to so na metade        "); mvprintw(9, 7, "Eu nao quero fazer diagrama de Venn...                   "); refresh(); }
                                    else if (cont > 45000 && cont <= 60000) { mvprintw(7, 7, "Garoto- Nao vou falar mais nada nao, seu...              "); mvprintw(8, 7, "SEU BOBOCA!!! EH, BOBOCA, voce nao me deixa              "); mvprintw(9, 7, "saiiiiir, eu quero jogar =(, nao ver equacoes            "); }
                                }
                                else if (livro2)
                                {
                                    if (cont > 5000 && cont <= 15000) { mvprintw(7, 7, "Garoto- Geometria? Serio mesmo?                          "); mvprintw(8, 7, "Pra que eu quero saber o tamanho de um poligono?         "); }
                                    else if (cont > 15000 && cont <= 30000) { mvprintw(7, 7, "Garoto- 'Calcule a area da figura hachurada...'          "); mvprintw(8, 7, "Isso aqui parece um labirinto bizarro!                   "); mvprintw(9, 7, "Minha cabeca ta comecando a doer...                      "); }
                                    else if (cont > 30000 && cont <= 45000) { mvprintw(7, 7, "Garoto- Ei, voce ai controlando o teclado...              "); mvprintw(8, 7, "Se eu ver mais um triangulo retangulo na minha frente    "); mvprintw(9, 7, "eu vou quebrar esse terminal, juro por Deus!             "); }
                                    else if (cont > 45000 && cont <= 60000) { mvprintw(7, 7, "Garoto- Cateto oposto, hipotenusa, blablabla...          "); mvprintw(8, 7, "Corta essa! Me deixa voltar pro celular!                 "); mvprintw(9, 7, "Voce gosta de me ver sofrer, e isso?                     "); }
                                }
                                else if (livro3)
                                {
                                    if (cont > 5000 && cont <= 15000) { mvprintw(7, 7, "Garoto- Ah nao, algebra linear...                        "); mvprintw(8, 7, "Matrizes 5x5 cheias de zeros e uns. Que tedio.           "); }
                                    else if (cont > 15000 && cont <= 30000) { mvprintw(7, 7, "Garoto- 'Um algoritmo deterministico...'                 "); mvprintw(8, 7, "Eu sou um personagem de um jogo em C, sabia?             "); mvprintw(9, 7, "Estudar programacao dentro de um programa e meta demais. "); }
                                    else if (cont > 30000 && cont <= 45000) { mvprintw(7, 7, "Garoto- Querido jogador introspectivo...                 "); mvprintw(8, 7, "A essa altura, a cobrinha do celular parece              "); mvprintw(9, 7, "a oitava maravilha do mundo moderno. Larga o 'R'!        "); }
                                    else if (cont > 45000 && cont <= 60000) { mvprintw(7, 7, "Garoto- Se eu nao passar nessa prova amanha...           "); mvprintw(8, 7, "A culpa vai ser inteiramente sua e desse loop...         "); mvprintw(9, 7, "Aperta 'P' e finge que a gente leu tudo! Vai!            "); }
                                }
                                if (cont > 60000 && cont <= 75000) { mvprintw(7, 7, "Garoto- ...                                              "); mvprintw(8, 7, "                                                         "); mvprintw(9, 7, "                                                         "); }
                                else if (cont > 75000) { mvprintw(7, 7, "Garoto- FINALMENTE!!!                                    "); refresh(); napms(1500); estudo++; save.atividade_sono++; break; }
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
                    if (save.atividade_sono > 5 && estudo >= 3) { cair_no_sono(); dialogoprovacs(); prova_cansado_simples(&cor, &acertos); }
                    if (save.atividade_sono <= 5 && estudo >= 3) { dormir(); dialogoprovas(); prova_simples(&cor, &acertos); }
                    if (save.atividade_sono > 5 && estudo < 3) { cair_no_sono(); dialogoprovacc(); prova_cansado_complexa(&cor, &acertos); }
                    if (save.atividade_sono <= 5 && estudo < 3) { dormir(); dialogoprovac(); prova_complexa(&cor, &acertos); }
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
            
            /*if (save.x >= espelhox - 6 && save.x <= espelhox + 20 && save.y < espelhoy + 13 && vira % 2 == 1)
                    {
                        int reflexx = save.x;
                        int distancia = save.y - espelhoy;
                        int reflexy = (espelhoy + 4) - (distancia / 3);
                        if (reflexy < espelhoy + 1) reflexy = espelhoy + 1;
                        if (reflexy > espelhoy + 4) reflexy = espelhoy + 4;
                        if (reflexx < espelhox) reflexx = espelhox;
                        if (reflexx > espelhox + 9) reflexx = espelhox + 9;
                        if (vira % 2 == 1 && save.x >= espelhox && save.x <= espelhox + 7)
                        {
                            int borda1 = espelhox, borda2 = espelhox + 10;
                            if (reflexx >= borda1 && reflexx <= borda2)
                            {
                                if (save.celularpickup == 1)
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx-2, "[]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx-2, "[]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                else if (save.revistapickup == 1 || save.livropickup == 1)
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx-3, "[I]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx-3, "[I]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                else
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx, "%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx, "%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                if (passo % 2 == 0) mvprintw(reflexy+1, reflexx+1, "%s", pernas[selecao_pernas]);
                                else mvprintw(reflexy+1, reflexx+1, "%s", pernas[selecao_pernas+1]);
                            }
                        }
                    }*/
        }
    }
    demo();
    napms(3000);
    endwin();
    return 0;
}

// ==================== FUNÇÕES ====================
void espelhaogaroto(SAVE save,int espelhox, int espelhoy, int pisca, char **faces, char **olhos, char **pernas,int selecao_face,int selecao_pernas, int selecao_olhos,int passo,int vira)
{
    if (save.x >= espelhox - 6 && save.x <= espelhox + 20 && save.y < espelhoy + 13 && vira % 2 == 1)
                    {
                        int reflexx = save.x;
                        int distancia = save.y - espelhoy;
                        int reflexy = (espelhoy + 4) - (distancia / 3);
                        if (reflexy < espelhoy + 1) reflexy = espelhoy + 1;
                        if (reflexy > espelhoy + 4) reflexy = espelhoy + 4;
                        if (reflexx < espelhox) reflexx = espelhox;
                        if (reflexx > espelhox + 9) reflexx = espelhox + 9;
                        if (vira % 2 == 1 && save.x >= espelhox && save.x <= espelhox + 7)
                        {
                            int borda1 = espelhox, borda2 = espelhox + 10;
                            if (reflexx >= borda1 && reflexx <= borda2)
                            {
                                if (save.celularpickup == 1)
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx-2, "[]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx-2, "[]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                else if (save.revistapickup == 1 || save.livropickup == 1)
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx-3, "[I]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx-3, "[I]%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                else
                                {
                                    if (pisca % 2 == 1) { mvprintw(reflexy, reflexx, "%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "%s", olhos[selecao_olhos]); }
                                    else { mvprintw(reflexy, reflexx, "%s", faces[selecao_face]); mvprintw(reflexy, reflexx+1, "--"); }
                                }
                                if (passo % 2 == 0) mvprintw(reflexy+1, reflexx+1, "%s", pernas[selecao_pernas]);
                                else mvprintw(reflexy+1, reflexx+1, "%s", pernas[selecao_pernas+1]);
                            }
                        }
                    }
}

void inicializar_cores(int cor, int interage, int selecaocor, int *par)
{
    if (cor == 1)
    {
        start_color();
        use_default_colors();
        init_color(COR_MARROM, 550, 270, 70);
        init_color(COR_JANELA, 400, 450, 500);
        init_color(COR_FUNDO_CHUVA, 30, 40, 120);
        init_color(COR_CHUVA, 400, 700, 1000);
        init_color(COR_CHAO, 760, 600, 410);
        init_color(COR_ESTANTE, 300, 150, 50);
        init_color(COR_TAPETE_OPCAO1, 500, 0, 100);
        init_color(COR_RODAPE, 750, 750, 750);
        init_color(COR_BANCO, 600, 400, 200);
        init_color(COR_ESPELHO, 700, 850, 900);
        init_color(COR_CIANO, 0, 1000, 1000);
        init_color(COR_CINZAESCURO, 900, 900, 900);
        init_pair(1, COR_RODAPE, -1);
        init_pair(2, COR_JANELA, -1);
        init_pair(4, COLOR_RED, -1);
        init_pair(5, COR_CHUVA, -1);
        init_pair(6, COR_MARROM, -1);
        init_pair(7, COR_ESTANTE, -1);
        init_pair(8, COR_TAPETE_OPCAO1, -1);
        init_pair(9, COR_RODAPE, -1);
        init_pair(10, COLOR_WHITE, COLOR_WHITE);
        init_pair(11, COR_ESPELHO, -1);
        init_pair(15, COR_CINZAESCURO, -1);
        init_pair(16, COLOR_WHITE, COLOR_BLUE);
        init_pair(17, COLOR_WHITE, COLOR_GREEN);
        init_pair(18, COLOR_WHITE, COLOR_RED);
        init_pair(19, COLOR_WHITE, COLOR_MAGENTA);
        init_pair(20, COLOR_WHITE, COLOR_YELLOW);
        if (interage == 1)
        {
            init_pair(12, COLOR_YELLOW, -1);
            init_pair(13, COLOR_WHITE, -1);
            init_pair(14, COR_CIANO, -1);
            if (selecaocor == 0) *par = 12;
            else if (selecaocor == 1) *par = 13;
            else if (selecaocor == 2) *par = 14;
        }
    }
}

void desenhar_cama(int Xall, int Yall, int cor, int interagirCam, int par)
{
    int camaY = 8 + Yall, camaX = 80 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(1));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(4));
    if (interagirCam == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(camaY, camaX, "._______.");
    mvprintw(camaY+1, camaX, "|~~     |");
    mvprintw(camaY+2, camaX, "|       |");
    mvprintw(camaY+3, camaX, "|    ~~ |");
    mvprintw(camaY+4, camaX, "|_______|");
    wattroff(stdscr, COLOR_PAIR(4));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (interagirCam == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(camaY+5, camaX, "||     ||");
    wattroff(stdscr, COLOR_PAIR(6));
    mvprintw(camaY+1, camaX+2, "(   )");
    wattroff(stdscr, COLOR_PAIR(12));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(7));
}

void desenhar_estante(int Xall, int Yall, int cor, int interagirEst, int par, SAVE *save, int celularX, int celularY)
{
    int estanteY = 5 + Yall, estanteX = 34 + Xall;
    if (interagirEst == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
    mvprintw(estanteY, estanteX, " ____________ ");
    mvprintw(estanteY+1, estanteX, "[____!!__||__]");
    mvprintw(estanteY+2, estanteX, "[||____!!_!!_]");
    mvprintw(estanteY+3, estanteX, "[!!_!!__||_!!]");
    mvprintw(estanteY+4, estanteX, "[__!!_!!___!!]");
    mvprintw(estanteY+5, estanteX, "[_||!!___!!||]");
    mvprintw(estanteY+6, estanteX, "[_!!_!!______]");
    wattroff(stdscr, COLOR_PAIR(7));
    wattroff(stdscr, COLOR_PAIR(par));
    gravar_imagem_do_momento(save->x, save->y, save->imagem);
    printar_imagem_do_momento(celularX+18, celularY, save->imagem);
}

void desenhar_mesa(int Xall, int Yall, int cor)
{
    int mesaY = 8 + Yall, mesaX = 74 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    mvprintw(mesaY, mesaX, " ____");
    mvprintw(mesaY+1, mesaX, "|    |");
    mvprintw(mesaY+2, mesaX, "|____|");
    mvprintw(mesaY+3, mesaX, " T  T ");
    wattroff(stdscr, COLOR_PAIR(6));
}

void desenhar_armario(int Xall, int Yall, int cor, int armarioaberto, int interagirArm, int par)
{
    int armarioY = 14 + Yall, armarioX = 19 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
    if (armarioaberto == 1)
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(armarioY+1, armarioX, " |\"\"\"\"|/|");
        mvprintw(armarioY+2, armarioX, " |    | |");
        mvprintw(armarioY+3, armarioX, " |    | |  ");
        mvprintw(armarioY+4, armarioX, " |    |/ ");
        mvprintw(armarioY+5, armarioX, " |\"\"\"\"|  ");
        mvprintw(armarioY+6, armarioX, " |    |\\");
        mvprintw(armarioY+7, armarioX, " |    | |");
        mvprintw(armarioY+8, armarioX, " |    |[|");
        mvprintw(armarioY+9, armarioX, " |____|\\|");
    }
    else
    {
        if (interagirArm == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(armarioY+1, armarioX, " |\"\"\"\"|");
        mvprintw(armarioY+2, armarioX, " |    |");
        mvprintw(armarioY+3, armarioX, " |    |");
        mvprintw(armarioY+4, armarioX, " |    |]");
        mvprintw(armarioY+5, armarioX, " |\"\"\"\"|");
        mvprintw(armarioY+6, armarioX, " |    |]");
        mvprintw(armarioY+7, armarioX, " |    |");
        mvprintw(armarioY+8, armarioX, " |    |");
        mvprintw(armarioY+9, armarioX, " |____|");
    }
    wattroff(stdscr, COLOR_PAIR(par));
    wattroff(stdscr, COLOR_PAIR(6));
}

void desenhar_espelho(int Xall, int Yall, int cor, int par)
{
    int espelhoy = 3 + Yall, espelhox = 63 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(11));
    if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
    mvprintw(espelhoy, espelhox, " ,_,_,_,_,");
    mvprintw(espelhoy+1, espelhox, " {|");
    mvprintw(espelhoy+2, espelhox, " {|");
    mvprintw(espelhoy+3, espelhox, " {|");
    mvprintw(espelhoy+4, espelhox, " {|");
    mvprintw(espelhoy+1, espelhox+8, "|}     ");
    mvprintw(espelhoy+2, espelhox+8, "|}     ");
    mvprintw(espelhoy+3, espelhox+8, "|}     ");
    mvprintw(espelhoy+4, espelhox+8, "|}    ");
    mvprintw(espelhoy+5, espelhox, " \"=\"=\"=\"=\" ");
    wattroff(stdscr, COLOR_PAIR(par));
    wattroff(stdscr, COLOR_PAIR(11));
}

void desenhar_janela(int Xall, int Yall, int cor, int janelaaberta, int interagirJan, int par,int chuvax, int chuvay, int *pos, int *pos2, int *pos3, int check)
{
    int janelaY = 4 + Yall, janelaX = 50 + Xall;
    if (janelaaberta == 0)
    {
        
        if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
        if (interagirJan == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(janelaY, janelaX, "|\\ _______ /| ");
        mvprintw(janelaY+1, janelaX, "| |       | | ");
        mvprintw(janelaY+2, janelaX, "| |       | | ");
        mvprintw(janelaY+3, janelaX, " \\|       |/  ");
        mvprintw(janelaY+4, janelaX, "  ---------   ");
        wattroff(stdscr, COLOR_PAIR(2));
        wattroff(stdscr, COLOR_PAIR(par));
        desenhar_chuva(Xall, Yall, cor, chuvax, chuvay, pos, pos2, pos3, check);
    }
    else
    {
        if (cor == 1) wattron(stdscr, COLOR_PAIR(2));
        if (interagirJan == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
        mvprintw(janelaY, janelaX, "   _______    ");
        mvprintw(janelaY+1, janelaX, "  |   |   |   ");
        mvprintw(janelaY+2, janelaX, "  |   |   |   ");
        mvprintw(janelaY+3, janelaX, "  |   |   |   ");
        mvprintw(janelaY+4, janelaX, "  ---------");
        wattroff(stdscr, COLOR_PAIR(par));
        wattroff(stdscr, COLOR_PAIR(2));
    }
}

void desenhar_porta(int Xall, int Yall, int cor, int depoisprova, int maepistoladef, int maexinga, int acertos)
{
    int portaY = 3 + Yall, portaX = 11 + Xall;
    if (depoisprova == 0)
    {
        if (maepistoladef == 1)
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY+1, portaX+11, "_______");
            mvprintw(portaY+2, portaX+11, "|     |");
            mvprintw(portaY+3, portaX+11, "|     |");
            mvprintw(portaY+4, portaX+11, "|*    |");
            mvprintw(portaY+5, portaX+11, "|     |");
            mvprintw(portaY+6, portaX+11, "I_____I");
            wattroff(stdscr, COLOR_PAIR(6));
        }
        else
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY, portaX+1,   "                   ");
            mvprintw(portaY+1, portaX+1, "          _______  ");
            mvprintw(portaY+2, portaX+1, "          |     |\\");
            mvprintw(portaY+3, portaX+1, "          |     | |");
            mvprintw(portaY+4, portaX+1, "          |(00) | |");
            mvprintw(portaY+5, portaX+1, "          | ||  |*|");
            mvprintw(portaY+6, portaX+11,          "I_____I |");
            mvprintw(portaY+7, portaX+18,                "\\|");
            wattroff(stdscr, COLOR_PAIR(6));
            if (maexinga)
            {
                mvprintw(portaY, portaX+1, " ________");
                mvprintw(portaY+1, portaX+1, "|00&!@&@C|");
                mvprintw(portaY+2, portaX+1, "|________|");
                mvprintw(portaY+3, portaX+10, "\\  \\/");
                mvprintw(portaY+4, portaX+12, "(00) ");
                mvprintw(portaY+5, portaX+13, "||  ");
            }
            else
            {
                mvprintw(portaY, portaX-1, " __________");
                mvprintw(portaY+1, portaX-1, "|vai dormir|");
                mvprintw(portaY+2, portaX-1, "|__________|");
                mvprintw(portaY+3, portaX+10, "\\| \\/");
                mvprintw(portaY+4, portaX+12, "(00) ");
                mvprintw(portaY+5, portaX+13, "||  ");
            }
        }
    }
    else if (acertos < 5 && depoisprova == 1)
    {
        if (maepistoladef == 1)
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY+1, portaX+11, "_______");
            mvprintw(portaY+2, portaX+11, "|     |");
            mvprintw(portaY+3, portaX+11, "|     |");
            mvprintw(portaY+4, portaX+11, "|*    |");
            mvprintw(portaY+5, portaX+11, "|     |");
            mvprintw(portaY+6, portaX+11, "I_____I");
            wattroff(stdscr, COLOR_PAIR(6));
        }
        else
        {
            if (cor == 1) wattron(stdscr, COLOR_PAIR(6));
            mvprintw(portaY, portaX+1, "                   ");
            mvprintw(portaY+1, portaX+1, "          _______  ");
            mvprintw(portaY+2, portaX+1, "          |     |\\");
            mvprintw(portaY+3, portaX+1, "          |     | |");
            mvprintw(portaY+4, portaX+1, "          |(00) | |");
            mvprintw(portaY+5, portaX+1, "          | ||  |*|");
            mvprintw(portaY+6, portaX+11,          "I_____I |");
            mvprintw(portaY+7, portaX+18,                 "\\|");
            wattroff(stdscr, COLOR_PAIR(6));
            if (acertos < 2)
            {
                if (maexinga)
                {
                    mvprintw(portaY, portaX+1, " ________________");
                    mvprintw(portaY+1, portaX-3, "|SEU INCOMPETENTE|");
                    mvprintw(portaY+2, portaX-3, "|________________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                }
                else
                {
                    mvprintw(portaY, portaX+1, " ________");
                    mvprintw(portaY+1, portaX+1, "|00&!@&@C|");
                    mvprintw(portaY+2, portaX+1, "|________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                }
            }
            else
            {
                mvprintw(portaY, portaX-1, " ___________");
                mvprintw(portaY+1, portaX-1, "|vai estudar|");
                mvprintw(portaY+2, portaX-1, "|___________|");
                mvprintw(portaY+3, portaX+10, "\\  \\/");
                mvprintw(portaY+4, portaX+12, "(00) ");
                mvprintw(portaY+5, portaX+13, "||  ");
            }
        }
    }
}

void desenhar_lixo(int Xall, int Yall, int cor)
{
    int lixoY = 27 + Yall, lixoX = 84 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(15));
    mvprintw(lixoY+1, lixoX, "|###|");
    mvprintw(lixoY+2, lixoX, " \\#/");
    if (cor == 1) wattroff(stdscr, COLOR_PAIR(15));
}

void desenhar_tapete(int Xall, int Yall, int cor)
{
    int tapetey = 18 + Yall, tapetex = 45 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(8));
    mvprintw(tapetey, tapetex, "  I~~~~~~~~~~~~~I ");
    mvprintw(tapetey+1, tapetex, "  |    ~~~      | ");
    mvprintw(tapetey+2, tapetex, "  |       ~~~~  | ");
    mvprintw(tapetey+3, tapetex, "  |  ~~~        | ");
    mvprintw(tapetey+4, tapetex, "  |      ~~~~   | ");
    mvprintw(tapetey+5, tapetex, "  I~~~~~~~~~~~~~I ");
    wattroff(stdscr, COLOR_PAIR(8));
}

void desenhar_rodape(int Xall, int Yall, int cor)
{
    int rodapey = 9 + Yall, rodapex = 21 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(9));
    mvprintw(rodapey, rodapex, "_____________");
    mvprintw(rodapey+21, rodapex, "_____________________________________________________________________");
    for (; rodapex < 63 + Xall; rodapex++)
    {
        mvprintw(rodapey, rodapex+27, "_");
        if (rodapex == 46 + Xall) rodapex = 61 + Xall;
    }
    wattroff(stdscr, COLOR_PAIR(9));

    int rodape2y = 10 + Yall, rodape2x = 20 + Xall;
    if (cor == 1) wattron(stdscr, COLOR_PAIR(9));
    for (; rodape2y < 31 + Yall; rodape2y++)
    {
        if (rodape2y < 31 + Yall) mvprintw(rodape2y, rodape2x, "|");
        mvprintw(rodape2y, rodape2x+70, "|");
    }
    wattroff(stdscr, COLOR_PAIR(9));
}
void printar_celular(SAVE save,int celularX,int celularY)
{   

    if(save.celularpickup==1&&save.depoisprova==0)
    {
        
                        mvprintw(celularY,      celularX+18, "  _______________ ");
                        mvprintw(celularY+1,    celularX+18, " | _____________ |");        
                        mvprintw(celularY+2,    celularX+18, " ||      O      ||");
                        mvprintw(celularY+3,    celularX+18, " ||             ||");
                        mvprintw(celularY+4,    celularX+18, " ||             ||");
                        mvprintw(celularY+5,    celularX+18, " ||             ||");
                        mvprintw(celularY+6,    celularX+18, " ||             ||");
                        mvprintw(celularY+7,    celularX+18, " ||             ||");
                        mvprintw(celularY+8,    celularX+18, " ||             ||");
                        mvprintw(celularY+9,    celularX+18, " ||             ||");
                        mvprintw(celularY+10,   celularX+18, " ||_____________||");
                        mvprintw(celularY+11,   celularX+18, " | ===  [ ]  <-- |");
                        mvprintw(celularY+12,   celularX+18, " \\===============/");
    }
}
void desenhar_gato(int Xall, int Yall, int armarioX, int armarioY, int vontadedepisca, int depoisprova)
{
    int gatoy = armarioY + 13, gatox = armarioX + 10;
    if (depoisprova == 0)
    {
        mvprintw(gatoy, gatox, "(\\   /)");
        mvprintw(gatoy+1, gatox, "(=*.*=)");
        mvprintw(gatoy+2, gatox, " (\") (\")_/");
        if (vontadedepisca >= 300 && vontadedepisca <= 390)
        {
            static int meow = 0;
            meow++;
            if (meow >= 3 && meow <= 4) { mvprintw(gatoy-1, gatox+3, "MEOW"); meow = 0; }
        }
    }
}

void desenhar_celular_chao(int Xall, int Yall, int cor, SAVE *save, int celularX, int celularY, int interagirCel, int par)
{
    if (save->celularpickup == 0)
    {
        if (save->depoisprova == 0)
        {
            if (interagirCel == 1 && cor == 1) wattron(stdscr, COLOR_PAIR(par));
            if (save->celularpos == 1) mvprintw(celularY, celularX, "[]");
            else if (save->celularpos == 2) mvprintw(celularY+1, celularX, "[]");
            else if (save->celularpos == 3) mvprintw(celularY+1, celularX-1, "[]");
            wattroff(stdscr, COLOR_PAIR(par));
        }
    }
}

void desenhar_chuva(int Xall, int Yall, int cor, int chuvax, int chuvay, int *pos, int *pos2, int *pos3,int check)
{
    
        if (cor == 1) wattron(stdscr, COLOR_PAIR(5));
        mvprintw(chuvay+*pos, chuvax, ",;';,,;");
        mvprintw(chuvay+*pos2, chuvax, " ';.;.'");
        mvprintw(chuvay+*pos3, chuvax, ".,.,'' ");
        wattroff(stdscr, COLOR_PAIR(5));
     if(check%5==0)  
            {(*pos)++; (*pos2)++; (*pos3)++;}
        if((*pos)>2) {*pos=0;} 
        if((*pos2)>2){*pos2=0;} 
        if((*pos3)>2){*pos3=0;}
            
}

void desenhar_jogador(SAVE *save, int vira, int passo, int pisca, int cor, int selecao_face, int selecao_olhos, int selecao_pernas)
{
    char *olhos[10] = {"##", "@@", "**", "$$", "vv", "><", "XX", "OO", "00", "oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >", "d  b"};
    char *pernas[4] = {"/|", "|\\", "<v", "v>"};

    if (save->celularpickup == 0)
    {
        if (vira % 2 == 0)
        {
            if (pisca % 2 == 1) { mvprintw(save->y, save->x, "%s", faces[selecao_face]); mvprintw(save->y, save->x+1, "%s", olhos[selecao_olhos]); }
            else { mvprintw(save->y, save->x, "%s", faces[selecao_face]); mvprintw(save->y, save->x+1, "--"); }
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
        else if (vira % 2 == 1)
        {
            mvprintw(save->y, save->x, "%s", faces[selecao_face]);
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
    }
    if (save->celularpickup == 1)
    {
        if (vira % 2 == 0)
        {
            if (pisca % 2 == 1) { mvprintw(save->y, save->x, "%s[]", faces[selecao_face]); mvprintw(save->y, save->x+1, "%s", olhos[selecao_olhos]); }
            else { mvprintw(save->y, save->x, "%s[]", faces[selecao_face]); mvprintw(save->y, save->x+1, "--"); }
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
        else if (vira % 2 == 1)
        {
            mvprintw(save->y, save->x-2, "[]%s", faces[selecao_face]);
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
    }
    if (save->revistapickup == 1 || save->livropickup == 1)
    {
        if (vira % 2 == 0)
        {
            if (pisca % 2 == 1) { mvprintw(save->y, save->x, "%s[I]", faces[selecao_face]); mvprintw(save->y, save->x+1, "%s", olhos[selecao_olhos]); }
            else { mvprintw(save->y, save->x, "%s[I]", faces[selecao_face]); mvprintw(save->y, save->x+1, "--"); }
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
        else if (vira % 2 == 1)
        {
            mvprintw(save->y, save->x-3, "[I]%s", faces[selecao_face]);
            if (passo % 2 == 0) mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas]);
            else mvprintw(save->y+1, save->x+1, "%s", pernas[selecao_pernas+1]);
        }
    }
}

void desenhar_hud(int ybarra, int xbarra, int cor, SAVE *save, int jogarcelular5, int encararespelho, int dormircama, int jogartodosjogos, int ler1jogar3, int ler3jogatodos, int ler3dormir, char *quests[])
{
    wattroff(stdscr, COLOR_PAIR(9));
    mvprintw(ybarra-1, xbarra, "Cansaco.");
    mvprintw(ybarra, xbarra, "+-----------+");
    if (save->atividade_sono >= 1) mvprintw(ybarra+1, xbarra+1, "##");
    if (save->atividade_sono >= 2) mvprintw(ybarra+1, xbarra+3, "##");
    if (save->atividade_sono >= 3) mvprintw(ybarra+1, xbarra+5, "##");
    if (save->atividade_sono >= 4) { if (cor == 1) attron(COLOR_PAIR(4)); mvprintw(ybarra+1, xbarra+7, "##"); attroff(COLOR_PAIR(4)); }
    if (save->atividade_sono >= 5) { if (cor == 1) attron(COLOR_PAIR(4)); mvprintw(ybarra+1, xbarra+9, "##"); attroff(COLOR_PAIR(4)); }
    mvprintw(ybarra+2, xbarra, "+-----------+");
    mvprintw(ybarra+1, xbarra, "|");
    mvprintw(ybarra+1, xbarra+12, "|");
    if ((jogarcelular5 != 5 || encararespelho != 1 || dormircama != 1 || jogartodosjogos != 6 || ler1jogar3 != 4 || ler3jogatodos != 4 || ler3dormir != 3) && save->depoisprova == 0)
    {
        wattron(stdscr, A_BOLD);
        mvprintw(ybarra, xbarra+30, "Quest: %s", quests[save->quest]);
        wattroff(stdscr, A_BOLD);
    }
}

void movimentar_jogador(int tecla, int *xf, int *yf, int *passo, int *lado, int *vira, int Xall, int Yall)
{
    switch (tecla)
    {
        case 'a': (*xf)--; if (*xf < 20 + Xall) *xf = 20 + Xall; (*passo)++; *lado = 2; break;
        case 'd': (*xf)++; if (*xf > 87 + Xall) *xf = 87 + Xall; (*passo)++; *lado = 1; break;
        case 's': (*yf)++; if (*yf > 29 + Yall) *yf = 29 + Yall; (*passo)++; *vira = 2; break;
        case 'w': (*yf)--; if (*yf < 8 + Yall) *yf = 8 + Yall; (*passo)++; *vira = 1; break;
        default: break;
    }
}

void processar_colisoes(int *xf, int *yf, SAVE *save, int camaX, int camaY, int estanteX, int estanteY, int armarioX, int armarioY, int mesaX, int mesaY, int lixoX, int lixoY)
{
    for (int i = camaX - 2; i <= camaX + 7; i++)
        for (int j = camaY; j <= camaY + 3; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = camaX - 2; i <= camaX + 8; i++)
        for (int j = camaY; j <= camaY + 3; j++)
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
    for (int i = estanteX - 2; i <= estanteX + 13; i++)
        for (int j = estanteY; j <= estanteY + 4; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = armarioX - 2; i <= armarioX + 5; i++)
        for (int j = armarioY + 5; j <= armarioY + 7; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = mesaX - 1; i <= mesaX + 5; i++)
        for (int j = mesaY; j <= mesaY + 1; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
    for (int i = lixoX - 2; i <= lixoX + 3; i++)
        for (int j = lixoY + 1; j <= lixoY + 1; j++)
        {
            if (*xf == i && *yf == j && (*xf - save->x) != 0) *xf = save->x;
            else if (*xf == i && *yf == j && (*yf - save->y) != 0) *yf = save->y;
        }
}

void processar_interacoes(SAVE *save, int tecla, int Xall, int Yall, int espelhox, int espelhoy, int camaX, int camaY, int armarioX, int armarioY, int janelaX, int janelaY, int celularX, int celularY, int *espelho, int *dormindo, int *armarioaberto, int *interagirCam, int *interagirArm, int *interagirJan, int *interagirCel, int *interagirEst, int *marcar, int *jogarcelular5, int cor, int *revista_linha, int *revista_coluna, int *livro1, int *livro2, int *livro3, int *abrindolivro, int *estudo, int *estudando, int *acertos, int vira,int estanteX, int estanteY)
{
    // ESPELHO
    if (save->y > espelhoy && save->y < espelhoy + 8 && save->x > espelhox - 2 && save->x < espelhox + 9 && vira % 2 == 1)
    {
        wattron(stdscr, A_BOLD);
        mvprintw(Yall+33, Xall+27, "Encarar o espelho: E");
        wattroff(stdscr, A_BOLD);
        if (tecla == 'e' || tecla == 'E') *espelho = 1;
    }

    // CAMA
    if (save->y > camaY && save->y < camaY + 5 && save->x > camaX - 4 && save->x < camaX + 9)
    {
        *interagirCam = 1;
        mvprintw(camaY-2, camaX, "Dormir: F");
        if (tecla == 'f' || tecla == 'F') *dormindo = 1;
    }
    else *interagirCam = 0;

    // ARMARIO
    int pertodearmario = (save->x >= armarioX - 2 && save->x <= armarioX + 8) && (save->y >= armarioY + 2 && save->y <= armarioY + 9);
    if (pertodearmario)
    {
        if (*armarioaberto) { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+26, "Fechar armario: E"); wattroff(stdscr, A_BOLD); *interagirArm = 1; }
        else { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, "Abrir armario: E"); wattroff(stdscr, A_BOLD); *interagirArm = 1; }
        if (tecla == 'e' || tecla == 'E') *armarioaberto = !(*armarioaberto);
    }
    else *interagirArm = 0;

    // JANELA
    int pertoJanela = (save->x >= janelaX - 2 && save->x <= janelaX + 8) && (save->y >= janelaY - 1 && save->y <= janelaY + 5);
    if (pertoJanela)
    {
        if (save->janelaaberta) { *interagirJan = 1; wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, " Abrir janela: E"); wattroff(stdscr, A_BOLD); }
        else { *interagirJan = 1; wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, " Fechar janela: E"); wattroff(stdscr, A_BOLD); }
        if (tecla == 'e' || tecla == 'E') save->janelaaberta = !save->janelaaberta;
    }
    else *interagirJan = 0;

    // CELULAR
    if (save->celularpickup == 0 && save->y > celularY - 3 && save->y < celularY + 3 && save->x >= celularX - 4 && save->x <= celularX + 4 && save->revistapickup == 0 && save->livropickup == 0)
    {
        *interagirCel = 1;
        if (save->depoisprova == 0) { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+27, "Pegar celular: E"); wattroff(stdscr, A_BOLD); }
        else mvprintw(Yall+33, Xall+27, "Caramba, ela tirou o celular daqui...");
        if ((tecla == 'e' || tecla == 'E') && save->depoisprova == 0) save->celularpickup = 1;
    }
    else if (save->celularpickup == 1 && save->y > celularY - 3 && save->y < celularY + 3 && save->x >= celularX - 4 && save->x <= celularX + 4)
    {

        wattron(stdscr, A_BOLD);
        mvprintw(Yall+33, Xall+27, "Soltar celular: E");
        wattroff(stdscr, A_BOLD);
        if (tecla == 'e' || tecla == 'E') { save->celularpickup = 0; }
        save->celularpos++;
        if (save->celularpos > 3) save->celularpos = 1;
    }
    else *interagirCel = 0;
    
    // REVISTA
    int pertoRevista = ((save->x >= armarioX - 3 && save->x <= armarioX + 7) && (save->y >= armarioY && save->y <= armarioY + 7));
    if (*armarioaberto)
    {
        if (pertoRevista && save->celularpickup == 0 && save->livropickup == 0 && save->revistapickup == 0)
        {
            *interagirArm = 1;
            if (save->depoisprova == 0) { wattron(stdscr, A_BOLD); mvprintw(Yall+33, Xall+47, " Pegar revista: R"); wattroff(stdscr, A_BOLD); }
            else mvprintw(Yall+33, Xall+47, "Caramba, ela tirou o revista daqui...");
            if ((tecla == 'r' || tecla == 'R') && save->depoisprova == 0) save->revistapickup = !save->revistapickup;
        }
        else if (save->revistapickup && pertoRevista && save->celularpickup == 0 && save->livropickup == 0)
        {
            wattron(stdscr, A_BOLD);
            mvprintw(Yall+33, Xall+47, "Soltar revista: R");
            wattroff(stdscr, A_BOLD);
            if (tecla == 'r' || tecla == 'R') save->revistapickup = !save->revistapickup;
        }
        else if ((save->celularpickup == 1 || save->livropickup == 1) && pertoRevista)
        {
            *interagirArm = 0;
            wattron(stdscr, A_BOLD);
            mvprintw(Yall+33, Xall+65, "Mao ocupada");
            mvprintw(Yall+34, Xall+65, "Devolva o item da mao");
            wattroff(stdscr, A_BOLD);
        }
    }

    // ESTANTE / LIVROS
    int pertoestante = ((save->x >= estanteX - 2 && save->x <= estanteX + 14) && (save->y >= estanteY - 1 && save->y <= estanteY + 7));
    if (pertoestante)
    {
        *interagirEst = 1;
        if (save->livropickup == 0 && save->celularpickup == 0 && save->revistapickup == 0)
        {
            if (save->x >= estanteX - 2 && save->x <= estanteX + 2)
            {
                wattron(stdscr, A_BOLD);
                mvprintw(Yall+33, Xall+27, " Pegar livro 1: E");
                wattroff(stdscr, A_BOLD);
                if (tecla == 'e' || tecla == 'E') { save->livropickup = 1; *livro1 = 1; *livro2 = 0; *livro3 = 0; *abrindolivro = 1; }
            }
            else if (save->x >= estanteX + 3 && save->x <= estanteX + 8)
            {
                wattron(stdscr, A_BOLD);
                mvprintw(Yall+33, Xall+27, " Pegar livro 2: E");
                wattroff(stdscr, A_BOLD);
                if (tecla == 'e' || tecla == 'E') { save->livropickup = 1; *livro1 = 0; *livro2 = 1; *livro3 = 0; *abrindolivro = 1; }
            }
            else if (save->x >= estanteX + 9 && save->x <= estanteX + 14)
            {
                wattron(stdscr, A_BOLD);
                mvprintw(Yall+33, Xall+27, " Pegar livro 3: E");
                wattroff(stdscr, A_BOLD);
                if (tecla == 'e' || tecla == 'E') { save->livropickup = 1; *livro1 = 0; *livro2 = 0; *livro3 = 1; *abrindolivro = 1; }
            }
        }
        else if (save->livropickup == 1)
        {
            wattron(stdscr, A_BOLD);
            mvprintw(Yall+33, Xall+27, "Soltar livro: E");
            wattroff(stdscr, A_BOLD);
            if (tecla == 'e' || tecla == 'E') { save->livropickup = 0; *livro1 = 0; *livro2 = 0; *livro3 = 0; *abrindolivro = 0; }
        }
    }
    else *interagirEst = 0;
}

void printar_livro(int livropickup, int *abrindolivro, int livro1, int livro2, int livro3, int livroY, int livroX )
{
if (livropickup == 1)
    {
        if (*abrindolivro == 1) 
        {
            abrirlivro(&livro1, &livro2, &livro3); 
            abrindolivro = 0; 
            werase(stdscr); 
        }
        if (livro1 == 1 && livro2 == 0 && livro3 == 0)
        {
            mvwprintw(stdscr, livroY, livroX, " ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1, livroX, "|CAPITULO I:EQUACOES |CAPITULO II:Silogismo|");
            mvwprintw(stdscr, livroY+2, livroX, "|Exemplo Pratico     |Diagramas de         |");
            mvwprintw(stdscr, livroY+3, livroX, "|de Isolamento:      |Conjuntos(Venn):     |");
            mvwprintw(stdscr, livroY+4, livroX, "|Seja a equacao      |Se todo elemento de  |");
            mvwprintw(stdscr, livroY+5, livroX, "|Ax - B = Cx + D     |A esta em B e todos  |");
            mvwprintw(stdscr, livroY+6, livroX, "|1)Isola os termos   |de B estao em A, logo|");
            mvwprintw(stdscr, livroY+7, livroX, "|com 'x':            |B=A                  |");
            mvwprintw(stdscr, livroY+8, livroX, "|Ax - Cx = D + B     |Simbolismos:         |");
            mvwprintw(stdscr, livroY+9, livroX, "|2)Evidencie x:      |Se 2 enunciados sao  |");
            mvwprintw(stdscr, livroY+10, livroX, "|x * (A - C) = D + B |iguais, tem-se uma   |");
            mvwprintw(stdscr, livroY+11, livroX, "| x = (D + B)/(A - C)|tautologia=verdadeiro|");
            mvwprintw(stdscr, livroY+12, livroX, "|____________________|_____________________|");
        }
        else if (livro2 == 1 && livro1 == 0 && livro3 == 0)
        {
            mvwprintw(stdscr, livroY, livroX, " ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1, livroX, "|CAPITULO III:MATRIZ |CAPITULO IV: AREAS   |");
            mvwprintw(stdscr, livroY+2, livroX, "|Contagem Absoluta de|PLANAS               |");
            mvwprintw(stdscr, livroY+3, livroX, "|Elementos           |Calculo em figuras   |");
            mvwprintw(stdscr, livroY+4, livroX, "|O numero de itens em|vazadas:             |");
            mvwprintw(stdscr, livroY+5, livroX, "|uma matriz eh dado  |Seja um retangulo    |");
            mvwprintw(stdscr, livroY+6, livroX, "|da seguinte forma:  |que possui uma figura|");
            mvwprintw(stdscr, livroY+7, livroX, "|                    |inscrita(FI), a area |");
            mvwprintw(stdscr, livroY+8, livroX, "|   N = i x j        |do retangulo externo |");
            mvwprintw(stdscr, livroY+9, livroX, "|Onde i eh o numero  |sera:                |");
            mvwprintw(stdscr, livroY+10, livroX, "|de linhas e j o de  |   A=(B*H) - Ai      |");
            mvwprintw(stdscr, livroY+11, livroX, "|colunas             |Ai:Area da FI        |");
            mvwprintw(stdscr, livroY+12, livroX, "|____________________|_____________________|");
        }
        else if (livro3 == 1 && livro1 == 0 && livro2 == 0)
        {
            mvwprintw(stdscr, livroY, livroX, " ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1, livroX, "|CAPITULO V:GRAFICOS |                     |");
            mvwprintw(stdscr, livroY+2, livroX, "|O pico de um grafico|  Morte de golfinhos |");
            mvwprintw(stdscr, livroY+3, livroX, "|pode ser visualemnte|  no Atlantico       |");
            mvwprintw(stdscr, livroY+4, livroX, "|percebido, bem como |                     |");
            mvwprintw(stdscr, livroY+5, livroX, "|em que momento,que  |500 |          /\\    |");
            mvwprintw(stdscr, livroY+6, livroX, "|eh normalmente o    |90  |    /\\   /  \\   |");
            mvwprintw(stdscr, livroY+7, livroX, "|eixo X, esse pico   |0   +----+----+----+ |");
            mvwprintw(stdscr, livroY+8, livroX, "|foi alcançado      |       T1   T2   T3  |");
            mvwprintw(stdscr, livroY+9, livroX, "|                    |                     |");
            mvwprintw(stdscr, livroY+10, livroX, "|                    | Pico:T3             |");
            mvwprintw(stdscr, livroY+11, livroX, "|                    |                     |");
            mvwprintw(stdscr, livroY+12, livroX, "|____________________|_____________________|");
        }
    }
}