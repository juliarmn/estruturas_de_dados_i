#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#define SIZE 100

struct dados {
  char nome[80];
  int codigo;
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
  int pos, key_busca;
  int i = 1;
  do {
    do {
      printf("Menu: \n");
      printf("1) Inserir novo elemento\n");
      printf("2) Buscar elemento pela chave\n");
      printf("3) Buscar elemento pela posição\n");
      printf("4) Remover elemento\n");
      printf("5) Destruir lista\n");
      printf("0) Sair\n");
    } while (op < 0 || op);
    scanf("%d", &op);
    switch (op) {
      case 1: {
        printf("Digite o nome: ");
        scanf("%[^\n]s", list.elem[i].info.nome);
        list.elem[i].info.codigo = i;
        inserir_elemento(&list, i, list.elem[i]);
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
        printf("Digite a posição do elmento para remover: ");
        scanf("%d", &pos);
        if(busca_segundo_tipo(pos, &list)) {
          eliminar_elemento(&list, &pos);
        } else {
          printf("Esse elemento não existe.\n");
        }
        break;
      }
      case 5: {
        if (!vazia(&list)) {
          destruir_lista(&list);
        } else {
          printf("Essa lista já está vazia!\n");
        }
        break;
      }
    }
  } while (op != 0);
  return 0;
}