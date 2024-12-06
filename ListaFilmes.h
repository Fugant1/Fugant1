#ifndef LISTAFILMES_H
#define LISTAFILMES_H

typedef struct no_filme
{
    char *nome_filme;
    struct no_filme *prox;
} No_Filme;

typedef struct Lista_filmes
{
    No_Filme *inicio;
    No_Filme *fim;
} Lista_Filmes;

// Protótipo das funções utilizadas

void inicializar_lista(Lista_Filmes *);
int lista_vazia(Lista_Filmes *);
int esta_na_lista(Lista_Filmes *, char *);
void inserir_lista(Lista_Filmes *, char *, char *, int *);
char *devolver_nome_filme(Lista_Filmes *, int, int *);
void excluir_lista(Lista_Filmes *, int *);

#endif