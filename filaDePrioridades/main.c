#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filaDePrioridades.h"

#define MAX_TAMANHO_LINHA_FILE 500

int get_nave_file(FilaPrio *heap){
    char buffer[MAX_TAMANHO_LINHA_FILE];
    int count = 0;

    FILE* file = fopen("naves.csv", "r");

    if (file == NULL){
        printf("Erro ao abrir o arquivo. \n");
        return 0;
    }

    //paga a primeira linha da lista, que tem o nome dos parametos
    fgets(buffer, sizeof(buffer), file);

    //leitura do arquivo até ler uma linha nula
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        Nave nave;

        char prioridade[20];
        strcpy(prioridade, strtok(buffer, ","));
        nave.prioridade = atoi(prioridade);

        char tipo_nave[20];
        strcpy(tipo_nave, strtok(NULL, ","));
        nave.tipo_nave = atoi(tipo_nave);

        char quantidade_passageiros[20];
        strcpy(quantidade_passageiros, strtok(NULL, ","));
        nave.size_passageiro = atoi(quantidade_passageiros);

        char quantidade_recursos[20];
        strcpy(quantidade_recursos, strtok(NULL, ","));
        nave.size_recursos_transportados = atoi(quantidade_recursos);

        for(int i = 0; i < nave.size_passageiro; i++) {
            Passageiro passageiro;

            char id_passageiro[20];
            strcpy(id_passageiro, strtok(NULL, ","));
            passageiro.id = atoi(id_passageiro);

            char nome_passageiro[100];
            strcpy(nome_passageiro, strtok(NULL, ","));
            strcpy(passageiro.nome ,nome_passageiro);

            char idade_passageiro[20];
            strcpy(idade_passageiro, strtok(NULL, ","));
            passageiro.idade = atoi(idade_passageiro);

            char planeta_passageiro[100];
            strcpy(planeta_passageiro, strtok(NULL, ","));
            strcpy(passageiro.planeta ,planeta_passageiro);

            nave.passageiros[i] = passageiro;
        }

        for(int i = 0; i < nave.size_recursos_transportados; i++){
            Recurso recurso;

            char quantidade_produto[20];
            strcpy(quantidade_produto, strtok(NULL, ","));
            recurso.quantidade = atoi(quantidade_produto);

            char nome_produto[100];
            strcpy(nome_produto, strtok(NULL, ","));
            strcpy(recurso.nome ,nome_produto);

            nave.recurso[i] = recurso;
        }

        heap->naves[count] = nave;
        count++;

    }

    heap->size_nave = count;
    return 1;
}

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
    Heap *fila_de_naves;
    fila_de_naves = criar_heap();

    get_nave_file(fila_de_naves);

    get_nave_file(heap);

    do{
        menu();
        printf("\nEscolha uma opcao: ");
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
                printf("\nAte breve :)");
            break;
            default:
                printf("\nOPCAO INVÁLIDA\n");
            break;
    }
    }while(option != 4);

    return 0;
}
