#include <stdio.h>

struct Nodo {
    char nome[30];
    int valor;
    int anterior;
    int proximo;};

typedef struct Nodo Nodo;

void iniciaNODO(Nodo* nodo, char nome[30], int valor) {

    for (int i = 0; i < 30; ++i) {
        nodo->nome[i] = nome[i];}
  
    nodo->valor = valor;

    nodo->anterior = -1;
    nodo->proximo = -1;}

int main() {
    while (1) {
        int n, i, j;
        
        Nodo crianca[100];
        
        scanf("%d", &n);
        if (!n)
        break;
        
        for (i = 0; i < n; ++i) {
            char nome[30];
            int valor;
            
            scanf("%s%d", nome, &valor);
            
            iniciaNODO(&crianca[i], nome, valor);
            
            crianca[i].anterior = (i - 1 + n) % n;
            crianca[i].proximo = (i + 1) % n;}
            
        i = 0;
        while (n > 1) {
            int valor = crianca[i].valor;
            
            for (j = 0; j < valor; ++j) {
                if (valor % 2) {
                    i = crianca[i].proximo;
                } else {
                    i = crianca[i].anterior;}}
            
            crianca[crianca[i].anterior].proximo = crianca[i].proximo;
            crianca[crianca[i].proximo].anterior = crianca[i].anterior;
            --n;}
            
        i = crianca[i].proximo;
        
        printf("Vencedor(a): %s\n", crianca[i].nome);}
    return 0;}
