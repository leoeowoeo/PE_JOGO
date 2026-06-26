#include<stdio.h>
#include"jogos.h"
int recarregar(int slot,SAVE *save_atual)// a função recarrega o save
{
    FILE *load;
    
    load=fopen("save.bin","rb"); // abre o arquivo apenas para leitura binaria
    
    if(load != NULL)
    {
        fseek(load, (slot - 1) * sizeof(SAVE), SEEK_SET); // pula direto para o bloco do slot
        
        if (fread(save_atual,sizeof(SAVE),1,load) == 1) { // le a struct inteira do arquivo
            fclose(load);
            return 1;
        }
        fclose(load);
    }

    if (save_atual != NULL) {
        *save_atual = (SAVE){0};
    }
    return 0;
}