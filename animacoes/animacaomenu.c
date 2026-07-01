#include"jogos.h"

void animacaomenu(int yselecao,int xselecao)
{
    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
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
wrefresh(stdscr);

        mvprintw(yselecao+20,xselecao-8,"JOGAR");
        mvprintw(yselecao+20+2,xselecao-8,"OPCOES");
        mvprintw(yselecao+20+4,xselecao-8,"CREDITOS");
        mvprintw(yselecao+20+6,xselecao-8,"CUSTOMIZACAO");
        mvprintw(yselecao+20+8,xselecao-8,"SAIR");
   int altura=1;
    int passo=0;
    int lugar=-3;
    int espacamento=0; 
    int tecla;
    int parar=0;

for(int i=0;i<4&&parar==0;i++,passo++)
{   
    tecla=getch();
    if(tecla=='\n') { nodelay(stdscr, FALSE); parar=1;}
    mvprintw(yselecao+5, xselecao+47, "                                  ");
    mvprintw(yselecao+5+1, xselecao+47, "                                  ");
    mvprintw(yselecao+5+2, xselecao+47, "                                  ");
    mvprintw(yselecao+5+3, xselecao+47, "                                  ");
    mvprintw(yselecao+5+4, xselecao+47, "                                  ");
    mvprintw(yselecao+5+5, xselecao+47, "                                  ");
    mvprintw(yselecao+5+6, xselecao+47, "                                  ");
    mvprintw(yselecao+5+7, xselecao+47, "                                  ");
    mvprintw(yselecao+5+8, xselecao+47, "                                  ");
    mvprintw(yselecao+5+9, xselecao+47, "                                  ");
    
    if(passo%2==0&&parar==0)
    {
        lugar+=3;
        altura=lugar;
    mvprintw(yselecao+5+altura++, xselecao+47, "    ..                     ..     ");
    mvprintw(yselecao+5+altura++, xselecao+47, "  pd' .g8\"\"8q.     .g8\"\"8q. `bq   ");
    mvprintw(yselecao+5+altura++, xselecao+47, " 6P .dP'    `YM. .dP'    `YM. YA  ");
    mvprintw(yselecao+5+altura++, xselecao+47, "6M' dM'      `MM dM'      `MM `Mb ");
    mvprintw(yselecao+5+altura++, xselecao+47, "MN  MM        MM MM        MM  8M ");
    mvprintw(yselecao+5+altura++, xselecao+47, "MN  MM.      ,MP MM.      ,MP  8M ");
    mvprintw(yselecao+5+altura++, xselecao+47, "YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ");
    mvprintw(yselecao+5+altura++, xselecao+47, " Mb   `\"bmmd\"'     `\"bmmd\"'   dM  ");
    mvprintw(yselecao+5+altura++, xselecao+47, "  Yq.                       .pY   ");
    mvprintw(yselecao+5+altura++, xselecao+47, "    ``                     ''     ");
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM    VM              ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM     MA             ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM     `M.            ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM       MA           ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM       `M.          ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM        VM          ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM         MA         ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM         `M.        ");        
    mvprintw(yselecao+5+altura++, xselecao+47, "            MM          VM        "); 
    }
    else if(passo%2!=0&&parar==0)
    {
        lugar+=3;
        altura=lugar;
    mvprintw(yselecao+5+altura++, xselecao+47, "    ..                     ..     ");
    mvprintw(yselecao+5+altura++, xselecao+47, "  pd' .g8\"\"8q.     .g8\"\"8q. `bq   ");
    mvprintw(yselecao+5+altura++, xselecao+47, " 6P .dP'    `YM. .dP'    `YM. YA  ");
    mvprintw(yselecao+5+altura++, xselecao+47, "6M' dM'      `MM dM'      `MM `Mb ");
    mvprintw(yselecao+5+altura++, xselecao+47, "MN  MM        MM MM        MM  8M ");
    mvprintw(yselecao+5+altura++, xselecao+47, "MN  MM.      ,MP MM.      ,MP  8M ");
    mvprintw(yselecao+5+altura++, xselecao+47, "YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ");
    mvprintw(yselecao+5+altura++, xselecao+47, " Mb   `\"bmmd\"'     `\"bmmd\"'   dM  ");
    mvprintw(yselecao+5+altura++, xselecao+47, "  Yq.                       .pY   ");
    mvprintw(yselecao+5+altura++, xselecao+47, "    ``                     ''     ");    
    mvprintw(yselecao+5+altura++, xselecao+47, "             AW    MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "            ,M'    MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "            MV     MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "           AW      MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "          ,M'      MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "          MV       MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "         AW        MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "        ,M'        MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "        MV         MM             ");
    mvprintw(yselecao+5+altura++, xselecao+47, "       AW          MM             ");
    }
    refresh();
    napms(200);
}            

for(int i=0;i<10&&parar==0;i++,passo++)

{   tecla=getch(); 
    
    if(tecla=='\n') { nodelay(stdscr, FALSE); parar=1;}
    for(int apaga = 0; apaga < 20; apaga++) {
        mvprintw(yselecao + 5 + lugar + apaga, xselecao + espacamento + 47, "                                      ");
    }
    if(i==9)
    {altura++;}
    if(passo%2==0&&parar==0)
    {
        espacamento+=10; 
        altura=lugar;
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ..                     ..     ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  pd' .g8\"\"8q.     .g8\"\"8q. `bq   ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " 6P .dP'    `YM. .dP'    `YM. YA  ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "6M' dM'      `MM dM'      `MM `Mb ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN  MM        MM MM        MM  8M ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN  MM.      ,MP MM.      ,MP  8M ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " Mb   `\"bmmd\"'     `\"bmmd\"'   dM  ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  Yq.                       .pY   ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ``                     ''     ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM    VM              ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM     MA             ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM     `M.            ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM      VM            ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM       MA           ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM       `M.          ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM        VM          ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM         MA         ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM         `M.        ");        
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MM          VM        "); 
    }
    else if(passo%2!=0&&parar==0)
    {
        espacamento+=10; 
        altura=lugar;
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ..                     ..     ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  pd' .g8\"\"8q.     .g8\"\"8q. `bq   ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " 6P .dP'    `YM. .dP'    `YM. YA  ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "6M' dM'      `MM dM'      `MM `Mb ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN  MM        MM MM        MM  8M ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "MN  MM.      ,MP MM.      ,MP  8M ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "YM. `Mb.    ,dP' `Mb.    ,dP' ,M9 ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, " Mb   `\"bmmd\"'     `\"bmmd\"'   dM  ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "  Yq.                       .pY   ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "    ``                     ''     ");    
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "             AW    MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            ,M'    MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "            MV     MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "           AW      MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "          ,M'      MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "          MV       MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "         AW        MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "        ,M'        MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "        MV         MM             ");
    mvprintw(yselecao+5+altura++, xselecao+espacamento+47, "       AW          MM             ");
    }



    mvprintw(yselecao+12, COLS-34, "                                  ");
    mvprintw(yselecao+12+1, COLS-34, "                                  ");
    mvprintw(yselecao+12+2, COLS-34, "                                  ");
    mvprintw(yselecao+12+3, COLS-34, "                                  ");
    mvprintw(yselecao+12+4, COLS-34, "                                  ");
    mvprintw(yselecao+12+5, COLS-34, "                                  ");
    mvprintw(yselecao+12+6, COLS-34, "                                  ");
    mvprintw(yselecao+12+7, COLS-34, "                                  ");
    mvprintw(yselecao+12+8, COLS-34, "                                  ");
    mvprintw(yselecao+12+9, COLS-34, "                                  ");
    mvprintw(yselecao+12+10, COLS-34, "                                  ");
    mvprintw(yselecao+12+11, COLS-34, "                                  ");
    mvprintw(yselecao+12+12, COLS-34, "                                  ");
    mvprintw(yselecao+12+13, COLS-34, "                                  ");
    mvprintw(yselecao+12+14, COLS-34, "                                  ");
    mvprintw(yselecao+12+15, COLS-34, "                                  ");
    mvprintw(yselecao+12+16, COLS-34, "                                  ");
    mvprintw(yselecao+12+17, COLS-34, "                                  ");
    mvprintw(yselecao+12+18, COLS-34, "                                  ");
    mvprintw(yselecao+12+19, COLS-34, "                                  ");
    mvprintw(yselecao+12+20, COLS-34, "                                  ");
    mvprintw(yselecao+12+21, COLS-34, "                                  ");
    mvprintw(yselecao+12+22, COLS-34, "                                  ");
    mvprintw(yselecao+12+23, COLS-34, "                                  ");
    mvprintw(yselecao+12+24, COLS-34, "                                  ");
    mvprintw(yselecao+12+25, COLS-34, "                                  ");
    mvprintw(yselecao+12+26, COLS-34, "                                  ");
    if(espacamento>=COLS-34&&parar==0)
    {espacamento=COLS-64;}

    mvprintw(yselecao+12+3, 0, "                                  ");
    mvprintw(yselecao+12+4, 0, "                                  ");
    mvprintw(yselecao+12+5, 0, "                                  ");
    mvprintw(yselecao+12+6, 0, "                                  ");
    mvprintw(yselecao+12+7, 0, "                                  ");
    mvprintw(yselecao+12+8, 0, "                                  ");
    mvprintw(yselecao+12+9, 0, "                                  ");
    mvprintw(yselecao+12+10, 0, "                                  ");
    mvprintw(yselecao+12+11, 0, "                                  ");
    mvprintw(yselecao+12+12, 0, "                                  ");
    mvprintw(yselecao+12+13, 0, "                                  ");
    mvprintw(yselecao+12+14, 0, "                                  ");
    mvprintw(yselecao+12+15, 0, "                                  ");
    mvprintw(yselecao+12+16, 0, "                                  ");
    mvprintw(yselecao+12+17, 0, "                                  ");
    mvprintw(yselecao+12+18, 0, "                                  ");
    mvprintw(yselecao+12+19, 0, "                                  ");
    mvprintw(yselecao+12+20, 0, "                                  ");
    mvprintw(yselecao+12+21, 0, "                                  ");
    mvprintw(yselecao+12+22, 0, "                                  ");
    mvprintw(yselecao+12+23, 0, "                                  ");
    mvprintw(yselecao+12+24, 0, "                                  ");
    mvprintw(yselecao+12+25, 0, "                                  ");
        

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
    mvprintw(yselecao+5, xselecao+47, "                                  ");
    mvprintw(yselecao+5+1, xselecao+47, "                                  ");
    mvprintw(yselecao+5+2, xselecao+47, "                                  ");
    mvprintw(yselecao+5+3, xselecao+47, "                                  ");
    mvprintw(yselecao+5+4, xselecao+47, "                                  ");
    mvprintw(yselecao+5+5, xselecao+47, "                                  ");
    mvprintw(yselecao+5+6, xselecao+47, "                                  ");
    mvprintw(yselecao+5+7, xselecao+47, "                                  ");
    mvprintw(yselecao+5+8, xselecao+47, "                                  ");
    mvprintw(yselecao+5+9, xselecao+47, "                                  ");
    refresh();
    napms(200);
}            
int andar=0;
for(int i=0;i<xselecao-13&&parar==0;i++,passo++)
{   tecla=getch();
       if(tecla=='\n') { nodelay(stdscr, FALSE); parar=1;}
    andar++;
    if(passo%2==0&&parar==0)
    {
        mvprintw(yselecao+20,andar, " (oo)");
        mvprintw(yselecao+21,andar, "  |\\");
    }
    else if(passo%2!=0&&parar==0)
    {
        mvprintw(yselecao+20,andar, " (oo)");
        mvprintw(yselecao+21,andar, "  /|");
    }
    
    
    wrefresh(stdscr);
    napms(25);
}
nodelay(stdscr,FALSE);
}