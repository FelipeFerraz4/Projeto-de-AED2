#ifndef TABLEHASH_H_INCLUDED
#define TABLEHASH_H_INCLUDED

#define TAMANHO_HASH 23

// Definição de estrutura de nó para a lista encadeada
typedef struct elemento {
    int id_1, id_2, id_3;
    struct elemento* proximo;
}Elemento;

typedef struct lista {
    int tamanho_lista;
    Elemento* elemento;
} Lista;

typedef struct tableHash {
    Lista lista_elementos[TAMANHO_HASH];
} TableHash;

Elemento* cria_elemento(int id1, int id2, int id3);
//void criarHashTable();
void insereHash(TableHash* hash_nave, int id1, int id2, int id3);
int buscaHash(TableHash* hash_nave, int id1, int id2, int id3);
void print_hash(TableHash* hash_nave);
void remove_lista_Hash(TableHash* hash_nave, int id1, int id2, int id3);
int verificaLista(TableHash* hash_nave, int id1, int id2, int id3);

int teste_hash();
TableHash* cria_hash();
void libera_hash(TableHash* hash_nave);


#endif // TABLEHASH_H_INCLUDED
