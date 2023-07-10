#ifndef HEAP_H
#define HEAP_H

#define pai(i) ((i - 1)/2)
#define filho_esquerdo(i) (2 * i + 1)
#define filho_dir(i) (2 * i + 2)

typedef struct fila fila_prioritaria;

// Função auxiliar
void permuta(int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

// Funções
void insere (fila_prioritaria *f, int elem);
void sobe_no_heap(fila_prioritaria *f, int posicao);
int remove_maior(fila_prioritaria *f);
void desce_no_heap(fila_prioritaria *f, int posicao);
void altera_prioridade (fila_prioritaria *f, int posicao, int novo_valor);
void constroi_heap(fila_prioritaria *f);
void heapsort(fila_prioritaria *f);


#endif