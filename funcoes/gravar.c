#include<stdio.h>
#include"jogos.h"
void gravar(int slot,SAVE *save_atual)
{
    FILE *save;
    save=fopen("save.dat","rb+");


        fseek(save, slot * sizeof(SAVE), SEEK_SET);
        
        fwrite(save_atual,sizeof(SAVE),1,save);
        fclose(save);
}