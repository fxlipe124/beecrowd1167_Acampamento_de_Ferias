/***********************************************/ 
/* beecrowd | 1167 Acampamento de Férias       */
/* grupo: Charles Babbage					   */
/* programador: Felipe Adona e Bryan Ruppenthal*/
/* testador: Anderson						   */
/* criado em: 01/12/2021                       */
/* data da última alteração: 11/12/2023        */
/***********************************************/ 

#include <stdio.h>
// entrada e saída padrão: printf, scanf

struct Nodo {
    char nome[30];
    int valor;
    int anterior;
    int proximo;};
//definida a estrutura Nodo, que contém informações como:
// nome, valor, índice do nó anterior e índice do próximo nó

typedef struct Nodo Nodo;
//renomeando a struct nodo para nodo para facilitar o uso

void iniciaNODO(Nodo* nodo, char nome[30], int valor) {
//função recebe um ponteiro para um Nodo, um nome e um valor, e inicializa o nó com esses valores

    for (int i = 0; i < 30; ++i) {
        nodo->nome[i] = nome[i];}
//O nome é copiado para o campo nome do nó  
    nodo->valor = valor;
//o valor é atribuído ao campo valor

    nodo->anterior = -1;
    nodo->proximo = -1;}
//e os campos anterior e proximo são inicializados com -1.

//loop principal do programa
int main() {
    while (1) {
        int n, i, j;
        
//criando um vetor de Nodos chamado crianca com tamanho máximo de 100
        Nodo crianca[100];
        
//lendo o número de elementos na lista circular
        scanf("%d", &n);
        if (!n)
        break; // Se n for 0, encerra o programa
        
//loop para ler informações sobre cada criança
        for (i = 0; i < n; ++i) {
            char nome[30];
            int valor;
            
//lendo o nome e valor da crianca atual
            scanf("%s%d", nome, &valor);
            
//inicializando o Nodo atual com os dados lidos
            iniciaNODO(&crianca[i], nome, valor);
            
//configurando os ponteiros anterior e próximo para formar uma lista circular
            crianca[i].anterior = (i - 1 + n) % n;
            crianca[i].proximo = (i + 1) % n;}
            
//inicializando a variável i para apontar para o primeiro elemento da lista
        i = 0;
//loop principal para eliminar crianças até que reste apenas uma
        while (n > 1) {
            int valor = crianca[i].valor;
            
//movendo i para a criança a ser eliminada 
// Loop para contar até o valor do nó e determinar para onde ir
            for (j = 0; j < valor; ++j) {
                if (valor % 2) {
                    i = crianca[i].proximo;
                } else {
                    i = crianca[i].anterior;}}
            
//removendo a criança ou nó atual da lista
            crianca[crianca[i].anterior].proximo = crianca[i].proximo;
            crianca[crianca[i].proximo].anterior = crianca[i].anterior;
            --n;}
            
//atualizando i para a única criança restante
        i = crianca[i].proximo;
        
//imprimindo o nome da criança vencedora
        printf("Vencedor(a): %s\n", crianca[i].nome);}
    return 0;}
