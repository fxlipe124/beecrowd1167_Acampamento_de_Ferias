/***********************************************/ 
/* beecrowd | 1167 Acampamento�de�F�rias       */
/* grupo: Charles Babbage					   */
/* programador: Felipe Adona e Bryan Ruppenthal*/
/* testador: Anderson						   */
/* criado em: 01/12/2021                       */
/* data da �ltima altera��o: 11/12/2023        */
/***********************************************/ 

#include <stdio.h>
// entrada e sa�da padr�o: printf, scanf

struct Nodo {
    char nome[30];
    int valor;
    struct Nodo* anterior;
    struct Nodo* proximo;};
//definida estrutura chamada Nodo que representa um n� na lista circular. 
//cada n� cont�m um nome (uma string de at� 30 caracteres), um valor inteiro, um ponteiro para o n� anterior na lista e um ponteiro para o pr�ximo n� na lista.

typedef struct Nodo Nodo; // cria um nome para a struct para facilitar o uso.

void iniciaNODO(Nodo* nodo, char nome[30], int valor) {
    for (int i = 0; i < 30; ++i) {
        nodo->nome[i] = nome[i];}
    nodo->valor = valor;
    nodo->anterior = NULL;
    nodo->proximo = NULL;}
//fun��o iniciaNODO recebe um ponteiro para um n� (Nodo* nodo), um nome e um valor, e inicializa os campos do n� com esses valores.

int main() {
    while (1) {
        int n, i, j;
//variaveis
//n = numero de criancas
//i = indice
//j = indice
        Nodo crianca[100];

        scanf("%d", &n);
        if (!n)
            break;
//programa entra em loop e solicita ao usu�rio que insira um n�mero N. 
//Se N for zero, encerra o programa.

        for (i = 0; i < n; ++i) {
            char nome[30];
            int valor;
            scanf("%s%d", nome, &valor);

            iniciaNODO(&crianca[i], nome, valor);

            crianca[i].anterior = &crianca[(i - 1 + n) % n];
            crianca[i].proximo = &crianca[(i + 1) % n];}
//o programa entra em um loop de N vezes para criar uma lista circular de crian�as. 
//cada crian�a, recebe o nome e o valor e, em seguida, a fun��o iniciaNODO � chamada para inicializar o n� correspondente.
//ponteiros anterior e proximo s�o configurados para criar a lista circular.

        i = 0;
        while (n > 1) {
            int valor = crianca[i].valor;

            for (j = 0; j < valor; ++j) {
                if (valor % 2) {
                    i = crianca[i].proximo - crianca;
                } else {
                    i = crianca[i].anterior - crianca;}}
//programa entra em outro loop que simula o jogo de elimina��o. 
//percorre a lista circular valor vezes, onde valor � o valor associado � crian�a atual.
//l�gica determina se a crian�a � eliminada indo para o pr�ximo ou para o anterior com base no valor.

            crianca[i].anterior->proximo = crianca[i].proximo;
            crianca[i].proximo->anterior = crianca[i].anterior;
            --n;}
//depois de determinar qual crian�a deve ser eliminada, os ponteiros anterior e proximo dos n�s vizinhos s�o ajustados para "pular" a crian�a eliminada. 
//n�mero total de crian�as N � decrementado.

        i = crianca[i].proximo - crianca;
//�ndice do n� restante � atualizado para o pr�ximo na lista.

        printf("Vencedor(a): %s\n", crianca[i].nome);}
    return 0;}
//programa imprime o nome da �ltima crian�a restante, que � declarada como vencedora.
//loop externo continua at� que o usu�rio insira 0.
