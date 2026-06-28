CC = gcc
CFLAGS = -O2
LIBS = -lncursesw -I.
OUT = /tmp/game
DELETE = rm -f
CLEAR = && clear
SRC = dialogos/dialogofinal.c \
      funcoes/demo.c \
      animacoes/transicao.c \
      animacoes/slow_mvwprintw.c \
      funcoes/inicio.c \
      funcoes/personalizar.c \
      PE_JOGO_2.c \
      jogos/pedrapapeltesoura.c \
      jogos/cobra.c \
      animacoes/dormir.c \
      animacoes/cair_no_sono.c \
      provas/prova_simples.c \
      provas/prova_cansado_simples.c \
      provas/prova_complexa.c \
      provas/prova_cansado_complexa.c \
      animacoes/abrirlivro.c \
      dialogos/dialogoProvaCC.c \
      dialogos/dialogoProvaCS.c \
      dialogos/dialogoProvaS.c \
      dialogos/dialogoProvaC.c \
      dialogos/dialogoMae.c \
      dialogos/dialogodepoisprova.c \
      funcoes/iniciar.c \
      funcoes/recarregar.c \
      funcoes/gravar.c \
      funcoes/menusave.c \
      funcoes/gravar_imagem_do_momento.c \
      funcoes/printar_imagem_do_momento.c \
      funcoes/desenha_borda.c \
      animacoes/animacaomenu.c \
      animacoes/animacaopequenina.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

run:
	$(OUT)

run-ext:
	gnome-terminal -- $(OUT)

clean:
	$(DELETE) $(OUT) $(CLEAR)