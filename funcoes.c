/** 
 * @file funcoes.c
 * @brief Ficheiro com todos as funções necessárias
 * @version 0.5
 * @authors Samuel Dias, name2, name3, name4, name5
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 20

/** 
 * Função que permite ao programa limpar a consola (input) em caso do utilizador digitar alguma letra ou simbolo inválido
*/
void limpaInput()
{
    while (getchar() != '\n');
}

void clear()
{
    system ("clear");
}


/*void voltaratras ()
{
    char enter[5];
    int confirmar;
           do
                {
                    printf("Pressiona ENTER para voltares ao menu de funcionalidades\n");
                    fgets(enter, 5, stdin);
                    char *pos = strchr(enter, '\n');
                    *pos = '\0';

                    if ((strcmp(enter, "\0") == 0))
                    {
                        confirmar = 1;
                        clear();
                        
                    }
                    else
                        confirmar = 0;
                } while (enter == 0);
}*/


/**
 * Permite a leitura do vetor para ser possivel proceder para menu de funcionalidades 
 */
void ler(int v[N])
{
    printf("Antes de poder aceder ao menu de funcionalidades, precisamos de saber qual é o seu vetor! \n");
    printf("Indique agora os valores entre 7 e 30 que o seu vetor vai ter nas suas respetivas posições (20 posicões): \n");
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%dº valor - ", i + 1);

        while (scanf("%d", &v[i]) != 1)
        // != 1 faz armazenar o valores no array/vetor
        {
            limpaInput();
            printf("ERRO! Digite um valor entre 7 e 30\n");
        }

        while (v[i] < 7 || v[i] > 30)
        {

            limpaInput();
            printf("ERRO! Digite um valor entre 7 e 30\n");
            while (scanf("%d", &v[i]) != 1)
            // != 1 faz armazenar o valores no array/vetor
            {
                limpaInput();
            }
        }
    }
    printf("\n");
}

//Função que permite ao utilizador visualizar o vetor que digitou
void escreve(int v[N])
{
    printf("O vetor é: ");
    for (int i = 0; i < N; i++)
    {

        printf("%d ", v[i]);
    }

    printf("\n");
}

/**
 Função que faz a multiplicação de todos os valores no vetor
 @param total variavel que vai armazenar o valor da multiplicação de todas os membros do vetor 
*/
void multiplicacao(int v[N])
{
    long total = 1;
    for (int i = 0; i < N; i++)
    {

        total *= v[i];
    }
    printf("A multiplicação dos valores do vetor é %ld\n", total);
    printf ("\n");
}

/**
 Função que ordena o vetor escolhido por ordem crescente
 @param aux variavel que vai funcionar como auxiliar para ordenar o vetor na ordem crescente
*/
void ordemcrescente(int v[N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (v[i] > v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    printf("O vetor na ordem crescente fica: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", v[i]);
    }
}

/**
 Função que calcula o seno de cada membro do vetor. Utiliza a biblioteca math.h.
*/

void vetorsin(int v[N])
{

    for (int i = 0; i < 20; i++)
    {
        printf("Na posicao %iº o seno é: %f\n", (i + 1), sin((v[i])));
    };
}

/**
 Função que constroi uma nova matriz utilizando os valores digitados para a primeira matriz.
*/

void matriz(int v[N])
{
    printf("A primeira linha vai ser:\n");
    printf("\n");
    //Escrita da 1º linha
    for (int i = 0; i < 20; i++)
        printf("%i  ", v[i]);
    printf("\n");
    //Gerador das próximas linhas 
    printf("A matriz criada é:\n");
    printf("\n");
    for (int l = 1; l < 20; l++)
    {
        //Gerador das colunas 
        for (int c = 0; c < 20; c++)
        {
            printf(" %i", v[rand() % 20]);
        }
        printf("\n");
    }
}

/**
 Função que devolve o numero maior que 2 e divisivel por 5.
 @param i variavel que vai correr o vetor dado pelo utilizador à procura do que é pretendido
*/
void devolvenumero(int v[N])
{
    printf("Os números que são maiores que dois e divisiveis por cinco são:\n");
    int i;
    for (i = 0; i < N; i++)
    {
        if (v[i] > 2)
        {
            if (v[i] % 5 == 0)
            {

                printf("%d\t", v[i]);
            }
        }
    }
}

/**
 Função que revela qual é o valor minimo do vetor
 @param i variavel que vai correr o vetor dado pelo utilizador
 @param minimo variavel que armazena o menor valor existente no array 
*/
void minimodovetor(int v[N])
{

    int i = 0;
    int minimo = v[0];

    for (i = 1; i < N; i++)
    {
        if (v[i] < minimo)
            minimo = v[i];
    }
    printf("O valor minimo do vetor é: %d\n", minimo);
}
