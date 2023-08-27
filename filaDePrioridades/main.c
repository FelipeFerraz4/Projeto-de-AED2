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

    nave1.tipo_nave = 1 + rand() % 10;
    nave1.prioridade = rand() % 100 * nave1.tipo_nave;


    printf("\nprioridade: %d\n", nave1.prioridade);
    printf("\nTipo da nave: %d\n", nave1.tipo_nave);

    printf("Quantos passageiros a nave possui: \n");
    scanf("%d", &nave1.size_passageiro);

    for(int i = 1; i <= nave1.size_passageiro; i++){
        nave1.passageiros[i] = get_passageiro();
    }

    printf("Quantos recursos a nave possui: \n");
    scanf("%d", &nave1.size_recursos_transportados);

    for(int i = 1; i <= nave1.size_recursos_transportados; i++){
        nave1.recurso[i] = get_recurso();
    }

    return nave1;
}

void menu(){
    printf("\n\t[ MENU ]");
    printf("\n[1] - Inserir naves\n[2] - Remover nave\n[3] - Imprimir naves\n[4] - Sair\n");
}

int main()
{
    srand((unsigned)time(NULL));
    int option = 0;

    FilaPrio *heap;
    heap = criar_heap();

    do{
        menu();
        printf("\nEscolha uma opção: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                if(inserir(heap, get_nave()))
                    printf("\nNave inserida com sucesso!!\n");
                else
                    printf("\nErro ao inserir nave, fila cheia\n");
            break;
            case 2:
                if(remover(heap))
                    printf("\nNave removida com sucesso!!\n");
                else
                    printf("\nErro ao remover nave, fila vazia\n");
            break;
            case 3:
                for(int i = 1; i < heap->size_nave; i++){
                    printf("\nNave[%d] - Prioridade: %d", i, heap->naves[i].prioridade);
                }
                printf("\n");
            break;
            case 4:
                printf("\nAté breve :)");
            break;
            default:
                printf("\nOPÇÃO INVÁLIDA\n");
            break;
    }
    }while(option != 4);

    return 0;
}
