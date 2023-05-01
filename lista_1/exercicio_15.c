#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  struct no *dir, *esq;
  int info;
} tipo_no;

int main() {
  int vet[7] = {7, 8, 9, 10, 12, 13, 15};
  
  tipo_no *raiz;
  criar_arvore(&raiz, vet, 7);


  return 0;
}

tipo_no* cria_arvore(tipo_no *raiz, int *vet, int len) {
    int metade = len/2;
    raiz = malloc(sizeof(tipo_no));
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->chave = vet[metade];

    int *vet_esq = malloc(metade * sizeof(int));
    int *vet_dir = malloc(metade * sizeof(int));

    int j = 0;

    printf("vet_esq: ");
    for(int i = 0; i < metade; i++) {
        vet_esq[i] = vet[i];
        printf(" %d", vet_esq[i]);
    }

    printf("\nvet_dir: ");
    for(int i = metade+1; i < len; i++) {
        vet_dir[j++] = vet[i];
        printf(" %d", vet_dir[i]);
    }
    if(metade != 0) {
        raiz->esq = cria_arvore(raiz->esq, vet_esq, metade);
        raiz->dir = cria_arvore(raiz->dir, vet_dir, metade);
    }

    return raiz;    
}
