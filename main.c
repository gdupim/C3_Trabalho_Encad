/*
 *Alunos:
 *      Nome: Ian Batista Fornaziero / RA: 2677210
 *      Nome: Gabriel Augusto Dupim / RA: 2651408
 */

#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int main(void)
{
    /*
    1. Criar matriz
    2. Desalocar matriz
    3. Inserir valor na matriz
    4. Consultar valor na matriz
    5. Buscar valor na matriz
    6. Imprimir valor dos 4 vizinhos de um nó
    */

    int i = 3; // linha
    int j = 3; // coluna

    // 1.
    // matriz 3x3
    Matriz *matriz = CriarMatriz(i, j);

    // 3.
    // preenche a diagonal principal com 1 e a terceira coluna da segunda linha com 10
    InserirValor(matriz, 3, 2, 10);

    i = VerificarLinhas(matriz);
    j = VerificarColunas(matriz);

    // print
    printf("Detalhes da matriz:\n");
    printf(">Linhas: %d\n", i);
    printf(">Colunas: %d\n", j);
    printf(">Valor a ser inserido: %d\n\n", matriz->baixo->baixo->direita->valor);
    printf("Matriz:\n");
    ImprimirMatriz(matriz);

    // 4.
    printf("\nValor na 3ª linha da 2ª coluna: %d\n", *((int *)ConsultarValor(matriz, 3, 2)));

    // 5.
    printf("\nBuscando valor 10 na matriz:\n");
    BuscarValor(matriz, 10);

    // 6.
    printf("\n\nQuais são os vizinhos do nó (3, 2):");
    ImprimirVizinhos(matriz, 3, 2);

    printf("\n\nQuais são os vizinhos do nós (2, 2):");
    ImprimirVizinhos(matriz, 2, 2);

    // 2.
    printf("\nLiberando matriz...\n");
    LiberarMatriz(matriz);

    return 0;
}
