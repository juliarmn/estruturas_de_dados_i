#include <stdio.h>
#include "../heap/max_heap.h"
#define CAPACIDADE 12

int main() {
    int op = 0;
    int elem;
    int deletado;
    int novo;
    int antigo;
    Heap *h;
    h = criar_heap_vazio(CAPACIDADE);
    do {
        op = menu();
        if (op < 0 || op > 5) {
            printf("OPÇÃO INVALIDA!!!\n");
            op = menu();
        }
        switch (op) {
            case 1: {
                printf("Digite o elemento que quer inserir: ");
                scanf("%d", &elem);
                h = inserir_no_heap(h, elem);
                break;
            }
            case 2: {
                imprimir_heap_recursivo(h, 0, 0);
                printf("\n");
                printf("Forma de vetor:\n");
                imprimir_normal(h);
                break;
            }
            case 3: {
                deletado = remover_prioritario(h);
                if (deletado != -999999)
                    printf("O item removido foi: %d\n", deletado);
                break;
            }
            case 4: {
                printf("Digite o elemento que quer alterar: ");
                scanf("%d", &antigo);
                printf("Digite o elemento novo: ");
                scanf("%d", &novo);
                h = alterar_prioridade(antigo, novo, h);
                imprimir_normal(h);
                break;
            }
            case 5: {
                inserir_pronto(h);
                imprimir_normal(h);
                break;
            }
            case 0: {
                printf("Ate logo ;)\n");
                break;
            }
        }
    } while (op != 0);
}
