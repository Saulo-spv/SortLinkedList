### Shell Sort para Lista Duplamente Encadeada

#### Descrição do Algoritmo

O Shell Sort é um algoritmo de ordenação que generaliza o Insertion Sort para permitir a troca de elementos que estão distantes uns dos outros. O algoritmo utiliza uma sequência de gaps decrescentes para ordenar sublistas espaçadas pelo gap. Começa encontrando o comprimento da lista e utiliza a função `regresseK` para retroceder k posições na lista a partir de um nó dado. Durante a ordenação, funciona de maneira semelhante ao Insertion Sort, movendo os elementos maiores para a posição correta dentro de suas sublistas ordenadas. A cada iteração, o gap é reduzido até atingir 1, garantindo que a lista seja finalmente ordenada de forma crescente.

#### Exemplo de Execução

Vamos considerar a seguinte lista inicial:

78, 59, 77, 72, 56, 62, 54, 67, 1, 92

##### Passo a Passo

**Lista Inicial:**

Elements:
78 59 77 72 56 62 54 67 1 92

**Gap 5:**

Sublistas para Gap 5:
[78, 62], [59, 54], [77, 67], [72, 1], [56, 92]

Após ordenar sublistas:
[62, 78], [54, 59], [67, 77], [1, 72], [56, 92]

Lista após Gap 5:
62, 54, 67, 1, 56, 78, 59, 77, 72, 92

**Gap 2:**

Sublistas para Gap 2:
[62, 67, 56, 59, 72], [54, 1, 78, 77, 92]

Após ordenar sublistas:
[56, 1, 59, 54, 62, 67, 72, 77, 78, 92]

Lista após Gap 2:
56, 1, 59, 54, 62, 77, 67, 78, 72, 92

**Gap 1:**

Lista inicial para Gap 1:
56, 1, 59, 54, 62, 77, 67, 78, 72, 92

Após ordenar:
1, 54, 56, 59, 62, 67, 72, 77, 78, 92

**Resultado Final**

O resultado final após aplicar o Shell Sort é uma lista ordenada:

1, 54, 56, 59, 62, 67, 72, 77, 78, 92

#### Desempenho

Este exemplo demonstra como o Shell Sort utiliza gaps decrescentes para reorganizar a lista de maneira eficiente, resultando em uma lista ordenada após a última iteração com gap 1.
