# FROM gcc:latest AS base
# # gcc:latest define que será um linux com a versão mais recente do compilador gcc baixado
#
# WORKDIR /app

FROM gcc:latest AS base
# gcc:latest define um Linux com compilador GCC disponível

WORKDIR /app

# Instala ncurses para compilar e rodar o jogo com ncurses
RUN apt-get update && apt-get install -y libncurses-dev && rm -rf /var/lib/apt/lists/*

COPY . /app



