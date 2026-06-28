CC = gcc
CFLAGS = -O2
LIBS = -lncursesw -I.
OUT = /tmp/game
DELETE = rm -f
CLEAR = && clear
SRC = funcoes/demo.c \
      PE_JOGO_2.c \
      jogos/pedrapapeltesoura.c \
      jogos/cobra.c \
      animacoes/dormir.c \
      animacoes/cair_no_sono.c \
      animacoes/animacaomenu.c \
      animacoes/animacaopequenina.c \
      animacoes/abrirlivro.c \
      animacoes/transicao.c \
      animacoes/slow_mvwprintw.c \
      provas/prova_simples.c \
      provas/prova_cansado_simples.c \
      provas/prova_complexa.c \
      provas/prova_cansado_complexa.c \
      dialogos/dialogoProvaCC.c \
      dialogos/dialogoProvaCS.c \
      dialogos/dialogoProvaS.c \
      dialogos/dialogoProvaC.c \
      dialogos/dialogoMae.c \
      dialogos/dialogodepoisprova.c \
      dialogos/dialogofinal.c \
      funcoes/save/iniciar.c \
      funcoes/save/recarregar.c \
      funcoes/save/gravar.c \
      funcoes/cenario/desenhar_cama.c \
      funcoes/cenario/desenhar_estante.c \
      funcoes/cenario/desenhar_mesa.c \
      funcoes/cenario/desenhar_armario.c \
      funcoes/cenario/desenhar_espelho.c \
      funcoes/cenario/desenhar_chuva.c \
      funcoes/cenario/desenhar_janela.c \
      funcoes/cenario/desenhar_porta.c \
      funcoes/cenario/desenhar_lixo.c \
      funcoes/cenario/desenhar_tapete.c \
      funcoes/cenario/desenhar_rodape.c \
      funcoes/cenario/desenhar_gato.c \
      funcoes/cenario/desenhar_celular.c \
      funcoes/cenario/inicializar_cores.c \
      funcoes/cenario/mecanicas/processar_colisoes.c \
      funcoes/cenario/mecanicas/processar_interacoes.c \
      funcoes/cenario/mecanicas/espelhaogaroto.c \
      funcoes/hud/printar_celular.c \
      funcoes/hud/desenhar_hud.c \
      funcoes/hud/printar_livro.c \
      funcoes/jogador/desenhar_jogador.c \
      funcoes/jogador/movimentar_jogador.c \
      funcoes/menu/menusave.c \
      funcoes/menu/gravar_imagem_do_momento.c \
      funcoes/menu/printar_imagem_do_momento.c \
      funcoes/menu/desenha_borda.c \
      funcoes/menu/inicio.c \
      funcoes/menu/personalizar.c \





all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

run:
	$(OUT)

run-ext:
	gnome-terminal -- $(OUT)

clean:
	$(DELETE) $(OUT) $(CLEAR)