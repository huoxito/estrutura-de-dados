#ifndef ABP_H
#define ABP_H

// tipo base para o elemento usado na árvore
typedef int telem;

// estrutura de cada nó
typedef struct no {
    // ponteiro para o filho da esquerda
    struct no * esq;
    
    // elemento armazenado no nó
    telem dado;
    
    // ponteiro para o filho da direita
    struct no * dir;
} tno;

// tipo equivalente a um ponteiro para um nó, usado para o
// ponteiro inicial da árvore (que aponta para o nó raiz)
typedef tno* tabp;

// inicializa a árvore, deixando-a pronta para ser utilizada
void inicializa(tabp* T)
{
    // define o ponteiro inicial como NULL (árvore vazia)
    *T = NULL;
}

// verifica se a árvore está vazia
int vazia(tabp T)
{
    if (T == NULL) return 1;
    else return 0;
}

// exibe os elementos de uma ABP, usando um percurso IN-Ordem (recursivo)
void exibe_in(tabp T)
{
    if (T != NULL) {
        exibe_in(T->esq);
        printf("%d ", T->dado);
        exibe_in(T->dir);
    }
}

// exibe os elementos de uma ABP, usando um percurso POS-Ordem (recursivo)
void exibe_pos(tabp tree)
{
    int i = 0;
    if (tree != NULL) {
        exibe_pos(tree->esq);
        exibe_pos(tree->dir);
        printf("%d ", tree->dado);
    }
}

// exibe os elementos de uma ABP, usando um percurso PRE-Ordem
// usando espaços para definir o nível dos nós
void exibe_pre(tabp T)
{
    int i;
    if (T != NULL) {
        printf("%d ", T->dado);
        exibe_pre(T->esq);
        exibe_pre(T->dir);
    }
}

// insere um novo nó na árvore, respeitando as regras da ABP
int insere(tabp *T, telem e)
{
    // variável auxiliar
    tno* raiz;
    
    // se a árvore (ou subárvore) estiver vazia, insere o nó na raíz
    if (vazia(*T)) {
        // aloca o novo nó
        raiz = (tno*) malloc(sizeof(tno));
        
        // verifica se consguiu alocar memória
        if (raiz == NULL) return 0; // erro: memória insuficiente
        
        // define os filhos como NULL
        raiz->esq = NULL;
        raiz->dir = NULL;
        
        // preenche com o elemento
        raiz->dado = e;
        *T = raiz;
        
        // inserção realizada com sucesso
        return 1;
    }
    
    raiz = *T;
    
    // se o elemento a ser inserido for menor que o valor do nó, 
    // tenta inserir na subárvore esquerda, recursivamente
    if (e < raiz->dado) return insere(&(raiz->esq), e);
    // se o elemento a ser inserido for maior que o valor do nó, 
    // tenta inserir na subárvore direita, recursivamente
    else if (e > raiz->dado) return insere(&(raiz->dir), e);
    // se o elemento for igual, é porque já existe na árvore
    else return 0;
}

// remove um elemento da árvore
int exclui(tabp *T, telem *e)
{
    // implemente aqui a operação de remover um nó de uma ABP
}

// procura um elemento na árvores, retornando um ponteiro para o
// nó, caso seja encontrado, ou NULL caso contrário
tno* busca(tabp T, telem e)
{
    // verifica se a árvore (ou subárvore) está vazia
    if (vazia(T)) return NULL;
    
    // se o elemento procurado estiver na raiz, retorna o endereço do nó
    if (T->dado == e) return T;
    
    // se o elemento procurado for menor que a raiz,
    // procura na subárvore esquerda, recurvisamente
    if (e < T->dado) return busca(T->esq, e);
    // se for maior, procura na subárvore esquerda
    else return busca(T->dir, e);
}

#endif
