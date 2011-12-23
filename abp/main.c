#include <stdio.h>
#include <stdlib.h>
#include "abp.h"
#include "helpers.h"

int main()
{
    tabp a;
    int opcao;

    inicializa(&a);
    preenche(&a);

    while(opcao != 0)
    {
        switch(opcao)
        {
            case 1:
                exibir(a);
                break;
            case 2:
                inserir(&a);
                break;
            case 3:
                remover();
                break;
            case 4:
                procurar(a);
                break;
            case 5:
                exibir_infos();
                break;
            case 6:
                balancear();
                break;
            case 7:
                esvaziar();
                break;
        }
        menu(&opcao);
    }
    printf("Good Bye !!!\n\n");
}
