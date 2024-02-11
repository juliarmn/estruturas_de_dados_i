#include "max_heap.h"

struct heap {
    int *vetor;
    int tamanho;
    int capacidade;
};

Heap* criar_heap_vazio (int capacidade) {
    Heap *novo_heap = malloc(sizeof(Heap));

    // Checagem de memoria
    if (!novo_heap) {
        printf("Memória insuficiente\n");
        return NULL;
    }

    novo_heap->tamanho = 0;
    novo_heap->capacidade = capacidade;
    novo_heap->vetor = malloc(capacidade * sizeof(int));

    if (!novo_heap->vetor) {
        printf("Memória insuficiente\n");
        return NULL;
    }
    return novo_heap;
}

Heap *inserir_no_heap (Heap *novo_heap, int elem) {
    if (novo_heap->capacidade == novo_heap->tamanho) {
        printf("Capacidade máxima atingida!!!\n");
        return novo_heap;
    }

    novo_heap->vetor[novo_heap->tamanho] = elem;
    novo_heap->tamanho++;

    for (int i = (novo_heap->tamanho - 1) / 2; i >= 0; i--)
        heapfy(novo_heap, i);

    return novo_heap;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapfy(Heap *novo_heap, int indice) {
    int maior = indice;
    int esquerdo = 2 * indice + 1;
    int direito = 2 * indice + 2;

    if (esquerdo < novo_heap->tamanho && novo_heap->vetor[esquerdo] > novo_heap->vetor[maior])
        maior = esquerdo;

    if (direito < novo_heap->tamanho && novo_heap->vetor[direito] > novo_heap->vetor[maior])
        maior = direito;

    if (maior != indice) {
        trocar(&novo_heap->vetor[indice], &novo_heap->vetor[maior]);
        heapfy(novo_heap, maior);
    }
}

int remover_prioritario (Heap *novo_heap) {
    int deletado;
    if (!novo_heap->tamanho) {
        printf("VAZIA!!!\n");
        return -999999;
    }

    deletado = novo_heap->vetor[0];
    novo_heap->vetor[0] = novo_heap->vetor[novo_heap->tamanho - 1];
    novo_heap->tamanho--;

    for (int i = (novo_heap->tamanho - 1) / 2; i >= 0; i--)
        heapfy(novo_heap, i);

    return deletado;
}

void inserir_pronto (Heap *novo_heap) {
    int vet[8] = {28, 33, 39, 60, 66, 70, 78, 95};
    for (int i = 0; i < novo_heap->tamanho; i ++)
        novo_heap->vetor[i] = 0;

    novo_heap->tamanho = 0;

    for (int i = 0; i < 8; i ++)
        novo_heap->vetor[i] = vet[i];
    novo_heap->tamanho = 8;

    for (int i = (novo_heap->tamanho - 1) / 2; i >= 0; i--)
        heapfy(novo_heap, i);
}

Heap* alterar_prioridade (int antigo, int nova, Heap *novo_heap) {
    int indice = -1;
    for (int i = 0; i < novo_heap->tamanho; i ++) {
        if (novo_heap->vetor[i] == antigo)
            indice = i;
    }

    if (indice == -1) {
        printf("Elemento nao encontrado\n");
        return;
    }

    novo_heap->vetor[indice] = nova;
    for (int i = (novo_heap->tamanho - 1) / 2; i >= 0; i--)
        heapfy(novo_heap, i);

    return novo_heap;
}

void imprimir_heap_recursivo(Heap *novo_heap, int indice, int nivel) {
    if (indice < novo_heap->tamanho) {
        imprimir_heap_recursivo(novo_heap, 2 * indice + 2, nivel + 1);
        for (int i = 0; i < nivel; i++)
            printf("   ");
        printf("%d\n", novo_heap->vetor[indice]);
        imprimir_heap_recursivo(novo_heap, 2 * indice + 1, nivel + 1);
    }
}

void imprimir_normal(Heap *novo_heap) {
    int i = 0;
    while (i < novo_heap->tamanho) {
        printf("[%d] ", novo_heap->vetor[i]);
        i++;
    }
    printf("\n");
}

int menu () {
    int op;
    printf("****** MENU ******\n");
    printf("1) Inserir\n");
    printf("2) Imprimir\n");
    printf("3) Remover\n");
    printf("4) Alterar prioridade\n");
    printf("5) Inserir ex pronto\n");
    printf("0) Sair\n");
    scanf("%d", &op);
    return op;
}
