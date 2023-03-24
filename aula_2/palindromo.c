#include "palindromo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palindromo {
  char c;
  struct palindromo *next;
};

int main() {
  char str[100];
  Stack *head = NULL;
  printf("Digite a string: ");
  scanf(" %[^\n][^' ']s", str);
  int tam = strlen(str);
  for (int i = 0; i < tam; i ++) 
    push(&head, str[i]);
  if (palindromo(head, str)) {
    printf("É palíndromo");
  } else {
    printf("Não é palíndromo");
  }
}

void push(Stack **head, char elem) {
  Stack *aux = malloc(sizeof(Stack));
  aux->c = elem;
  if (*head == NULL) {
    *head = aux;
    (*head)->next = NULL;
    return;
  }
  aux->next = *head;
  *head = aux;
}

Stack *pop(Stack **head) {
  if (*head == NULL) {
    printf("No element\n");
    return NULL;
  }
  Stack *aux = malloc(sizeof(Stack));
  aux = *head;
  *head = (*head)->next;
  return (aux);
}

void print_stack(Stack *head) {
  if (head == NULL) {
    printf("No elements\n");
    return;
  }
  printf("-----\n");
  while (head != NULL) {
    printf("%c\n", head->c);
    head = head->next;
  }
  printf("-----\n");
}

bool empty(Stack *head) {
  if (head == NULL) {
    return true;
  }
  return false;
}

bool palindromo(Stack *head, char *str) {
  int i = 0;
  while (str[i] != '\0') {
    if (!empty(head)) {
      if (str[i] != pop(&head)->c) {
        return false;
      }
    }
    i--;
  }
  return true;
}