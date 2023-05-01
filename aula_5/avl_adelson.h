#ifndef AVL_ADELSON_H
#define AVL_ADELSON_H
typedef struct tree node;
node* novo_no(int info);
int altura (node *no);
int diferenca_altura(node *no);
node *menor_no(node *no);
node *insert_avl(node *raiz, int info);
node *remover (node *raiz, int info);
node *rotacao_dir(node *no);
node *rotacao_esq(node *no);
node* esq_dir_rotate(node* no);
node* dir_esq_ratate(node * no);
void printPreOrder(node *node);
void printInOrder(node *node);
void printPostOrder(node *node);

#endif