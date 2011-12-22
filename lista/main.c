#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "helpers.h"

int main()
{
    tlista a;
    int opcao;

    inicializa(&a);
    preenche(&a);

    while(opcao != 0)
    {
        switch(opcao)
        {
            case 1:
                exibe_lista(a);
                break;
            case 2:
                inserir_elemento(&a);
                break;
            case 3:
                remover(&a);
            case 4:
                exibir_elemento(&a);
            case 5:
                buscar(&a);
            case 6:
                esvaziar(&a);
        }
        menu(&opcao);
    }
    printf("Good Bye !!!\n\n");
}
