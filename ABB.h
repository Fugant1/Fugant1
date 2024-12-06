#ifndef ABB_H
#define ABB_H

#include "ListaPonteiros.h"
#include "ListaFilmes.h"

typedef struct bloco_ABB
{
    int n_usp;
    char *nome_usuario;
    Lista_Ponteiro lista_ponteiros;
    struct bloco_ABB *esq, *dir;
} Bloco_ABB;

typedef struct ABB
{
    Bloco_ABB *raiz;
} ABB;

ABB *criar(void);
int inserir_recursivo(Bloco_ABB **, int *, char *, char **);

#endif