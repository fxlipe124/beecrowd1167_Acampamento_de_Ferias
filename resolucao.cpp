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
//definindo a estrutura nodo para representar os elementos da lista circular


typedef struct Nodo Nodo;
//renomeando a struct nodo para nodo para facilitar o uso

void iniciaNODO(Nodo* nodo, char nome[30], int valor) {
//função para inicializar um nodo com um nome e valor específicos

    for (int i = 0; i < 30; ++i) {
        nodo->nome[i] = nome[i];}
//copiando cada caractere do nome fornecido para o nodo->nome
  
    nodo->valor = valor;
//atribuindo o valor fornecido a nodo->valor

    nodo->anterior = -1;
    nodo->proximo = -1;}
//inicializando os ponteiros anterior e próximo com -1

//loop principal do programa
int main() {
    while (1) {
        int n, i, j;
        
//criando um array de Nodos chamado crianca com tamanho máximo de 100
        Nodo crianca[100];
        
//lendo o número de elementos na lista circular
        scanf("%d", &n);
        if (!n)
        break; // Se n for 0, encerra o programa
        
//preenchendo o array crianca com dados fornecidos pelo usuário
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
            for (j = 0; j < valor; ++j) {
                if (valor % 2) {
                    i = crianca[i].proximo;
                } else {
                    i = crianca[i].anterior;}}
            
//removendo a criança atual da lista
            crianca[crianca[i].anterior].proximo = crianca[i].proximo;
            crianca[crianca[i].proximo].anterior = crianca[i].anterior;
            --n;}
            
//atualizando i para a única criança restante
        i = crianca[i].proximo;
        
//imprimindo o nome da criança vencedora
        printf("Vencedor(a): %s\n", crianca[i].nome);}
    return 0;}
