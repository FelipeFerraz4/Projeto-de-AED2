#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDePrioridades.h"

//cria na memória uma lista estática
//lista começa no índice 1
FilaPrio* criar_heap(){
    FilaPrio *fp;
    fp = (FilaPrio*)malloc(sizeof(FilaPrio));
    if( fp != NULL){
        fp->size_nave = 1;
    }
    return fp;
}

//insere uma nave na heap
int inserir(FilaPrio *fp, Nave nave){
    if(fp == NULL)
        return 0;
    if(cheia(fp)){
        return 0;
    }
    fp->naves[fp->size_nave] = nave;
    subir(fp, fp->size_nave);
    fp->size_nave++;
    return 1;
}


int remover(FilaPrio *fp){
    if(fp == NULL)
        return 0;
    if(vazia(fp)){
        return 0;
    }
    fp->size_nave--;
    fp->naves[1] = fp->naves[fp->size_nave];
    descer(fp, 1);
    return 1;
}

/*
int consultar(FilaPrio *fp, Nave n){
    if(fp == NULL || vazia(fp))
        return 0;
    n = fp->naves[0];
    return 1;
}
*/

//realoca a nova nave inserida na posição de prioridade correta
//Considerando vetor iniciando em 1
void subir(FilaPrio *fp, int filho){
    int pai = filho/2;
    Nave temp;
    if(pai >= 1){
        if(fp->naves[filho].prioridade > fp->naves[pai].prioridade){
            temp = fp->naves[filho];
            fp->naves[filho] = fp->naves[pai];
            fp->naves[pai] = temp;
            subir(fp, pai);
        }
    }
}

//realoca valor inserido ao topo na posição correta
void descer(FilaPrio *fp, int pai){
    int filho = 2*pai;
    Nave temp;
    if(filho < fp->size_nave){
        if(fp->naves[filho + 1].prioridade > fp->naves[filho].prioridade)
            filho++;
        if(fp->naves[filho].prioridade > fp->naves[pai].prioridade){
            temp = fp->naves[pai];
            fp->naves[pai] = fp->naves[filho];
            fp->naves[filho] = temp;
            descer(fp, filho);
        }
    }
}

//funções auxiliares:

void libera(FilaPrio *fp){
    free(fp);
}

int tamanho(FilaPrio *fp){
    if(fp == NULL){
        return -1;
    }else{
        return fp->size_nave;
    }
}

int cheia(FilaPrio *fp){
    if(fp == NULL){
        return -1;
    }else if(fp->size_nave > MAX_DEFAULT){
        return 1;
    }else{
        return 0;
    }
}

int vazia(FilaPrio *fp){
    if(fp == NULL){
        return -1;
    }else if(fp->size_nave == 1){
        return 1;
    }else{
        return 0;
    }
}
