#include <ncurses.h>
#include <stdlib.h>
#include<stdio.h>
    #define VERMELHO
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
int main()
{
    curs_set(0);
    initscr(); // inicia a tela (janela)  
    cbreak(); // quebra a linha, tipo o \n, mas do ncurses, n da pra usar os 2 aqui, so esse msms
    noecho(); // n mostra o que o usuario ta digita ndo
    
    //coordenadas
    int Xall=(COLS/2)-57, Yall=3;
    int tecla=0, x=22+Xall, y=10+Yall;
    //coordenadas, e variaveis de controle
    int janelaY = 4+Yall, janelaX = 50+Xall,janelaaberta=0; 
    int celularY = 8+Yall, celularX = 76+Xall, celularpickup=0,celularpos=1;
    int armarioY = 14+Yall, armarioX = 19+Xall, armarioaberto=0,pertocama=0,dormindo=0;
    int revistapickup=0,revistax=celularX, revistay=celularY, meow=0;
    int livropickup=0, livroX=celularX+17, livroY=celularY,abrindolivro=0;
    int livro1=0,livro2=0,livro3=0,estudando=0;

    //seleção
    int interagirCel=0,interagirEst=0,interagirArm=0,interagirJan=0,interagirCam=0;
    int selecaocor=4,tecla_selecao,interage=0,cor=0,par=0;
    //movimento
    int passo=0,vira=0;
    //acontecimentos periódicos
    int check=0;
    //misc
    int espelho=0;
    int marcar = 0;
    int xbarra=3,ybarra=3;
    char barra[20]={'#','#','#','#','#','#','#','#','#','#','#'};
    int j;
    int iniciot;
    // condições de inicio do ato2
    int atividade_sono=0,estudo=0;

    int iniciar=0;
    keypad(stdscr, TRUE); // ativa o teclado para usar as setas, na tela principal, que é a stdscr
    nodelay(stdscr, TRUE); // Faz o getch() não ser bloqueante

    erase(); // limpa a tela, tipo o system("cls") do windows, mas do ncurses
    move(0,0);
    curs_set(0);
    while(1)//menu
    {
        inicio(&cor, &interage, &selecaocor,&iniciar);

    erase();
    refresh();
    if(cor==1)
    {
        
        cor=1;
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

    init_pair(1, COR_RODAPE,  -1); 
    init_pair(2, COR_JANELA,   -1); 
    init_pair(3, COR_CHAO,  -1); 
    init_pair(4, COLOR_RED, -1); 
    init_pair(5, COR_CHUVA, -1); 
    init_pair(6, COR_MARROM,-1 ); 
    init_pair(7, COR_ESTANTE,-1 );
    init_pair(8, COR_TAPETE_OPCAO1,-1 );
    init_pair(9, COR_RODAPE,-1 );
    init_pair(10, COR_BANCO,-1 );
    init_pair(11, COR_ESPELHO,-1 );
    init_pair(15, COR_CINZAESCURO,-1 );
    

        if(interage==1)
        {
            init_pair(12, COLOR_YELLOW,-1 );
            init_pair(13, COLOR_WHITE,-1 );
            init_pair(14, COR_CIANO,-1 );
    
            if(selecaocor==0)   
                par=12;
            else if(selecaocor==1)   
                par=13;
            else if(selecaocor==2)   
                par=14;
        }
    }
    napms(30);
 //DIALOGO INICIAL
    /*mvprintw(Yall,Xall,"Voce esta na sala, tomando nescau, comendo bisnaguinha");
    Yall++;
    mvprintw(Yall,Xall,"e assistindo Cartoon");
    refresh();
    napms(4000);
    erase();
    Yall++;*/






























//DIALOGO INICIAL

    /*mvprintw(Yall,Xall,"Mova-se com \"WASD\" - saia com a tecla q");
    refresh();
    napms(4000);
    erase();
    mvprintw(Yall,Xall,"Para uma boa gameplay, dentro dos jogos nao saia apertando todos os botoes");
    mvprintw((Yall)+1,Xall,"Ou movendo a janela do terminal, pode ocasionar em bugs");
    refresh();
    napms(3000);
    mvprintw((Yall)+3,Xall,"Fora dos jogos aperte \"Q\" para sair*");
    refresh();
    napms(4000);
    erase();
    mvprintw(Yall,Xall,"Bom jogo!");
    refresh();
    napms(4000);
    erase();*/

    // to dizendo o que tem que fazer
    // não botei um refresh aqui, pq eu posso botar varios printw e dps dar um refresh em tudo
    int pisca=1, vontadedepisca=0;

    int chuvax = 53+Xall, chuvay = 5+Yall, pos=0, pos2=1, pos3=2;

    int maepistola=0,maepistoladef=0;

    while(1)//jogo
    {
    // Localização dos objetos IMOVEIS
        vontadedepisca++;



            if(vontadedepisca<=600)
            {pisca=1;}
            else if(vontadedepisca > 600 && vontadedepisca <= 605)    
            {pisca = 0;}
            else
                vontadedepisca=0;
            
            erase();
           if(cor==1) wattron(stdscr, COLOR_PAIR(1));
           if(cor==1) wattron(stdscr, COLOR_PAIR(4));
        int camaY = 8+Yall, camaX = 80+Xall;
                    if(interagirCam==1)
                {
                   if(cor==1) wattron(stdscr, COLOR_PAIR(par));
                }
            mvprintw(camaY,   camaX, "._______.");
            mvprintw(camaY+1, camaX, "|~~     |");
            mvprintw(camaY+2, camaX, "|       |");
            mvprintw(camaY+3, camaX, "|    ~~ |");
            mvprintw(camaY+4, camaX, "|_______|");
            wattroff(stdscr, COLOR_PAIR(4));
           if(cor==1) wattron(stdscr, COLOR_PAIR(6));
            if(interagirCam==1)
                {
                   if(cor==1) wattron(stdscr, COLOR_PAIR(par));
                }
            mvprintw(camaY+5, camaX, "||     ||");
            wattroff(stdscr, COLOR_PAIR(6));

            mvprintw(camaY+1, camaX+2, "(   )");
            wattroff(stdscr, COLOR_PAIR(12));

           if(cor==1) wattron(stdscr, COLOR_PAIR(7));
        int estanteY = 5+Yall, estanteX = 34+Xall;
        if(interagirEst==1)
        {
           if(cor==1) wattron(stdscr, COLOR_PAIR(par));
        }
            mvprintw(estanteY,   estanteX, " ____________ ");
            mvprintw(estanteY+1, estanteX, "[____!!__||__]");
            mvprintw(estanteY+2, estanteX, "[||____!!_!!_]");
            mvprintw(estanteY+3, estanteX, "[!!_!!__||_!!]");
            mvprintw(estanteY+4, estanteX, "[__!!_!!___!!]");
            mvprintw(estanteY+5, estanteX, "[_||!!___!!||]");
            mvprintw(estanteY+6, estanteX, "[_!!_!!______]");
            wattroff(stdscr, COLOR_PAIR(7));
            wattroff(stdscr, COLOR_PAIR(par));

           if(cor==1) wattron(stdscr, COLOR_PAIR(6));
        if(armarioaberto==1)
        {
            if(interagirArm==1)
        {
           if(cor==1) wattron(stdscr, COLOR_PAIR(par));
        }
            int armarioY = 14+Yall, armarioX = 19+Xall;
            mvprintw (armarioY,   armarioX, "  ____ ");
            mvprintw (armarioY+1, armarioX, " |    |/|");
            mvprintw (armarioY+2, armarioX, " |    | |");
            mvprintw (armarioY+3, armarioX, " |    | |  ");
            mvprintw (armarioY+4, armarioX, " |____|/ ");
            mvprintw (armarioY+5, armarioX, " |    |  ");
            mvprintw (armarioY+6, armarioX, " |    |\\");
            mvprintw (armarioY+7, armarioX, " |    | |");
            mvprintw (armarioY+8, armarioX, " |    |[|");
            mvprintw (armarioY+9, armarioX, " |____|\\|");
        }
        else
        {
                if(interagirArm==1)
        {
           if(cor==1) wattron(stdscr, COLOR_PAIR(par));
        }
            mvprintw (armarioY,   armarioX, "  ____ ");
            mvprintw (armarioY+1, armarioX, " |    |");
            mvprintw (armarioY+2, armarioX, " |    |");
            mvprintw (armarioY+3, armarioX, " |    |");
            mvprintw (armarioY+4, armarioX, " |____|]");
            mvprintw (armarioY+5, armarioX, " |    |");
            mvprintw (armarioY+6, armarioX, " |    |]");
            mvprintw (armarioY+7, armarioX, " |    |");
            mvprintw (armarioY+8, armarioX, " |    |");
            mvprintw (armarioY+9, armarioX, " |____|");
        }
        wattroff(stdscr, COLOR_PAIR(par));
        wattroff(stdscr, COLOR_PAIR(6));
        if(livropickup==1)
            {
                if(abrindolivro==1)
                {
                    abrirlivro();
                    abrindolivro=0;
                    werase(stdscr);
                }
                if(livro1==1&&livro2==0&&livro3==0)
                {
                    mvwprintw(stdscr, livroY,       livroX," ____________________ _____________________ ");
                    mvwprintw(stdscr, livroY+1,     livroX,"|CAPITULO I:EQUACOES |CAPITULO II:Silogismo|");    
                    mvwprintw(stdscr, livroY+2,     livroX,"|Exemplo Pratico     |Diagramas de         |");
                    mvwprintw(stdscr, livroY+3,     livroX,"|de Isolamento:      |Conjuntos(Venn):     |");
                    mvwprintw(stdscr, livroY+4,     livroX,"|Seja a equacao      |Se todo elemento de  |");
                    mvwprintw(stdscr, livroY+5,     livroX,"|Ax - B = Cx + D     |A esta em B, e alguns|");
                    mvwprintw(stdscr, livroY+6,     livroX,"|1)Isola os termos   |elementos de B estao |");      
                    mvwprintw(stdscr, livroY+7,     livroX,"|com 'x':            |em C,nao se pode     |");
                    mvwprintw(stdscr, livroY+8,     livroX,"|Ax - Cx = D + B     |afirmar que todo ou  |");
                    mvwprintw(stdscr, livroY+9,     livroX,"|2)Evidencie x:      |nenhum elemento de A |");
                    mvwprintw(stdscr, livroY+10,    livroX,"|x * (A - C) = D + B |está em C           |");
                    mvwprintw(stdscr, livroY+11,    livroX,"| x = (D + B)/(A - C)|                     |");
                    mvwprintw(stdscr, livroY+12,    livroX,"|____________________|_____________________|"); 
                }
                else if(livro2==1&&livro1==0&&livro3==0)
                {
                    mvwprintw(stdscr, livroY,       livroX," ____________________ _____________________ ");
                    mvwprintw(stdscr, livroY+1,     livroX,"|CAPITULO III:MATRIZ |CAPITULO IV: AREAS   |");    
                    mvwprintw(stdscr, livroY+2,     livroX,"|Contagem Absoluta de|PLANAS               |");
                    mvwprintw(stdscr, livroY+3,     livroX,"|Elementos           |Calculo em figuras   |");
                    mvwprintw(stdscr, livroY+4,     livroX,"|O numero de itens em|vazadas:             |");
                    mvwprintw(stdscr, livroY+5,     livroX,"|uma matriz é dado da|Seja um retangulo    |");
                    mvwprintw(stdscr, livroY+6,     livroX,"|seguinte forma:     |que possui uma figura|");      
                    mvwprintw(stdscr, livroY+7,     livroX,"|                    |inscrita(FI), a area |");
                    mvwprintw(stdscr, livroY+8,     livroX,"|   N = i x j        |do retangulo externo |");
                    mvwprintw(stdscr, livroY+9,     livroX,"|Onde i eh o numero  |sera:                |");
                    mvwprintw(stdscr, livroY+10,    livroX,"|de linhas e j o de  |   A=(B*H) - Ai      |");
                    mvwprintw(stdscr, livroY+11,    livroX,"|colunas             |Ai:Area da FI        |");
                    mvwprintw(stdscr, livroY+12,    livroX,"|____________________|_____________________|"); 
                }
                else if(livro3==1&&livro1==0&&livro2==0)
                {
            mvwprintw(stdscr, livroY,        livroX," ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1,      livroX,"|CAPITULO V:GRAFICOS |                     |");    
            mvwprintw(stdscr, livroY+2,      livroX,"|O pico de um grafico|  Morte de golfinhos |");
            mvwprintw(stdscr, livroY+3,      livroX,"|pode ser visualemnte|  no Atlantico       |");
            mvwprintw(stdscr, livroY+4,      livroX,"|percebido, bem como |                     |");
            mvwprintw(stdscr, livroY+5,      livroX,"|em que momento,que  |500 |          /\\    |");
            mvwprintw(stdscr, livroY+6,      livroX,"|eh normalmente o    |90  |    /\\   /  \\   |");      
            mvwprintw(stdscr, livroY+7,      livroX,"|eixo X, esse pico   |0   +----+----+----+ |");
            mvwprintw(stdscr, livroY+8,      livroX,"|foi alcançado      |       T1   T2   T3  |");
            mvwprintw(stdscr, livroY+9,      livroX,"|                    |                     |");
            mvwprintw(stdscr, livroY+10,     livroX,"|                    | Pico:T3             |");
            mvwprintw(stdscr, livroY+11,     livroX,"|                    |                     |");
            mvwprintw(stdscr, livroY+12,     livroX,"|____________________|_____________________|");
                }
            }

            
            if(celularpickup==1)
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

            if(revistapickup==1)
            {       
                        mvprintw(revistay+2,    revistax+18, " |-_          __-|  ");
                        mvprintw(revistay+3,    revistax+18, " |  '--__.__-'   |  ");
                        mvprintw(revistay+4,    revistax+18, " |sudoku1|palavra|  ");
                        mvprintw(revistay+5,    revistax+18, " |sudoku2|cruzada| ");
                        mvprintw(revistay+6,    revistax+18, " |sudoku3|1, 2, 3|  ");
                        mvprintw(revistay+7,    revistax+18, " |-__    |    __-|  ");
                        mvprintw(revistay+8,    revistax+18, " |-__'-__|__-'__-|  ");
                        mvprintw(revistay+9,   revistax+18, "     '-__|__-'    ");
            }
            if(cor==1) wattron(stdscr, COLOR_PAIR(15));
            int lixoY = 27+Yall, lixoX = 84+Xall;
            mvprintw(lixoY,   lixoX, " ___");
            mvprintw(lixoY+1, lixoX, "|###|");
            mvprintw(lixoY+2, lixoX, " \\#/");
            if(cor==1) wattroff(stdscr, COLOR_PAIR(15));

           if(cor==1) wattron(stdscr, COLOR_PAIR(8));
            int tapetey=18+Yall, tapetex=45+Xall;
            mvprintw(tapetey , tapetex, "  I~~~~~~~~~~~~~I ");
            mvprintw(tapetey+1,tapetex, "  |    ~~~      | ");
            mvprintw(tapetey+2,tapetex, "  |       ~~~~  | ");
            mvprintw(tapetey+3, tapetex,"  |  ~~~        | ");
            mvprintw(tapetey+4, tapetex,"  |      ~~~~   | ");
            mvprintw(tapetey+5, tapetex,"  I~~~~~~~~~~~~~I ");
            wattroff(stdscr, COLOR_PAIR(8));

           if(cor==1) wattron(stdscr, COLOR_PAIR(9));
            int rodapey = 9+Yall, rodapex = 21+Xall;
            mvprintw(rodapey, rodapex,"_____________");
            mvprintw(rodapey+21,rodapex,"_____________________________________________________________________");
            for(; rodapex<63+Xall; rodapex++)
            {
                mvprintw(rodapey, rodapex+27, "_");
                if(rodapex==46+Xall)
                    rodapex=61+Xall;
            }
            wattroff(stdscr, COLOR_PAIR(9));

            mvprintw(ybarra-1,xbarra,"Cansaco");
            mvprintw(ybarra,xbarra,"+-----------+");

            if(atividade_sono>=1){
                
                mvprintw(ybarra+1,xbarra+1, "##");
                
            }
            if(atividade_sono>=2){
                mvprintw(ybarra+1,xbarra+3, "##");
            }
            if(atividade_sono>=3){
                mvprintw(ybarra+1,xbarra+5, "##");
            }
            if(atividade_sono>=4){
              if(cor==1)  attron(COLOR_PAIR(4));
                mvprintw(ybarra+1,xbarra+7, "##");
                attroff(COLOR_PAIR(4));
            }
            if(atividade_sono>=5){
              if(cor==1)  attron(COLOR_PAIR(4));
                mvprintw(ybarra+1,xbarra+9, "##");
                attroff(COLOR_PAIR(4));
            }
            
            mvprintw(ybarra+2,xbarra,"+-----------+");
            mvprintw(ybarra+1,xbarra,"|");
            mvprintw(ybarra+1,xbarra+12,"|");

            int espelhoy = 3+Yall, espelhox = 63+Xall;
            
            if (espelho==1)
            {
                nodelay(stdscr, FALSE); //pro jogo não continuar rodando ( a chiuva, piscar, o meow, etc)
                pedrapapeltesoura(&cor);//inicia o