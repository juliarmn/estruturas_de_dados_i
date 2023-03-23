#include "stack_expression.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stack {
  char c;
  struct stack *next;
};

int main(int argc, char *argv[]) {
  Stack *head = NULL;
  int i = 0, j = 0;
  char str_1[100], str_2[100];
  printf("Write the expression\n");
  scanf(" %[^\n]s", str_1);
  // printf("%s\n", str_1);
  while (str_1[i] != '\0') {
    // printf("%c\n", str_1[i]);
    if (str_1[i] == '(' || str_1[i] == ')' || str_1[i] == '[' || str_1[i] == ']' || str_1[i] == '{' || str_1[i] == '}') {
      str_2[j] = str_1[i];
      j++;
    }
    i++;
    // printf("%c\n", str_2[j]);
  }
  str_2[j] = '\0'; 
  i = 0;
  // printf("%s\n", str_2);
  // while (str_2[i] != '\0') {
  //   if (str_2[i] == '(' || str_2[i] == '[' || str_2[i] == '{')
  //     push(&head, str_2[i]);
  //   i++;
  // }
  // print_stack(head);
  printf("Your expression is: %s", verify_expression(head, str_2) ? "true" : "false");
  return 0;
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

bool verify_expression(Stack *head, char *str) {
  Stack *popped;
  int i = 0;
  char c;
  while (str[i] != '\0') {
    c = str[i];
    if (c == '(' || c == '[' || c == '{') {
      push(&head, c);
    } else if (c == ')' || c == ']' || c == '}') {
      popped = pop(&head);
      if (popped == NULL) {
        return false;
      }
      if (c == ')' && popped->c != '(') {
        return false;
      } else if (c == ']' && popped->c != '[') {
        return false;
      } else if (c == '}' && popped->c != '{') {
        return false;
      }
    }
    i++;
  }
  return empty(head);
}