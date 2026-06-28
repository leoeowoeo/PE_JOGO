#include"jogos.h"
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