#include "avl_adelson.h"
#include <stdio.h>
#include <stdlib.h>

int maior(a,b) {return (a > b) ? a : b;}

struct tree{
  struct tree *esq;
  struct tree *dir;
  int altura;
  int info;
};

node* novo_no(int info) {
  node *raiz = malloc(sizeof(node));
  if (!raiz) {
    printf("Sem espaço\n");
    return NULL;
  }
  raiz->info = info;
  raiz->altura = 1;
  raiz->esq = NULL;
  raiz->dir = NULL;
  return raiz;
}

int altura (node *no) {
  if (!no) {
    return 0;
  }
  return no->altura;
}

int diferenca_altura(node *no) {
  if (no == NULL) {
    return 0;
  } 
  return (altura(no->esq) - altura(no->dir));
}

node *menor_no(node *no) {
  node *aux = no;
  while (aux->esq != NULL) {
    aux = aux->esq;
  }
  return aux;
}

node *insert_avl(node *raiz, int info) {
  if (!raiz) {
    raiz = novo_no(info);
    return raiz;
  }

  if (info < raiz->info) {
    raiz->esq = insert_avl(raiz->esq, info);
  } else {
    raiz->dir = insert_avl(raiz->dir, info);
  }

  raiz->altura = (maior(altura(raiz->esq), altura(raiz->dir) + 1));

  int diferenca = diferenca_altura(raiz);

  if (diferenca > 1 && info < raiz->esq->info) {
    return rotacao_dir(raiz);
  }
  if (diferenca < -1 && info > raiz->dir->info) {
    return rotacao_esq(raiz);
  }
  if (diferenca > 1 && info > raiz->esq->info) {
    return esq_dir_rotate(raiz);
  }
  if (diferenca < -1 && info < raiz->dir->info) {
    return dir_esq_ratate(raiz);
  }
  return raiz;
}

node *remover (node *raiz, int info) {
  if (!raiz) {
    return NULL;
  }
  if (info < raiz->info) {
    raiz->esq = remover(raiz->esq, info);
  }
  else if (info > raiz->info) {
    raiz->dir = remover(raiz->dir, info);
  }
  else {
    if (!raiz->esq || !raiz->dir) {
      node *aux = raiz->esq ? raiz->dir : raiz->dir;

      if (aux == NULL) {
        aux = raiz;
        raiz = NULL;
      }
      else {
        *raiz = *aux;
      }
      free(aux);
    }
    else {
      node *aux = menor_no(raiz->dir);
      raiz->info = aux->info;
      aux->dir = remover(raiz->dir, aux->info);
    }
  }

  int diferenca  = diferenca_altura(raiz);

  if (diferenca > 1 && diferenca_altura(raiz->esq)>=0) {
    return rotacao_dir(raiz);
  }
  if (diferenca > 1 && diferenca_altura(raiz->esq)<0) {
    return esq_dir_rotate(raiz);
  }
  if(diferenca < -1 && diferenca_altura(raiz->dir)>=0) {
    return rotacao_esq(raiz);
  }
  if(diferenca < -1 && diferenca_altura(raiz->dir)<0) {
    return dir_esq_ratate(raiz);
  }
  return raiz;
}

node *rotacao_dir(node *no) {
  node *esq = no->esq;
  node *dir = esq->dir;

  esq->dir = no;
  no->esq = dir;

  no->altura = (maior(altura(no->esq), altura(no->dir) +1));
  esq = (maior(altura(esq->esq), altura(esq->dir + 1)));

  return esq;
}

node *rotacao_esq(node *no) {
  node* dir = no->dir;
  node *esq = dir->esq;

  dir->esq = no;
  no->dir = esq;

  no->altura = (maior(altura(no->esq), altura(no->dir) +1));
  dir->altura = (maior(altura(dir->esq), altura(dir->dir + 1)));

  return dir;
}

node* esq_dir_rotate(node* no) {
  no->esq = rotacao_esq(no);
  return(rotacao_dir(no));
}

node* dir_esq_ratate(node * no) {
  no->dir = rotacao_dir(no);

  return rotacao_esq(no);
}
node* busca_binaria_recursiva(node *raiz, int info) {
    if(!raiz)
        return NULL;

    if(info == raiz->info)
        return raiz;

    if(raiz->info > info)
        return busca_binaria_recursiva(raiz->esq, info);
    else
        return busca_binaria_recursiva(raiz->dir, info);

}

void printPreOrder(node *node)
{
    if (node == NULL)
        return;

    printf(" %d ", (node->info));
    printPreOrder(node->esq);
    printPreOrder(node->dir);
}

void printInOrder(node *node)
{
    if (node == NULL)
        return;
    printInOrder(node->esq);
    printf(" %d ", (node->info));
    printInOrder(node->dir);
}

void printPostOrder(node *node)
{
    if (node == NULL)
        return;
    printPostOrder(node->esq);
    printPostOrder(node->dir);
    printf(" %d ", (node->info));
}

int main() {
  int op, aux;
  node*raiz = malloc(sizeof(node));
  raiz = NULL;
  node* no_aux;
  while(op) {
    printf("1) Inserir\n");
    printf("2) Deletar\n");
    printf("3) Buscar\n");
    printf("4) Pré-Ordem\n");
    printf("5) In-Ordem\n");
    printf("6) Pós-Ordem\n");
    printf("7) Árvore toda\n");
    printf("0) Sair");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
          printf("Obrigada Wallas :)\n");
          break;
    case 1: {
      printf("Insira o primeiro elemento\n");
      scanf("%d", &aux);
      no_aux = busca_binaria_recursiva(raiz, aux);
      if (no_aux) {
        printf("Esse número já existe\n");
      } else {
        raiz = insert_avl(raiz, aux);
      }
    }
    case 2: {
      printf("Insere o valor para delete\n");
      scanf("%d", &aux);
      no_aux = busca_binaria_recursiva(raiz, aux);
      if (!no_aux) {
        printf("Num tem\n");
      } else {
        raiz = remover(raiz, aux);
      }
      break;
    }
    case 3: {
      printf("Digite o que quer find\n");
      scanf("%d", &aux);
      no_aux = busca_binaria_recursiva(raiz, aux);
       if (!no_aux) {
        printf("Num tem\n");
      } else {
        printf("Achouuu\n");
      }
      break;
    }
    case 4: {
      printf("Pré-order:\n");
      printPreOrder(raiz);
      break;
    }
    case 5: {
      printf("IN-order:\n");
      printInOrder(raiz);
      break;
    }
    case 6: {
      printf("Pos-order:\n");
      printPosOrder(raiz);
      break;
    }
    case 7: {
      printf("Árvore toda:\n");
      //printPosOrder(raiz);
      break;
    }
    default:
      printf("Opção inválida\n");
      break;
    }
  }
  return 0;
}