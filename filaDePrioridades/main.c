#include <stdio.h>
#include <stdlib.h>
#include "filaDePrioridades.h"

void inserirNaves(struct Nave *dados){
    int i = 0;
    struct passageiro *pass;
    /*pass =(struct passageiro*)malloc(sizeof(struct passageiro));*/
    struct recursos_transportados *recur;
    printf("\nDigite a idade do passageiro: ");
    scanf("%d",pass->idade);
    printf("\nDigite o nome do passageiro: ");
    fflush(stdin);
    scanf("%s", pass->nome);
    printf("\nDigite o planeta do passageiro: ");
    fflush(stdin);
    scanf("%d", pass->planeta);
    printf("Quais recursos estão sendo transportados: ");
    fflush(stdin);
    scanf("%s", recur->recursos);
    /*dados->passageiro[i] = pass;
    dados->rt[i] = recur;*/
    i++;
}

int main()
{
    FilaPrio *fp;
    Nave *dados;
    consulta(fp, dados);
    dados = (Nave*)malloc(sizeof(Nave));
    inserirNaves(dados);
    fp = cria();
    fp->naves[fp->qtd] = dados;
    insere(fp,20);

    return 0;
}
