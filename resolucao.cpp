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
    int anterior;
    int proximo;};
//definida a estrutura Nodo, que cont�m informa��es como:
// nome, valor, �ndice do n� anterior e �ndice do pr�ximo n�

typedef struct Nodo Nodo;
//renomeando a struct nodo para nodo para facilitar o uso

void iniciaNODO(Nodo* nodo, char nome[30], int valor) {
//fun��o recebe um ponteiro para um Nodo, um nome e um valor, e inicializa o n� com esses valores

    for (int i = 0; i < 30; ++i) {
        nodo->nome[i] = nome[i];}
//O nome � copiado para o campo nome do n�  
    nodo->valor = valor;
//o valor � atribu�do ao campo valor

    nodo->anterior = -1;
    nodo->proximo = -1;}
//e os campos anterior e proximo s�o inicializados com -1.

//loop principal do programa
int main() {
    while (1) {
        int n, i, j;
        
//criando um vetor de Nodos chamado crianca com tamanho m�ximo de 100
        Nodo crianca[100];
        
//lendo o n�mero de elementos na lista circular
        scanf("%d", &n);
        if (!n)
        break; // Se n for 0, encerra o programa
        
//loop para ler informa��es sobre cada crian�a
        for (i = 0; i < n; ++i) {
            char nome[30];
            int valor;
            
//lendo o nome e valor da crianca atual
            scanf("%s%d", nome, &valor);
            
//inicializando o Nodo atual com os dados lidos
            iniciaNODO(&crianca[i], nome, valor);
            
//configurando os ponteiros anterior e pr�ximo para formar uma lista circular
            crianca[i].anterior = (i - 1 + n) % n;
            crianca[i].proximo = (i + 1) % n;}
            
//inicializando a vari�vel i para apontar para o primeiro elemento da lista
        i = 0;
//loop principal para eliminar crian�as at� que reste apenas uma
        while (n > 1) {
            int valor = crianca[i].valor;
            
//movendo i para a crian�a a ser eliminada 
// Loop para contar at� o valor do n� e determinar para onde ir
            for (j = 0; j < valor; ++j) {
                if (valor % 2) {
                    i = crianca[i].proximo;
                } else {
                    i = crianca[i].anterior;}}
            
//removendo a crian�a ou n� atual da lista
            crianca[crianca[i].anterior].proximo = crianca[i].proximo;
            crianca[crianca[i].proximo].anterior = crianca[i].anterior;
            --n;}
            
//atualizando i para a �nica crian�a restante
        i = crianca[i].proximo;
        
//imprimindo o nome da crian�a vencedora
        printf("Vencedor(a): %s\n", crianca[i].nome);}
    return 0;}
