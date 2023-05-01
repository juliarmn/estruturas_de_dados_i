#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#define SIZE 100

struct dados {
  char nome[80];
  int posicao;
};

struct elemento {
  Dados info;
  chave key;
};

struct lista {
  Elem elem[SIZE + 1];
  int num_elem;
};

int main(int argc, char *argv[]) {
  Lista list;
  inicializar_lista(&list);
  int op = -1;
  int pos, key_busca, key;
  int i = 1;
  do {
    do {
      printf("\nMenu: \n");
      printf("1) Inserir novo elemento\n");
      printf("2) Buscar elemento pela chave\n");
      printf("3) Buscar elemento pela posição\n");
      printf("4) Remover elemento\n");
      printf("5) Destruir lista\n");
      printf("6) Mostrar a lista\n");
      printf("7) Número de elmentos na lista\n");
      printf("0) Sair\n");
      scanf("%d", &op);
    } while (op < 0 || op > 7);
    switch (op) {
      case 1: {
        printf("Digite o nome: ");
        scanf(" %[^\n]s", list.elem[i].info.nome);
        printf("Digite a chave do elemento: ");
        scanf("%d", &key);
        list.elem[i].key = key;
        if(inserir_ordenado_chave(&list, list.elem[i].key, list.elem[i])){
          printf("Inserido com sucesso\n");
        } else {
          printf("Erro ao inserir\n");
        }
        i++;
        break;
      }
      case 2: {
        printf("Digite a chave do elemento: ");
        scanf("%d", &key_busca);
        pos = busca_primeiro_tipo(key_busca, &list);
        if (pos == -1) {
          printf("Elemento não encontrado.\n");
        } else {
          printf("Elemento encontrado na posição %d:\n", pos);
          printa_elem(list.elem[pos]);
        }
        break;
      }
      case 3: {
        printf("Digite a posição: ");
        scanf("%d", &pos);
        if (busca_segundo_tipo(pos, &list)) {
          printf("Elemento encontrado.\n");
        } else {
          printf("Elemento não encontrado.\n");
        }
        break;
      }
      case 4: {
        printf("Digite a posição do elemento para remover: ");
        scanf("%d", &pos);
        if (busca_segundo_tipo(pos, &list)) {
          eliminar_elemento(&list, pos);
        } else {
          printf("Esse elemento não existe.\n");
        }
        break;
      }
      case 5: {
        if (!vazia(&list)) {
          destruir_lista(&list);
          i = 1;
        } else {
          printf("Essa lista não possui nada\n");
        }
        break;
      }
      case 6: {
        imprimir_lista(&list);
        break;
      }
      case 7: {
        printf("O tamanho é: %d\n", tamanho(&list));
        break;
      }
      default:
        printf("Até a próxima\n");
        break;
    }
  } while (op != 0);
  return 0;
}