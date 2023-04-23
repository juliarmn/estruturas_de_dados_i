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

// Create an empty binary tree
void create_empty_tree(tree **t) {
  *t = NULL;
}

// Verify if is empty
bool is_empty(tree *t) {
  return (t == NULL);
}

// Create a root node:
tree *create_root(tree *t, type_of_data elem) {
  if (!t) {
    t = (tree*) malloc(sizeof(tree));
    t->left = NULL;
    t->right = NULL;
    t->data = elem;
  }
  return t;
}

// Insert the right child:
void insert_right_child(tree *parent, type_of_data elem) {
  tree *t = malloc(sizeof(tree));
  if (!parent) {
    printf("Error\n");
    return;
  }
  if (parent->right) {
    printf("Error\n");
    return;
  }
  t = create_root(parent->right, elem);
  parent->right = t;
}

// Insert the left child:
void insert_left_child(tree *parent, type_of_data elem) {
  tree *t = malloc(sizeof(tree));
  if (!parent) {
    printf("Error\n");
    return;
  }
  if (parent->left) {
    printf("The node already has a left child\n");
    return;
  }
  t = create_root(parent->left, elem);
  parent->left = t;
}

// Calculate the height:
int tree_height(tree *root) {
  if (root == NULL) {
    return 0;
  }

  int left_height = tree_height(root->left);
  int right_height = tree_height(root->right);

  if (left_height > right_height) {
    return (left_height + 1);
  }
  return (right_height + 1);
  //Or:
  //height = max(left_height, right_height) + 1;
}

// Verify if is balanced:
bool is_balanced(tree *root) {
  if (!root) {
    return true;
  }
  if (root->left == NULL && root->right == NULL) {
    return true;
  }
  if (root->left != NULL && root->right != NULL) {
    return(is_balanced(root->left) && is_balanced(root->right));
  }
  if(!(root->left)) {
    return (tree_height(root->left) == 1);
  }
  if(!(root->right)) {
    return (tree_height(root->right) == 1);
  }
}

// Count the number of nodes:
int number_of_nodes(tree *root) {
  if (root == NULL) {
    return 0;
  }
  int num_right = number_of_nodes(root->right);
  int num_left = number_of_nodes(root->left);

  return num_left + num_right + 1;
}

// Perfectly balanced:
bool is_perfectly_balanced(tree *root) {
  if (!root) {
    return true;
  }
  if (root->left == NULL && root->right == NULL) {
    return true;
  }
  if (root->left != NULL && root->right != NULL) {
    return (is_perfectly_balanced(root->left) && is_perfectly_balanced(root->right));
  }
  if (root->left != NULL) {
    return (number_of_nodes(root->left) == 1);
  }
  if (root->right != NULL) {
    return (number_of_nodes(root->right) == 1);
  }
}

void print_element(type_of_data elem) {
  //printf("Char: %c\n", elem.letter);
  printf("Int number: %d\n", elem.number);
  //printf("Double value: %c\n", elem.value);
}

void pre_order(tree *root) {
  if (!root) {
    printf("Empty tree\n");
    return;
  }
  print_element(root->data);
  pre_order(root->left);
  pre_order(root->right);
}

void in_order(tree *root) {
  if (!root) {
    printf("Empty tree\n");
    return;
  }
  in_order(root->left);
  print_element(root->data);
  in_order(root->right);
}

void pos_order(tree *root) {
  if (!root) {
    printf("Empty tree\n");
    return;
  }
  pos_order(root->left);
  pos_order(root->right);
  print_element(root->data);
}