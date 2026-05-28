1. Instalar a extensão Dev Container no VSCODE

2. Tenha o dockerfile que eu deixei ai. Voce pode ver oq tem la nele

3. Tenha a pasta .devcontainer com o devcontainer.json 

```json
{
  "name": "PE JOGO",

  "build": {
    "dockerfile": "../Dockerfile" //a localização do dockerfile
  },

  "workspaceFolder": "/workspace", 

  "workspaceMount": "source=${localWorkspaceFolder},target=/workspace,type=bind", //cria um bind mound do docker com teu arquivo, sendo a fonte sua pasta de trabalho atual
//Um bind mount no Docker é um recurso que mapeia um diretório ou arquivo do seu sistema operacional local //(host) diretamente para dentro do contêiner. Qualquer alteração feita nos arquivos de um lado é refletida imediatamente no outro, sendo ideal para desenvolvimento em tempo real.

  "postCreateCommand": "apt install -y libncurses-dev", //define um comando para executar diretamente pos criacao

"customizations": {   //define quais extensões que o vscode terá
    "vscode": {
      "extensions": [
        "ms-vscode.cpptools"
      ]
    }
  },

  "remoteUser": "root" //define o usuario  como root
}
```



Para abrir sua pasta de trabalho atual utilize Dev Containers: Reopen in Container
Para sair, use Dev Containers: Reopen Folder Locally
```sh
gcc main.c -lncurses -o app
```