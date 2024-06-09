# SortLinkedList

Este repositório é dedicado à implementação de algoritmos de ordenação para listas duplamente encadeadas.

## Colaboradores
- [Saulo Pires](https://github.com/Saulo-spv)
- [Gabriel Matos](https://github.com/santos-gmatos)

## Estrutura das Pastas

O projeto está organizado da seguinte forma:

- **SortingAlgorithm**: Esta pasta contém a implementação dos algoritmos de ordenação para listas duplamente encadeadas.
- **TimeMeasure**: Aqui estão os tempos de ordenação de 100 listas com 10 mil elementos. Esses dados podem ser usados para avaliar o desempenho dos algoritmos implementados.

## Como Executar o Código

Para executar os algoritmos de ordenação, siga estas etapas:

1. Clone este repositório em sua máquina local:

```bash
git clone https://github.com/seu-usuario/SortLinkedList.git
```

2. Navegue até o diretório onde o repositório foi clonado:

```bash
cd SortLinkedList
```

3. Compile os arquivos em um executável:
```bash
c++ main.cpp scr/linkedList/linkedList.cpp scr/linkedList/SortingAlgorithm/bubbleSort.cpp scr/linkedList/SortingAlgorithm/selectionSort.cpp scr/linkedList/SortingAlgorithm/insertionSort.cpp scr/linkedList/SortingAlgorithm/bogoSort.cpp scr/linkedList/SortingAlgorithm/shellSort.cpp scr/binaryTree/binaryTree.cpp -o main -I scr/linkedList -I scr/binaryTree
```

4. Execute o código:
```bash
 ./main
```
