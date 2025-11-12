#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
} NO;
typedef struct no *ArvBin;

ArvBin *cria_arv()
{
    ArvBin *raiz = malloc(sizeof(ArvBin));
    if (raiz != NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}
int isVazia(ArvBin *raiz)
{
    if (raiz == NULL || *raiz == NULL)
    {
        return 0;
    }
    return 1;
}

void preOrdem_ArvBin(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return;
    }
    // raiz, esq, dir
    if (*raiz != NULL)
    {
        printf("%d ", (*raiz)->dado);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}
void posOrdem_ArvBin(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return;
    }
    // esq, dir, raiz
    if (*raiz != NULL)
    {
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d ", (*raiz)->dado);
    }
}
void emOrdem_ArvBin(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return;
    }
    // esq, raiz, dir
    if (*raiz != NULL)
    {
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d ", (*raiz)->dado);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}
// peso da arvore

int peso_ArvBin(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return 0;
    }
    int peso = 1;
    peso += peso_ArvBin(&((*raiz)->esq));
    peso += peso_ArvBin(&((*raiz)->dir));

    return peso;
}

int altura_ArvBin(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return 0;
    }

    int altura_esq = 0;
    int altura_dir = 0;
    if ((*raiz)->esq != NULL)
    {
        altura_esq += altura_ArvBin(&((*raiz)->esq));
    }
    if ((*raiz)->dir != NULL)
    {
        altura_dir += altura_ArvBin(&((*raiz)->dir));
    }

    if (altura_dir > altura_esq)
    {
        return altura_dir + 1;
    }

    return altura_esq + 1;
}

int insereNo(ArvBin *raiz, NO n)
{

    if (raiz == NULL)
    {
        return 0;
    }
    if (*raiz == NULL)
    {
        *raiz = malloc(sizeof(NO));
        (*raiz)->dado = n.dado;
        (*raiz)->dir = n.dir;
        (*raiz)->esq = n.esq;

        return 1;
    }
    int altura = altura_ArvBin(raiz);
    int pesoDir = peso_ArvBin(&((*raiz)->dir));
    int pesoEsq = peso_ArvBin(&((*raiz)->esq));

    if (pesoDir != altura)
    {
        if ((*raiz)->dir == NULL)
        {
            (*raiz)->dir = malloc(sizeof(NO));
            if ((*raiz)->dir == NULL)
            {
                return 0;
            }
            (*raiz)->dir->dado = n.dado;
            (*raiz)->dir->dir = n.dir;
            (*raiz)->dir->esq = n.esq;
            return 1;
        }
        return insereNo(&((*raiz)->dir), n);
    }

    if (pesoEsq != altura)
    {

        if ((*raiz)->esq == NULL)
        {
            (*raiz)->esq = malloc(sizeof(NO));
            if ((*raiz)->esq == NULL)
            {
                return 0;
            }
            (*raiz)->esq->dado = n.dado;
            (*raiz)->esq->dir = n.dir;
            (*raiz)->esq->esq = n.esq;
            return 1;
        }
        return insereNo(&((*raiz)->esq), n);
    }
    return 0;
}
void liberaArvBin(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return 0;
    }

    if ((*raiz)->esq != NULL)
    {

        liberaArvBin(&((*raiz)->esq));
    }
    if ((*raiz)->dir != NULL)
    {

        liberaArvBin(&((*raiz)->dir));
    }

    free(*raiz);
    *raiz = NULL;
}

void insereNoTradicional(ArvBin *raiz, int valor)
{
    if (raiz == NULL)
    {
        return;
    }

    if (*raiz == NULL)
    {
        (*raiz) = malloc(sizeof(NO));
        (*raiz)->dado = valor;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
        return;
    }

    if (valor < ((*raiz)->dado))
    {
        insereNoTradicional((&((*raiz)->esq)), valor);
    }
    else if (valor > ((*raiz)->dado))
    {
        insereNoTradicional((&((*raiz)->dir)), valor);
    }
    else
    {
        return;
    }
}

int buscaArvBin(ArvBin *raiz, int dadoBuscado)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return 0;
    }

    if ((*raiz)->dado == dadoBuscado)
    {
        return 1;
    }
    else if ((*raiz)->dado > dadoBuscado)
    {
        return buscaArvBin((&((*raiz)->esq)), dadoBuscado);
    }
    else if ((*raiz)->dado < dadoBuscado)
    {
        return buscaArvBin((&((*raiz)->dir)), dadoBuscado);
    }
    return 0;
}

void removerNo(ArvBin *raiz, int dado_remocao)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return;
    }
    ArvBin aux = *raiz;
    if ((*raiz)->dado == dado_remocao)
    {
        if ((*raiz)->dir == NULL && (*raiz)->esq == NULL)
        {
            free(*raiz);
            *raiz = NULL;
            return;
        }
        else if ((*raiz)->dir != NULL ^ (*raiz)->esq != NULL)
        {
            if ((*raiz)->dir != NULL)
            {
                aux = (*raiz)->dir;
                free(*raiz);
                *raiz = aux;
                return;
            }
            if ((*raiz)->esq != NULL)
            {
                aux = (*raiz)->esq;
                free(*raiz);
                *raiz = aux;
                return;
            }
        }
        else
        {
            ArvBin aux2 = (*raiz)->dir;
            ArvBin pai = (*raiz)->dir; // parei aqui
            while (aux2->esq != NULL)
            {
                pai = aux2;
                aux2 = aux2->esq;
            }
            if (pai == aux2)
            {
                (*raiz)->dir = aux2->dir;
                (*raiz)->dado = aux2->dado;
                free(aux2);
                return;
            }
            if (aux2->dir != NULL)
            {
                pai->esq = aux2->dir;
            }
            else
            {
                pai->esq = NULL;
            }
            (*raiz)->dado = aux2->dado;
            free(aux2);
        }
    }
    if ((*raiz)->dado > dado_remocao)
    {
        removerNo((&((*raiz)->esq)), dado_remocao);
    }
    else if ((*raiz)->dado < dado_remocao)
    {
        removerNo((&(*raiz)->dir), dado_remocao);
    }

    return;
}

int buscaMenorElemento(ArvBin *raiz)
{
    ArvBin aux = *raiz;
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return 0;
    }
    if ((*raiz)->esq == NULL)
    {
        return (*raiz)->dado;
    }
    while (aux->esq != NULL)
    {
        aux = aux->esq;
    }
    return aux->dado;
}

int buscaMaiorElemento(ArvBin *raiz)
{
    ArvBin aux = *raiz;
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return 0;
    }
    if ((*raiz)->dir == NULL)
    {
        return (*raiz)->dado;
    }

    while (aux->dir != NULL)
    {
        aux = aux->dir;
    }
    return aux->dado;
}

int contarFolhas(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return 0;
    }

    ArvBin aux = *raiz;
    if ((*raiz)->dir == NULL && (*raiz)->esq == NULL)
    {
        return 1;
    }
    int folhasEsquerda = contarFolhas((&((*raiz)->esq)));
    int folhasDireita = contarFolhas((&((*raiz)->dir)));

    return folhasDireita + folhasEsquerda;
}

void imprimeArvBin(ArvBin *raiz)
{
    int vazia = isVazia(raiz);
    if (vazia == 0)
    {
        return;
    }
}

int main()
{

    return 0;
}