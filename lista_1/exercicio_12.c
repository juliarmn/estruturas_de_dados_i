#include <stdlib.h>

typedef struct node {
  int info;
  struct node *esq;
  struct node *dir;
} no;

no *busca_insere (no *raiz, int elem)
{
   //Inserir elem. a partir de um n� desalocado
   if (raiz == NULL)
   {
      raiz = malloc(sizeof(no));
      raiz->info = elem;
      raiz->esq = NULL;
      raiz->dir = NULL;

      return raiz;
   }

   if (elem < raiz->info)
      raiz->esq = busca_insere(raiz->esq, elem);

   if (elem > raiz->info)
      raiz->dir = busca_insere(raiz->dir, elem);
 
   return raiz;
}