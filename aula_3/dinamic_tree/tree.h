#ifndef TREE_H
#define TREE_H
#include <stdbool.h>
typedef struct node T_node;
typedef struct tree T_tree;
void init_tree(T_tree *tree);
void create_root(T_tree* tree, int value);
int get_empty_node (T_tree *tree);
void insert_left_child (T_tree *tree, T_node *parent, int value);
void insert_right_child (T_tree *tree, T_node *parent, int value);
void create_root (T_tree* tree, int value);
int calc_height (T_tree *tree, int index);
int calc_number_of_nodes (T_tree* tree);
bool is_balanced (T_tree *tree, int index);
void pre_order(T_tree* tree, int index);
void in_order(T_tree* tree, int index);
void pos_order(T_tree* tree, int index);
#endif