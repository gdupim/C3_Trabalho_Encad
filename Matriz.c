/*
 *Alunos:
 *      Nome: Ian Batista Fornaziero / RA: 2677210
 *      Nome: Gabriel Augusto Dupim / RA: 2651408
 */

#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

Matriz *CriarMatriz(int i, int j)
{
    Matriz ***matAux = malloc((size_t)i * sizeof(Matriz **)); // aloca as linhas
    if (matAux == NULL)
        return NULL; // erro de alocação

    for (int m = 0; m < i; m++)
    {
        matAux[m] = malloc((size_t)j * sizeof(Matriz *));
        if (matAux[m] == NULL)
            return NULL; // erro de alocação

        for (int n = 0; n < j; n++)
        {
            matAux[m][n] = malloc(sizeof(Matriz));
            if (matAux[m][n] == NULL)
                return NULL; // erro de alocação

            matAux[m][n]->valor = (m == n) ? 1 : 0; // gera a matriz identidade
            matAux[m][n]->cima = NULL;
            matAux[m][n]->baixo = NULL;
            matAux[m][n]->esquerda = NULL;
            matAux[m][n]->direita = NULL;
        }
    }

    // manipulação dos ponteiros
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            // linhas
            if (m > 0)
                matAux[m][n]->cima = matAux[m - 1][n];
            if (m < i - 1)
                matAux[m][n]->baixo = matAux[m + 1][n];

            // colunas
            if (n > 0)
                matAux[m][n]->esquerda = matAux[m][n - 1];
            if (n < j - 1)
                matAux[m][n]->direita = matAux[m][n + 1];
        }
    }

    Matriz *matriz = matAux[0][0]; // retorna um ponteiro para o nó 0,0

    return matriz;
}

/*
 * Nessa função deu leak de memória, depois de muito pesquisar e tentar outras coisas,
 * a solução seria fazer Criarmatriz retornar o mat, ou seja, mudar para ***CriarMatriz,
 * porém, ele iria quebrar a regra de retornar um ponteiro para o nó (0,0), então mantive o leak para ser 100% fiel ao exercício,
 * mas a solução seria literalmente retornar no main mat e fazer Matriz *matriz = mat[0][0] e liberar mat depois
 */

int VerificarLinhas(Matriz *matriz)
{
    int i = 1;
    Matriz *aux = matriz;

    while (aux->baixo != NULL) // vai descendo até o final para saber a quantidade de linhas
    {
        aux = aux->baixo;
        i++;
    }
    return i;
}

int VerificarColunas(Matriz *matriz)
{
    int j = 1;
    Matriz *aux = matriz;

    while (aux->direita != NULL) // vai indo para a esquerda até o final para saber a quantidade de colunas
    {
        aux = aux->direita;
        j++;
    }
    return j;
}

int InserirValor(Matriz *mat, int i, int j, int val)
{
    if (mat == NULL)
        return -1;

    Matriz *aux = ConsultarValor(mat, i, j);
    aux->valor = val; // muda o valor do elemento

    return 1;
}

int LiberarMatriz(Matriz *mat)
{
    if (mat == NULL)
        return -1; // caso a matriz não exista

    Matriz *linha = mat; // define as linhas

    while (linha != NULL)
    {
        Matriz *coluna = linha;           // para definir o mesmo índice
        Matriz *proxLinha = linha->baixo; // valor para segurar o próximo valor sem perder a ref depois do free

        while (coluna != NULL)
        {
            Matriz *prox = coluna->direita; // valor para segurar a ref do prox depois do free
            free(coluna);                   // da free no célula
            coluna = prox;                  // vai pro prox célula
        } // no caso, ele vai se movimentar de forma horizontal, dando free em todos os elementos horizontalmente, e em seguida, descer para a proxima linha
        linha = proxLinha; // vai pra prox linha
    }
    return 1;
}

Matriz *ConsultarValor(Matriz *mat, int i, int j)
{
    if (mat == NULL)
    {
        printf("A matriz nao existe");
        return NULL;
    }

    int linhas = i;
    int colunas = j;

    if (i > VerificarLinhas(mat)) // se o número de linha for maior que na matriz
    {
        printf("Numero de linhas maior que a da matriz");
        return 0;
    }
    if (j > VerificarColunas(mat)) // se o número de coluna for maior que na matriz
    {
        printf("Numero de colunas maior que a da matriz");
        return 0;
    }

    Matriz *aux = mat;

    while (linhas != 1)
    {
        aux = aux->baixo; // desce até a linha desejada
        linhas--;
    }

    while (colunas != 1)
    {
        aux = aux->direita; // vai até a coluna desejada
        colunas--;
    }

    return aux;
}

Matriz *BuscarValor(Matriz *mat, int valor)
{
    if (mat == NULL)
    {
        printf("A matriz nao existe.");
        return NULL;
    }

    Matriz *auxLinha = mat;
    int linha = 1; // índice da linha

    while (auxLinha != NULL) // percorre as linhas
    {
        Matriz *auxColuna = auxLinha;

        int coluna = 1; // indice da coluna
        while (auxColuna != NULL)
        {
            if (auxColuna->valor == valor)
            {
                printf(">Valor encontrado na posicao (%d, %d)", linha, coluna);
                return auxColuna; // retorna o nó
            }
            auxColuna = auxColuna->direita;
            coluna++;
        }
        auxLinha = auxLinha->baixo;
        linha++;
    }

    return NULL; // se não encontrar, retorna null
}

Matriz *ImprimirVizinhos(Matriz *mat, int i, int j)
{
    Matriz *aux = ConsultarValor(mat, i, j);
    if (aux == NULL)
    {
        printf("No nao encontrado.\n");
        return NULL;
    }

    if (aux->cima != NULL)
        printf(">Cima: %d\n", aux->cima->valor);
    else
        printf(">Cima: NULL\n");

    if (aux->baixo != NULL)
        printf(">Baixo: %d\n", aux->baixo->valor);
    else
        printf(">Baixo: NULL\n");

    if (aux->esquerda != NULL)
        printf(">Esquerda: %d\n", aux->esquerda->valor);
    else
        printf(">Esquerda: NULL\n");

    if (aux->direita != NULL)
        printf(">Direita: %d\n", aux->direita->valor);
    else
        printf(">Direita: NULL\n");

    return aux;
}

void ImprimirMatriz(Matriz *mat)
{
    Matriz *auxLinha = mat;
    Matriz *auxColuna = mat;

    while (auxLinha != NULL)
    {
        while (auxColuna != NULL)
        {
            if (auxColuna->valor <= 9)
            {
                if (auxColuna->valor == 0 || auxColuna->valor == 1)
                    printf("|" RED "0%d" RESET, auxColuna->valor);
                else
                    printf("|" GREEN "0%d" RESET, auxColuna->valor); // formata o número para ter 2 dígitos
            }
            else
                printf("|" GREEN "%d" RESET, auxColuna->valor);

            auxColuna = auxColuna->direita; // vai passando pela linha até o final
        }
        printf("|\n");
        auxLinha = auxLinha->baixo; // move uma linha pra baixo
        auxColuna = auxLinha;       // volta para printar o primeiro da próxima linha
    }
}