#ifndef FILADEPRIORIDADES_H_INCLUDED
#define FILADEPRIORIDADES_H_INCLUDED
#define MAX_DEFAULT 50

typedef struct passageiro{
    int id;
    char nome[MAX_DEFAULT];
    int idade;
    char planeta[MAX_DEFAULT];
}Passageiro;

typedef struct recurso{
    char nome[MAX_DEFAULT];
    int quantidade;
}Recurso;

typedef struct nave_espacial{
    int prioridade;
    int tipo_nave;
    int size_passageiro;
    int size_recursos_transportados;
    Passageiro passageiros[MAX_DEFAULT];
    Recurso recurso[MAX_DEFAULT];
}Nave;

typedef struct fila_prioridade{
    int size_nave;
    Nave naves[MAX_DEFAULT];
}FilaPrio;

FilaPrio* criar_heap();

//CRUD
int inserir(FilaPrio*, Nave);
int remover(FilaPrio*);
//int consultar(FilaPrio*);

//funções auxiliares
void subir(FilaPrio*, int);
void descer(FilaPrio*, int);
void libera(FilaPrio*);
int vazia(FilaPrio* );
int tamanho(FilaPrio* );
int cheia(FilaPrio* );



#endif // FILADEPRIORIDADES_H_INCLUDED
