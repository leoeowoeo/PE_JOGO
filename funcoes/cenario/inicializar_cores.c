#include"jogos.h"
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
void inicializar_cores(SAVE save, int interage, int selecaocor, int *par)
{
    if (save.cor == 1)
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