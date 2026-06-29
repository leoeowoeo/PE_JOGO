#include <ncurses.h>
#include <stdlib.h>
#include "jogos.h"
#include <signal.h>
#define COR_CIANO          18
void XeYselecaoLUGAR(int *yselecao, int *xselecao);
int inicio(int *interage,int *iniciar,int *epilepsia,SAVE *save,int *jogar,int estanoquarto)
// a função apresenta a tela inicial do jogo, com o botão de iniciar,opção,credito,customização e sair
{//abriu main
    keypad(stdscr,TRUE);
    noecho();
    raw();
    curs_set(0);
    start_color();
    use_default_colors();
    timeout(200);
    init_color(COR_CIANO, 0, 1000, 1000);

    init_pair(1,-1,COLOR_WHITE);
    init_pair(2,-1,COLOR_YELLOW);
    init_pair(4,COLOR_WHITE,-1);
    init_pair(3,-1 ,COR_CIANO );
    wattron(stdscr,COLOR_PAIR(4));
    int xselecao=COLS-120,yselecao=10;
    XeYselecaoLUGAR(&yselecao,&xselecao);
    int tecla, selecao=1,selecao_opcoes=1,selecao_aparencia=0;
    int piscar=0;
    int indicacao=0;
    int sair=0;
    int x=2;
    char *olhos[10]={"##","@@", "**","$$","vv","><","XX","OO","00","oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >","d  b"};
    char *pernas[4] = {"/|","|\\","<v", "v>"};
    int i; 
    int validador=0;
    int e=0;
    *iniciar=0;
    *jogar=0;
    estanoquarto=0;
while(sair!=1)// tem q verificar esses ifs, ta dando erro nas chaves, tem algo no lugar errado :-(
    {//abriu while

        if (tecla == 3) { 
            int i;
            for(i = 1; i <= 25; i++) {
                clear();
                mvprintw(yselecao+20 + 8, xselecao - 12, "%s", faces[save->selecao_face]);
                mvprintw(yselecao+20 + 8, xselecao - 11, "xx");
                mvprintw(yselecao+20 + 5, xselecao - 14, "na");
                int j;
                for(j = 0; j < i; j++) {
                    printw("o");
                }
                if(i == 25) {
                    printw("!!!");
                }
                refresh();
                napms(60);
            }
            napms(800);
            endwin();
            exit(0);
        }
            erase();

        if(validador==0&&COLS>=170)
        {
            animacaomenu(yselecao,xselecao);
            validador=1;
            flushinp();
                timeout(200);
        }
        else if(validador==0)
        {
            animacaopequenina(yselecao,xselecao);
            validador=1;
            flushinp();
                timeout(200);
        }
        if(tecla=='e'||tecla=='E')
        {e++;}
        
        if(e==100)
        {e=0;validador=0;}
        else
        {validador=1;}
        
        if(COLS>=170)
        {
        mvprintw(yselecao-5, xselecao - 39, "                        ,,         ,,   ,,              ..           ,,                      ,,                     ..      ");
        mvprintw(yselecao-4, xselecao - 39, "`7MMF'     A     `7MF'`7MM         db `7MM            pd'`7MM\"\"\"Mq.`7MM                      db                      `bq    ");
        mvprintw(yselecao-3, xselecao - 39, "  `MA     ,MA     ,V    MM              MM           6P    MM   `MM. MM                                                YA   ");
        mvprintw(yselecao-2, xselecao - 39, "   VM:   ,VVM:   ,V     MMpMMMb. `7MM   MM  .gP\"Ya  6M'    MM   ,M9  MM   ,6\"Yb.`7M'   `MF'`7MM `7MMpMMMb.  .P\"Ybmmm   `Mb    ");
        mvprintw(yselecao-1, xselecao - 39, "    MM.  M' MM.  M'     MM    MM   MM   MM ,M'   Yb MN     MMmmdM9   MM  8)   MM  VA   ,V    MM   MM    MM :MI  I8      8M       ");
        mvprintw(yselecao, xselecao - 39, "    `MM A'  `MM A'      MM    MM   MM   MM 8M\"\"\"\"\"\" MN     MM        MM   ,pm9MM   VA ,V     MM   MM    MM  WmmmP\"      8M ");
        mvprintw(yselecao+1, xselecao - 39, "     :MM;    :MM;       MM    MM   MM   MM YM.    , YM.    MM        MM  8M   MM    VVV      MM   MM    MM 8M          ,M9  ");
        mvprintw(yselecao+2, xselecao - 39, "      VF      VF      .JMML  JMML.JMML.JMML.`Mbmmd'  Mb  .JMML.    .JMML.`Moo9^Yo.  ,V     .JMML.JMML  JMML.YMMMMMb    dM   ");
        mvprintw(yselecao+3, xselecao - 39, "                                                      Yq.                          ,V                      6'     dP .pY    ");
        mvprintw(yselecao+4, xselecao - 39, "                                                        ``                      OOb\"                       Ybmmmd'  ''      ");
        mvprintw(yselecao+5, xselecao - 39, "    ,pm                                       ,,              ,,                          ..                     ..      mq.    ");
        mvprintw(yselecao+6, xselecao - 39, "   6M   OO             mm                   `7MM              db                        pd' .g8\"\"8q.     .g8\"\"8q. `bq      Mb   ");
        mvprintw(yselecao+7, xselecao - 39, "   MM   88             MM                     MM                                       6P .dP'    `YM. .dP'    `YM. YA     MM   ");
        mvprintw(yselecao+8, xselecao - 39, "   M9   ||   ,pP\"Ybd mmMMmm `7MM  `7MM   ,M\"\"bMM `7M'   `MF'`7MM `7MMpMMMb.  .P\"Ybmmm 6M' dM'      `MM dM'      `MM `Mb gp YM   ");
        mvprintw(yselecao+9, xselecao - 39, "_.d\"'   ||   8I   `\"   MM     MM    MM ,AP    MM   VA   ,V    MM   MM    MM :MI  I8   MN  MM        MM MM        MM  8M \"\" `\"b._");
        mvprintw(yselecao+10, xselecao - 39, "`\"bp.   `'   `YMMMa.   MM     MM    MM 8MI    MM    VA ,V     MM   MM    MM  WmmmP\"   MN  MM.      ,MP MM.      ,MP  8M    ,qd\"'");
        mvprintw(yselecao+11, xselecao - 39, "   Mb   ,,   L.   I8   MM     MM    MM `Mb    MM     VVV      MM   MM    MM 8M        YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ,, 6M   ");
        mvprintw(yselecao+12, xselecao - 39, "   MM   db   M9mmmP'   `Mbmo  `Mbod\"YML.`Wbmd\"MML.   ,V     .JMML.JMML  JMML.YMMMMMb   Mb   `\"bmmd\"'     `\"bmmd\"'   dM  dg MM   ");
        mvprintw(yselecao+13, xselecao - 39, "   YM                                               ,V                      6'     dP   Yq.                       .pY   ,j M9   ");
        mvprintw(yselecao+14, xselecao - 39, "    `bm                                          OOb\"                       Ybmmmd'       ``                     ''    ,'md'    ");
        }
        else
        {
            int altura=1;
            int lugar=-3;
            int espacamento=0;
                        altura=lugar;
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "    ..                     ..     ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "  pd' .g8\"\"8q.     .g8\"\"8q. `bq   ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, " 6P .dP'    `YM. .dP'    `YM. YA  ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "6M' dM'      `MM dM'      `MM `Mb ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "MN  MM        MM MM        MM  8M ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "MN  MM.      ,MP MM.      ,MP  8M ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, " Mb   `\"bmmd\"'     `\"bmmd\"'   dM  ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "  Yq.                       .pY   ");
                    mvprintw(yselecao+5+altura++, xselecao+espacamento+4, "    ``                     ''     "); 

        mvprintw(yselecao+16,xselecao-8,"While(playing)");
        mvprintw(yselecao+17,xselecao-8,"{!studying(OO);}");

        }
        
        wrefresh(stdscr);

        
        mvprintw(yselecao+20,xselecao-8,"JOGAR");
        mvprintw(yselecao+20+2,xselecao-8,"OPCOES");
        mvprintw(yselecao+20+4,xselecao-8,"CREDITOS");
        mvprintw(yselecao+20+6,xselecao-8,"CUSTOMIZACAO");
        mvprintw(yselecao+20+8,xselecao-8,"SAIR");
        if(*epilepsia==1)
        {
            mvprintw(LINES-5,5,"MODO DE EPILEPSIA");
        }

        mvprintw(LINES-3,5,"Aqui, use as setas e enter para selecionar");
        
        if(selecao==1)
        {//abriu if 1 e fechou
            if(piscar<=25)
            {//aif2 e fechou
                    if(save->cor==0)
                    {mvprintw(3,7,"Voce pode ativar as cores nas opcoes");}
                mvprintw(yselecao+20,xselecao-12,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20,xselecao-11,"%s",olhos[save->selecao_olhos]);
            }//fechou if2
            else{
                if(save->cor==0)
                        {mvprintw(3,7,"Voce pode ativar as cores nas opcoes");}
                    mvprintw(yselecao+20,xselecao-12,"%s",faces[save->selecao_face]);
                    mvprintw(yselecao+20,xselecao-11,"--");
                    piscar=0;
            }
            
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+20,xselecao-8,"JOGAR");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }//fechou if1
        
        if(selecao==2)
        {//abriu if5
            if(piscar>25)
            {//abriu if6
                mvprintw(yselecao+20+2,xselecao-14,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+2,xselecao-13,"--");
                piscar=0;
            }//fechou if6
            else
                {mvprintw(yselecao+20+2,xselecao-14,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+2,xselecao-13,"%s",olhos[save->selecao_olhos]);}
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+20+2,xselecao-8,"OPCOES");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
            wrefresh(stdscr);
        }////fechou if5
        if(selecao==3)
        {//abriu if3
            if(piscar>25)
            {    mvprintw(yselecao+20+4,xselecao-14,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+4,xselecao-13,"%s",olhos[save->selecao_olhos]);
            //æbriu if4
                mvprintw(yselecao+20+4,xselecao-14,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+4,xselecao-13,"--");
                piscar=0;
            }//fechou if4
            else
                {mvprintw(yselecao+20+4,xselecao-14,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+4,xselecao-13,"%s",olhos[save->selecao_olhos]);}
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+20+4,xselecao-8,"CREDITOS");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
            wrefresh(stdscr);
        }//fechou if3
        if(selecao==4)
        {
            if(piscar>25)
            {
                mvprintw(yselecao+20+6,xselecao-14,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+6,xselecao-13,"--");
                piscar=0;
            }
            else
            {
                mvprintw(yselecao+20+6,xselecao-14,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+6,xselecao-13,"%s",olhos[save->selecao_olhos]);
            }
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+20+6,xselecao-8,"CUSTOMIZACAO");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
            wrefresh(stdscr);
        }
        if(selecao==5)
        {//abriu if7
            if(piscar>25)
            {//abru if8
                mvprintw(yselecao+20+8,xselecao-12,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+8,xselecao-11,"xx");
                piscar=0;
            }//fechou if8
            else
            {
                mvprintw(yselecao+20+8,xselecao-12,"%s",faces[save->selecao_face]);
                mvprintw(yselecao+20+8,xselecao-11,"%s",olhos[save->selecao_olhos]);
            }
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+20+8,xselecao-8,"SAIR");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
            wrefresh(stdscr);
        }
        
            //fechou if7
        
        piscar++;
        refresh();
        tecla=getch();

        switch(tecla){//abriu switch1
            case KEY_UP:
                selecao--;
                if(selecao<1)
                    selecao=5;
                break;//break keyup
            case KEY_DOWN:
                selecao++;
                if(selecao>5)
                    selecao=1;
                break;//break keydown
            case '\n':
                if(selecao==1)
                {//abriu if 8
                    *jogar=1;
                    cbreak();
                    menusave(save,jogar,estanoquarto);
                    nodelay(stdscr,FALSE);
                    timeout(200);
                    wattroff(stdscr,COLOR_PAIR(4));
                    break;
                }//fechou if8
                else if(selecao==2)
                {//abriu else if
                    tecla = 0;
                    erase();
                    while(tecla!='p' && tecla!='P')
                    {//abriu while
                        timeout(200);
                        tecla=getch();

                        if(tecla == KEY_UP || tecla == KEY_DOWN || tecla == '\n')
                        {
                            erase();
                        }

                        mvprintw(yselecao+20-10+6,xselecao+10,"Aperte 'P' para voltar");
                        
                        if(*epilepsia==1)
                        {
                            mvprintw(yselecao+20-10+5,xselecao+10,"MODO DE EPILEPSIA ATIVO");
                        }

                        mvprintw(yselecao+20-10+2,xselecao,"HABILITAR INDICADORES DE INTERACAO");
                        mvprintw(yselecao+20-10,xselecao,"ATIVAR/DESATIVAR CORES");
                        mvprintw(yselecao+20-10+4,xselecao,"MODO EPILEPSIA");
                    
                        mvprintw(LINES-3,5,"As cores e os indicadores não afetam a gameplay");
                        if(save->cor==1 && *interage==1)
                        {   
                            wattron(stdscr,COLOR_PAIR(x));
                            mvprintw(yselecao+20-10+2,xselecao+36,"  ");
                            wattroff(stdscr,COLOR_PAIR(x));
                        }
                        
                        if(save->cor==1)
                        {   
                            wattron(stdscr,COLOR_PAIR(1));
                            mvprintw(yselecao+20-10,xselecao+23,"  ");
                            wattroff(stdscr,COLOR_PAIR(1));
                        }
                        
                        if(selecao_opcoes==1)
                        {//abriu if10
                            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                            mvprintw(yselecao+20-10,xselecao,"ATIVAR/DESATIVAR CORES");
                            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                        }//fechou if10
                        else if(selecao_opcoes==2)
                        {//abriu if11
                            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                            mvprintw(yselecao+20-10+2,xselecao,"HABILITAR INDICADORES DE INTERACAO");
                            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                            indicacao=1;
                        }
                        else if(selecao_opcoes==3)
                        {
                            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                            mvprintw(yselecao+20-10+4,xselecao,"MODO EPILEPSIA");
                            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                        }

                        switch(tecla)
                        {//abriu switch2
                            case KEY_UP:
                                selecao_opcoes--;
                                if(selecao_opcoes<1)
                                {//abriu if12
                                    selecao_opcoes=3;
                                }//fechou if12
                                break;//break keyup
                            case KEY_DOWN:
                                selecao_opcoes++;
                                if(selecao_opcoes>3)
                                {//abriu if13
                                    selecao_opcoes=1;
                                }//fechou if13
                                break;
                            case '\n':
                                if(selecao_opcoes==1)
                                {//abriu if 14
                                    save->cor=!(save->cor);
                                    erase();
                                    cbreak();
                                    break;
                                }//fechou if14
                                else if(selecao_opcoes==2)
                                {//abriu if15
                                    *interage=!(*interage);
                                    
                                    if(*interage == 0) {
                                        erase();
                                        break;
                                    }
                                raw();
/*O QUE TEM QUE MUDAR AINDA:

ELE TA PISCANDO QUANDO CLICA: RESOLVI

TEM QUE AVISAR QUE BOTAO É PRA USAR E O QUE ELE VAI FAZER EM SEGUIA< QUANDO CLICAR (ATIVAR/DESATIVAR): RESOLVI

LOGO/NOME DO JOGO N TEM AINDAAAA
*/
                                    int tecla_cor = 0;
                                    while(tecla_cor!='\n'){
                                        if(x==1)
                                            save->selecao_cor=1;
                                        else if(x==2)
                                            save->selecao_cor=0;
                                        else if(x==3)
                                            save->selecao_cor=2;
                                        erase();
                                        mvprintw(yselecao+20-10, xselecao, "Escolha a cor com as setas e selecione com ENTER:");
                                        
                                            wattron(stdscr,COLOR_PAIR(x));
                                        mvprintw(yselecao+20-10+2, xselecao, "  ");
                                            wattroff(stdscr,COLOR_PAIR(x));
                                        refresh();

                                        timeout(-1);
                                        tecla_cor=getch();
                                        switch(tecla_cor){
                                            case 'w':
                                            case KEY_UP:
                                                x--;
                                                if(x<1)
                                                    x=3;
                                                
                                                break;
                                            case 's':
                                            case KEY_DOWN:
                                                x++;
                                                if(x>3) 
                                                    x=1;
                                                break;
                                        }
                                        
                                    }
                                    erase();
                                }//fechou if15
                                else if(selecao_opcoes==3)
                                {
                                    *epilepsia=!(*epilepsia);
                                    tecla = 0;
                                    erase(); 
                                }
                                break;
                        }//fechou switch2
                        refresh();
                        napms(30);
                    }//fechou while
                    timeout(200);
                    clear();
                }//fechou if9
                else if(selecao==3)
                {
                    tecla = 0;
                    while(tecla!='p' && tecla!='P')
                    {//abriu if16
                        erase();
                        timeout(-1);
                        mvprintw(yselecao+20-10,xselecao,"KAIKE FROM ESPIRITO SANTO");
                        mvprintw(yselecao+20-10+1,xselecao,"LEO FROM NILOPOLIS");
                        mvprintw(yselecao+20-10+4,xselecao+10,"Aperte 'P' para voltar");
                        refresh();
                        tecla=getch();
                    }
                    timeout(200);
                    clear();
                }//fechou if16 
                else if(selecao==4)
                {
                personalizar(&save->selecao_olhos,&save->selecao_face,&save->selecao_pernas, xselecao, yselecao+20-10);
                }
                else if(selecao==5)
                {
                    sair=1;
                    wattroff(stdscr,COLOR_PAIR(4));
                    break;
                }
                break;
        }//fechou switch
        if(*jogar==1||sair==1)
            break;
        napms(30);
    }

    if(*jogar==1)
    {
        noraw();
        cbreak();
        return 0;
    }

    if (sair==1)
    {
            int i;
            for(i = 1; i <= 25; i++) {
                clear();
                mvprintw(yselecao+20 + 8, xselecao - 12, "%s", faces[save->selecao_face]);
                mvprintw(yselecao+20 + 8, xselecao - 11, "xx");
                mvprintw(yselecao+20 + 5, xselecao - 14, "na");
                int j;
                for(j = 0; j < i; j++) {
                    printw("o");
                }
                if(i == 25) {
                    printw("!!!");
                }
                refresh();
                napms(60);
            }
            napms(800);
            endwin();
            exit(0);
    }
    return 1;
}


void XeYselecaoLUGAR(int *yselecao, int *xselecao) {
    *yselecao = (LINES / 2) - 10;
    int centro_horizontal = COLS / 2;
    *xselecao = centro_horizontal - 45; 
    if (*yselecao < 5) *yselecao = 5;
    if (*xselecao < 20) *xselecao = 20;
}