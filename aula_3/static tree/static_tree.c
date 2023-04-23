#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

#include "tree.h"

typedef struct node {// Relações locais
  int value;
  int left;
  int right;
  int used;
}T_node;

typedef struct tree {// Relações globais
  T_node buffer[MAX];
  int root; // Se não existir usa índice negativo
}T_tree;

int main(){
    T_tree tree;

    init_tree(&tree);
    create_root(&tree, 1);

    insert_left_child(&tree, (&tree)->root, 2);
    insert_right_child(&tree, (&tree)->root, 3);
    insert_left_child(&tree, (&tree)->buffer[1], 4);
    insert_right_child(&tree, (&tree)->buffer[1], 5);
    insert_left_child(&tree, (&tree)->buffer[2], 6);
    insert_right_child(&tree, (&tree)->buffer[2], 7);

    printf("A altura é: %d", calc_height(&tree, 0));
    printf("A quantidade de nós é: %d", calc_number_of_nodes(&tree));

    if (is_balanced(&tree, 0)) {
      printf("Balanceada\n");
    } else {
      printf("Não balanceada\n");
    }
    

    pre_order(&tree, 0);
    in_order(&tree, 0);
    pos_order(&tree, 0);
    return 0;
}

void init_tree(T_tree *tree) {// Inicializa a árvore -> evitar lixo de memória
  tree->root = -1;
  int i;
  for (i = 0; i < MAX; i ++) {
      tree->buffer->value = 0;
      tree->buffer->left = -1;
      tree->buffer->right = -1;
      tree->buffer->used = 0;
  }
}

int get_empty_node (T_tree *tree) { // Retorna um espaço vazio (o primeiro possível para inserir)
int i;
  for (i = 0; i < MAX; i ++) {
    if (!(tree->buffer[i].used)) {
      return i;
    }
  }
  return -1; // Não tem mais espaço vazio
}

bool insert_left_child (T_tree *tree, T_node *parent, int value) {
  int free_position = get_empty_node(tree);
  if (free_position < 0) {
    return false;
  }
  parent->left = free_position;
  tree->buffer[free_position].value = value;
  tree->buffer[free_position].left = tree->buffer[free_position].right = -1;
  tree->buffer[free_position].used = 1;
  return true;
}

bool insert_right_child (T_tree *tree, T_node *parent, int value) {
  int free_position = get_empty_node(tree);
  if (free_position < 0) {
    return false;
  }
  parent->right = free_position;
  tree->buffer[free_position].value = value;
  tree->buffer[free_position].left = tree->buffer[free_position].right = -1;
  tree->buffer[free_position].used = 1;
  return true;
}

void create_root (T_tree* tree, int value) {
  tree->root = 0;
  tree->buffer[0].value = value;
  tree->buffer[0].left = tree->buffer[0].right = -1;
  tree->buffer[0].used = 1;
}

int calc_height (T_tree *tree, int index) {
  if (index < 0 || !(tree->buffer[index].used)) {
    return 0;
  }
  int left_height = calc_height(tree, tree->buffer[index].left);
  int right_height = calc_height(tree, tree->buffer[index].right);

  if (left_height > right_height) {
    return (1 + left_height);
  }

  return (1 + right_height);

}

int calc_number_of_nodes (T_tree* tree) {
  int node = 0;
  if (tree->root == -1) {
    return 0;
  }
  while (tree->buffer[node].used != 0) {
    node ++;
  }
  return node;
}

bool is_balanced (T_tree *tree, int index) {
  if (index < 0 || !(tree->buffer[index].used)) {
    return true;
  }

  if (tree->buffer[index].left == -1 && tree->buffer[index].right == -1) {
    return true;
  }

  if (tree->buffer[index].left != -1 && tree->buffer[index].left == -1) {
    return (is_balanced(tree, tree->buffer[index].left) && is_balanced(tree, tree->buffer[index].right));
  }

  if (tree->buffer[index].left != -1) {
    return calc_height(tree, tree->buffer[index].left) == 1;
  }

  if (tree->buffer[index].right != -1) {
    return calc_height(tree, tree->buffer[index].right) == 1;
  }
}


void pre_order(T_tree* tree, int index) {
  if (index < 0 || !tree->buffer[index].used) {
    return;
  }
  printf("%d ", tree->buffer[index].value);
  pre_order(tree, tree->buffer[index].left);
  pre_order(tree, tree->buffer[index].right);
}

void in_order(T_tree* tree, int index) {
  if (index < 0 || !tree->buffer[index].used) {
    return;
  }
  in_order(tree, tree->buffer[index].left);
  printf("%d ", tree->buffer[index].value);
  in_order(tree, tree->buffer[index].right);
}

void post_order(T_tree* tree, int index) {
  if (index < 0 || !tree->buffer[index].used) {
    return;
  }
  post_order(tree, tree->buffer[index].left);
  post_order(tree, tree->buffer[index].right);
  printf("%d ", tree->buffer[index].value);
}