
void menu(int *opcao)
{
    printf("\n\nEditor de Listas:\n\n");
    printf(" 1 - Exibir lista\n");
    printf(" 2 - Inserir Elemento\n");
    printf(" 3 - Remover Elemento\n");
    printf(" 4 - Exibir Elemento\n");
    printf(" 5 - Procurar Elemento\n");
    printf(" 6 - Esvaziar Lista\n");
    printf(" 0 - Sair\n");

    printf("\nDigite sua opção: ");
    scanf("%d", opcao);
    if(*opcao < 0 || *opcao > 7)
    {
        printf("\nOpção inválida");
        menu(opcao);
    }
}

void preenche(tlista *lista)
{
    int numeros[7] = { 3, 7, 9, 11, 8, 1, 57 };
    int i;
    for(i = 0; i < 7; i++)
    {
        insere(lista, numeros[i], i+1);
    }
}

void inserir_elemento(tlista *lista)
{
    int elemento, posicao;

    printf("Digite o numero inteiro: ");
    scanf("%d", &elemento);

    printf("Digite a posicao desejada pelo elemento na lista: ");
    scanf("%d", &posicao);

    if(insere(lista, elemento, posicao))
    {
        printf("Elemento %d inserido na lista");
    }
    else
    {
        printf("Posição inválida");
    }
}

void remover(tlista *lista)
{
    int posicao;
    printf("Digite a posição do elemento a ser removido: ");
    scanf("%d", &posicao);
    exclui(lista, posicao); 
}

void exibir_elemento(tlista *lista)
{
    int posicao;
    printf("Digite a posição do elemento que deseja exibir: ");
    scanf("%d", &posicao);
    printf("Elemento da posição %d é %d\n", posicao, exibe(*lista, posicao));
}


void buscar(tlista *lista)
{
    int elemento, result;
    printf("Digite o elemento que deseja encontrar: ");
    scanf("%d", &elemento);
    result = busca(*lista, elemento);
    if(result)
    {
        printf("\nElemento %d encontrado na posição %d", elemento, result);
    }
    else
    {
        printf("\nElemento não foi encontrado");
    }
}

void esvaziar(tlista *lista)
{
    esvazia(lista);
}

