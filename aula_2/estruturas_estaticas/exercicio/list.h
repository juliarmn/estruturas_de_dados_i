#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
//estruturas:
typedef int chave;
typedef struct dados Dados;
typedef struct elemento Elem;
typedef struct lista Lista;
//funções:
//----------------------
//Criar uma lista vazia
void inicializar_lista(Lista *list);
//Verifica se o número de elementos é zero
bool vazia(Lista *list);
//Verifica se o número de elementos é igual ao máximo
bool cheia(Lista *list);
//Inserir elemento:
void inserir_elemento (Lista *list, int posicao, Elem pessoa);
//Quantos elementos tem na lista:
int contar_num_elementos (Lista *list);
//Busca a posição do elemento pela chave -> busca binária-> considerei a lista ordenada:
int busca_primeiro_tipo(chave key, Lista *list);
//Busca o elemento pela posição dada:
bool busca_segundo_tipo(int posicao, Lista *list);
//Printar o elemento:
void printa_elem(Elem elemento);
//Eliminar o elemento:
void eliminar_elemento (Lista *list, int posicao);
//Destrói a lista (logicamente)
void destruir_lista (Lista *list);
//Imprimir a lista:
void imprimir_lista(Lista *list);
//Tamanho da lista:
int tamanho(Lista *list);
#endif