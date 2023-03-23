#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>
// Define a sruct que usaremos
typedef struct stack Stack;
// As funções:
//--------------------------------------
// Função que faz o pop -> remoção de outro elemento
Stack *pop(Stack **);
// Faz o push -> inserção de novo elemento
void push(Stack **, char);
// Verificação da expressão
bool verify_expression(Stack *, char *);
// Printar os elementos:
void print_stack(Stack *);
// Verificar se está vazia:
bool empty(Stack *);
#endif