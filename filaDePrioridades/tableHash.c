#include <stdio.h>
#include <stdlib.h>
#include "tableHash.h"

// Função para criar uma nova lista encadeada
Elemento* cria_elemento(int id1, int id2, int id3) {
    Elemento* dado;
    dado = (Elemento*)malloc(sizeof(Elemento));
    if(dado != NULL){
        dado->id_1 = id1;
        dado->id_2 = id2;
        dado->id_3 = id3;
        dado->proximo = NULL;
    }

    return dado;
}

TableHash* cria_hash(){
    TableHash* hash_nave;
    hash_nave = (TableHash*) malloc(sizeof(TableHash));
    if(hash_nave != NULL){
        for(int i = 0; i < TAMANHO_HASH; i++){
            hash_nave->lista_elementos[i].tamanho_lista = 0;
            hash_nave->lista_elementos[i].elemento = NULL;
        }
    }
    return hash_nave;
}

void libera_hash(TableHash* hash_nave){
    if(hash_nave != NULL){
        for(int i = 0; i < TAMANHO_HASH; i++){
            Elemento* aux = hash_nave->lista_elementos[i].elemento;
            while(aux != NULL){
                Elemento* aux2 = aux;
                aux = aux->proximo;
                free(aux2);
            }
        }
        free(hash_nave);
    }
}

// Definição da tabela hash como um array de ponteiros para a lista encadeada
//Elemento* hashTable[SIZE];

// Função para inicializar a tabela hash
/*
void criarHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

*/

// Função para buscar um elemento na tabela hash
int buscaHash(TableHash* hash_nave, int id1, int id2, int id3) {
    int soma, posicao;
    soma = id1 + id2 + id3;
    posicao = soma % TAMANHO_HASH;
    Elemento* atual = hash_nave->lista_elementos[posicao].elemento;

    while (atual != NULL) {
        if (atual->id_1 == id1 && atual->id_2 == id2 && atual->id_3 == id3) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

// Função para inserir um elemento na tabela hash
void insereHash(TableHash* hash_nave, int id1, int id2, int id3) {
    int soma, posicao;
    soma = id1 + id2 + id3;
    posicao = soma % TAMANHO_HASH;

    if (hash_nave->lista_elementos[posicao].elemento == NULL) {
        hash_nave->lista_elementos[posicao].elemento = cria_elemento(id1, id2, id3);
    } else {
        if(buscaHash(hash_nave, id1, id2, id3) == 0){
            Elemento* dado = cria_elemento(id1, id2, id3);
            dado->proximo = hash_nave->lista_elementos[posicao].elemento;
            hash_nave->lista_elementos[posicao].elemento = dado;
        }
    }
}

void remove_lista_Hash(TableHash* hash_nave, int id1, int id2, int id3){
    int soma, posicao;
    soma = id1 + id2 + id3;
    posicao = soma % TAMANHO_HASH;
    Elemento* aux = hash_nave->lista_elementos[posicao].elemento;

    while(aux != NULL){
        Elemento* aux2 = aux;
        aux = aux->proximo;
        free(aux2);
    }

    hash_nave->lista_elementos[posicao].elemento = NULL;
}

// Função para imprimir a tabela hash
void print_hash(TableHash* hash_nave) {
    printf("\n");
    for (int i = 0; i < TAMANHO_HASH; i++) {
        Elemento* atual = hash_nave->lista_elementos[i].elemento;
        printf("Posicao %d: ", i);
        while (atual != NULL) {
            printf("[ %d %d %d ] ", atual->id_1, atual->id_2, atual->id_3);
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("\n");
}

int verificaLista(TableHash* hash_nave, int id1, int id2, int id3){
    int soma, posicao, qtd = 0;
    soma = id1 + id2 + id3;
    posicao = soma % TAMANHO_HASH;

    Elemento* aux = hash_nave->lista_elementos[posicao].elemento;
    while(aux != NULL){
        qtd += 1;
        aux = aux->proximo;
    }
    if(qtd == 6){
        remove_lista_Hash(hash_nave, id1, id2, id3);
        return 1;
    } else {
        return 0;
    }
}

