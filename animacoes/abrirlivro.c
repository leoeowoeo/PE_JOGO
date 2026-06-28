#include <ncurses.h>
#include "jogos.h"
void abrirlivro(int *livro1,int *livro2,int *livro3)// a função roda os sprites do livro N abrindo
{
        curs_set(0); // guia foca

        keypad(stdscr, TRUE);
        int Xall=(COLS/2)-40, Yall=3;
        int livroY = Yall+8, livroX = Xall+35;
        int ganhou=0;
if(*livro1==1&&*livro2==0&&*livro3==0){
            mvwprintw(stdscr, livroY++,     livroX-20,"     ______ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    /     /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"   /     / |");
            mvwprintw(stdscr, livroY++,     livroX-20,"  /     /  |"); 
            mvwprintw(stdscr, livroY++,     livroX-20," /_____/   |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fund |  , |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da   | /| |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat. |  | |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|elem-|  | |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|entar|  | |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  1  |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |   /" );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |  /"  );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     | /"   );
            mvwprintw(stdscr, livroY++,     livroX-20,"|_____|/"    );
            wrefresh(stdscr);
            napms(60);

            
            
                livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-11,                  "____ ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"       ,-'  ,-|");
                    mvwprintw(stdscr, livroY++,     livroX-20,"   _,-'_,--'  |");
                    mvwprintw(stdscr, livroY++,     livroX-20,",-'_,-'       |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|fun|         |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|da |    ,    |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|mat|   /|    |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ele|    |    |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ent|    |    |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"| 1 |    |    |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |       ,-'");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |    ,-'   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|___| ,-'      ");
            wrefresh(stdscr);   


                    
                livroY = 8+Yall;
            
            napms(105);
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"              __,,");
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___,--'''__,|");
            mvwprintw(stdscr, livroY++,     livroX-20,"_,--'___---'''   |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fun|            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da |     _,     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat|    / |     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ele|      |     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ent|      |     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"| 1 |      |     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |           _|");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |    __,--''  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___|,--'         ");
            wrefresh(stdscr);
            napms(105);



                livroY = 8+Yall;
                werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|        _,          |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      -' |          |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         |          |");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|         |          |");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|         |          |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|");
            wrefresh(stdscr);
            napms(105);



                livroY = 8+Yall;
                werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ''---..,_,.-=:;|");   
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     ,      ||||||||");            
            mvwprintw(stdscr, livroY++,     livroX-20,"|    /|      ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |      ||||||||");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |      ||||||||");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |      ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___         ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"    ''---..,|;:-=\"' ");
            wrefresh(stdscr);
            napms(55);


            
                livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|''-=::;;_'','.\"',:;|");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   ,     || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  /|     || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |     || |||  ||| ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |     || |||  ||| ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |     || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|_        ||,|||,_||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"''-=:..,_'' ;:'  ''   ");
            wrefresh(stdscr);
            napms(55);
            

            
            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___________________ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,'-,'-, '--,,'-, |");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   '-,'-,'-,  | || |");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |");
            mvwprintw(stdscr, livroY++,     livroX-20,"    | ,   || | ||  | || |");
            mvwprintw(stdscr, livroY++,     livroX-20,"    | |   || | ||  | || |");
            mvwprintw(stdscr, livroY++,     livroX-20,"    | |   || | ||  | || |");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"    | |   || | ||  | || |");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    | |   || | ||  | || |");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||._|_||_|");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,   ||_|_||'-,:'' '");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,; -',;'           ");
            wrefresh(stdscr);
            napms(105);


            
            livroY = 8+Yall;
            werase(stdscr);

            mvwprintw(stdscr, livroY++,     livroX-20,"          ___,____________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20," ___---'''__,|                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|_,,--''''   |                    |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");     
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");         
            mvwprintw(stdscr, livroY++,     livroX-20,"|||         _|____________________|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||  __,--''                         ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|,--'                                ");
            wrefresh(stdscr);
            napms(105);  


            
            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________ ____________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");      
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|____________________|  ");
            wrefresh(stdscr);
            livroY = 8+Yall;
            napms(100);
}
if(*livro1==0&&*livro2==1&&*livro3==0){
    werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"     ______ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    /     /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"   /     / |");
            mvwprintw(stdscr, livroY++,     livroX-20,"  /     /  |"); 
            mvwprintw(stdscr, livroY++,     livroX-20," /_____/   |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fund.|  _ |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da   | / '|"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat. |'  ||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|elem-| .' |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|entar| | /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  2  | |/ |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |   /" );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |  /"  );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     | /"   );
            mvwprintw(stdscr, livroY++,     livroX-20,"|_____|/"    );
            wrefresh(stdscr);
            napms(60);



            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-10,                   "____  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"       ,-'  ,-|  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"   _,-'_,--'  |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,",-'_,-'       |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|fun|  ,--,   |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|da | '    |  |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|mat|     ,/  |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ele|    /    |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ent|   /   , |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"| 2 |  /,--'  |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |       ,-'  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |    ,-'     ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|___| ,-'        ");
            wrefresh(stdscr);   


            livroY = 8+Yall;
            napms(105);
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"              __,,");
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___,--'''__,|");
            mvwprintw(stdscr, livroY++,     livroX-20,"_,--'___---'''   |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fun|            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da |   ,--,     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat|  '    |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ele|      ,/    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ent|     /      |");
            mvwprintw(stdscr, livroY++,     livroX-20,"| 1 |    /   ,   |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |   /,--'    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |           _|");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |    __,--''  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___|,--'         ");
            wrefresh(stdscr);
            napms(105); // Espera 2 segundos



                    
            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|       ,-'''-.      |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      '       |     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ,-'     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|          ,-'       |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|        ,-          |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|       /_______     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|");
            wrefresh(stdscr);
            napms(105);
            

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________     ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ''---..,_,.-=:;|    ");   
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   .,       ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  /   \\    ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      ,     ||||||||    ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ,'      ||||||||    ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|  .'___     ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___         ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    ''---..,|;:-=\"'     ");
            wrefresh(stdscr);
            napms(55);




            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|''-=::;;_'','.\"',:| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  ,.-,   || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"| '    |  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      /  || |||  ||| ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|   ,-'   || |||  ||| ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|  /____  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|_        ||,|||,_||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"''-=:..,_'' ;:'  ''   ");
            wrefresh(stdscr);
            napms(55);
            
            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,'-,'-, '--,,'-, |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   '-,'-,'-,  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    | ,-. || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |    ||| | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   ,'|| | ||  | || |  ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"    | ,'  || | ||  | || |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |',,._|| | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||._|_||_|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,.,.||_|_||'-,:'' '  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,; -',;'             ");
            wrefresh(stdscr);
            napms(105);

            livroY = 8+Yall;
            werase(stdscr);

            mvwprintw(stdscr, livroY++,     livroX-20,"          ___,____________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20," ___---'''__,|                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|_,,--''''   |                    |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");     
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");         
            mvwprintw(stdscr, livroY++,     livroX-20,"|||         _|____________________|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||  __,--''                         ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|,--'                                ");
            wrefresh(stdscr);
            napms(105);  

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________ ____________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");      
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|____________________|  ");
            wrefresh(stdscr);
            livroY = 8+Yall;
            napms(100);
}
if(*livro1==0&&*livro2==0&&*livro3==1){
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"     ______ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    /     /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"   /     / |");
            mvwprintw(stdscr, livroY++,     livroX-20,"  /     /  |"); 
            mvwprintw(stdscr, livroY++,     livroX-20," /_____/   |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fund.|    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da   |    |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat. |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|elem-|    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|entar|    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  3  |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |   /" );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |  /"  );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     | /"   );
            mvwprintw(stdscr, livroY++,     livroX-20,"|_____|/"    );
            wrefresh(stdscr);
            napms(60);

            
            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-10,          "____  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"       ,-'  ,-|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"   _,-'_,--'  |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,",-'_,-'       |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |     _,  |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fun|  ,-'  | |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da |      _| |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat|   ,-' | |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ele|      _| |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ent|   ,-'   |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"| 3 |         |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |       ,-'  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |    ,-'     ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___| ,-'        ");
            wrefresh(stdscr);  
            
            

            livroY = 8+Yall;
            napms(105);
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"              __,,");
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___,--'''__,|");
            mvwprintw(stdscr, livroY++,     livroX-20,"_,--'___---'''   |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fun|            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da |    _--.-   |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat|         |  | ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ele|     __--|  |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ent|         |  | ");
            mvwprintw(stdscr, livroY++,     livroX-20,"| 3 |     __--'  |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |           _|");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |    __,--''  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___|,--'         ");
            wrefresh(stdscr);
            napms(105); 

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|       ----.        |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            |       |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|        ----'       |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            |       |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|       ----'        |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|");
            wrefresh(stdscr);
            napms(105);
            
            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________     ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ''---..,_,.-=:;|    ");   
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   '---.    ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|        |   ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|    '--,;   ||||||||    ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|        |   ||||||||    ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|   '--,.|   ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___         ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    ''---..,|;:-=\"'     ");
            wrefresh(stdscr);
            napms(55);

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|''-=::;;_'','.\"',:| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  '-,.   || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      |  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  '-,.|  || |||  ||| ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|      |  || |||  ||| ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|  '-,.'  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|_        ||,|||,_||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"''-=:..,_'' ;:'  ''   ");
            wrefresh(stdscr);
            napms(55);
            
            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,'-,'-, '--,,'-, |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   '-,'-,'-,  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,  || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   | || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,' || | ||  | || |  ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   | || | ||  | || |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,| || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||._|_||_|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,.,.||_|_||'-,:'' '  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,; -',;'             ");
            wrefresh(stdscr);
            napms(105);

            livroY = 8+Yall;
            werase(stdscr);

            mvwprintw(stdscr, livroY++,     livroX-20,"          ___,____________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20," ___---'''__,|                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|_,,--''''   |                    |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");     
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");         
            mvwprintw(stdscr, livroY++,     livroX-20,"|||         _|____________________|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||  __,--''                         ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|,--'                                ");
            wrefresh(stdscr);
            napms(105);  

            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________ ____________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");      
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|____________________|  ");
            wrefresh(stdscr);
            livroY = 8+Yall;
            napms(100);
}
}
/*          mvwprintw(stdscr, livroY,       livroX," ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1,     livroX,"|CAPITULO I:EQUACOES |CAPITULO II:Silogismo|");    
            mvwprintw(stdscr, livroY+2,     livroX,"|Exemplo Pratico     |Diagramas de         |");
            mvwprintw(stdscr, livroY+3,     livroX,"|de Isolamento:      |Conjuntos(Venn):     |");
            mvwprintw(stdscr, livroY+4,     livroX,"|Seja a equacao      |Se todo elemento de  |");
            mvwprintw(stdscr, livroY+5,     livroX,"|Ax - B = Cx + D     |A esta em B, e alguns|");
            mvwprintw(stdscr, livroY+6,     livroX,"|1)Isola os termos   |elementos de B estao |");      
            mvwprintw(stdscr, livroY+7,     livroX,"|com 'x':            |em C,nao se pode     |");
            mvwprintw(stdscr, livroY+8,     livroX,"|Ax - Cx = D + B     |afirmar que todo ou  |");
            mvwprintw(stdscr, livroY+9,     livroX,"|2)Evidencie x:      |nenhum elemento de A |");
            mvwprintw(stdscr, livroY+10,    livroX,"|x * (A - C) = D + B |está em C            |");
            mvwprintw(stdscr, livroY+10,    livroX,"| x = (D + B)/(A - C)|                     |");
            mvwprintw(stdscr, livroY+12,    livroX,"|____________________|_____________________|"); 
*/
/*          mvwprintw(stdscr, livroY,       livroX," ____________________ _____________________ ");
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
*/
/*          mvwprintw(stdscr, livroY,        livroX," ____________________ _____________________ ");
            mvwprintw(stdscr, livroY+1,      livroX,"|CAPITULO V:GRAFICOS |                     |");    
            mvwprintw(stdscr, livroY+2,      livroX,"|O pico de um grafico|  Morte de golfinhos |");
            mvwprintw(stdscr, livroY+3,      livroX,"|pode ser visualemnte|  no Atlantico       |");
            mvwprintw(stdscr, livroY+4,      livroX,"|percebido, bem como |                     |");
            mvwprintw(stdscr, livroY+5,      livroX,"|em que momento,que  |500 |          /\\   |");
            mvwprintw(stdscr, livroY+6,      livroX,"|eh normalmente o    |90  |    /\\   /  \\ |");      
            mvwprintw(stdscr, livroY+7,      livroX,"|eixo X, esse pico   |0   +----+----+----+ |");
            mvwprintw(stdscr, livroY+8,      livroX,"|foi alcançado.      |     T1   T2   T3    |");
            mvwprintw(stdscr, livroY+9,      livroX,"|                    |                     |");
            mvwprintw(stdscr, livroY+10,     livroX,"|                    | Pico:T3             |");
            mvwprintw(stdscr, livroY+11,     livroX,"|                    |                     |");
            mvwprintw(stdscr, livroY+12,     livroX,"|____________________|_____________________|");





            
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20,"     ______ ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    /     /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"   /     / |");
            mvwprintw(stdscr, livroY++,     livroX-20,"  /     /  |"); 
            mvwprintw(stdscr, livroY++,     livroX-20," /_____/   |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fund.|  _ |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da   | / '|"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat. |'  ||");
            mvwprintw(stdscr, livroY++,     livroX-20,"|elem-| .' |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|entar| | /|");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  2  | |/ | ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |    |");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |   /" );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     |  /"  );
            mvwprintw(stdscr, livroY++,     livroX-20,"|     | /"   );
            mvwprintw(stdscr, livroY++,     livroX-20,"|_____|/"    );
            wrefresh(stdscr);
            napms(60);



            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-20,                  "____");
                    mvwprintw(stdscr, livroY++,     livroX-20,"       ,-'  ,-|  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"   _,-'_,--'  |");
                    mvwprintw(stdscr, livroY++,     livroX-20,",-'_,-'       |");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|fun|  ,--,   |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|da | '    |  |  ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|mat|     ,/  |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ele|    /    |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|ent|   /   , |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"| 2 |  /,--'  |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |         |   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |       ,-'   ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|   |    ,-'      ");
                    mvwprintw(stdscr, livroY++,     livroX-20,"|___| ,-'         ");


            livroY = 8+Yall;
            napms(105);
            mvwprintw(stdscr, livroY++,     livroX-20,"              __,,  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___,--'''__,|");
            mvwprintw(stdscr, livroY++,     livroX-20,"_,--'___---'''   |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |       ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|fun|            |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|da |   ,--,     |       ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|mat|  '    |     |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ele|      ,/    |           ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|ent|     /      |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"| 1 |    /   ,      |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |   /,--'     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |            |          ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |           _|   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   |    __,--''          ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___|,--'           ");
            wrefresh(stdscr);
            napms(105); // Espera 2 segundos



                    
            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |"); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|       ,-'''-.      |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      '       |     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ,-'     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|          ,-'       |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|        ,-          |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|       /_______     |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|");
            wrefresh(stdscr);
            napms(105);
            

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ''---..,_,.-=:;|    ");   
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|   .,       ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  /   \     ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      ,     ||||||||    ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|    ,'      ||||||||    ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|  .'___     ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||    ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|            ||||||||  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|___         ||||||||");
            mvwprintw(stdscr, livroY++,     livroX-20,"    ''---..,|;:-=\"' ");
            wrefresh(stdscr);
            napms(55);




            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ___________________  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|''-=::;;_'','.\"',:| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|  ,.-,   || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"| '    |  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|      /  || |||  ||| ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"|   ,-'   || |||  ||| ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"|  /____  || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|         || |||  ||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|_        ||,|||,_||| ");
            mvwprintw(stdscr, livroY++,     livroX-20,"''-=:..,_'' ;:'  ''   ");
            wrefresh(stdscr);
            napms(55);
            
            livroY = 8+Yall;
            werase(stdscr); 
            mvwprintw(stdscr, livroY++,     livroX-20,"     ___________________   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |'-,'-,'-, '--,,'-, |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   '-,'-,'-,  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    | ,-. || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |    ||| | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |   ,'|| | ||  | || |  ");                 
            mvwprintw(stdscr, livroY++,     livroX-20,"    | ,'  || | ||  | || |  ");       
            mvwprintw(stdscr, livroY++,     livroX-20,"    |',,._|| | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||  | || |  "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"    |     || | ||._|_||_|  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,.,.||_|_||'-,:'' '  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"    '-,; -',;'             ");
            wrefresh(stdscr);
            napms(105);

            livroY = 8+Yall;
            werase(stdscr);

            mvwprintw(stdscr, livroY++,     livroX-20,"          ___,____________________");
            mvwprintw(stdscr, livroY++,     livroX-20," ___---'''__,|                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|_,,--''''   |                    |     "); 
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |     ");     
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |      ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||          |                    |     ");         
            mvwprintw(stdscr, livroY++,     livroX-20,"|||         _|____________________|     ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|||  __,--''                              ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|,--'                                    ");
            wrefresh(stdscr);
            napms(105);  

            livroY = 8+Yall;
            werase(stdscr);
            mvwprintw(stdscr, livroY++,     livroX-20," ____________________ ____________________  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");    
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");      
        mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |  ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |   
            mvwprintw(stdscr, livroY++,     livroX-20,"|                    |                    |   ");
            mvwprintw(stdscr, livroY++,     livroX-20,"|____________________|____________________|   ");
            wrefresh(stdscr);
            livroY = 8+Yall;
            napms(100);
            
            */