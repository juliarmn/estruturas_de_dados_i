#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

struct data {
  //char letter;
  int number;
  //double value;
};

struct node {
  type_of_data data;
  struct node *right;
  struct node *left;
};

int main (int argv, char *args[]) {
  type_of_data elem;
  // Empty tree
  tree *t = malloc(sizeof(tree));
  tree *aux_left = malloc(sizeof(tree));
  tree *aux_right = malloc(sizeof(tree));
  create_empty_tree(&t);
  // Root:
  elem.number = 8;
  t = create_root(t, elem);
  // Left child:
  elem.number = 4;
  insert_left_child(t, elem);
  // Right child:
  elem.number = 12;
  insert_right_child(t, elem);
  // Next line:
  aux_left = t->left;

  
  // Left left child:
  elem.number = 2;
  insert_left_child(aux_left, elem);
  // Left right child:
  elem.number = 6;
  insert_right_child(aux_left, elem);
  aux_right = t->right;
  // Right left child:
  elem.number = 10;
  insert_left_child(aux_right, elem);
  // Right right child:
  elem.number = 14;
  insert_right_child(aux_right, elem);
  
  // Next line:
  elem.number = 1;
  insert_left_child(aux_left->left, elem);
  elem.number = 3;
  insert_right_child(aux_left->left, elem);
  
  elem.number = 5;
  insert_left_child(aux_left->right, elem);
  elem.number = 7;
  insert_right_child(aux_left->right, elem);
  
  elem.number = 9;
  insert_left_child(aux_right->left, elem);
  elem.number = 11;
  insert_right_child(aux_right->left, elem);
  
  elem.number = 13;
  insert_left_child(aux_right->right, elem);
  elem.number = 15;
  insert_right_child(aux_right->right, elem);

  
  printf("Pre-order:\n");
  pre_order(t);

  printf("\n\n\nIn-order:\n");
  in_order(t);

  printf("\n\n\nPos-order:\n");
  pos_order(t);

  return 0;
}
