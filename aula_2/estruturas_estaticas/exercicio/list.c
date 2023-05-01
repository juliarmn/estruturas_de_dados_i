#include "list.h"

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// Criação das structs

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

// Inicializa a lista, que começará pela poisção 1

void inicializar_lista(Lista *list) {
  list->num_elem = 0;
  list->elem[0].key = 0;
}

// Verifica se a lista está vazia

bool vazia(Lista *list) {
  return list->num_elem == 0;
}

// Verifica se a lista está cheia pelo número de elementos

bool cheia(Lista *list) {
  return list->num_elem == SIZE;
}

// Função que pela chave acha a posição e chama a inserir por posição
// Como foi requerido no enunciado, essa função devia chavar a outra função de inserir

bool inserir_ordenado_chave(Lista *list, chave chave, Elem pessoa) {
  int pos = list->num_elem + 1;
  int i;
  if (cheia(list) || busca_primeiro_tipo(chave, list) != -1) {
    return false;
  }
  if (!cheia(list) && busca_primeiro_tipo(chave, list) == -1) {
    for (i = list->num_elem; list->elem[i].key >= chave && i > 0; i--) {
      pos--;
    }
    inserir_elemento(list, pos, pessoa);
    return true;
  }
}

// Função que isere o  elemento a partir de uma posição passada como parâmetro (no nosso caso, usamos ela em outra função denominada inserir por chave)

void inserir_elemento(Lista *list, int posicao, Elem pessoa) {
  if (!cheia(list) && posicao <= list->num_elem + 1 && posicao > 0) {
    for (int i = list->num_elem; i >= posicao; i--) {
      list->elem[i + 1] = list->elem[i];
    }
    list->elem[posicao] = pessoa;
    list->num_elem++;
    // list->elem[posicao].info.posicao = posicao;
    atualizarPosicao(list, posicao);
    return;
  }
}

// Função que atualiza a posição dos elementos que estavam antes na lista ao ser inserido um novo elemento

void atualizarPosicao(Lista *list, int posicao) {
  for (int i = list->num_elem; i > 0; i--) {
    printf("%d\n", i);
    list->elem[i].info.posicao = i;
  }
}

// Devolve o campo que conta quantos elementos tem na lista

int contar_num_elementos(Lista *list) {
  return list->num_elem;
}

// Busca o elmento pela chave, faz uma busca binária (lista ordenada pelas chaves)

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

// Busca o elemento pela posição -> busca iterativa

bool busca_segundo_tipo(int posicao, Lista *list) {
  if (!(vazia(list)) && posicao < list->elem + 1 && posicao > 0) {
    printa_elem(list->elem[posicao]);
    return true;
  }
  return false;
}

// Printa os elementos chamando a função de printar elemento, mostrando toda a lista no terminal

void imprimir_lista(Lista *list) {
  if (vazia(list)) {
    printf("Lista vazia\n");
  } else {
    for (int i = 1; i <= list->num_elem; i++)
      printa_elem(list->elem[i]);
  }
}

// Printa cada elemento separadamente

void printa_elem(Elem elemento) {
  printf("posição: %d\n", elemento.info.posicao);
  printf("nome: %s\n", elemento.info.nome);
  printf("chave: %d\n", elemento.key);
}

//Elimina o elemento fazendo cópia de todos os elementos posteriores uma posição atrás e decrementando o número de elementos

void eliminar_elemento(Lista *list, int posicao) {
  for (int i = posicao + 1; i <= list->num_elem; i++) {
    list->elem[i - 1] = list->elem[i];
  }
  list->num_elem--;
}

//Destrói logicamente a lista, sobrescrevendo se quiser recomeçá-la

void destruir_lista(Lista *list) {
  list->num_elem = 0;
}

// Retorna o tamanho da lista

int tamanho(Lista *list) {
  return list->num_elem;
}
