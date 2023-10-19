#include <stdio.h>
#include <stdlib.h>
#include "tableHash.h"

// Função para criar uma nova lista encadeada
Lista* criar(int id1, int id2, int id3) {
    Lista* ldse;
    ldse = (Lista*)malloc(sizeof(Lista));
    ldse->id_1 = id1;
    ldse->id_2 = id2;
    ldse->id_3 = id3;
    ldse->proximo = NULL;
    return ldse;
}

// Definição da tabela hash como um array de ponteiros para a lista encadeada
Lista* hashTable[SIZE];

// Função para inicializar a tabela hash
void criarHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Função para inserir um elemento na tabela hash
void insereHash(int id1, int id2, int id3) {
    int dado, i;
    dado = id1 + id2 + id3;
    i = dado % SIZE;

    if (hashTable[i] == NULL) {
        hashTable[i] = criar(id1, id2, id3);
    } else {
        if(buscaHash(id1, id2, id3)){
            printf("\nCombinação existente\n");
        }else{
            Lista* ldse = criar(id1, id2, id3);
            ldse->proximo = hashTable[i];
            hashTable[i] = ldse;
        }
    }
}

void removeHash(int id1, int id2, int id3){
    int dado, i;
    dado = id1 + id2 + id3;
    i = dado % SIZE;
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    while(hashTable[i] != NULL){
        aux = hashTable[i];
        hashTable[i] = aux->proximo;
        free(aux);
    }
}

int permutacao(int id1, int id2, int id3){
    int dado, i, qtd = 0;
    dado = id1 + id2 + id3;
    i = dado % SIZE;
    Lista* aux = hashTable[i];
    while(aux != NULL){
        qtd += 1;
        aux = aux->proximo;
    }
    if(qtd == 6){
        removeHash(id1, id2, id3);
        return 1;
    } else {
        return 0;
    }
}


// Função para buscar um elemento na tabela hash
int buscaHash(int id1, int id2, int id3) {
    int dado, i;
    dado = id1 + id2 + id3;
    i = dado % SIZE;
    Lista* atual = hashTable[i];

    while (atual != NULL) {
        if (atual->id_1 == id1 && atual->id_2 == id2 && atual->id_3 == id3) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

// Função para imprimir a tabela hash
void listarHashTable() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        Lista* atual = hashTable[i];
        printf("Posição %d: ", i);
        while (atual != NULL) {
            printf("[ %d %d %d ] ", atual->id_1, atual->id_2, atual->id_3);
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("\n");
}
