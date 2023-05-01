#include <stdlib.h>

void bfsTraversal(t *root) {
  // Verifica se a árvore é nula
  if (root == NULL) {
    return;
  }

  // Cria uma fila para armazenar os nós da árvore
  t *queue[1000];
  int front = -1, rear = -1;

  // Adiciona a raiz da árvore na fila
  queue[++rear] = root;

  // Loop para processar todos os nós da fila
  while (front != rear) {
    // Remove o primeiro nó da fila e o exibe
    t *node = queue[++front];
    printf("%d ", node->dado.chave);

    // Adiciona os filhos do nó removido na fila
    if (node->esq != NULL) {
      queue[++rear] = node->esq;
    }
    if (node->dir != NULL) {
      queue[++rear] = node->dir;
    }
  }
}