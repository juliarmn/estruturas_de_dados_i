#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
  int lin;
  int col;
  float *value;
};

int main (int argc, char *argv[]) {
  //Chamadas das funções
  return 0;
}

Matriz *create(int num_lines, int num_columns) {
  Matriz *mat = malloc(sizeof(Matriz));
  if (mat == NULL) {
    //Dúvida nesse pedaço de código:
    printf("Memória insuficiente");
    exit(1);
  }
  mat->lin = num_lines;
  mat->col = num_columns;
  mat->value = (float*)calloc(num_lines*num_columns, sizeof(float));
}

float acess(Matriz *value, int line, int column) {
  int simple;
  if (line < 0 || column < 0 || line >= value->lin || column >= value->col) {
    printf("Valores inválidos");
    exit(1);
  }
  simple = (line * value->col) + column;
  return value->value[simple];
}

void free_matriz(Matriz *pointer) {
  free(pointer->value);
  free(pointer);
}

void value(Matriz *val, int lines, int columns, float new_value) {
  int simple;
  if (lines < 0 || columns < 0 || lines >= val->lin || columns >= val->col) {
    printf("Valores inválidos");
    exit(1);
  }
  simple = (lines * val->col) + columns;
  val->value[simple] = new_value;
}
