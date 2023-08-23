#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filaDePrioridades.h"

Passageiro get_passageiro(){
    Passageiro passageiro1;

    passageiro1.id = rand() % 100;

    printf("Digite o nome do passageiro: \n");
    scanf("%s", passageiro1.nome);

    printf("Digite a idade do passageiro: \n");
    scanf("%d", &passageiro1.idade);

    printf("Digite o planeta do passageiro: \n");
    scanf("%s", passageiro1.planeta);

    return passageiro1;
}

Recurso get_recurso(){
    Recurso recurso1;

    printf("Nome do recurso transportado: \n");
    scanf("%s", recurso1.nome);

    printf("Quantidade do recurso transportado: \n");
    scanf("%d", &recurso1.quantidade);

    return recurso1;
}

Nave get_nave(){
    Nave nave1;

    nave1.prioridade = rand() % 100;

    printf("Quantos passageiros a nave possui: \n");
    scanf("%d", &nave1.size_passageiro);

    for(int i = 0; i < nave1.size_passageiro; i++){
        nave1.passageiros[i] = get_passageiro();
    }

    printf("Quantos recursos a nave possui: \n");
    scanf("%d", &nave1.size_recursos_transportados);

    for(int i = 0; i < nave1.size_recursos_transportados; i++){
        nave1.recurso[i] = get_recurso();
    }

    return nave1;
}

int main()
{
    srand((unsigned)time(NULL));

    FilaPrio heap;
    heap.size_nave = 1;
    heap.naves[0] = get_nave();

    return 0;
}
