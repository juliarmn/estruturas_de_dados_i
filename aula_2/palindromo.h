#ifndef PALINDROMO_H
#define PALINDROMO_H
#include <stdbool.h>
//Estrutura:
typedef struct palindromo Stack;
//Funções:
//--------------------------------------
// Função que faz o pop -> remoção de outro elemento
Stack *pop(Stack **);
// Faz o push -> inserção de novo elemento
void push(Stack **, char);
// Printar os elementos:
void print_stack(Stack *);
// Verificar se está vazia:
bool empty(Stack *);
//Verificar se é palíndromo:
bool palindromo(Stack *, char *);
#endif