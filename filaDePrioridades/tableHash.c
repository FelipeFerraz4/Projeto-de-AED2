#include <stdio.h>
#include <stdlib.h>
#include "tableHash.h"
<<<<<<< HEAD

// FunÃ§Ã£o para criar uma nova lista encadeada
Lista* criar(int id1, int id2, int id3) {
    Lista* ldse;
    ldse = (Lista*)malloc(sizeof(Lista));
    ldse->id_1 = id1;
    ldse->id_2 = id2;
    ldse->id_3 = id3;
    ldse->proximo = NULL;
    return ldse;
}

// DefiniÃ§Ã£o da tabela hash como um array de ponteiros para a lista encadeada
Lista* hashTable[SIZE];

// FunÃ§Ã£o para inicializar a tabela hash
=======
#include "filaDePrioridades.h"

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
>>>>>>> 28d59a823db38a0b5137a8b155f094a0805a14b4
void criarHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

<<<<<<< HEAD
// FunÃ§Ã£o para inserir um elemento na tabela hash
void insereHash(int id1, int id2, int id3) {
    int dado, i;
    dado = id1 + id2 + id3;
    i = dado % SIZE;

    if (hashTable[i] == NULL) {
        hashTable[i] = criar(id1, id2, id3);
    } else {
        if(buscaHash(id1, id2, id3)){
            printf("\nCombinaÃ§Ã£o existente\n");
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


// FunÃ§Ã£o para buscar um elemento na tabela hash
int buscaHash(int id1, int id2, int id3) {
    int dado, i;
    dado = id1 + id2 + id3;
    i = dado % SIZE;
    Lista* atual = hashTable[i];
=======
*/

int buscaPosicao(TableHash* hash_nave, int id1, int id2, int id3){
    int soma, posicao;
    soma = id1 + id2 + id3;
    posicao = soma % TAMANHO_HASH;
    int statusFim = 0;
    int contador = 0;
    while(contador < TAMANHO_HASH){
        Elemento* atual = hash_nave->lista_elementos[posicao].elemento;

        if(atual == NULL){
            return posicao;
        } else {
            if(atual->id_1 == id1){
                if(atual->id_2 == id2){
                    if(atual->id_3 == id3){
                        return posicao;
                    }
                }
                if(atual->id_2 == id3){
                    if(atual->id_3 == id2){
                        return posicao;
                    }
                }
            } else if(atual->id_1 == id2){
                if(atual->id_2 == id1){
                    if(atual->id_3 == id3){
                        return posicao;
                    }
                }
                if(atual->id_2 == id3){
                    if(atual->id_3 == id1){
                        return posicao;
                    }
                }
            } else if(atual->id_1 == id3){
                if(atual->id_2 == id2){
                    if(atual->id_3 == id1){
                        return posicao;
                    }
                }
                if(atual->id_2 == id1){
                    if(atual->id_3 == id2){
                        return posicao;
                    }
                }
            } else {
                posicao += 1;
                if(posicao >= TAMANHO_HASH){
                    posicao = 0;
                    if(statusFim == 1){
                        printf("erro, não encontrado posicao para elemento");
                        return -1;
                    }
                    statusFim = 1;
                }
            }
        }
        contador++;
    }
    return -1;
}

// Função para buscar um elemento na tabela hash
int buscaHash(TableHash* hash_nave, int id1, int id2, int id3) {
    int posicao = buscaPosicao(hash_nave, id1, id2, id3);
    if(posicao == -1){
        return -1;
    }
    Elemento* atual = hash_nave->lista_elementos[posicao].elemento;
>>>>>>> 28d59a823db38a0b5137a8b155f094a0805a14b4

    while (atual != NULL) {
        if (atual->id_1 == id1 && atual->id_2 == id2 && atual->id_3 == id3) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

<<<<<<< HEAD
// FunÃ§Ã£o para imprimir a tabela hash
void listarHashTable() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        Lista* atual = hashTable[i];
        printf("PosiÃ§Ã£o %d: ", i);
=======
// Função para inserir um elemento na tabela hash
int insereHash(TableHash* hash_nave, int id1, int id2, int id3) {
    int posicao = buscaPosicao(hash_nave, id1, id2, id3);
    if(posicao == -1){
        return -1;
    }

    if (hash_nave->lista_elementos[posicao].elemento == NULL) {
        hash_nave->lista_elementos[posicao].elemento = cria_elemento(id1, id2, id3);
    } else {
        int busca = buscaHash(hash_nave, id1, id2, id3);
        if(busca == 0){
            Elemento* dado = cria_elemento(id1, id2, id3);
            dado->proximo = hash_nave->lista_elementos[posicao].elemento;
            hash_nave->lista_elementos[posicao].elemento = dado;
        }
    }

    return 0;
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
>>>>>>> 28d59a823db38a0b5137a8b155f094a0805a14b4
        while (atual != NULL) {
            printf("[ %d %d %d ] ", atual->id_1, atual->id_2, atual->id_3);
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("\n");
}
<<<<<<< HEAD
=======

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

>>>>>>> 28d59a823db38a0b5137a8b155f094a0805a14b4
