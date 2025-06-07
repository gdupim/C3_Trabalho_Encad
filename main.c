/*
 *Alunos:
 *      Ian Batista Fornaziero RA: 2677210
 *      Gabriel Augusto Dupim RA: 2651408
 */

#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int main(void)
{
    int escolha;
    int continuar = 1;
    Matriz *matriz = NULL;
    Matriz *matriz2 = NULL;
    Matriz *soma, *sub, *no;
    int i;
    int j;
    int valor;

    do
    {
        printf("\n MENU PRINCIPAL \n");
        printf("1 - Criar matriz\n");
        printf("2 - Verificar a quantidade de linhas\n");
        printf("3 - Verificar a quantidade de colunas\n");
        printf("4 - Inserir valor na matriz\n");
        printf("5 - Consultar valor por linha e coluna\n");
        printf("6 - Buscar Valor na matriz\n");
        printf("7 - Imprimir Matriz\n");
        printf("8 - Imprimir vizinhos do no\n");
        printf("9 - Somar matrizes\n");
        printf("10 - Subtrair matrizes\n");
        printf("0 - Sair\n");
        printf("Escolha algum menu: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha)
        {
        case 1:
        {
            printf("Digite o numero de linhas: ");
            scanf("%d", &i);
            getchar();
            printf("Digite o numero de colunas: ");
            scanf("%d", &j);
            getchar();

            if (matriz == NULL)
            {
                matriz = CriarMatriz(i, j);
                printf("Matriz criada com sucesso: \n");
                ImprimirMatriz(matriz);
            }
            else if (matriz2 == NULL)
            {
                matriz2 = CriarMatriz(i, j);
                printf("Matriz criada com sucesso: \n");
                ImprimirMatriz(matriz2);
            }
            else
            {
                printf("As duas matrizes ja foram criadas\n");
            }
        }
        break;
        case 2:
        {
            printf("Deseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            if (escolha == 1)
            {
                printf("A quantidade de linhas e:");
                printf("%d\n", VerificarLinhas(matriz));
            }
            else if (escolha == 2)
            {
                printf("A quantidade de linhas e:");
                printf("%d\n", VerificarLinhas(matriz2));
            }
        }
        break;
        case 3:
        {
            printf("Deseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            if (escolha == 1)
            {
                printf("A quantidade de colunas e:");
                printf("%d\n", VerificarColunas(matriz));
                getchar();
            }
            else if (escolha == 2)
            {
                printf("A quantidade de colunas e:");
                printf("%d\n", VerificarColunas(matriz2));
                getchar();
            }
        }
        break;
        case 4:
        {
            printf("Deseja inserir na matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            printf("Insira a linha e a coluna a ser inserido: ");
            scanf("%d", &i);
            getchar();
            scanf("%d", &j);
            getchar();
            printf("Agora insira o valor a ser inserido: ");
            scanf("%d", &valor);
            getchar();
            if (escolha == 1)
            {
                InserirValor(matriz, i, j, valor);
            }
            else if (escolha == 2)
            {
                InserirValor(matriz2, i, j, valor);
            }
        }
        break;
        case 5:
        {
            printf("Deseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            printf("Insira a linha e a coluna a ser verificado");
            scanf("%d", &i);
            getchar();
            scanf("%d", &j);
            getchar();

            if (escolha == 1)
            {
                no = ConsultarValor(matriz, i, j);
                printf("O valor do no e: %d", no->valor);
            }
            else if (escolha == 2)
            {
                no = ConsultarValor(matriz2, i, j);
                printf("O valor do no e: %d", no->valor);
            }
        }
        break;
        case 6:
        {
            printf("Deseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();
            printf("Insira o valor a ser buscado: ");
            scanf("%d", &valor);

            if (escolha == 1)
            {
                BuscarValor(matriz, valor);
            }
            else if (escolha == 2)
            {
                BuscarValor(matriz2, valor);
            }
        }
        break;
        case 7:
        {
            printf("Deseja imprimir a matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            if (escolha == 1)
            {
                ImprimirMatriz(matriz);
            }
            else if (escolha == 2)
            {
                ImprimirMatriz(matriz2);
            }
        }
        break;
        case 8:
        {
            printf("Deseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();
            printf("Insira a linha e a coluna a ser verificado");
            scanf("%d", &i);
            getchar();
            scanf("%d", &j);
            getchar();

            if (escolha == 1)
            {
                ImprimirVizinhos(matriz, i, j);
            }
            else if (escolha == 2)
            {
                ImprimirVizinhos(matriz2, i, j);
            }
        }
        break;
        case 9:
        {
            soma = SomaMatriz(matriz, matriz2);
            printf("A matriz somada e: \n");
            ImprimirMatriz(soma);
        }
        break;
        case 10:
        {
            sub = SubtracaoMatriz(matriz, matriz2);
            printf("A matriz subtraida e: \n");
            ImprimirMatriz(sub);
        }
        break;
        case 0:
            printf("Saindo...\n");
            continuar = 0;
            break;
        default:
            printf("Escolha invalida, tente novamente\n");
            break;
        }
    } while (continuar);
    return 0;
}
