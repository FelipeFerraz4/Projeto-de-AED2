#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDePrioridades.h"

int main()
{
    //criando o heap
    Heap *fila_de_naves;
    fila_de_naves = criar_heap();

    //criando a tabela hash
    TableHash* hash_nave;
    hash_nave = cria_hash();

    //lendo o arquivo csv
    get_nave_file(fila_de_naves);

    //testes de cada estrutura (heap e hash)
    //teste_heap(fila_de_naves);
    //teste_hash();

    //fun��o que inicia a intera��o com o usu�rio
    option_programa(fila_de_naves, hash_nave);

    //um printf padr�o com mensagem de motiva��o
    printf("Hello world!\n");

    //libera��o das estruturas heap e hash
    libera_hash(hash_nave);
    libera_heap(fila_de_naves);

    return 0;
}
