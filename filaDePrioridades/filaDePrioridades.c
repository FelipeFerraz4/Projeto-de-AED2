#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDePrioridades.h"

//cria na memória uma lista estática
FilaPrio* criar_heap(){
    FilaPrio *fp;
    fp = (FilaPrio*)malloc(sizeof(FilaPrio));
    if( fp != NULL){
        fp->size_nave = 0;
    }
    return fp;
}
/*
//insere uma nave na fila
int insere(FilaPrio *fp, int prio){
    if(fp == NULL)
        return 0;
    if(cheia(fp)){
        return 0;
    }

    fp->naves[fp->size_nave].prioridade = prio;
    subir(fp, fp->size_nave);
    fp->size_nave++;
    return 1;
}
*/
/*
int remov(FilaPrio *fp, int prio){
    if(fp == NULL)
        return 0;
    if(vazia(fp)){
        return 0;
    }
    fp->size_nave--;
    fp->naves[0] = fp->naves[fp->size_nave];
    descer(fp, 0);
    return 1;
}
*/
/*
int consulta(FilaPrio *fp, Nave n){
    if(fp == NULL || vazia(fp))
        return 0;
    n = fp->naves[0];
    return 1;
}

//realoca a nova nave inserida na posição de prioridade correta
void subir(FilaPrio *fp, int filho){
    int pai;
    struct nave_espacial temp;
    pai = (filho - 1) / 2;
    while((filho > 0) && (fp->naves[pai].prioridade <= fp->naves[filho].prioridade)){
        temp = fp->naves[filho];
        fp->naves[filho] = fp->naves[pai];
        fp->naves[pai] = temp;
        filho = pai;
        pai = (pai - 1) / 2;
    }
}
*/

void descer(FilaPrio *fp, int pai){
    struct nave_espacial temp;
    int filho = 2 * pai + 1;
    while(filho < fp->size_nave){
        if(filho < fp->size_nave-1){
            if(fp->naves[filho].prioridade < fp->naves[filho + 1].prioridade){
                filho++;
            }
        }
        if(fp->naves[pai].prioridade >= fp->naves[filho].prioridade){
            break;
        }
        temp = fp->naves[pai];
        fp->naves[pai] = fp->naves[filho];
        fp->naves[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
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
/*
int cheia(FilaPrio *fp){
    if(fp == NULL){
        return -1;
    }else if(fp->size_nave == MAX){
        return 1;
    }else{
        return 0;
    }
}
*/
int vazia(FilaPrio *fp){
    if(fp == NULL){
        return -1;
    }else if(fp->size_nave == 0){
        return 1;
    }else{
        return 0;
    }
}
