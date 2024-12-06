#ifndef LISTAPONTEIROS_H
#define LISTAPONTEIROS_H

// Struct que cada nó armazena um ponteiro para um produto
typedef struct No_ListaP
{
    char *ponteiro_filme;
    struct No_ListaP *prox;
} No_ListaP;

// Ponteiros de início e fim da lista
typedef struct
{
    No_ListaP *inicio;
    No_ListaP *fim;
} Lista_Ponteiro;

// Protótipos das funções utilizadas
void inicializar_lista_ponteiros(Lista_Ponteiro *);
int lista_vazia_ponteiros(Lista_Ponteiro *);
void inserir_ponteiro(Lista_Ponteiro *, char *, int *);
int tamanho_lista_ponteiros(Lista_Ponteiro *);
char *devolver_filme_ponteiro(Lista_Ponteiro *, int, int *);
void excluir_lista_ponteiro(Lista_Ponteiro *, int *);

#endif