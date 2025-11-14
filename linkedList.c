#include <stdio.h>
#include <stdlib.h>


struct no{
    int dado;
    struct no* prox;
};
typedef struct no* Lista;

Lista* cria_lista(){
    Lista* li;
    li = (Lista*)malloc(sizeof(*li));
    if(li == NULL){
        return NULL;
    }
    *li = NULL;

    return li;
}

int insereNoInicio(Lista *li, int valor){
    Lista aux = malloc(sizeof(struct no));
    if(aux == NULL){
        return -1;
    }
    aux->dado = valor;
    aux->prox = *li;
    *li = aux;

    return 0;
}
int insereNoFim(Lista *li, int valor){
    if(li == NULL){return -1;}
    Lista aux = malloc(sizeof(struct no));
    Lista aux2 = *li;
    aux->dado = valor;
    aux->prox = NULL;

    if(*li == NULL){
        aux->dado = valor;
        aux->prox = NULL;
        *li = aux;

        return 0;
    }
    while(aux2->prox != NULL){
        aux2 = aux2->prox;
    }
    aux2->prox = aux;

    return 0;
}
int imprimirLista(Lista *li){
    if(li == NULL){return -1;}
    Lista aux = *li;
    
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    return 0;

}
int buscaListaEnc(Lista *li, int valor){
    if(li == NULL){return -1;}
    Lista aux = *li;
    while(aux != NULL){
    if(aux->dado == valor){
        return aux->dado;
    }
    aux = aux->prox;
}

return -1;
}

Lista* concatenaLista(Lista *li, Lista *li2){
    if(li == NULL || li2 == NULL){return NULL;}
    Lista *li3 = cria_lista();
    Lista aux = *li;
    Lista aux2 = *li2;

    while(aux != NULL){
        insereNoFim(li3, aux->dado);
        aux = aux->prox;
    }
    while(aux2 != NULL){
        insereNoFim(li3, aux2->dado);
        aux2 = aux2->prox;
    }
    return li3;
}

Lista* removerPrimeirosElementos(Lista *li, int quantidade){
    if(li == NULL || quantidade < 0){return NULL;}
    Lista aux = *li;
    Lista temp;
    int contador = 0;

    while(contador < quantidade && aux != NULL){
        temp = aux;
        aux = aux->prox;
        free(temp);
        contador++;
}
    *li = aux;
    return li;
}
typedef struct{
    int maior;
    int posicao;
}maiorElemento;
maiorElemento buscarMaiorElemento(Lista *li){
    //tratamento de erro
    maiorElemento valorReturnErro;
    valorReturnErro.maior = -1;
    valorReturnErro.posicao = -1;
    if(li == NULL || *li == NULL){return valorReturnErro;}
    //codigo
    Lista aux = *li;
    int maior = aux->dado;
    int posicaoAtual = 0;
    int posicaoMaior = 0;
    maiorElemento valorReturn;

    while(aux != NULL){
        if(aux->dado > maior){
            maior = aux->dado;
            posicaoMaior = posicaoAtual;
        }
        aux = aux->prox;
        posicaoAtual++;
    }
    valorReturn.maior = maior;
    valorReturn.posicao = posicaoMaior;
    return valorReturn;
}

int contarNumerosPares(Lista *li){
    if(li == NULL || *li == NULL){return 0;}
    int contador = 0;
    Lista aux = *li;

    while(aux != NULL){
        if((aux->dado) % 2 == 0){
            contador++;
        }
        aux = aux->prox;
    }
    return contador;
}

float calcularMedia(Lista *li){
    if(li == NULL || *li == NULL){return -1;}
    Lista aux = *li;
    int soma = 0;
    int quant = 0;
    float media = 0.0;

    while(aux != NULL){
        soma += aux->dado;
        aux = aux->prox;
        quant++;
    }
    media = (float) soma / quant;
    
    return media;
}
Lista* copiaLista(Lista *li, Lista *li2){
    if(li == NULL || *li == NULL || li2 == NULL){return NULL;}
    Lista aux = *li;
    Lista aux2;
    int repetido = 0;

    while(aux != NULL){
        aux2 = *li2;
        while(aux2 != NULL){
            
            if(aux->dado == aux2->dado){
                repetido = 1;
                break;
            }
            aux2 = aux2->prox;
            
        }
        if(repetido == 0){
            insereNoFim(li2, aux->dado);
        }
        repetido = 0;
        aux = aux->prox;
      

    }
    return li2;

}
Lista* inverteLista(Lista *li){
    if(li == NULL || *li == NULL){return NULL;}
    Lista aux = *li;
    Lista *li2 = cria_lista();

    while(aux != NULL){
        insereNoInicio(li2, aux->dado);
        aux = aux->prox;
    }
    return li2;
}

int* copiarParaVetor(Lista *li){
    Lista aux = *li;
    int tamanho = 0;

    while(aux != NULL){
        tamanho++;
        aux = aux->prox;
    }

    int *vetor = malloc(tamanho*sizeof(int));
    if(vetor == NULL){return NULL;}
    aux = *li;

    for(int i = 0; aux != NULL; i++){
        vetor[i] = aux->dado;
        aux = aux->prox;
    }
    return vetor;
}

int comparaListas(Lista *li, Lista *li2){
    Lista aux = *li;
    Lista aux2 = *li2;

    while(aux != NULL && aux2 != NULL){
        if(aux->dado != aux2->dado){
            return 0;
        }
           
            aux = aux->prox;
            aux2 = aux2->prox;
            
        
    }

    if(aux == NULL && aux2 == NULL){
        return 1;
    }
    else{
        return 0;
    }
    
}
//Faça uma função que verifique se uma lista está contida na outra
//usando buscaListaEnc
int contemLista(Lista *li, Lista *li2){
  if(li == NULL || li2 == NULL || *li == NULL || *li2 == NULL){return -1;}
  Lista aux = *li;
  Lista aux2 = *li2;
  int busca;
  int contador = 0;
  int tamanhoLi2 = 0;
  while(aux2 != NULL){
    tamanhoLi2++;
    aux2=aux2->prox;
  }
  aux2 = *li2;
  while(aux2 != NULL){
    busca = buscaListaEnc(li, aux2->dado);
    if(busca != -1){
      contador++;
    }
    aux2 = aux2->prox;
  }
  if(contador == tamanhoLi2){
    return 1;
  }
  return 0;
  

}
//sem usar buscaListaEnc
int contemLista2(Lista *li, Lista *li2){
  if(li == NULL || li2 == NULL || *li == NULL || *li2 == NULL){return -1;}
  Lista aux = *li;
  Lista aux2 = *li2;
  int flag = 0;
  
  while(aux != NULL){
    if(aux2->dado == aux->dado){
      flag = 1;
    }
    if(flag == 1){
      aux2 = aux2->prox;
      aux = *li;
      flag = 0;
    }
    if(aux->prox == NULL && flag == 0){
      return 0;
    }
    aux = aux->prox;
    
    
  }
  if(aux2 == NULL){
      return 1;
    }
    return 0;
}


int main() {
    Lista *lista1 = cria_lista();
    Lista *lista2 = cria_lista();
    Lista *lista3 = cria_lista();

    // Inserindo elementos
    insereNoFim(lista1, 1);
    insereNoFim(lista1, 2);
    insereNoFim(lista1, 3);
    insereNoFim(lista1, 4);
    insereNoFim(lista1, 5);

    insereNoFim(lista2, 2);
    insereNoFim(lista2, 4);

    insereNoFim(lista3, 7);
    insereNoFim(lista3, 8);

    printf("Lista 1: ");
    imprimirLista(lista1);
    printf("\nLista 2: ");
    imprimirLista(lista2);
    printf("\nLista 3: ");
    imprimirLista(lista3);

    // Teste contemLista
    printf("\n\nLista 2 está contida em Lista 1 (com busca)? %s", contemLista(lista1, lista2) == 1 ? "Sim" : "Não");
    printf("\nLista 3 está contida em Lista 1 (com busca)? %s", contemLista(lista1, lista3) == 1 ? "Sim" : "Não");

    // Teste contemLista2
    printf("\n\nLista 2 está contida em Lista 1 (sem busca)? %s", contemLista2(lista1, lista2) == 1 ? "Sim" : "Não");
    printf("\nLista 3 está contida em Lista 1 (sem busca)? %s", contemLista2(lista1, lista3) == 1 ? "Sim" : "Não");

    // Teste comparação
    printf("\n\nLista 1 e Lista 2 são iguais? %s", comparaListas(lista1, lista2) == 1 ? "Sim" : "Não");

    // Teste inversão
    Lista *listaInvertida = inverteLista(lista1);
    printf("\nLista 1 invertida: ");
    imprimirLista(listaInvertida);

    // Teste cópia sem repetição
    Lista *listaCopia = cria_lista();
    copiaLista(lista1, listaCopia);
    printf("\nCópia da Lista 1 sem repetição: ");
    imprimirLista(listaCopia);

    // Teste média
    printf("\n\nMédia dos valores da Lista 1: %.2f", calcularMedia(lista1));

    // Teste pares
    printf("\nQuantidade de pares na Lista 1: %d\n", contarNumerosPares(lista1));

    return 0;
}
