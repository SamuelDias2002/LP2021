/** 
 * @file main.c
 * @brief Programa com o obejtivo de oferecer um conjunto de funcionalidades. Ler Reedme para mais informações
 * @version 0.5
 * @authors Samuel Dias, name2, name3, name4, name5
 
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 20

int main()
{

    /**
     * Parte que contem a funcionalidade de introdução e confirmação do vetor.
     * Além disso, apresenta o menu com as funcionalidades disponiveis para o utilizador poder execeutar
     *  
     */

    /**
     * @param arr variável que vai armazenar o vetor do utilizador
     */
    int arr[N];
    /**
     * @param confirmararray variavel que permite confirmar o vetor escolhido
     */
    int confirmararray;
    /**
     * @param escolher varivael que vai permitir o utilizador escolher a funcionalidade que quer executar
     */
    int escolher;

    char enter;
    //enter variavel que vai ser util para podermos voltar ao menu de funções disponiveis
    ler(arr);
    escreve(arr);
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Tem a certeza que quer este vetor? \n1 - Sim\n2 - Não\n");
    printf("\n");
    printf (">>>>> ");
    scanf("%d", &confirmararray);
    printf("\n");
    if (confirmararray == 0 || confirmararray > 2)
    {
        printf("Erro, o programa vai voltar ao inicio!\n");
        return main();
    }
    else if (confirmararray == 1)
    {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("Vetor validado com sucesso! \n");
        printf("\n");
    }
    else
    {
        do
        {
            printf("\n");
            ler(arr);
            printf("\n");
            escreve(arr);
            printf("\n");
            printf("Tem a certeza que quer este vetor? \n1 - Sim\n2 - Não\n");
            printf("\n");
            scanf("%d", &confirmararray);
            printf("\n");

        } while (confirmararray == 2);
    }

    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Escolha a função que pretende executar: \n");
    printf("1 - Cálculo da multiplicação de todos os elementos no vetor\n");
    printf("2 - Devolução do vetor ordenado por ordem crescente\n");
    printf("3 - Cálculo do seno (sin) de todos os elementos no vetor\n");
    printf("4 - Construção de uma matriz 20 por 20, em que cada linha é composta pelo vetor lido (primeira linha) e por permutações dos seus valores (outras linhas)\n");
    printf("5 - Devolução dos valores maiores que dois e divisíveis por cinco\n");
    printf("6 - Identificação do mínimo do vetor\n");
    printf("7 - Sair\n");
    printf("\n");
    scanf("%d", &escolher);

    if (escolher == 0 || escolher > 7)
    {
        printf("Por favor digite um valor entre 1 e 6! \n");
        scanf("%d", &escolher);
    }
    else
    {

        {
            switch (escolher)
            {
            case 1:
                multiplicacao(arr);
                //voltaratras;
                break;
            case 2:
                ordemcrescente(arr);
                break;
            case 3:
                vetorsin(arr);
                break;
            case 4:
                matriz(arr);
                break;
            case 5:
                devolvenumero(arr);
                break;
            case 6:
                minimodovetor(arr);
                break;
            case 7:
                printf("\n");
                printf("Obrigado por usar o nosso programa! \n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                return 0;
            default:
                break;
            }
        }
    }
    
}
