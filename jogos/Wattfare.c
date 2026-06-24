#include<ncurses.h>

/* não está finalizado, mas aqui será um dos minijogos, ele consiste em um sistema de vantagens, similar a um pedra papel tesoura ou pokemon,
mas junto com cartas, manejo de dinheiro e algumas outras mecanicas

eu tentei dar uma olhada na melhor maneira de por isso em prática, pelo que eu entendi eu tive que fazer eles num modelo onde 
toda dupla de elementos tenha um elemento em comum que venca deles

https://forumcontent.paradoxplaza.com/public/1504355/1779854896432.png

nesse estilo.
*/







typedef struct model 
{
    int valor; //quantos watts vale
    int tipo; //se é o normal ou o sucata 1 ou 0
    int vida; // 100/100
    int dano; 
    int defesa; // 10/10, redução de dano
    int habilidade;
    int passivas;  // acho que os eletrodomésticos podem dar efeitos diferentes, dano no decorrer do tempo, tomar dano por alguem, gerar watts, etc 

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
    eletrodomestico roteador,caixa_de_som,micro_ondas,airfryer,chaleira,WAP;
    roteador.modelo.dano=5;
    roteador.modelo.defesa=0;
    roteador.modelo.habilidade=1;

    int Xall=(COLS/2)-57, Yall=3;
    curs_set(0);
    WINDOW *wattfarewindow = newwin(LINES, COLS, 0, 0);
    keypad(wattfarewindow,TRUE);
    nodelay(wattfarewindow,TRUE);
    time jogador, bot;
    mvwprintw(wattfarewindow, Yall-1, Xall+20, "Wattfare");

    mvwprintw(wattfarewindow, Yall-1, Xall+20, "Batalha");
    mvwprintw(wattfarewindow, Yall-1, Xall+20, "Eletrodomesticos");
    mvwprintw(wattfarewindow, Yall-1, Xall+20, "sair");
    
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
/*
o jogo funciona com o jogador comprando os eletrodomésticos que ele vai usar, logo antes da partida, com os watts que ele tiver disponivel,
e a cada partida que ele ganhar, ele ganha 3 watts, e a cada que ele perder, ele ganha 1, não há empates.

as batalhas acontecem quando o jogador escolhe 3 eletrodomésticos que ele tem e o inimigo também, onde eles escolhem um pra atacar o outro ou usar 
habilidades, as quais custam watts.

o objetivo é tirar a vida dos eletrodomésticos do inimigo, ou que ele desista ( desistir te da 0 watts mas preserva o eletrodoméstico em arena)




HABILIDADES


roteador: desconecta os outros da internet, 
reduzir dano dos do mesmo tipo pelo resto da rodada,
inibir o dano na rodada, mas tira vida dele
tira ou reduz a defesa de 3 eletrodomésticos disponiveis

Caixa de som: ressonância
da dano que ignora a defesa
atordoa o inimigo e impede que receba dano, mas só usa a cada 2 ou 3 rodadas
vai gerando um stack de dano que quando chega em 3 da um dano extra ou da um dano em área

Micro-ondas: interferência
as ondas eletromagnétcas stacam e quando atingem 5, transforma os 2 eletrodomésticos afetados nas versões sucata deles
impede que o inimigo troque os eletrodomésticos
faz o inimigo fazer um 2 ações aleatórias ao inves de decidir o que vai fazer

airfryer: fritância
joga comida no eletrodoméstico e ele por ficar gordurento fica mais fraco
ataque de calor ignora a defesa
intensifica o calor dela e consome os watts do inimigo pelo grande gasto energético, isso aumenta o dano dela na proxima rodada, temporáriamente

chaleira: água quente
da 2x de dano
ataque em área
da pani no eletrodoméstico inimigo e faz ele atacar um parceiro

umidificador: vapor
da pani no eletrodoméstico inimigo e faz ele atacar um parceiro
joga vapor nos circuitos e trava o eletrodoméstico por 2 rodadas
intensifica a própia passiva

WAP: jato
fica invulneravel por uma partida e da o dobro de dano, mas toma o triplo na proxima
ataque perfurante, ataca 2 e perfura a defesa de um deles. mas só pode a cada 3 rodadas
atrai os ataques que envolvam agua e soma (dano do eletrodoméstico inimigo X 0.1 X dano) no seu dano, pode acumular por 2 rodadas 



PASSIVAS:

roteador: Gera watts

caixa de som: descobre o eletrodoméstico que o inimigo mais tem

micro-ondas: cria a chance de 5% de um ataque do inimigo falhar quando presente (soma por microondas até 30%)

airfryer: acelera os cooldowns em 30% (soma 30-9%Xquantidade de airfryers )

chaleira: da dano extra em sucata Ou os ataques dela enfraquecem a defesa

umidificador: dano por tempo, 3% da vida do inimigo por rodada (estaca até 10%) só sai quando retira o eletrodoméstico do campo

WAP: dano na defesa, diminui ela permanentemente



*/

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

SPRITES:

    Roteador

    Caixa de som

    micro-ondas

    airFryer

    Chaleira

    umidificador

    WAP
*/