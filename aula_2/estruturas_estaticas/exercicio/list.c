#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

// int main(int argc, char *argv[]) {
//   Lista list;
//   inicializar_lista(&list);

//   // Criar alguns elementos
//   Elem elem1 = {{"Amanda", 1}, 1};
//   Elem elem2 = {{"Júlia", 2}, 2};
//   Elem elem3 = {{"Furriel", 3}, 3};
//   Elem elem4 = {{"Luciana", 4}, 4};
//   Elem elem5 = {{"Márcio", 5}, 5};

//   // Inserir elementos na lista
//   inserir_elemento(&list, 1, elem1);
//   inserir_elemento(&list, 2, elem2);
//   inserir_elemento(&list, 3, elem3);
//   inserir_elemento(&list, 4, elem4);

//   // Imprimir a lista
//   printf("Lista:\n");
//   imprimir_lista(&list);

//   // Buscar um elemento pela chave
//   int pos = busca_primeiro_tipo(4, &list);
//   if (pos != -1) {
//     printf("Elemento encontrado na posição %d:\n", pos);
//     printa_elem(list.elem[pos]);
//   } else {
//     printf("Elemento nao encontrado.\n");
//   }

//   // Buscar um elemento pela posicao
//   if (busca_segundo_tipo(3, &list)) {
//     printf("Elemento encontrado.\n");
//   } else {
//     printf("Elemento não encontrado.\n");
//   }

//   // Remover um elemento
//   int posicao = 2;
//   eliminar_elemento(&list, &posicao);

//   // Imprimir a lista novamente
//   printf("Lista depois de remover o elemento:\n");
//   imprimir_lista(&list);

//   // Destruir a lista
//   destruir_lista(&list);

//   return 0;
// }

void inicializar_lista(Lista *list) {
  list->num_elem = 0;
  list->elem[0].key = 0;
}

bool vazia(Lista *list) {
  return list->num_elem == 0;
}

bool cheia(Lista *list) {
  return list->num_elem == SIZE;
}

void inserir_elemento(Lista *list, int posicao, Elem pessoa) {
  if (!cheia(list) && posicao <= list->num_elem + 1 && posicao > 0) {
    for (int i = list->num_elem; i >= posicao; i--) {
      list->elem[i + 1] = list->elem[i];
    }
    list->elem[posicao] = pessoa;
    list->num_elem++;
    return;
  }
}

int contar_num_elementos(Lista *list) {
  return list->num_elem;
}

int busca_primeiro_tipo(chave key, Lista *list) {
  int inferior = 1;
  int superior = list->num_elem;
  int meio;
  if (vazia(list))
    return -1;
  if (list->elem[inferior].key == key)
    return inferior;
  if (list->elem[superior].key == key)
    return superior;
  while (superior > inferior) {
    meio = (superior + inferior) / 2;
    if (list->elem[meio].key == key) {
      return meio;
    } else if (list->elem[meio].key < key) {
      inferior = meio + 1;
    } else {
      superior = meio - 1;
    }
  }
  return -1;  // Não encontrou a posição
}

bool busca_segundo_tipo(int posicao, Lista *list) {
  if (!(vazia(list)) && posicao < list->elem + 1 && posicao > 0) {
    printa_elem(list->elem[posicao]);
    return true;
  }
  return false;
}

void printa_elem(Elem elemento) {
  printf("%d\n", elemento.info.codigo);
  printf("%s\n", elemento.info.nome);
}

void eliminar_elemento(Lista *list, int *posicao) {
  for (int i = (*posicao) + 1; i < list->num_elem; i++) {
    list->elem[i - 1] = list->elem[i];
  }
  list->num_elem--;
}

void imprimir_lista(Lista *list) {
  if (!vazia(list)) {
    for (int i = 0; i < list->num_elem; i++)
      printa_elem(list->elem[i]);
  }
}

void destruir_lista(Lista *list) {
  list->num_elem = 0;
}