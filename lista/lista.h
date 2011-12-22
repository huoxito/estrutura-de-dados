#ifndef LISTA_H
#define LISTA_H

typedef int telem;

typedef struct no {
    telem dado;
    struct no *prox;
} tno;

typedef tno* tlista;

void inicializa(tlista *p)
{
    *p = NULL;
}

int tamanho(tlista lista)
{
    int n = 0;
    while (lista != NULL) {
        lista = lista->prox;
        n++;
    }
    return n;
}

int vazia (tlista lista){
    if(!lista){
        return 1;
    }else{
        return 0;
    }
}

int insere(tlista *L, telem elem, int pos)
{
    int n = 1;
    tno *novo;
    tlista P = *L;
    
    if (pos < 1) return 0; // posição inválida

    novo = (tno*) malloc(sizeof(tno)); // aloca dinamicamente novo item da lista

    // inserção na primeira posição
    if (pos == 1)
    {
        if (novo == NULL) return 0; // não conseguiu alocar memória
        novo->dado = elem; // insere elemento
        novo->prox = NULL; // ultimo nó sempre aponta pra NULL
        *L = novo; // Lista agora com um elemento + o prox que é NULL
        return 1;
    }
    // inserção da segunda posição em diante
    while (P != NULL) // percorrendo a lista
    {
        if (n == pos - 1)
        {
            novo->dado = elem;
            novo->prox = P->prox;
            P->prox = novo; // bug?: Quando lista já existe o método exclui os próximos elementos da lista
            return 1;
        }
        P = P->prox;
        n++;
    }
    
    free(novo); // libero caso não tenha ocorrido a inserção
    return 0;
}

int exibe_lista(tlista L)
{
    if(!L){
        printf("\nLista está vazia insira alguns elementos por favor\n");
        return 0;
    }
    printf("\nLista: ");
    while (L != NULL) {
        printf("%d ", L->dado);
        L = L->prox;
    }
    printf("\n");
    return 1;
}

int exclui(tlista *lista, telem posicao)
{
    int contador = 1;
    tlista elemento_anterior;
    tlista elemento_a_deletar; 
    tlista p_lista = *lista; // var auxiliar pra percorrer a lista
	
    if(posicao == 1) 
    {
        elemento_a_deletar = p_lista;
        *lista = p_lista->prox;
        free(elemento_a_deletar);
    }
    else
    {
        // Percore a lista até o elemento anterior ao deletado.
        while(contador < posicao - 1){
            p_lista = p_lista->prox;
            contador++;
	    }
        elemento_anterior = p_lista;
        elemento_a_deletar = p_lista->prox;

        // Atribuir o nó do elemento a ser deletado ao elemento anterior.
        elemento_anterior->prox = elemento_a_deletar->prox;
        free(elemento_a_deletar);
	}
    return 1;
}


// Exibe um elemento da lista dada uma determinada posição
int exibe(tlista L, telem posicao)
{
    int auxiliar = 1;
    while (L != NULL) {
        if (auxiliar == posicao) {
            return L->dado;
        }
        L = L->prox;
        auxiliar++;
    }
    return 0;
}

int busca(tlista lista, telem elemento)
{
    int posicao = 1;
    while(lista != NULL)
    {
        if(elemento == lista->dado)
        {
            return posicao;
        }
        lista = lista->prox;
        posicao++;
    }
    return 0;
}

void esvazia(tlista *lista)
{
    int size, i;
    size = tamanho(*lista);
    for(i = size; i > 0; i--)
    {
        exclui(lista, i);
    }
}

#endif
