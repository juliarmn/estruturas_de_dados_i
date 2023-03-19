#ifndef SET_H
#define SET_H

typedef struct set Set;

//Criar Set:
Set* create();
//Inserir elemento:
void put_elem(Set *, int);
//Igualdade de Set:
int is_equal(Set *, Set *);
//União:
Set* add(Set *, Set *);
//Intersecção:
Set* intersection(Set *, Set *);
//Ver se é membro:
int is_member(int, Set *);
//Ver se está vazio:
int is_empty(Set *);
//Diferença de conjuntos
Set *difference(Set *, Set *);
//printar
void print_set(Set *);

#endif