
void menu(int *opcao)
{
    printf("\n\nEditor de Listas:\n\n");
    printf(" 1 - Exibir Árvore\n");
    printf(" 2 - Inserir Elemento\n");
    printf(" 3 - Remover Elemento\n");
    printf(" 4 - Procurar Elemento\n");
    printf(" 5 - Exibir Informções\n");
    printf(" 6 - Balancear Árvore\n");
    printf(" 7 - Esvaziar Árvore\n");
    printf(" 0 - Sair\n");

    printf("\nDigite sua opção: ");
    scanf("%d", opcao);
    if(*opcao < 0 || *opcao > 7)
    {
        printf("\nOpção inválida");
        menu(opcao);
    }
}

void preenche(tabp *tree)
{
    int numeros[7] = { 3, 7, 9, 11, 8, 1, 57 };
    int i;
    for(i = 0; i < 7; i++)
    {
        insere(tree, numeros[i]);
    }
}

void exibir(tabp arvore)
{
    printf("\nPercurso IN ordem:\n");
    exibe_in(arvore);
    printf("\n\nPercurso PRE ordem:\n");
    exibe_pre(arvore);
    printf("\n\nPercurso POS ordem:\n");
    exibe_pos(arvore);
    printf("\n");
}

void inserir(tabp *tree)
{
    int elemento;
    printf("Digite o numero a ser inserido: ");
    scanf("%d", &elemento);
    if(insere(tree, elemento))
    {
        printf("Número inserido com sucesso !");
    }
    else
    {
        printf("Número já está na árvore !");
    }
}


void remover()
{
    printf("Método ainda não implementado.");
}


void procurar(tabp tree)
{
    int elemento;
    printf("Digite o numero a ser procurado: ");
    scanf("%d", &elemento);
    if(busca(tree, elemento))
    {
        printf("\nNúmero encontrado !");
    }
    else
    {
        printf("\nNúmero não foi encontrado !");
    }
}


void exibir_infos()
{
    printf("Método ainda não implementado.");
}

void balancear()
{
    printf("Método ainda não implementado.");
}

void esvaziar()
{
    printf("Método ainda não implementado.");
}


