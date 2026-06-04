#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

    #define TARGET_FRAME_MS 30 // teste pra commit
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
    FILE *entrada, *saida;
    

    curs_set(0);
    initscr(); // inicia a tela (janela)  
    cbreak(); // quebra a linha, tipo o \n, mas do ncurses, n da pra usar os 2 aqui, so esse msms
    noecho(); // n mostra o que o usuario ta digita ndo
    

    SAVE save1,save2,save3;

        save1.atividade_sono=0;
        save1.celularpickup=0;
        save1.livropickup=0;
        save1.revistapickup=0;
        save1.maepistola=0;
        save1.maepistoladef=0;
        save1.janelaaberta=0;
        save1.depoisprova=0;

        save2.atividade_sono=0;
        save2.celularpickup=0;
        save2.livropickup=0;
        save2.revistapickup=0;
        save2.maepistola=0;
        save2.maepistoladef=0;
        save2.janelaaberta=0;
        save2.depoisprova=0;

        save3.atividade_sono=0;
        save3.celularpickup=0;
        save3.livropickup=0;
        save3.revistapickup=0;
        save3.maepistola=0;
        save3.maepistoladef=0;
        save3.janelaaberta=0;
        save3.depoisprova=0;
    
    int Xall=(COLS/2)-57, Yall=3;
    int tecla=0, x=22+Xall, y=10+Yall;
    int xf=22+Xall,yf=10+Yall,lado=0;
    //coordenadas, e variaveis de controle
    int janelaY = 4+Yall, janelaX = 50+Xall,janelaaberta=0; 
    int celularY = 9+Yall, celularX = 76+Xall, celularpickup=0,celularpos=1;
    int armarioY = 14+Yall, armarioX = 19+Xall, armarioaberto=0,pertocama=0,dormindo=0;
    int revistapickup=0,revistax=celularX, revistay=celularY, meow=0;
    int livropickup=0, livroX=celularX+17, livroY=celularY,abrindolivro=0;
    int livro1=0,livro2=0,livro3=0,estudando=0;
    int jogarcelular=0;
    int acertos=0;

    //seleção
    int interagirCel=0,interagirEst=0,interagirArm=0,interagirJan=0,interagirCam=0;
    int selecaocor=4,tecla_selecao,interage=0,cor=1,par=0;
    int quest=0;
    int jogarcelular5=0,encararespelho=0,dormircama=0,jogartodosjogos=0,ler1jogar3=0,ler3dormir=0,ler3jogatodos=0;
    char *quests[8]=
            {
                "Ganhar 5 jogos no celular",
                "Encarar o espelho",
                "Dormir na cama",
                "Jogar todos os jogos uma vez",
                "Ler um livro e jogar 3 jogos",
                "Ler 3 livros e jogar todos os jogos do celular",
                "Ler 3 livros e dormir?"
            };
            
    int finais_alcancados;


    char *olhos[10]={"##","@@", "**","$$","vv","><","XX","OO","00","oo"};
    char *faces[5] = {"(  )", "[  ]", "{  }", "<  >","d  b"};
    char *pernas[4] = {"/|","|\\","<v", "v>"};
    char *revista[9]={"1","2","3","4","5","6"};
    int selecao_olhos=9,selecao_face=0,selecao_pernas=0;
    //movimento
    int passo=0,vira=0;
    //acontecimentos periódicos
    int check=0;
    //misc
    int espelho=0;
    int marcar = 0;
    int xbarra=3,ybarra=3;
    char barra[20]={'#','#','#','#','#','#','#','#','#','#','#'};
    int j,i;
    int iniciot;
    int linhaatual=Yall;
    int maexinga=0;
    int epilepsia=0;
    // condições de inicio do ato2 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int atividade_sono=0,estudo=0;
            //CONDIÇÕES DO ATO 3--------------------------------------------------------------------------------------------------------
    int depoisprova=0;
    int validador=1;
    int fechar=0;


    int debug=1;


    int revista_coluna=0;
    int revista_linha=0;
    int iniciar=0;
    keypad(stdscr, TRUE); // ativa o teclado para usar as setas, na tela principal, que é a stdscr
    nodelay(stdscr, TRUE); // Faz o getch() não ser bloqueante

    erase(); // limpa a tela, tipo o system("cls") do windows, mas do ncurses
    move(0,0);
    curs_set(0);
    while(1)//menu
    {
        if(depoisprova==0) inicio(&selecao_olhos,&selecao_face,&selecao_pernas,&cor, &interage, &selecaocor,&iniciar,&epilepsia);
        if(epilepsia==1){
            mvprintw(LINES-5,5,"MODO DE EPILEPSIA");
        }
        // FAZER CONTATO COM MOVEIS
        //FAZER NÃO REPETIR A INTRODUÇÃO QUANDO SAIR E ENTRAR USANDO "Q"

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

    init_pair(4, COLOR_RED, -1); 
    init_pair(5, COR_CHUVA, -1); 
    init_pair(6, COR_MARROM,-1 ); 
    init_pair(7, COR_ESTANTE,-1 );
    init_pair(8, COR_TAPETE_OPCAO1,-1 );
    init_pair(9, COR_RODAPE,-1 );
    init_pair(10,COLOR_WHITE,COLOR_WHITE);

    init_pair(11, COR_ESPELHO,-1 );
    init_pair(15, COR_CINZAESCURO,-1 );
    
    init_pair(16,COLOR_WHITE,COLOR_BLUE);
    init_pair(17,COLOR_WHITE,COLOR_GREEN);
    init_pair(18,COLOR_WHITE,COLOR_RED);
    init_pair(19,COLOR_WHITE,COLOR_MAGENTA);
    init_pair(20,COLOR_WHITE,COLOR_YELLOW);
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
    if(iniciar==0||depoisprova==0)
    {
        //DIALOGO INICIAL
    /*keypad(stdscr, FALSE);
    mvprintw(Yall,Xall,"Mova-se com \"WASD\" - saia com a tecla q");
    refresh();
    napms(4000);
    erase();
    mvprintw(Yall,Xall,"Para uma boa gameplay, dentro dos jogos nao saia apertando todos os botoes");
    mvprintw((Yall)+1,Xall,"Ou movendo a janela do terminal, pode ocasionar em bugs");
    refresh();
    napms(4000);
    mvprintw((Yall)+3,Xall,"Fora dos jogos aperte \"Q\" para sair*");
    refresh();
    napms(5000);
    erase();
    mvprintw(Yall,Xall,"Esse projeto ainda esta sendo desenvolvido");
    refresh();
    napms(4000);
    erase();
    mvprintw(Yall,Xall,"Bom jogo!");
    refresh();
    napms(4000);

    erase();
    transicao(&epilepsia);
    quest=dialogoMae(&maexinga);*/
    keypad(stdscr, TRUE);

    }
    // não botei um refresh aqui, pq eu posso botar varios printw e dps dar um refresh em tudo
    int pisca=1, vontadedepisca=0;

    int chuvax = 53+Xall, chuvay = 5+Yall, pos=0, pos2=1, pos3=2;

    int maepistola=0,maepistoladef=0;

    while(1){//antes/depoisprova
    if(atividade_sono>=4){atividade_sono=3;}
    dormindo=0;
    while(1)//jogo
    {   
        if(depoisprova==1&&validador==1){maepistola=0;maepistoladef=0;validador=0;}
        fechar=0;
        //achar onde tão as linhas e colunas enquanto está no jogo
    if (debug == 1) 
        {
            for (int i = 0; i < LINES; i++) 
            {
                mvprintw(i, COLS - 3, "%2d", i);
            }

            for (int j = 0; j < COLS; j += 3) 
            {
                mvprintw(LINES - 1, j, "%2d", j);
            }
        }
        
        clock_t frame_start = clock(); // mede o tempo no começo do loop de jogo
    // Localização dos objetos IMOVEIS
        vontadedepisca++;

        nodelay(stdscr, TRUE);

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



            
            if(celularpickup==1&&depoisprova==0)
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

            if(revistapickup==1&&depoisprova==0)
            {       
                        mvprintw(revistay+2,    revistax+18, " |-_          __-|  ");
                        mvprintw(revistay+3,    revistax+18, " |  '--__.__-'   |  ");
                        mvprintw(revistay+4,    revistax+18, " |sudoku |palavra|  ");
                        mvprintw(revistay+5,    revistax+18, " | 1 2 3 |cruzada| ");
                        mvprintw(revistay+6,    revistax+18, " | 4 5 6 |1  2  3|  ");
                        mvprintw(revistay+7,    revistax+18, " |-__    |    __-|  ");
                        mvprintw(revistay+8,    revistax+18, " |-__'-__|__-'__-|  ");
                        mvprintw(revistay+9,   revistax+18, "     '-__|__-'    ");
            }
            if(cor==1) wattron(stdscr, COLOR_PAIR(15));
            int lixoY = 27+Yall, lixoX = 84+Xall;
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

            mvprintw(ybarra-1,xbarra,"Cansaco.");
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
            if((jogarcelular5!=5||encararespelho!=1||dormircama!=1||jogartodosjogos!=6||ler1jogar3!=4||ler3jogatodos!=4||ler3dormir!=3)&&depoisprova==0)
                mvprintw(ybarra+5,xbarra,"Quest: %s",quests[quest]);

            int espelhoy = 3+Yall, espelhox = 63+Xall;
            
            if (espelho==1)
            {
                nodelay(stdscr, FALSE); //pro jogo não continuar rodando ( a chiuva, piscar, o meow, etc)
                pedrapapeltesoura(&cor,&encararespelho);//inicia o minigame
                espelho=0; //zerar isso faz não entrar no minigame infinitdamente
                nodelay(stdscr, TRUE);// faz o jogo voltar a rodar
                erase();
                atividade_sono++;
            }

            if (x >= espelhox - 6 && x <= espelhox + 20 && y < espelhoy + 13 && vira % 2 == 1) {
            
                int reflexx = x; // O reflexo segue o seu X
                int distancia = y - espelhoy;
                int reflexy = (espelhoy + 4) - (distancia / 3);

                if (reflexy < espelhoy + 1) reflexy = espelhoy + 1;
                if (reflexy > espelhoy + 4) reflexy = espelhoy + 4;       
                if (reflexx < espelhox)     reflexx = espelhox;
                if (reflexx > espelhox + 9) reflexx = espelhox + 9;

                if (vira % 2 == 1 && x >= espelhox && x <= espelhox + 7)
                {
                    if (celularpickup == 0 && y == celularY && x >= celularX - 1 && x <= celularX + 1) 
                                        {
                                            mvprintw(Yall+33, Xall+27, "Pegar celular: E");
                                            if (tecla == 'e' || tecla == 'E')   
                                            {celularpickup = 1;}
                                        }
                    int borda1=espelhox,borda2=espelhox+10;
                    if (reflexx >= borda1 && reflexx <= borda2)
                    {
                        if (celularpickup == 1) 
                        {
                            // Se estiver com os olhos abertos
                            if (pisca % 2 == 1) {
                                mvprintw(reflexy, reflexx - 2, "[]%s",faces[selecao_face]);mvprintw(reflexy, reflexx +1,"%s",olhos[selecao_olhos]);
                            } 
                            // Se estiver piscando
                            else {
                                mvprintw(reflexy, reflexx - 2, "[]%s",faces[selecao_face]);mvprintw(reflexy, reflexx +1,"--");
                            }
                        } 
                        else if (revistapickup == 1||livropickup==1) 
                        {
                            if ((pisca % 2 == 1)) {
                                mvprintw(reflexy, reflexx - 3, "[I]%s",faces[selecao_face]);mvprintw(reflexy, reflexx +1,"%s",olhos[selecao_olhos]);
                            } 
                            else {
                                mvprintw(reflexy, reflexx - 3, "[I]%s",faces[selecao_face]);mvprintw(reflexy, reflexx +1,"--");
                            }
                        } 
                        else 
                        {
                            if (pisca % 2 == 1) {
                                mvprintw(reflexy, reflexx, "%s",faces[selecao_face]);mvprintw(reflexy, reflexx+1,"%s",olhos[selecao_olhos]);
                            } 
                            else {
                                mvprintw(reflexy, reflexx, "%s",faces[selecao_face]);mvprintw(reflexy, reflexx+1,"--");
                            }
                        }
                        // Pernas logo abaixo
                        if (passo % 2 == 0) {
                            mvprintw(reflexy + 1, reflexx+1, "%s",pernas[selecao_pernas]);
                        } 
                        else {
                            mvprintw(reflexy + 1, reflexx+1, "%s",pernas[selecao_pernas+1]);
                        }
                    }/*if(passo%2==0)mvprintw(y+1,x+1,"%s",pernas[selecao_pernas]);//perna no passo par
                       else          mvprintw(y+1,x+1,"%s",pernas[selecao_pernas-1])*/
                }
}
            if(cor==1) wattron(stdscr, COLOR_PAIR(11));
            if(cor==1) wattron(stdscr,COLOR_PAIR(2));
                if(y>espelhoy&&y<espelhoy+8&&x>espelhox-2&&x<espelhox+9&&vira%2==1)
                {
                    if(cor==1) wattron(stdscr, COLOR_PAIR(par));
                }
            mvprintw(espelhoy,   espelhox, " ,_,_,_,_,");
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


//if(y>espelhoy&&y<espelhoy+8&&x>espelhox-2&&x<espelhox+9&&vira%2==1)
            if(janelaaberta==0)
            {    
                
               if(cor==1) wattron(stdscr,COLOR_PAIR(2));
                if(interagirJan==1)
                {
                   if(cor==1) wattron(stdscr, COLOR_PAIR(par));
                }
                mvprintw(janelaY,   janelaX, "|\\ _______ /| ");
                mvprintw(janelaY+1, janelaX, "| |       | | ");
                mvprintw(janelaY+2, janelaX, "| |       | | ");
                mvprintw(janelaY+3, janelaX, " \\|       |/  ");
                mvprintw(janelaY+4, janelaX, "  ---------   ");  
                wattroff(stdscr,COLOR_PAIR(2));  
                wattroff(stdscr, COLOR_PAIR(par));

           if(cor==1) wattron(stdscr,COLOR_PAIR(5));
            mvprintw(chuvay+pos, chuvax,  ",;';,,;");
            mvprintw(chuvay+pos2, chuvax, " ';.;.'");
            mvprintw(chuvay+pos3, chuvax, ".,.,'' ");
            wattroff(stdscr,COLOR_PAIR(5));
            if(check%5==0)  
                {pos++; pos2++; pos3++;}
            if(pos>2) {pos=0;} 
            if(pos2>2){pos2=0;} 
            if(pos3>2){pos3=0;}
            }
            else
            {         
                
               if(cor==1) wattron(stdscr,COLOR_PAIR(2));if(interagirJan==1)
                {
                   if(cor==1) wattron(stdscr, COLOR_PAIR(par));
                }  
                mvprintw(janelaY,   janelaX, "   _______    ");
                mvprintw(janelaY+1, janelaX, "  |   |   |   ");
                mvprintw(janelaY+2, janelaX, "  |   |   |   ");
                mvprintw(janelaY+3, janelaX, "  |   |   |   ");
                mvprintw(janelaY+4, janelaX, "  ---------");
                wattroff(stdscr, COLOR_PAIR(par));
                wattroff(stdscr,COLOR_PAIR(2));
            }   
           if(cor==1) wattron(stdscr, COLOR_PAIR(6));
            int mesaY = 8+Yall, mesaX = 74+Xall;
            mvprintw(mesaY,   mesaX, " ____");
            mvprintw(mesaY+1, mesaX, "|    |");
            mvprintw(mesaY+2, mesaX, "|____|");
            mvprintw(mesaY+3, mesaX, " T  T ");
            wattroff(stdscr, COLOR_PAIR(6));

            

            if(celularpickup==0)
                    {
                        if(depoisprova==0)
                        {
                            if(interagirCel==1)
                            {
                            if(cor==1) wattron(stdscr, COLOR_PAIR(par));
                            }
                            if(celularpos==1)
                                mvprintw(celularY,   celularX, "[]");
                            else if(celularpos==2)
                                mvprintw(celularY+1,   celularX, "[]");
                            else if(celularpos==3)
                                mvprintw(celularY+1,   celularX-1, "[]");
                            else if(celularpickup==1)
                            {if(celularpos==0)
                                    mvprintw(celularY,   celularX, " ");}  
                            wattroff(stdscr, COLOR_PAIR(par));
                        }
                    }
                    if(celularpickup==0 && revistapickup==1 && y>celularY -3 && y<celularY + 3 && x >= celularX - 4 && x <= celularX + 4||celularpickup==0 && livropickup==1 && y>celularY -3 && y<celularY + 3 && x >= celularX - 4 && x <= celularX + 4)
                    {
                        mvprintw(Yall+33, Xall+27, "Pegar celular:");
                        mvprintw(Yall+33, Xall+35, "Mao ocupada");
                        mvprintw(Yall+35, Xall+27, "Devolva o item da mao");
                        celularpickup=0;
                    }


            if(maepistola>150)
                maepistoladef=1;
            int portaY = 3+Yall, portaX = 11+Xall;
            
        if(depoisprova==0){
            if(maepistoladef==1)
            {
               if(cor==1) wattron(stdscr,COLOR_PAIR(6));
                mvprintw(portaY+1, portaX+11, "_______");
                mvprintw(portaY+2, portaX+11, "|     |");
                mvprintw(portaY+3, portaX+11, "|     |");
                mvprintw(portaY+4, portaX+11, "|*    |");
                mvprintw(portaY+5, portaX+11, "|     |");
                mvprintw(portaY+6, portaX+11, "I_____I");
                wattroff(stdscr,COLOR_PAIR(6));
            }
            else
            {
               if(cor==1) wattron(stdscr,COLOR_PAIR(6));
                    
                mvprintw(portaY  , portaX+1, "                   ");
                mvprintw(portaY+1, portaX+1, "          _______  ");
                mvprintw(portaY+2, portaX+1, "          |     |\\ ");
                mvprintw(portaY+3, portaX+1, "          |     | |");
                mvprintw(portaY+4, portaX+1, "          |(00) | |");
                mvprintw(portaY+5, portaX+1, "          | ||  |*|");
                mvprintw(portaY+6, portaX+11,           "I_____I |");
                mvprintw(portaY+7, portaX+18,                 "\\|");
                wattroff(stdscr,COLOR_PAIR(6));
                if(maexinga)
                {
                    mvprintw(portaY  , portaX+1, " ________");
                    mvprintw(portaY+1, portaX+1, "|00&!@&@C|");
                    mvprintw(portaY+2, portaX+1, "|________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                }
                    else
                    {
                        mvprintw(portaY  , portaX-1, " __________");
                    mvprintw(portaY+1, portaX-1, "|vai dormir|");
                    mvprintw(portaY+2, portaX-1, "|__________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                    }
            }
        }
        else if(acertos<5&&depoisprova==1)
        {
            if(i==0)
            {
                x=22+Xall, y=10+Yall;
                i++;
            }

            if(maepistoladef==1)
            {
               if(cor==1) wattron(stdscr,COLOR_PAIR(6));
                mvprintw(portaY+1, portaX+11, "_______");
                mvprintw(portaY+2, portaX+11, "|     |");
                mvprintw(portaY+3, portaX+11, "|     |");
                mvprintw(portaY+4, portaX+11, "|*    |");
                mvprintw(portaY+5, portaX+11, "|     |");
                mvprintw(portaY+6, portaX+11, "I_____I");
                wattroff(stdscr,COLOR_PAIR(6));
            }
            else
            {
               if(cor==1) wattron(stdscr,COLOR_PAIR(6));
                    
                mvprintw(portaY  , portaX+1, "                   ");
                mvprintw(portaY+1, portaX+1, "          _______  ");
                mvprintw(portaY+2, portaX+1, "          |     |\\ ");
                mvprintw(portaY+3, portaX+1, "          |     | |");
                mvprintw(portaY+4, portaX+1, "          |(00) | |");
                mvprintw(portaY+5, portaX+1, "          | ||  |*|");
                mvprintw(portaY+6, portaX+11,           "I_____I |");
                mvprintw(portaY+7, portaX+18,                 "\\|");
                wattroff(stdscr,COLOR_PAIR(6));


                if(acertos<2)
                {
                    if(maexinga)
                    {
                    mvprintw(portaY  , portaX+1, " ________________");
                    mvprintw(portaY+1, portaX-3, "|SEU INCOMPETENTE|");
                    mvprintw(portaY+2, portaX-3, "|________________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                    }
                    else
                    {
                    mvprintw(portaY  , portaX+1, " ________");
                    mvprintw(portaY+1, portaX+1, "|00&!@&@C|");
                    mvprintw(portaY+2, portaX+1, "|________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                    }
                }
                else
                    {
                    mvprintw(portaY  , portaX-1, " ___________");
                    mvprintw(portaY+1, portaX-1, "|vai estudar|");
                    mvprintw(portaY+2, portaX-1, "|___________|");
                    mvprintw(portaY+3, portaX+10, "\\  \\/");
                    mvprintw(portaY+4, portaX+12, "(00) ");
                    mvprintw(portaY+5, portaX+13, "||  ");
                    }
            }
        }

            

        int gatoy=armarioY+13, gatox=armarioX+10;
        if(depoisprova==0)
        {
            mvprintw(gatoy,    gatox, "(\\   /)");
            mvprintw(gatoy+ 1, gatox, "(=*.*=)");
            mvprintw(gatoy+ 2, gatox, " (\")(\")_/");

            if(vontadedepisca>=300&&vontadedepisca<=390)
            {
                meow++;
                if(meow>=3&&meow<=4)
                    {mvprintw(gatoy-1,gatox+3, "MEOW");
                    meow=0;}
            }
        }

            
            maepistola++;

           if(cor==1) wattron(stdscr, COLOR_PAIR(9));
            int rodape2y = 10+Yall, rodape2x = 20+Xall;
            for(; rodape2y<31+Yall; rodape2y++)
            {
                if(rodape2y<31+Yall)
                {mvprintw(rodape2y, rodape2x,"|");}
                mvprintw(rodape2y, rodape2x+70,"|");
            }
            wattroff(stdscr, COLOR_PAIR(9));

                       if(cor==1) wattron(stdscr, COLOR_PAIR(6));
        if(armarioaberto==1)
        {
            if(interagirArm==1)
        {
           if(cor==1) wattron(stdscr, COLOR_PAIR(par));
        }
            int armarioY = 14+Yall, armarioX = 19+Xall;

            mvprintw (armarioY+1, armarioX, " |\"\"\"\"|/|");
            mvprintw (armarioY+2, armarioX, " |    | |");
            mvprintw (armarioY+3, armarioX, " |    | |  ");
            mvprintw (armarioY+4, armarioX, " |    |/ ");
            mvprintw (armarioY+5, armarioX, " |\"\"\"\"|  ");
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

            mvprintw (armarioY+1, armarioX, " |\"\"\"\"|");
            mvprintw (armarioY+2, armarioX, " |    |");
            mvprintw (armarioY+3, armarioX, " |    |");
            mvprintw (armarioY+4, armarioX, " |    |]");
            mvprintw (armarioY+5, armarioX, " |\"\"\"\"|");
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
                    abrirlivro(&livro1,&livro2,&livro3);
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
        //MOVIMENTAÇÃO DO GAROTO 
        move(y, x); // move o cursor para a posição x e y, que é onde eu quero que ele fique



                                    /*//++++++++++++++++++++++++++++++++++++++++++SPRITES++++++++++++++++++++++++++++++++++++++++++++//
                                        curs_set(0);
                                    //==========================SEM O CELULAR================================
                                    //-----------------------//OLHANDO PRA FRENTE:
                                    if(celularpickup==0)
                                        if(vira%2==0)
                                        {
                                            if(pisca%2==1)
                                                {mvprintw(y,x,"(oo)");} 
                                            else {mvprintw(y,x,"(--)");}                //printar o rosto
                                            if(passo%2==0)mvprintw(y+1, x+1, "|\\");//perna no passo par
                                            else          mvprintw(y+1, x+1,  "/|");//perna no passo impar
                                        }
                                    //-----------------------//OLHANDO PRA TRÁS:
                                        else if(vira%2==1)       
                                        {   
                                            mvprintw(y,x,"(  )");              //printar o rosto de costar
                                            if(passo%2==0)mvprintw(y+1,x+1, "|\\");//perna no passo par
                                            else          mvprintw(y+1, x+1, "/|");
                                        }


                                    //===========================COM O CELULAR================================
                                    if(celularpickup==1)
                                        if(vira%2==0)
                                        {
                                            if(pisca%2==1)
                                                {mvprintw(y,x,"(oo)[]");} 
                                            else {mvprintw(y,x,"(--)[]");}//printar o rosto
                                            if(passo%2==0)mvprintw(y+1, x+1, "|\\");//perna no passo par
                                            else          mvprintw(y+1, x+1,  "/|");//perna no passo impar
                                        }
                                    //-----------------------//OLHANDO PRA TRÁS:
                                        else if(vira%2==1)       
                                        {   
                                            mvprintw(y,x-2,"[](  )");              //printar o rosto de costar
                                            if(passo%2==0)mvprintw(y+1,x+1, "|\\");//perna no passo par
                                            else          mvprintw(y+1, x+1, "/|");
                                        }


                                    if(revistapickup==1||livropickup==1)
                                        if(vira%2==0)
                                        {
                                            if(pisca%2==1)
                                                {mvprintw(y,x,"(oo)[I]");} 
                                            else {mvprintw(y,x-3,"(--)[I]");}                //printar o rosto
                                            if(passo%2==0)mvprintw(y+1, x+1, "|\\");//perna no passo par
                                            else          mvprintw(y+1, x+1,  "/|");//perna no passo impar
                                        }
                                    //-----------------------//OLHANDO PRA TRÁS:
                                        else if(vira%2==1)       
                                        {   
                                            mvprintw(y,x-3,"[I](  )");              //printar o rosto de costar
                                            if(passo%2==0)mvprintw(y+1,x+1, "|\\");//perna no passo par
                                            else          mvprintw(y+1, x+1, "/|");
                                        }*/













                                    //++++++++++++++++++++++++++++++++++++++++++SPRITES++++++++++++++++++++++++++++++++++++++++++++//
                                        curs_set(0);
                                    //==========================SEM O CELULAR================================
                                    //-----------------------//OLHANDO PRA FRENTE:
                                    if(celularpickup==0)
                                        if(vira%2==0)
                                        {
                                            if(pisca%2==1)
                                                {mvprintw(y,x,"%s",faces[selecao_face]);mvprintw(y,x+1,"%s",olhos[selecao_olhos]);} 
                                            else {mvprintw(y,x,"%s",faces[selecao_face]);mvprintw(y,x+1,"--");}                //printar o rosto
                                            if(passo%2==0)mvprintw(y+1,x+1,"%s",pernas[selecao_pernas]);//perna no passo par
                                            else          mvprintw(y+1,x+1,"%s",pernas[selecao_pernas+1]);//perna no passo impar
                                        }
                                    //-----------------------//OLHANDO PRA TRÁS:
                                        else if(vira%2==1)       
                                        {   
                                            mvprintw(y,x,"%s",faces[selecao_face]);              //printar o rosto de costar
                                            if(passo%2==0)mvprintw(y+1,x+1,"%s",pernas[selecao_pernas]);//perna no passo par
                                            else          mvprintw(y+1,x+1,"%s",pernas[selecao_pernas+1]);
                                        }


                                    //===========================COM O CELULAR================================
                                    if(celularpickup==1)
                                        if(vira%2==0)
                                        {
                                            if(pisca%2==1)
                                                {mvprintw(y,x,"%s[]",faces[selecao_face]);mvprintw(y,x+1,"%s",olhos[selecao_olhos]);} 
                                            else {mvprintw(y,x,"%s[]",faces[selecao_face]);mvprintw(y,x+1,"--");}                //printar o rosto
                                            if(passo%2==0)mvprintw(y+1,x+1,"%s",pernas[selecao_pernas]);//perna no passo par
                                            else          mvprintw(y+1,x+1,"%s",pernas[selecao_pernas+1]);//perna no passo impar
                                        }
                                    //-----------------------//OLHANDO PRA TRÁS:
                                        else if(vira%2==1)       
                                        {   
                                            mvprintw(y,x-2,"[]%s",faces[selecao_face]);                 //printar o rosto de costar
                                            if(passo%2==0)mvprintw(y+1,x+1,"%s",pernas[selecao_pernas]);//perna no passo par
                                            else          mvprintw(y+1,x+1,"%s",pernas[selecao_pernas+1]);
                                        }


                                    if(revistapickup==1||livropickup==1)
                                        if(vira%2==0)
                                        {
                                            if(pisca%2==1)
                                                {mvprintw(y,x,"%s[I]",faces[selecao_face]);mvprintw(y,x+1,"%s",olhos[selecao_olhos]);} 
                                            else {mvprintw(y,x,"%s[I]",faces[selecao_face]);mvprintw(y,x+1,"--");}                //printar o rosto
                                            if(passo%2==0)mvprintw(y+1,x+1,"%s",pernas[selecao_pernas]);//perna no passo par
                                            else          mvprintw(y+1,x+1,"%s",pernas[selecao_pernas+1]);//perna no passo impar
                                        }
                                    //-----------------------//OLHANDO PRA TRÁS:
                                        else if(vira%2==1)       
                                        {   
                                            mvprintw(y,x-3,"[I]%s",faces[selecao_face]);              //printar o rosto de costar
                                            if(passo%2==0)mvprintw(y+1,x+1,"%s",pernas[selecao_pernas]);//perna no passo par
                                            else          mvprintw(y+1,x+1,"%s",pernas[selecao_pernas+1]);
                                        }










                                        //ARMARIO FICAR NA FRENTE DO GAROTO
                                                if(cor==1) wattron(stdscr, COLOR_PAIR(6));
        if(armarioaberto==1)
        {
            if(interagirArm==1)
        {
            if(cor==1) wattron(stdscr, COLOR_PAIR(par));
        }
            int armarioY = 14+Yall, armarioX = 19+Xall;

            mvprintw (armarioY+1, armarioX, " |\"\"\"\"|/|");
            mvprintw (armarioY+2, armarioX, " |    | |");
            mvprintw (armarioY+3, armarioX, " |    | |");
            mvprintw (armarioY+4, armarioX, " |    |");
            mvprintw (armarioY+5, armarioX, " |\"\"\"\"|");
            mvprintw (armarioY+6, armarioX+6, "|\\");
            mvprintw (armarioY+7, armarioX+6, "| |");
            mvprintw (armarioY+8, armarioX+7, "[|");
            mvprintw (armarioY+9, armarioX+7, "\\|");
        }
        else
        {
                if(interagirArm==1)
        {
           if(cor==1) wattron(stdscr, COLOR_PAIR(par));
        }

            mvprintw (armarioY+1, armarioX, " |\"\"\"\"|");
            mvprintw (armarioY+2, armarioX, " |    |");
            mvprintw (armarioY+3, armarioX, " |    |");
            mvprintw (armarioY+4, armarioX, " |    |]");
            mvprintw (armarioY+5, armarioX, " |\"\"\"\"|");
            mvprintw (armarioY+6, armarioX+7, "]");




        }
        wattroff(stdscr, COLOR_PAIR(par));
        wattroff(stdscr, COLOR_PAIR(6));
                    mvprintw(lixoY+1, lixoX, "|###|");
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>MOVIMENTAÇÃO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        tecla = getch();

        switch(tecla){
            case 'a':
                xf--;
                if(xf<20+Xall)
                {xf=20+Xall;}
                passo++; lado=2;//esquerda
                break;
            case 'd':
                xf++;
                if(xf>87+Xall)
                    {xf=87+Xall;}
                passo++; lado=1;//direita
                break;
            case 's':
                yf++;
                if(yf>29+Yall)
                    {yf=29+Yall;}
                passo++; vira=2;//baixo
                break;
            case 'w':
            yf--;
                if(yf<8+Yall)
                    {yf=8+Yall;}
                passo++; vira=1;//cima
                break;
            default:
            break;
        }
    check++;
    if(check>100){check=0;passo=0;}
/*
Móvel   |   (Altura x Largura)   | Xinicio e xfinal | Yinicio e yfinal
--------|------------------------|------------------|----------------------
Cama    | 6 linhas x 9 colunas   | camaX-2 a camaX+8| camaY   a camaY+5
Estante | 7 linhas x 14 colunas  | estX-2  a estX+13| estanteY a estanteY+6
Armário | 10 linhas x 9 colunas  | armX-2  a armX+8 | armarioY a armarioY+9
Mesinha | 4 linhas x 6 colunas   | mesaX-2 a mesaX+5| mesaY   a mesaY+3
Lixo    | 3 linhas x 4 colunas   | lixoX-2 a lixoX+3| lixoY   a lixoY+2
*/


for(int i=camaX-2; i<=camaX+7;i++)
    {
        for(int j=camaY;j<=camaY+3;j++)
        {
            if(xf==i&&yf==j&&(xf-x)!=0) {xf=x;} // se algum indice da matriz cama bater com as coordenadas do garoto por uma mudança no x, o x não altera
            else if(xf==i&&yf==j&&(yf-y)!=0) {yf=y;} // se algum indice bater com a coordenada por uma mudança no y, o y não altera
        }       
    }
    //CAMA
    for(int i=camaX-2; i<=camaX+8;i++)// 
    {
        for(int j=camaY;j<=camaY+3;j++)
        {
            if(xf==i&&yf==j&&(xf-x)!=0) {xf=x;} 
        }       
    }
    //ESTANTE
    for(int i=estanteX-2; i<=estanteX+13;i++)
        {
            for(int j=estanteY;j<=estanteY+4;j++)
            {
                if(xf==i&&yf==j&&(xf-x)!=0) {xf=x;} 
                else if(xf==i&&yf==j&&(yf-y)!=0) {yf=y;} 
            }       
        }
    //ARMARIO
    for(int i=armarioX-2; i<=armarioX+5;i++)
        {
            for(int j=armarioY+5;j<=armarioY+7;j++)
            {
                if(xf==i&&yf==j&&(xf-x)!=0) {xf=x;} 
                else if(xf==i&&yf==j&&(yf-y)!=0) {yf=y;} 
            }       
        }
    //MESA
    for(int i=mesaX-1; i<=mesaX+5;i++)
        {
            for(int j=mesaY;j<=mesaY+1;j++)
            {
                if(xf==i&&yf==j&&(xf-x)!=0) {xf=x;} 
                else if(xf==i&&yf==j&&(yf-y)!=0) {yf=y;} 
            }       
        }
    //LIXO
    for(int i=lixoX-2; i<=lixoX+3;i++)
        {
            for(int j=lixoY+1;j<=lixoY+1;j++)
            {
                if(xf==i&&yf==j&&(xf-x)!=0) {xf=x;} 
                else if(xf==i&&yf==j&&(yf-y)!=0) {yf=y;} 
            }       
        }
    x=xf;y=yf;


    check++;
    if(check > 100) { check = 0; passo = 0; }

//++++++++++++++++++++++++++++++++++++++INTERAÇÃO COM OBJETOS IMOVEIS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//ESPELHO
        if(y>espelhoy&&y<espelhoy+8&&x>espelhox-2&&x<espelhox+9&&vira%2==1)
            {
                mvprintw(Yall+33, Xall+27, "Encarar o espelho: E");
                if(tecla=='e'||tecla=='E')
                    {espelho=1;}
            }
//CAMA
        if(y>camaY&&y<camaY+5&&x>camaX-4&&x<camaX+9)
            {
                interagirCam=1;
                mvprintw(Yall+33, Xall+27, "Dormir: F");
                if(tecla=='f'||tecla=='F')
                    {dormindo=1;}
            }
            else 
                interagirCam=0;

//ARMARIO
        int pertodearmario = (x >= armarioX - 2 && x <= armarioX + 8) &&
                             (y >= armarioY+2 && y <= armarioY + 9);
        if (pertodearmario) 
        {
            if(armarioaberto)
            {
            mvprintw(Yall+33, Xall+27, "Fechar armario: E");
            interagirArm=1;
            }
            else
            {
                mvprintw(Yall+33, Xall+27, "Abrir armario: E");
                interagirArm=1;
            }

            if (tecla == 'e' || tecla == 'E') {
                armarioaberto = !armarioaberto;
            }
        }
        else if(pertodearmario==0)
        {
            interagirArm=0;
        }

//JANELA
    int pertoJanela = (x >= janelaX - 2 && x <= janelaX + 8) &&
                            (y >= janelaY - 1 && y <= janelaY + 5);
        if (pertoJanela) 
        {
            if(janelaaberta)
            {
                interagirJan=1;
            mvprintw(Yall+33, Xall+27, " Abrir janela: E");
            }
            else{
            interagirJan=1;
            mvprintw(Yall+33, Xall+27, " Fechar janela: E");
            }

            if (tecla == 'e' || tecla == 'E') {
                janelaaberta = !janelaaberta;
            }
        }
        else if(pertoJanela==0)
        {
            interagirJan=0;
        }

//CELULAR

    char *jogar[3] = {"cobrinha", "2048", "batalha naval"};
    int escolha=0;
        
        if (celularpickup == 0 && y>celularY -3 && y<celularY + 3 && x >= celularX - 4 && x <= celularX + 4 && revistapickup==0) 
        {
            interagirCel=1;
            if(depoisprova==0)
            mvprintw(Yall+33, Xall+27, "Pegar celular: E");
            else
            mvprintw(Yall+33, Xall+27,"Caramba, ela tirou o celular daqui...");
            
            if ((tecla == 'e' || tecla == 'E')&&depoisprova==0)   
            {celularpickup = 1;}
        }
            else if(celularpickup == 1 && y>celularY -3 && y<celularY + 3 && x >= celularX - 4 && x <= celularX + 4) 
        {
            mvprintw(Yall+33, Xall+27, "Soltar celular: E");
            if (tecla == 'e' || tecla == 'E')   
            {celularpickup = 0;}
            celularpos++;
            if(celularpos>3)
                {celularpos=1;}
        }
        else
            interagirCel=0;

        if(celularpickup==1)
        {
            for(int i = 0; i < 3; i++) 
            {
                if(i==marcar)
              if(cor==1)  attron(A_REVERSE); // Destaca a opção selecionada.if(cor==1) wattron ativa o destaque, wattroff desativa. A_REVERSE é o destaque de inversão de cores.
                mvprintw(celularY +4 +i, celularX+21,"%s", jogar[i]);
                attroff(A_REVERSE);
            }

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
                    if(marcar==0)
                        if(cor==1)
                            {cobra(&cor,&jogarcelular5);atividade_sono++;marcar=0;}


                        if(marcar==1||marcar==2){
                        demo();
                        marcar=0;}
                    break;

            }
        
        wrefresh(stdscr);

//REVISTA
    int pertoRevista = (x >= armarioX - 1 && x <= armarioX + 6) &&
        (y >= armarioY - 1 && y <= armarioY + 7);
        if(armarioaberto)
            if (pertoRevista&&celularpickup==0&&livropickup==0) 
            {
                
                if (revistapickup == 0&&depoisprova==0)
                    mvprintw(Yall+33, Xall+27, " Pegar revista: R");
                else if(revistapickup == 1&&depoisprova==0)
                    mvprintw(Yall+33, Xall+27, "Soltar revista: R");
                else if(revistapickup ==0&&depoisprova==1)
                    mvprintw(Yall+33, Xall+27, "Sumiu ate com a minha revista...");

                if ((tecla == 'r' || tecla == 'R')&&depoisprova==0) {
                    revistapickup = !revistapickup;
                }
            }
            else if(pertoRevista&&celularpickup==1||pertoRevista&&livropickup==1)
            {
                mvprintw(Yall+33, Xall+27, "Pegar revista:");
                mvprintw(Yall+33, Xall+35, "Mao ocupada");
                mvprintw(Yall+35, Xall+27, "Devolva o item da mao");
                revistapickup=0;
            }
        if(revistapickup==1){
            mvprintw(revistay+5+revista_linha,revistax+18+revista_coluna,"%s",revista[marcar]);
            switch(tecla)
            {
                case KEY_RIGHT: 
                    marcar--;
                    revista_coluna+=2;
                    if(revista_coluna>6&&revista_linha==0)revista_coluna=0;
                    else if(revista_linha==1)
                        {if(revista_coluna>6) marcar=0;
                        if(revista_coluna>12) revista_coluna=0;}
                    if(marcar==-1)
                    marcar=5;
                    break;

                case KEY_LEFT: 
                    marcar++;
                    if(marcar>5)
                    marcar=0;
                    break;
                case KEY_DOWN:
                    revista_linha++;
                    if(revista_linha>2) revista_linha=0;
                    break;
                case KEY_UP:
                    if(revista_coluna>=6)revista_linha--;
                    break;

                case '\n':
                    if(marcar==0||marcar)
                        if(cor==1)
                        demo();
                    break;

            }
        }
        }
        /*              
                        mvprintw(revistay+2,    revistax+18, " |-_          __-|  ");
                        mvprintw(revistay+3,    revistax+18, " |  '--__.__-'   |  ");
                        mvprintw(revistay+4,    revistax+18, " |sudoku |palavra|  ");
                        mvprintw(revistay+5,    revistax+18, " | 1 2 3 |cruzada|  ");
                        mvprintw(revistay+6,    revistax+18, " | 4 5 6 |1  2  3|  ");
                        mvprintw(revistay+7,    revistax+18, " |-__    |    __-|  ");
                        mvprintw(revistay+8,    revistax+18, " |-__'-__|__-'__-|  ");
                        mvprintw(revistay+9,   revistax+18, "     '-__|__-'       ");
        */
       
/*)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
        ))))))))))))))))))))))))))))))))))))))
        )))))))))))))))))))))))))))))))))))))))
        ))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
        ))))))))))))))))))))))))))))))))))))))))))))))))))))))))
        ))))))))))))))))))))))))))))))))))))))))))))))))))))))*/
// ==================== MECÂNICA DOS LIVROS ====================
int pertoestante = ((x >= estanteX - 2 && x <= estanteX + 14) && (y >= estanteY - 1 && y <= estanteY + 7));

            if (pertoestante) 
            {
                interagirEst=1;
                // Se o jogador não está segurando nenhum livro na mão, ele pode PEGAR um
                if (livropickup == 0 && celularpickup == 0 && revistapickup == 0) 
                {
                    // --- LIVRO 1 ---
                    if (x >= estanteX - 2 && x <= estanteX + 2) 
                    {
                        mvprintw(Yall+33, Xall+27, " Pegar livro 1: E");
                        if (tecla == 'e' || tecla == 'E') 
                        {
                            livropickup = 1;
                            livro1 = 1;
                            livro2 = 0;
                            livro3 = 0;
                            abrindolivro = 1; // Dispara a transição/função da tela do livro
                        }
                    }
                    // --- LIVRO 2 ---
                    else if (x >= estanteX + 3 && x <= estanteX + 8) 
                    {
                        mvprintw(Yall+33, Xall+27, " Pegar livro 2: E");
                        if (tecla == 'e' || tecla == 'E') 
                        {
                            livropickup = 1;
                            livro1 = 0;
                            livro2 = 1;
                            livro3 = 0;
                            abrindolivro = 1;
                        }
                    }
                    // --- LIVRO 3 ---
                    else if (x >= estanteX + 9 && x <= estanteX + 14) 
                    {
                        mvprintw(Yall+33, Xall+27, " Pegar livro 3: E");
                        if (tecla == 'e' || tecla == 'E') 
                        {
                            livropickup = 1;
                            livro1 = 0;
                            livro2 = 0;
                            livro3 = 1;
                            abrindolivro = 1;
                        }
                    }
                }
                // Se o jogador JÁ ESTÁ segurando um livro, o menu muda para SOLTAR
                else if (livropickup == 1) 
                {
                    mvprintw(Yall+33, Xall+27, "Soltar livro: E");
                    if (tecla == 'e' || tecla == 'E') 
                    {
                        livropickup = 0;
                        livro1 = 0;
                        livro2 = 0;
                        livro3 = 0;
                        abrindolivro = 0;
                    }
                }
            
            else if(celularpickup==1||livropickup==1||revistapickup==1)
            {
                mvprintw(Yall+33, Xall+27, "Pegar livro:");
                mvprintw(Yall+33, Xall+35, "Mao ocupada");
                mvprintw(Yall+35, Xall+27, "Devolva o item da mao");
                livropickup=0;
            }
        }
        else if(pertoestante==0)
        {
            interagirEst=0;
        }

        if(livro1||livro2||livro3)
        {
            mvprintw(Yall+35, Xall+27, "Estudar livro?:R");
            if (tecla == 'r' || tecla == 'R') 
            {
                estudando = 1;
                int cont = 0; // Vai contar o tempo real em milissegundos
                
                nodelay(stdscr, TRUE); 

                while(tecla != 'p' && tecla != 'P')
                {
                    
                    tecla = getch(); // Escuta o teclado instantaneamente a cada frame
                    
                    // --- ANIMAÇÃO DO "ESTUDANDO..." BASEADA NO TEMPO REAL ---
                    // A cada 300ms a gente muda o pontinho na tela sem travar o código
                    mvprintw(LINES-15, COLS-25, "Parar de estudar?: P");
                    if(cont>13000)
                        mvprintw(LINES-15, COLS-27, "Liberta-lo do sofrimento?: P");
                    if ((cont / 300) % 6 == 0)      mvprintw(y-2, x-8, "estudando... ");
                    else if ((cont / 300) % 6 == 1) mvprintw(y-2, x-8, "estudando.. .");
                    else if ((cont / 300) % 6 == 2) mvprintw(y-2, x-8, "estudando. ..");
                    else if ((cont / 300) % 6 == 3) mvprintw(y-2, x-8, "estudando ...");
                    else if ((cont / 300) % 6 == 4) mvprintw(y-2, x-8, "estudando. ..");
                    else                            mvprintw(y-2, x-8, "estudando.. .");

                    // ==================== DIÁLOGOS: LIVRO 1 ====================
                    if(livro1)
                    {
                        if(cont > 5000 && cont <= 15000)
                        {
                            mvprintw(7, 7, "Garoto- isso vai demorar...                              ");
                            mvprintw(9, 7, "eu poderia estar jogando agora                           ");
                        }
                        else if(cont > 15000 && cont <= 30000)
                        {
                            mvprintw(7, 7, "Garoto- quantas paginas tem isso aqui?                   ");
                            mvprintw(8, 7, "nossa, ainda estou em um 1/3...                          ");
                            mvprintw(9, 7, "Eu poderia jogar agora...                                ");
                        }
                        else if(cont > 30000 && cont <= 45000)
                        {
                            mvprintw(7, 7, "Garoto- Aperta \"P\", por favor, isso aqui...            ");
                            mvprintw(8, 7, "isso aqui e um saco, silogismo... to so na metade        ");
                            mvprintw(9, 7, "Eu nao quero fazer diagrama de Venn...                   ");
                            refresh();
                        }
                        else if(cont > 45000 && cont <= 60000)
                        {
                            mvprintw(7, 7, "Garoto- Nao vou falar mais nada nao, seu...              ");
                            mvprintw(8, 7, "SEU BOBOCA!!! EH, BOBOCA, voce nao me deixa              ");
                            mvprintw(9, 7, "saiiiiir, eu quero jogar =(, nao ver equacoes            ");
                        }
                    }
                    // ==================== DIÁLOGOS: LIVRO 2 ====================
                    else if(livro2)
                    {
                        if(cont > 5000 && cont <= 15000)
                        {
                            mvprintw(7, 7, "Garoto- Geometria? Serio mesmo?                          ");
                            mvprintw(8, 7, "Pra que eu quero saber o tamanho de um poligono?         ");
                        }
                        else if(cont > 15000 && cont <= 30000)
                        {
                            mvprintw(7, 7, "Garoto- 'Calcule a area da figura hachurada...'          ");
                            mvprintw(8, 7, "Isso aqui parece um labirinto bizarro!                   ");
                            mvprintw(9, 7, "Minha cabeca ta comecando a doer...                      ");
                        }
                        else if(cont > 30000 && cont <= 45000)
                        {
                            mvprintw(7, 7, "Garoto- Ei, voce ai controlando o teclado...              ");
                            mvprintw(8, 7, "Se eu ver mais um triangulo retangulo na minha frente    ");
                            mvprintw(9, 7, "eu vou quebrar esse terminal, juro por Deus!             ");
                        }
                        else if(cont > 45000 && cont <= 60000)
                        {
                            mvprintw(7, 7, "Garoto- Cateto oposto, hipotenusa, blablabla...          ");
                            mvprintw(8, 7, "Corta essa! Me deixa voltar pro celular!                 ");
                            mvprintw(9, 7, "Voce gosta de me ver sofrer, e isso?                     ");
                        }
                    }
                    // ==================== DIÁLOGOS: LIVRO 3 ====================
                    else if(livro3)
                    {
                        if(cont > 5000 && cont <= 15000)
                        {
                            mvprintw(7, 7, "Garoto- Ah nao, algebra linear...                        ");
                            mvprintw(8, 7, "Matrizes 5x5 cheias de zeros e uns. Que tédio.           ");
                        }
                        else if(cont > 15000 && cont <= 30000)
                        {
                            mvprintw(7, 7, "Garoto- 'Um algoritmo deterministico...'                 ");
                            mvprintw(8, 7, "Eu sou um personagem de um jogo em C, sabia?             ");
                            mvprintw(9, 7, "Estudar programacao dentro de um programa e meta demais. ");
                        }
                        else if(cont > 30000 && cont <= 45000)
                        {
                            mvprintw(7, 7, "Garoto- Querido jogador introspectivo...                 ");
                            mvprintw(8, 7, "A essa altura, a cobrinha do celular parece              ");
                            mvprintw(9, 7, "a oitava maravilha do mundo moderno. Larga o 'R'!        ");
                        }
                        else if(cont > 45000 && cont <= 60000)
                        {
                            mvprintw(7, 7, "Garoto- Se eu nao passar nessa prova amanha...           ");
                            mvprintw(8, 7, "A culpa vai ser inteiramente sua e desse loop...         ");
                            mvprintw(9, 7, "Aperta 'P' e finge que a gente leu tudo! Vai!            ");
                        }
                    }
                        

                    // --- BLOCOS FINAIS COMUNS ---
                    if(cont > 60000 && cont <= 75000)
                    {
                        mvprintw(7, 7, "Garoto- ...                                              ");
                        mvprintw(8, 7, "                                                         ");
                        mvprintw(9, 7, "                                                         ");
                    }
                    else if(cont > 75000)
                    {
                        mvprintw(7, 7, "Garoto- FINALMENTE!!!                                    ");
                        refresh();
                        napms(1500);
                        estudo++;
                        atividade_sono++;
                        break;
                    }

                    refresh();
                    napms(50);

                    cont += 1000; // O que faz o tempo do estudo rodar, se deixar mais rapido ele estuda mais rápido ( padrao 50)

                }

                // Ao sair do estudo (seja por terminar ou por apertar P), limpa as linhas de diálogo
                mvprintw(5, 10, "                                                         ");
                mvprintw(6, 10, "                                                         ");
                mvprintw(7, 10, "                                                         ");
                mvprintw(y-2, x-8, "              ");
                refresh();
            }
            
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    refresh();

    clock_t frame_end = clock(); // mede o tempo no final do loop de jogo
    double elapsed_ms = (double)(frame_end - frame_start) * 1000.0 / CLOCKS_PER_SEC; // tempo gasto no frame em milissegundos
    int sleep_ms = (int)(TARGET_FRAME_MS - elapsed_ms); // tempo restante até o frame ideal
    if (sleep_ms > 0) {
        napms(sleep_ms); // espera só o tempo necessário para completar o frame
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    nodelay(stdscr, TRUE);
    if(atividade_sono>5)
    {
        iniciar=0;
        break;
    }
    if(dormindo==1)
    {
        iniciar=0;
        break;
    }
    if(tecla=='q')
    {
        fechar=1;
        break;
    }
    }//while jogo
    

if(fechar==1)
{
    break;
}

    if(iniciar==0)
    {
        break;
    }
    else
    {

        mvprintw(7, 7, "Fechando o jogo");
        refresh();
        iniciar=1;
        napms(1000);
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



}//menu
if(depoisprova==0)
{
    if(atividade_sono>5&&estudo>=3)// se ele não dormiu mas estudou ele faz a prova cansado e sabendo (prova cansado simples)
    {
        
        cair_no_sono();
        dialogoprovacs();
        prova_cansado_simples(&cor,&acertos);
    }

    if (atividade_sono<=5&&estudo>=3)// se ele dormiu e estudou ele faz a prova descansado e sabendo (prova simples)
    {
        dormir();
        dialogoprovas();
        prova_simples(&cor,&acertos);
    }

    if (atividade_sono>5&&estudo<3)//se ele nao dormiu e não estudou ele faz a prova descansado e burro  (prova cansado complexa)
    {
        cair_no_sono();
        dialogoprovacc();
        prova_cansado_complexa(&cor,&acertos);
    }
    if (atividade_sono<=5&&estudo<3)// se ele dormiu mas não estudou ele faz a prova descansado e burro (prova complexa)
    {
        
        dormir();
        dialogoprovac();
        prova_complexa(&cor,&acertos);
    }
}
//ATO III?

dialogodepoisprova(&acertos,&maexinga,&epilepsia);

if(acertos<5&&depoisprova==0)
{
    depoisprova=1;
}
else
{
    if(dialogofinal(&finais_alcancados))// isso daqui que vai virar a struct que a gente rpecisa botar no arquivo binário do jogo, o save.
    // então, a gente bota tudo isso numa struct, da om ctrl +shift +l bota o nome da struct antes de todas essas variaveis do save. 
    // tipo save.ativida_desono
    //save.atividade_sono=0;
    //save.celularpickup=0;
    //save.livropickup=0;
    //save.revistapickup=0;
    //save.maepistola=0;
    //save.maepistoladef=0;
    //save.janelaaberta=0;
    //save.depoisprova=0;
    // e ai a gente só recarrega a struct com tudo, e a gente pode fazer 3 saves e salvar um sprite do momento tbm,
    //um vetor de caracteres com uma imagem pequena ao redor do jogador que mostre o ponto do save que ele ta pra botar na pasta.
    {

        atividade_sono=0;
        celularpickup=0;
        livropickup=0;
        revistapickup=0;
        maepistola=0;
        maepistoladef=0;
        janelaaberta=0;
        depoisprova=0;
        //zerar todas as variáveis que precisam ser zeradas, voltar elas para o valor inicial( se voce achar mais alguma bota ela aqui)
    }
    else
    {
    break;
    }
}

}//while do menu
    demo();
    napms(3000);
    endwin();// fecha a janela
    return 0;
}
