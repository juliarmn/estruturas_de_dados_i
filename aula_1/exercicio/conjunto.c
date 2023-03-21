#include <stdio.h>
#include <stdlib.h>

#include "set.h"

struct set {
  int *element;
  int size;
};

int main(int argc, char *argv[]) {
  Set *A, *B, *C, *D, *E, *F;
  A = create();
  B = create();
  // C = create();
  // D = create();
  // E = create();
  F = create();
  // printf("%d  ",is_empty(A));
  put_elem(A, 2);
  put_elem(A, 1);
  // printf("%d  ",is_empty(A));
  // print_set(A);
  put_elem(B, 1);
  put_elem(B, 3);
  // put_elem(B, 2);
  // put_elem(B, 3);
  // put_elem(B, 2);
  // is_equal(A, B);
  // printf("%d\n", is_equal(A, B));
  C = add(A, B);
  // printf("asdasd");
  // print_set(C);
  // D = intersection(A, B);
  // print_set(D);
  // printf("%d\n", is_member(3, A));
  // E = difference(A, B);
  // print_set(E);
  return 0;
}

Set *create() {
  Set *new_set = malloc(sizeof(Set));
  new_set->size = 0;
  new_set->element = malloc(sizeof(int));
}

int is_empty(Set *set) {
  if (set->size > 0) {
    return 0;
  }
  return 1;
}

void put_elem(Set *set, int elem) {
  // Elementos repetidos não importam
  // Assume que ainda não temos esse elemento
  int exist = 0;
  int i = 0;
  while (i < set->size) {
    // Já temos esse elemento -> não vamos inserir os repetidos
    if (set->element[i] == elem) {
      exist = 1;
      break;
    }
    i++;
  }
  if (!exist) {
    // Usar realloc
    set->element = realloc(set->element, sizeof(int) * (set->size + 1));
    set->element[set->size] = elem;
    set->size = set->size + 1;
  }
}

int is_equal(Set *set_1, Set *set_2) {
  int i, j, equal;
  if (set_1->size != set_2->size) {
    return 0;
  }
  for (i = 0; i < set_1->size; i++) {
    equal = 0;
    for (j = 0; j < set_2->size; j++) {
      if (set_1->element[i] == set_2->element[j]) {
        equal = 1;
      }
    }
    if (equal == 0) {
      return 0;
    }
  }
  return 1;
}

Set *add(Set *set_1, Set *set_2) {
  Set *new_set = create();
  if (is_equal(set_1, set_2)) {
    new_set->size = set_1->size;
    for (int i = 0; i < set_1->size; i++) {
      new_set->element[i] = set_1->element[i];
    }
    return new_set;
  }
  if (set_1->size == 0 && set_2->size == 0) {
    return new_set;
  }
  for (int i = 0; i < set_1->size; i++) {
    put_elem(new_set, set_1->element[i]);
  }
  for (int i = 0; i < set_2->size; i++) {
    put_elem(new_set, set_2->element[i]);
  }
  return new_set;
}

Set *intersection(Set *set_1, Set *set_2) {
  Set *new_set = create();
  if (is_equal(set_1, set_2)) {
    new_set->size = set_1->size;
    for (int i = 0; i < set_1->size; i++) {
      new_set->element[i] = set_1->element[i];
    }
    return new_set;
  }
  for (int i = 0; i < set_1->size; i++) {
    for (int j = 0; j < set_2->size; j++) {
      if (set_1->element[i] == set_2->element[j]) {
        put_elem(new_set, set_1->element[i]);
      }
    }
  }
  return new_set;
}

int is_member(int value, Set *set) {
  int i;
  for (i = 0; i < set->size; i++) {
    if (value == set->element[i]) {
      return 1;
    }
  }
  return 0;
}

// Set *difference(Set *set_1, Set *set_2) {
//   Set *new = create();
//   int i, j;
//   int in_set_2 = 0;
//   if (is_equal(set_1, set_2)) {
//     return new;
//   }
//   for (i = 0; i < set_2->size; i++) {
//     in_set_2 = 0;
//     if(!is_member(set_2->element[i], set_1)) {
//       put_elem(new, set_1);
//     }
//     for (j = 0; j < set_2->size; j++) {
//       if (set_1->element[i] == set_2->element[j]) {
//         in_set_2 = 1;
//       }
//       if (!in_set_2) {
//         put_elem(new, set_1->element[i]);
//       }
//       in_set_2 = 0;
//     }
//   }
//   return new;
// }

void print_set(Set *set) {
  if (set->size == 0) {
    printf("Set is empty\n");
    return;
  }
  int i = 0;
  while (i < set->size) {
    printf("%d ", set->element[i]);
    i++;
  }
}