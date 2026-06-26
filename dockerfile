FROM gcc:latest AS base
# gcc:latest define um Linux com compilador GCC disponível

# Define o mesmo diretório do devcontainer
WORKDIR /workspace

# Instala ncurses para compilar e rodar o jogo
RUN apt-get update && apt-get install -y \
    libncurses-dev \
    && rm -rf /var/lib/apt/lists/*

# Copia os arquivos locais para dentro do container
COPY . /workspace