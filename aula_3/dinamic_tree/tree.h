#ifndef TREE_H
#define TREE_H
#include <stdbool.h>
typedef struct data type_of_data;
typedef struct node tree;
// Create an empty binary tree:
void create_empty_tree(tree **root);
// Verify if the tree is empty:
bool is_empty(tree *t);
// Create a root node:
tree* create_root(tree *root, type_of_data elem);
// Right child:
void insert_right_child(tree *parent, type_of_data elem);
// Insert the left child:
void insert_left_child(tree *parent, type_of_data elem);
// Calculate the height:
int tree_height(tree *root);
// Verify if is balanced:
bool is_balanced(tree *root);
// Count the number of nodes:
int number_of_nodes(tree *root);
// Perfectly balanced:
bool is_perfectly_balanced(tree *root);
// Print element:
void print_element(type_of_data elem);
// Pre-order:
void pre_order(tree *root);
// In-order:
void in_order(tree *root);
// Pos-order:
void pos_order(tree *root);
#endif