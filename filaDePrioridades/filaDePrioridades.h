#ifndef FILADEPRIORIDADES_H_INCLUDED
#define FILADEPRIORIDADES_H_INCLUDED
#define MAX 50
#define MAXPR 50

struct passageiro{
    int id;
    int idade;
    char nome[25];
    char planeta[30];
};

struct recursos_transportados{
    char recursos[30];
};

struct nave_espacial{
    int prioridade;
    struct passageiro pa[MAXPR];
    struct recursos_transportados rt[MAXPR];
};

struct fila_prioridade{
    int qtd;
    struct nave_espacial naves[MAX];
};

typedef struct fila_prioridade FilaPrio;
typedef struct nave_espacial Nave;

FilaPrio* cria();
void libera(FilaPrio*);
int consulta(FilaPrio*, Nave );
int insere(FilaPrio*, int );
int remov(FilaPrio*, int);
int tamanho(FilaPrio* );
int cheia(FilaPrio* );
int vazia(FilaPrio* );

#endif // FILADEPRIORIDADES_H_INCLUDED
