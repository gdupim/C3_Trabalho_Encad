/*
 * Alunos:
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
        limparTela();

        printf(GREEN "\t/ MENU PRINCIPAL /\n" RESET);
        printf("[01] - Criar matriz.\n");
        printf("[02] - Verificar a quantidade de linhas.\n");
        printf("[03] - Verificar a quantidade de colunas.\n");
        printf("[04] - Inserir valor na matriz.\n");
        printf("[05] - Consultar valor por linha e coluna.\n");
        printf("[06] - Buscar Valor na matriz.\n");
        printf("[07] - Imprimir Matriz.\n");
        printf("[08] - Imprimir vizinhos do no.\n");
        printf("[09] - Somar matrizes.\n");
        printf("[10] - Subtrair matrizes.\n");
        printf("[00] - Sair.\n");
        printf("Escolha algum menu: ");
        scanf("%d", &escolha);
        getchar();

        limparTela();

        switch (escolha)
        {
        case 1:
        {
            printf(GREEN "\t/ CRIAR MATRIZ /\n" RESET);
            printf("\nDigite o numero de linhas: ");
            scanf("%d", &i);
            getchar();
            printf("\nDigite o numero de colunas: ");
            scanf("%d", &j);
            getchar();

            if (matriz == NULL)
            {
                matriz = CriarMatriz(i, j);
                printf("\nMatriz criada com sucesso: \n");
                ImprimirMatriz(matriz);
            }
            else if (matriz2 == NULL)
            {
                matriz2 = CriarMatriz(i, j);
                printf("\nMatriz criada com sucesso: \n");
                ImprimirMatriz(matriz2);
            }
            else
            {
                printf(RED "\nAs duas matrizes ja foram criadas...\n" RESET);
            }

            espera();
        }
        break;
        case 2:
        {
            printf(GREEN "\t/ VERIFICAR LINHAS /\n" RESET);
            printf("\nDeseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            if (escolha == 1)
            {
                printf("\nQuantidade de linhas: ");
                printf("%d\n", VerificarLinhas(matriz));
            }
            else if (escolha == 2)
            {
                printf("\nQuantidade de linhas: ");
                printf("%d\n", VerificarLinhas(matriz2));
            }

            espera();
        }
        break;
        case 3:
        {
            printf(GREEN "\t/ VERIFICAR COLUNAS /\n" RESET);
            printf("\nDeseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            if (escolha == 1)
            {
                printf("\nQuantidade de colunas: ");
                printf("%d\n", VerificarColunas(matriz));
                getchar();
            }
            else if (escolha == 2)
            {
                printf("\nQuantidade de colunas: ");
                printf("%d\n", VerificarColunas(matriz2));
                getchar();
            }

            espera();
        }
        break;
        case 4:
        {
            printf(GREEN "\t/ INSERIR VALOR /\n" RESET);
            printf("\nDeseja inserir na matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            printf("\nInsira a linha e a coluna a ser inserido: ");
            scanf("%d", &i);
            getchar();
            scanf("%d", &j);
            getchar();
            printf("\nAgora insira o valor a ser inserido: ");
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

            espera();
        }
        break;
        case 5:
        {
            printf(GREEN "\t/ CONSULTAR VALOR /\n" RESET);
            printf("\nDeseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();

            printf("\nInsira a linha e a coluna a ser verificado: ");
            scanf("%d", &i);
            getchar();
            scanf("%d", &j);
            getchar();

            if (escolha == 1)
            {
                no = ConsultarValor(matriz, i, j);
                printf("\nValor do no: %d", no->valor);
            }
            else if (escolha == 2)
            {
                no = ConsultarValor(matriz2, i, j);
                printf("\nValor do no: %d", no->valor);
            }

            espera();
        }
        break;
        case 6:
        {
            printf(GREEN "\t/ BUSCAR VALOR /\n" RESET);
            printf("\nDeseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();
            printf("\nInsira o valor a ser buscado: ");
            scanf("%d", &valor);

            if (escolha == 1)
            {
                BuscarValor(matriz, valor);
            }
            else if (escolha == 2)
            {
                BuscarValor(matriz2, valor);
            }

            espera();
        }
        break;
        case 7:
        {
            printf(GREEN "\t/ IMPRIMIR MATRIZ /\n" RESET);
            printf("\nDeseja imprimir a matriz 1 ou 2: ");
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

            espera();
        }
        break;
        case 8:
        {
            printf(GREEN "\t/ IMPRIMIR VIZINHOS /\n" RESET);
            printf("\nDeseja verificar da matriz 1 ou 2: ");
            scanf("%d", &escolha);
            getchar();
            printf("\nInsira a linha e a coluna a ser verificado: ");
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

            espera();
        }
        break;
        case 9:
        {
            printf(GREEN "\t/ SOMAR MATRIZES /\n" RESET);
            soma = SomaMatriz(matriz, matriz2);
            printf("\nA matriz somada e: \n");
            ImprimirMatriz(soma);

            espera();
        }
        break;
        case 10:
        {
            printf(GREEN "\t/ SUBTRAIR MATRIZES /\n" RESET);
            sub = SubtracaoMatriz(matriz, matriz2);
            printf("\nA matriz subtraida e: \n");
            ImprimirMatriz(sub);

            espera();
        }
        break;
        case 0:
            printf(GREEN "\nSaindo...\n" RESET);
            continuar = 0;

            espera();
            break;
        default:
            printf(RED "\nEscolha invalida, tente novamente...\n" RESET);

            espera();
            break;
        }
    } while (continuar);
    return 0;
}
