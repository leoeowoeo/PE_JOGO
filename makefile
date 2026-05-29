CC = gcc
LIBS = -lncursesw
OUT = /tmp/game
DELETE = rm -f
CLEAR = && clear

SRC = transicao.c slow_mvwprintw.c inicio.c personalizar.c PE_JOGO_2.c pedrapapeltesoura.c cobra.c dormir.c cair_no_sono.c prova_simples.c prova_cansado_simples.c prova_complexa.c prova_cansado_complexa.c abrirlivro.c dialogoProvaCC.c dialogoProvaCS.c dialogoProvaS.c dialogoProvaC.c dialogoMae.c dialogodepoisprova.c

all:
	$(CC) $(SRC) -o $(OUT) $(LIBS)

run:
	$(OUT)

clean:
	$(DELETE) $(OUT) $(CLEAR)