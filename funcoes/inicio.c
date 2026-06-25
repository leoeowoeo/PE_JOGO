#include <ncurses.h>
#include <stdlib.h>
#include "jogos.h"
#define COR_CIANO          18

int inicio(int *selecao_olhos, int *selecao_face,int *selecao_pernas, int *cor, int *interage, int *selecaocor,int *iniciar,int *epilepsia,SAVE *save_atual,int *iniciado)
// a função apresenta a tela inicial do jogo, com o botão de iniciar,opção,credito,customização e sair
{//abriu main
    keypad(stdscr,TRUE);
    noecho();
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
    int xselecao=60,yselecao=10;
    int tecla, selecao=1,selecao_opcoes=1,selecao_aparencia=0;
    int piscar=0;
    int indicacao=0;
    int jogar=0,sair=0;
    int x=2;
    char *olhos[10]={"##","@@", "**","$$","vv","><","XX","OO","00","oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >","d  b"};
    char *pernas[4] = {"/|","|\\","<v", "v>"};

    *iniciar=0;

    while(sair!=1)
    {//abriu while
        
        erase();
        mvprintw(yselecao,xselecao-8,"JOGAR");
        mvprintw(yselecao+2,xselecao-8,"OPCOES");
        mvprintw(yselecao+4,xselecao-8,"CREDITOS");
        mvprintw(yselecao+6,xselecao-8,"CUSTOMIZACAO");
        mvprintw(yselecao+8,xselecao-8,"SAIR");
        if(*epilepsia==1)
        {
            mvprintw(LINES-5,5,"MODO DE EPILEPSIA");
        }

        mvprintw(LINES-3,5,"Aqui, use as setas e enter para selecionar");
        
        if(selecao==1)
        {//abriu if 1 e fechou
            if(piscar<=25)
            {//aif2 e fechou
                    if(*cor==0)
                    {mvprintw(3,7,"Voce pode ativar as cores nas opcoes");}
                mvprintw(yselecao,xselecao-12,"%s",faces[*selecao_face]);
                mvprintw(yselecao,xselecao-11,"%s",olhos[*selecao_olhos]);
            }//fechou if2
            else{
                if(*cor==0)
                        {mvprintw(3,7,"Voce pode ativar as cores nas opcoes");}
                    mvprintw(yselecao,xselecao-12,"%s",faces[*selecao_face]);
                    mvprintw(yselecao,xselecao-11,"--");
                    piscar=0;
            }
            
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao,xselecao-8,"JOGAR");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
        }//fechou if1
        
        if(selecao==2)
        {//abriu if5
            if(piscar>25)
            {//abriu if6
                mvprintw(yselecao+2,xselecao-14,"%s",faces[*selecao_face]);
                mvprintw(yselecao+2,xselecao-13,"--");
                piscar=0;
            }//fechou if6
            else
                {mvprintw(yselecao+2,xselecao-14,"%s",faces[*selecao_face]);
                mvprintw(yselecao+2,xselecao-13,"%s",olhos[*selecao_olhos]);}
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+2,xselecao-8,"OPCOES");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
            wrefresh(stdscr);
        }////fechou if5
        if(selecao==3)
        {//abriu if3
            if(piscar>25)
            {    mvprintw(yselecao+4,xselecao-14,"%s",faces[*selecao_face]);
                mvprintw(yselecao+4,xselecao-13,"%s",olhos[*selecao_olhos]);
            //æbriu if4
                mvprintw(yselecao+4,xselecao-14,"%s",faces[*selecao_face]);
                mvprintw(yselecao+4,xselecao-13,"--");
                piscar=0;
            }//fechou if4
            else
                {mvprintw(yselecao+4,xselecao-14,"%s",faces[*selecao_face]);
                mvprintw(yselecao+4,xselecao-13,"%s",olhos[*selecao_olhos]);}
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+4,xselecao-8,"CREDITOS");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
            wrefresh(stdscr);
        }//fechou if3
        if(selecao==4)
        {
            if(piscar>25)
            {
                mvprintw(yselecao+6,xselecao-14,"%s",faces[*selecao_face]);
                mvprintw(yselecao+6,xselecao-13,"--");
                piscar=0;
            }
            else
            {
                mvprintw(yselecao+6,xselecao-14,"%s",faces[*selecao_face]);
                mvprintw(yselecao+6,xselecao-13,"%s",olhos[*selecao_olhos]);
            }
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+6,xselecao-8,"CUSTOMIZACAO");
            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
            wrefresh(stdscr);
        }
        if(selecao==5)
        {//abriu if7
            if(piscar>25)
            {//abru if8
                mvprintw(yselecao+8,xselecao-12,"%s",faces[*selecao_face]);
                mvprintw(yselecao+8,xselecao-11,"xx");
                piscar=0;
            }//fechou if8
            else
            {
                mvprintw(yselecao+8,xselecao-12,"%s",faces[*selecao_face]);
                mvprintw(yselecao+8,xselecao-11,"%s",olhos[*selecao_olhos]);
            }
            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
            mvprintw(yselecao+8,xselecao-8,"SAIR");
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
                    jogar=1;
                    menusave(cor,save_atual,&jogar, selecao_olhos, selecao_face, selecao_pernas,iniciado);
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

                        mvprintw(yselecao+6,xselecao+10,"Aperte 'P' para voltar");
                        
                        if(*epilepsia==1)
                        {
                            mvprintw(yselecao+5,xselecao+10,"MODO DE EPILEPSIA ATIVO");
                        }

                        mvprintw(yselecao+2,xselecao,"HABILITAR INDICADORES DE INTERACAO");
                        mvprintw(yselecao,xselecao,"ATIVAR/DESATIVAR CORES");
                        mvprintw(yselecao+4,xselecao,"MODO EPILEPSIA");
                    
                        mvprintw(LINES-3,5,"As cores e os indicadores não afetam a gameplay");
                        if(*cor==1 && *interage==1)
                        {   
                            wattron(stdscr,COLOR_PAIR(x));
                            mvprintw(yselecao+2,xselecao+36,"  ");
                            wattroff(stdscr,COLOR_PAIR(x));
                        }
                        
                        if(*cor==1)
                        {   
                            wattron(stdscr,COLOR_PAIR(1));
                            mvprintw(yselecao,xselecao+23,"  ");
                            wattroff(stdscr,COLOR_PAIR(1));
                        }
                        
                        if(selecao_opcoes==1)
                        {//abriu if10
                            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                            mvprintw(yselecao,xselecao,"ATIVAR/DESATIVAR CORES");
                            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                        }//fechou if10
                        else if(selecao_opcoes==2)
                        {//abriu if11
                            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                            mvprintw(yselecao+2,xselecao,"HABILITAR INDICADORES DE INTERACAO");
                            wattroff(stdscr,COLOR_PAIR(4)|A_BOLD);
                            indicacao=1;
                        }
                        else if(selecao_opcoes==3)
                        {
                            wattron(stdscr,COLOR_PAIR(4)|A_BOLD);
                            mvprintw(yselecao+4,xselecao,"MODO EPILEPSIA");
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
                                    *cor=!(*cor);
                                    erase();
                                    break;
                                }//fechou if14
                                else if(selecao_opcoes==2)
                                {//abriu if15
                                    *interage=!(*interage);
                                    
                                    if(*interage == 0) {
                                        erase();
                                        break;
                                    }
/*O QUE TEM QUE MUDAR AINDA:

ELE TA PISCANDO QUANDO CLICA RESOLVI

TEM QUE AVISAR QUE BOTAO É PRA USAR E O QUE ELE VAI FAZER EM SEGUIA< QUANDO CLICAR (ATIVAR/DESATIVAR) RESOLVI

LOGO/NOME DO JOGO*/
                                    int tecla_cor = 0;
                                    while(tecla_cor!='\n'){
                                        if(x==1)
                                            *selecaocor=1;
                                        else if(x==2)
                                            *selecaocor=0;
                                        else if(x==3)
                                            *selecaocor=2;
                                        erase();
                                        mvprintw(yselecao, xselecao, "Escolha a cor com as setas e selecione com ENTER:");
                                        
                                            wattron(stdscr,COLOR_PAIR(x));
                                        mvprintw(yselecao+2, xselecao, "  ");
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
                        mvprintw(yselecao,xselecao,"KAIKE FROM ESPIRITO SANTO");
                        mvprintw(yselecao+1,xselecao,"LEO FROM NILOPOLIS");
                        mvprintw(yselecao+4,xselecao+10,"Aperte 'P' para voltar");
                        refresh();
                        tecla=getch();
                    }
                    timeout(200);
                    clear();
                }//fechou if16 
                else if(selecao==4)
                {
                personalizar(&*selecao_olhos,&*selecao_face,&*selecao_pernas, xselecao, yselecao);
                }
                else if(selecao==5)
                {
                    sair=1;
                    wattroff(stdscr,COLOR_PAIR(4));
                    break;
                }
                break;
        }//fechou switch
        if(jogar==1||sair==1)
            break;
        napms(30);
    }

    if(jogar==1)
    {
        return 0;
    }

    if (sair==1)
    {
        mvprintw(yselecao+5,xselecao-14,"naooooooo!");
        mvprintw(yselecao+8,xselecao-12,"%s",faces[*selecao_face]);
        mvprintw(yselecao+8,xselecao-11,"xx");
        wrefresh(stdscr);
        napms(500);
        werase(stdscr);
        mvprintw(yselecao+5,xselecao-14,"naooooooo!");
        mvprintw(yselecao+8,xselecao-12,"%s",faces[*selecao_face]);
        mvprintw(yselecao+8,xselecao-11,"xx");
        wrefresh(stdscr);
        napms(1000);
        endwin();
        exit(0);
    }
    return 1;
}
