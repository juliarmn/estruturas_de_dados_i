#ifndef MATRIZ_H
#define MATRIZ_H

//TAD matriz com m linhas e n colunas

//Tipo exportado
typedef struct matriz Matriz;

//Funções:

//Criar a matriz -> aloca e retorna a matriz:
Matriz *create(int num_lines, int num_columns);
//acessar matriz:
float acess(Matriz *value, int line, int column);
//liberar a memória -> free:
void free_matriz(Matriz *pointer);
//Atribuir valores:
void value(Matriz *val, int lines, int columns, float new_value);

#endif
