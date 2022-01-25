/** 
 * version 0.5
 * Introducing 2 more functions named as "vetorsin" and "matriz"
 * "vetorsin" calculates the sine of all elements
 * "matriz" generates a matrix  using the elements that user input at the very beginning where the first line is the starting vector 
 * Ordaining the functions in "funcoes.c" and "funcoes.h" to make sure they are organized like in the menu
 * Minor bugs fixed
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 20

int main()
{
  
    //Processo de leitura e escrita do array
    int arr[N], confirmararray, escolher;
    int enter;
    ler(arr);
    escreve(arr);
    //Processo de validação do vetor
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Tem a certeza que quer este vetor? \n1 - Sim\n2 - Não\n");
    printf("\n");
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

    //Processo de construção do menu de opções
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
        //Case que perimite ao utilizador escolher o "programa" a executar
        {
            switch (escolher)
            {
            case 1:
                multiplicacao(arr);
                break;
            case 2:
                ordemcrescente(arr);
                break;
            case 3:
                vetorsin (arr);
                break;
            case 4:
                matriz(arr);
                break;
            case 5:
                //função devolução dos valores maisores que 2 e divisiveis por 5
                devolvenumero (arr);
                break;
            case 6:
                minimodovetor (arr);
                
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
