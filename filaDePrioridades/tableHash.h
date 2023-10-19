#ifndef TABLEHASH_H_INCLUDED
#define TABLEHASH_H_INCLUDED
#define SIZE 10

// Definição de estrutura de nó para a lista encadeada
typedef struct elemento {
    int id_1, id_2, id_3;
    struct elemento* proximo;
}Lista;

Lista* criar(int, int, int);
void criarHashTable();
void insereHash(int, int, int);
int buscaHash(int, int, int);
void listarHashTable();
void removeHash(int, int, int);
int permutacao(int, int, int);

#endif // TABLEHASH_H_INCLUDED
