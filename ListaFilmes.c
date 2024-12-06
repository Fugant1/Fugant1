
#include "ListaFilmes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Retorna os ponteiros início e fim da lista
void inicializar_lista(Lista_Filmes *L)
{
    L->inicio = NULL;
    L->fim = NULL;
}

// Verifica se a lista de usuários está vazia, retornando 1 se estiver e 0 caso contrário
int lista_vazia(Lista_Filmes *L)
{
    return (L->inicio == NULL);
}

// Verifica se um usuário está na lista
int esta_na_lista(Lista_Filmes *L, char *nome_filme)
{
    if (Lista_Filmes_vazia(L))
        return 0; // Caso a lista esteja vazia, retorna e o erro é atualizado

    // Ponteiro auxiliar para não modificar 'ini'
    No_Filme *aux = L->inicio;

    // Percorre a lista comparando o nome de cada usuário
    while (aux != NULL)
    {
        if (strcmp(aux->nome_filme, nome_filme) == 0)
            return 1; // Retorna 1 se o usuário for encontrado

        aux = aux->prox; // Avança para o próximo nó
    }

    return 0; // Retorna 0 se o usuário não estiver na lista
}

// Insere um novo usuário na lista de usuários
void inserir_lista(Lista_Filmes *L, char *nome_filme, int *erro)
{
    // Aloca memória para um novo nó 
    No_Filme *novo = (No_Filme *)malloc(sizeof(No_Filme)); 
    if (novo == NULL)
    {
        *erro = 1;
        return; // Caso a alocação falhe, retorna e o erro é atualizado
    }

    // Ajusta o ponteiro para o nome do usuário
    novo->nome_filme = nome_filme;
    novo->prox = NULL; // Define o próximo nó como NULL

    // Insere o novo nó no início da lista se ela estiver vazia
    if (L->inicio == NULL)
    {
        L->inicio = novo;
    }
    else // Se não estiver, insere o novo nó no final da lista
    {
        L->fim->prox = novo; 
    }

    L->fim = novo; // Atualiza 'fim' para o novo nó
    *erro = 0;
}

// Função para buscar um usuário pelo nome
No_Filme *comparar_nomes(Lista_Filmes *L, char *nome_filme, int *erro)
{
    // Ponteiro 'aux' para não alterar 'inicio'
    No_Filme *aux = L->inicio;

    // Percorre a lista comparando o nome fornecido com o da lista
    while (aux != NULL && strcmp(aux->nome_filme, nome_filme) != 0)
    {
        aux = aux->prox; // Avança para o próximo nó
    }
    return aux; // Retorna o nó encontrado ou NULL se não encontrar
}

// Função que retorna o nome do usuário no índice especificado
char *devolver_nome_filme(Lista_Filmes *L, int indice, int *erro)
{
    // Ponteiro 'aux' para não alterar 'inicio'
    No_Filme *aux = L->inicio;

    // Variável contadora
    int i = 0;

    // Percorre a lista até o índice desejado
    while (i != indice && aux != NULL)
    {
        i++;
        aux = aux->prox; // Avança para o próximo nó
    }
    if (aux != NULL) // Se encontrar o índice antes de chegar ao fim, retorna o nome do usuário
    {
        *erro = 0;
        return aux->nome_filme;
    }
    *erro = 1;
    return NULL; // Caso contrário, ajusta o erro e retorna NULL
}

// Exclui todos os nós da lista de usuários
void excluir_lista(Lista_Filmes *L, int *erro)
{
    if (Lista_Filmes_vazia(L))
    {
        *erro = 1;
        return; // Caso a lista esteja vazia, atualiza o erro e retorna
    }

    // Ponteiros auxiliares
    No_Filme *aux = L->inicio;
    No_Filme *temp = NULL;

    // Percorre a lista e libera cada nó
    while (aux != NULL)
    {
        temp = aux; // Guarda o nó atual para liberar
        aux = aux->prox; // Avança para o próximo nó
        free(temp->nome_filme); // Libera o nome
        free(temp); // Libera o nó atual
    }

    // Ajusta os ponteiros
    L->inicio = NULL;
    L->fim = NULL;
    *erro = 0; 
}