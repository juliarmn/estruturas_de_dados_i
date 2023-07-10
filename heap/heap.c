#include <stdio.h>
#include "heap.h"

struct fila {
  int *chave;
  int tam_max;
  int posicao;
};

void insere (fila_prioritaria *f, int elem) {
  f->chave[f->posicao] = elem;
  f->posicao++;
  sobe_no_heap(f, f->posicao-1);
}

void sobe_no_heap(fila_prioritaria *f, int posicao) {
  if (posicao > 0 && f->chave[pai(posicao)] < f->chave[posicao]) {
    permuta(&(f->chave[pai(posicao)]), &(f->chave[posicao]));
    sobe_no_heap(f, pai(posicao));
  }
}

int remove_maior(fila_prioritaria *f) {
  int aux = f->chave[0];
  permuta(&(f->chave[0]), &(f->chave[f->posicao-1]));
  f->posicao--;
  desce_no_heap(f, 0);
  return aux;
}

void desce_no_heap(fila_prioritaria *f, int posicao) {
  int maior_filho;
  if (filho_esquerdo(posicao) < f->posicao) {
    maior_filho = filho_esquerdo(posicao);
    if (filho_dir(posicao) < f->posicao && f->chave[filho_esquerdo(posicao)] < f->chave[filho_dir(posicao)]) {
      maior_filho = filho_dir(posicao);
    }
    if (f->chave[posicao] < f->chave[maior_filho]) {
      permuta(&f->chave[posicao], &f->chave[maior_filho]);
      desce_no_heap(f, maior_filho);
    }
  }
}

void altera_prioridade (fila_prioritaria *f, int posicao, int novo_valor) {
  if (f->chave[posicao] < novo_valor) {
    f->chave[posicao] = novo_valor;
    sobe_no_heap(f, posicao);
  } else {
    f->chave[posicao] = novo_valor;
    desce_no_heap(f, posicao);
  }
}

void constroi_heap(fila_prioritaria *f) {
  int meio = (f->posicao-1 / 2);
  for (int i = meio; i >= 0; i--) {
    desce_no_heap(f, i);
  }
}

void heapify (fila_prioritaria *f, int tam, int i) {
  int maior = i;
  if (filho_esquerdo(i) < tam && f->chave[filho_esquerdo(i)] > f->chave[maior]) {
    maior = filho_esquerdo(i);
  }
  if (filho_dir(i) < tam && f->chave[filho_dir(i)] > f->chave[maior]) {
    maior = filho_dir(i);
  }
  if (maior != i) {
    permuta(&(f->chave[i]), &(f->chave[maior]));
    heapify(f, tam, maior);
  }
}

void heapsort (fila_prioritaria *f) {
	int k;
	for (k = (f->posicao) / 2 - 1; k >= 0; k--)
		heapify(f, f->posicao,k);
		
  for (k = f->posicao - 1; k >= 0; k --) {
    permuta(&(f->chave[0]), &(f->chave[k]));
    heapify(f, k, 0);
  }
}

void imprime_fila (fila_prioritaria *filapri) {
    printf("Fila de prioridade: \n");
    int i;
	for(i = 0; i < filapri->posicao; i++) {
        printf("%d ", filapri->chave[i]);
    }
    printf("\n");
}

int main () {
  fila_prioritaria fila;
  int vet[20];
  fila.chave = vet;
  fila.tam_max = 20;
  fila.posicao = 0;
  fila.chave[0] = 28;
  fila.chave[1] = 95;
  fila.chave[2] = 78;
  fila.chave[3] = 60;
  fila.chave[4] = 66;
  fila.chave[5] = 70;
  fila.chave[6] = 39;
  fila.chave[7] = 33;
  fila.posicao = 8;
  heapsort(&fila);
  imprime_fila(&fila);
  return 0;
}