//
// Created by capit on 13/05/2025.
//

#ifndef MATRIZ_H
#define MATRIZ_H

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

typedef struct Matriz
{
    int valor;
    struct Matriz *cima;
    struct Matriz *baixo;
    struct Matriz *esquerda;
    struct Matriz *direita;
} Matriz;

// funções de matrizes
Matriz *CriarMatriz(int i, int j);
int VerificarLinhas(Matriz *matriz);
int VerificarColunas(Matriz *matriz);
int InserirValor(Matriz *mat, int i, int j, int valor);
int LiberarMatriz(Matriz *mat);
Matriz *ConsultarValor(Matriz *mat, int i, int j);
Matriz *BuscarValor(Matriz *mat, int valor);
Matriz *ImprimirVizinhos(Matriz *mat, int i, int j);
void ImprimirMatriz(Matriz *mat);
Matriz *BuscarValor(Matriz *mat, int valor);
Matriz *ImprimirVizinhos(Matriz *mat, int i, int j);
Matriz *SomaMatriz(Matriz *mat1, Matriz *mat2);
Matriz *SubtracaoMatriz(Matriz *mat1, Matriz *mat2);

// funções a parte
void limparTela();

#endif // MATRIZ_H
