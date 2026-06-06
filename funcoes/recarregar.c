#include<stdio.h>
#include"jogos.h"
void recarregar(int slot,SAVE *save_atual)
{
    FILE *load;
    load=fopen("save.dat","rb");
    
    if(load != NULL)
    {
        fseek(load, slot * sizeof(SAVE), SEEK_SET);
        
        fread(save_atual,sizeof(SAVE),1,load);
        fclose(load);
    }
}