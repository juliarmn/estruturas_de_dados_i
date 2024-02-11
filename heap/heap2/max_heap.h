#ifndef EDI_MAX_HEAP_H
#define EDI_MAX_HEAP_H
#include <stdio.h>
#include <stdlib.h>
typedef struct heap Heap;
Heap* criar_heap_vazio (int capacidade);
Heap *inserir_no_heap (Heap *novo_heap, int elem);
void trocar(int *a, int *b);
void heapfy(Heap *novo_heap, int indice);
void imprimir_heap_recursivo(Heap *novo_heap, int indice, int nivel);
void inserir_pronto (Heap *novo_heap);
void imprimir_normal(Heap *novo_heap);
Heap* alterar_prioridade (int antigo, int nova, Heap *novo_heap);
int remover_prioritario (Heap *novo_heap);
int menu ();
#endif //EDI_MAX_HEAP_H
