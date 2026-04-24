# Data_Structure

Implementações de estruturas de dados fundamentais em C, desenvolvidas como parte dos estudos de Estruturas de Dados na graduação em Ciência da Computação.

---

## Estruturas implementadas

### Árvore Binária de Busca — `arvBin.c`

Implementação de uma árvore binária de busca (BST) com as operações clássicas:

- Inserção de nós
- Busca por valor
- Percursos (pré-ordem, em-ordem, pós-ordem)
- Remoção de nós

A árvore binária de busca mantém a propriedade de que, para cada nó, todos os valores à esquerda são menores e todos à direita são maiores, garantindo busca em O(log n) no caso médio.

### Lista Encadeada — `linkedList.c`

Implementação de lista encadeada simples com alocação dinâmica de memória:

- Inserção no início e no fim
- Remoção por valor
- Percurso e exibição da lista
- Liberação de memória

---

## Linguagem e compilação

**Linguagem:** C

Para compilar e executar qualquer arquivo:

```bash
gcc arvBin.c -o arvBin
./arvBin

gcc linkedList.c -o linkedList
./linkedList
```

---

## Contexto

Estes arquivos fazem parte do estudo de estruturas de dados clássicas com foco em entender a implementação interna das estruturas usadas em sistemas reais — como bancos de dados, sistemas operacionais e compiladores. Veja também os repositórios [b_tree](https://github.com/ThiagoGama1/b_tree) e [B_tree2](https://github.com/ThiagoGama1/B_tree2) para a implementação de Árvore B em C.
