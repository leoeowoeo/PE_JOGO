#include "jogos.h"
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