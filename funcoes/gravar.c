#include<stdio.h>
#include<string.h>
#include "jogos.h"
int gravar(int slot, SAVE *save_atual)
// a função salva a struct do save atual no arquivo
{
    if (slot < 1 || slot > 3 || save_atual == NULL) {
        return 0;
    }

    FILE *save = fopen("save.bin", "r+b"); // "r+b" é melhor para atualizar dados existentes

    if (save == NULL) {
        // Se o arquivo ainda nao existe, crio um novo binario para os saves.
        save = fopen("save.bin", "w+b");
    }

    if (save != NULL) {
        fseek(save, (slot - 1) * sizeof(SAVE), SEEK_SET); // vai direto para o slot escolhido
        fwrite(save_atual, sizeof(SAVE), 1, save); // 
        fflush(save); // garante que os bytes saiam da memoria e vao para o disco
        fclose(save);
        return 1;
    }
    return 0;
}