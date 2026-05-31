#include<ncurses.h>

typedef struct model 
{
    int valor; //quantos watts vale
    int tipo; //se é o normal ou o sucata

    //int vida? a gente pode fazer isso realmente virar uma batalha pokemon, mas estilo roguelike, 
    //onde voce a cada rodada compra os eletrodomesticos que voce quer e tenta fazer com que eles
    //se protejam uns aos outros, cobrindo as suas fraquesas, e ai, a cada rodada os jogadores
    //ganham mais ou menos watts pra acelerar ou trazer o jogo pra um fim 
    
} modelo;

typedef struct eletro
{
    char nome[20];
    modelo modelo;
} eletrodomestico;

typedef struct jogador_time
{

    eletrodomestico tipos[7];
    int quantidade_total_eletrodomesticos;
    int possui_elemento[7];      // guarda qual elemento ele possui, se o indice 1, que são os roteadores ta em 3, ele tem 3 roteadores ( n sei oq fazer pros sucara)
    int elemento_derrotado[7];   // quantas cartas de cada elemento foramd errotadas ( acho q podemos subtrair do que ele possui pra virar o novo possiu, e ai zeramos o que foid errotado na nova jogada)
} time;

int wattfare()
{
    time jogador, bot;
}

int batalha(time jogador, int player, time bot, int robo) 
{
    int vantagens[7][7] = {
        { 0, -1, -1,  1, -1,  1,  1}, // ROTEADOR
        { 1,  0, -1, -1,  1, -1,  1}, // CAIXA DE SOM
        { 1,  1,  0, -1, -1,  1, -1}, // MIC-O
        { -1, 1,  1,  0, -1, -1,  1}, // AIR-F
        { 1, -1,  1,  1,  0, -1, -1}, // CHAL
        { -1, 1, -1,  1,  1,  0, -1}, // UMID
        { -1, -1, 1, -1,  1,  1,  0}  // WAP
    };

    int resultado = vantagens[player][robo];

    return resultado;
}

/*                  perde, ganha, ganha, empata, perde, perde, ganha 
                    ( ta nesse modelo por uma explicação um pouco complexa):
                    quando voce aplica o modelo:
                    ganha, ganha, ganha, empata, perde, perde, perde.
                    voce acaba fazendo com que o jogador só pecise escolher 2 objetos que estejam nos extremos
                    já que um deles acaba com todos os 3 a direita e o outro com todos os 3 a esquerda, considerando que eles estão num circulo de escolhas.
                    mas quando fazemos da forma que está aqui, não tem 2 grupos que ganhem de todos, na vedade, sempre tem uma dupla que perde pra 1, tem sempre
                    um elemento que derrota uma dupla, logo não tem essa de escolher só 2 elementos e se dar bem com eles numa chance de 50%, voce tem que analisar o seu
                    inimigo e ver o que ele ta planejando pra conseguir ganhar dele, porque se ele tiver algo que é a sua fraquesa, voce deve ter algo que ataque a fraquesa dele.

                        ROTE  CAIXA MIC-O AIR-F  CHAL UMID   WAP
|                      |-----|-----|-----|-----|-----|-----|-----|
| *0 (ROTEADOR)*       |  0  |  X  |  X  |  V  |  X  |  V  |  V  |
|                      |-----|-----|-----|-----|-----|-----|-----|
| *1 (CAIXA DE SOM)*   |  V  |  0  |  X  |  X  |  V  |  X  |  V  |
|                      |-----|-----|-----|-----|-----|-----|-----|
| *2 (MICRO-ONDAS)*    |  V  |  V  |  0  |  X  |  X  |  V  |  X  |
|                      |-----|-----|-----|-----|-----|-----|-----|
| *3 (AIR_FRYER)*      |  X  |  V  |  V  |  0  |  X  |  X  |  V  |
|                      |-----|-----|-----|-----|-----|-----|-----|
| *4 (CHALEIRA)*       |  V  |  X  |  V  |  V  |  0  |  X  |  X  |
|                      |-----|-----|-----|-----|-----|-----|-----|
| *5 (UMIDIFICADOR)*   |  X  |  V  |  X  |  V  |  V  |  0  |  X  |
|                      |-----|-----|-----|-----|-----|-----|-----|
| *6 (WAP)*            |  X  |  X  |  V  |  X  |  V  |  V  |  0  |
|                      |-----|-----|-----|-----|-----|-----|-----|


    0: Roteador Wi-Fi ganha de Caixa de Som, Micro-ondas e Air Fryer 
    (Interfere no sinal bluetooth da caixa, buga o painel digital do micro-ondas e descontrola o timer eletrônico da air fryer).

    1: Caixa de Som ganha de Micro-ondas, Air Fryer e Chaleira 
    (A vibração do som estoura o prato do micro-ondas, treme a air fryer até desencaixar a gaveta e vira a chaleira com água no chão).

    2: Micro-ondas ganha de Air Fryer, Chaleira e Umidificador 
    (Sua radiação eletromagnética frita a resistência da air fryer, evapora a água da chaleira antes de ligar e desmagnetiza o umidificador).

    3: Air Fryer ganha de Chaleira, Umidificador e WAP 
    (O fluxo de ar superaquecido frita a fiação da chaleira, seca instantaneamente a névoa do umidificador e derrete a mangueira plástica da WAP).

    4: Chaleira Elétrica ganha de Umidificador, WAP e Roteador 
    (Joga água fervendo no reservatório do umidificador, causa um curto na fiação da WAP e queima as antenas do roteador com vapor).

    5: Umidificador de Ar ganha de WAP, Roteador e Caixa de Som 
    (Sua névoa contínua oxida o gatilho da WAP, queima a placa lógica do roteador e causa curto nos alto-falantes da caixa).

    6: WAP ganha de Roteador, Caixa de Som e Micro-ondas 
    (O jato de água de alta pressão arranca as antenas do roteador, despedaça a carcaça da caixa e quebra o vidro temperado do micro-ondas).
*/