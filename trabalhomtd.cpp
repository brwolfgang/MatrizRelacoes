#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM 100

// O programa recebe valores m e n que serviram de intervalo para o domínio da relação
// m >= 0 e n <= 10
// Em seguida faz a leitura da quantidade q de Relações
// Então o programa gera valores aleatórios entre m e n
// E ao final diz se o conjunto de relações é simetrico ou antisimetrica
// Se simetrica imprime 1
// Se nao corrige a antisimetria passando a ser simetrica
// Depois exibe o conjunto de relações ordenados

void imprime(int matriz[][2], int q)
{
        int i;
        int j;

        for (i = 0; i < q; i++)
        {
                for (j = 0; j < 2; j++)
                        printf("%d ", matriz[i][j]);
                printf("\n");
        }
}

// Função que verifica se o vetor booleano
// é composto somente por 1's
// Se sim quer dizer que a R é simetrica
int isSimetrica(int vetor[], int q)
{
        int simetrica = 1;
        int i;

        for (i = 0; i < q; i++)
                if (vetor[i] == 0)
                        simetrica = 0;
        if (simetrica == 0)
                return 0;
        else
                return 1;
}

void ordenar(int matriz[][2], int q)
{
        int i, j;
        int aux1, aux2;

        for (i = q-1; i >= 1; i--)
                for (j = 0; j < i; j++)
                        if (matriz[j][0] > matriz[j+1][0])
                        {
                                aux1 = matriz[j][0];
                                aux2 = matriz[j][1];
                                matriz[j][0] = matriz[j+1][0];
                                matriz[j][1] = matriz[j+1][1];
                                matriz[j+1][0] = aux1;
                                matriz[j+1][1] = aux2;
                        }else{
                                 if (matriz[j][0] == matriz[j+1][0])
                                   {
                                          if (matriz[j][1] > matriz[j+1][1])
                                          {
                                                 aux1 = matriz[j][0];
                                                 aux2 = matriz[j][1];
                                                 matriz[j][0] = matriz[j+1][0];
                                                 matriz[j][1] = matriz[j+1][1];
                                                 matriz[j+1][0] = aux1;
                                                 matriz[j+1][1] = aux2;
                                          }
                                   }
                    }
}

int main()
{
        int cont, n, m, q, i, j, valorLinha, valorColuna;
        int matriz[TAM][2];
        int matrizAux[TAM][2];
        int vetor[TAM];
        char matrizResultante[TAM][4];

        printf("M : ");
        scanf("%d", &m);
        printf("N : ");
        scanf("%d", &n);
        printf("Q : ");
        scanf("%d", &q);

        // Preenche matriz de relações com valores aleatórios entre m a n
        for (i = 0; i < q; i++)
                for (j = 0; j < 2; j++)
                        // scanf("%d", &matriz[i][j]);
                        matriz[i][j] = m + rand() % (n + 1 - m);

        // Preenche matriz auxiliar com valores invertidos da matriz de relacoes
        // O que é linha na matriz, passa a ser coluna na auxiliar (valor)
        // O que é coluna na matriz, passa a ser linha na auxiliar (valor)
        // Exemplo: Matriz
        // 1  2
        // 3  4
        // Matriz Auxiliar
        // 2  1
        // 4  3
        for (i = 0; i < q; i++)
        {
                cont = 1;
                for (j = 0; j < 2; j++)
                {
                        matrizAux[i][j] = matriz[i][cont];
                        cont--;
                }
        }

        // Imprime a matriz de relações
        printf("\n Pares Gerados\n");
        imprime(matriz, q);

        // Inicializa o vetor booleano com 0
        for (i = 0; i < q; i++)
                vetor[i] = 0;

        // Verifica se existe linhas com valores iguais na matriz de relações e matriz auxiliar
        // Se sim, marca o vetor[i] com 1
        for (i = 0; i < q; i++)
        {
                valorLinha = matriz[i][0];
                valorColuna = matriz[i][1];
                for (j = 0; j < q; j++)
                        if (valorLinha == matrizAux[j][0] && valorColuna == matrizAux[j][1])
                                vetor[i] = 1;
        }

        j = 0;
        if (isSimetrica(vetor, q))
                printf("\n1\n");
        else
        {
                // Corrige a antisimetria
                printf("\n0\n");
                for (i = 0; i < q; i++)
                        if (vetor[i] == 0)
                        {
                                j++;
                                matriz[q+i][0] = matriz[i][1];
                                matriz[q+i][1] = matriz[i][0];
                        }
        }

        ordenar(matriz, q+j);
        imprime(matriz, q+j);
}
