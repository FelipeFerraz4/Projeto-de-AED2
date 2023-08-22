#include <stdio.h>
#include <stdlib.h>
#include "filaDePrioridades.h"

void inserirNaves(Nave *dados){
    int i = 0;
    Passageiro passageiro1;
    Recurso recurso1;
    printf("Digite o nome do passageiro: \n");
    scanf("%s", passageiro1.nome);
    printf("Digite a idade do passageiro: \n");
    scanf("%d", &passageiro1.idade);
    printf("Digite o planeta do passageiro: \n");
    scanf("%s", passageiro1.planeta);
    printf("Nome do recurso transportados: \n");
    scanf("%s", recurso1.nome);
    /*dados->passageiro[i] = pass;
    dados->rt[i] = recur;*/
    i++;
}

int main()
{
    FilaPrio *fp;
    Nave *dados;
    //consulta(fp, dados);
    dados = (Nave*)malloc(sizeof(Nave));
    inserirNaves(dados);
    fp = cria();
    //fp->naves[fp->qtd] = dados;
    //insere(fp,20);

    return 0;
}
