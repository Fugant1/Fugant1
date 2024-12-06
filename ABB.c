#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ABB.h"
#include "ListaPonteiros.c"
#include "ListaFilmes.c"

ABB *criar(void)
{
    ABB *A = (ABB *)malloc(sizeof(ABB));
    if (A != NULL)
    {
        A->raiz = NULL;
    }
    return A;
}

int inserir_ABB(ABB *A, int *X, char *N, char **LF)
{ // função pro usuario chamar na main
    inserir_recursivo(A->raiz, X, N, LF);
}

int inserir_recursivo(Bloco_ABB **B, int *X, char *N, char **LF)
{

    if (*B == NULL)
    {
        *B = (Bloco_ABB *)malloc(sizeof(Bloco_ABB));
        (*B)->n_usp = *X;
        (*B)->nome_usuario = *N;
        // continuar a função de inserção
    }
}