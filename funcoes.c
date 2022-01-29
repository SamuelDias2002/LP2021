/** 
 * @file funcoes.c
 * @brief Ficheiro com todos as funções necessárias
 * @version 1.0
 * @authors Carlos Silva, Gabriel Pacheco, Jõao Matos, Ricardo Pereira, Samuel Dias
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

/**
 * Permite a leitura do vetor para ser possivel proceder para menu de funcionalidades 
 * @param v é o vetor responsável em armazenar os valores que vão ser digitados pelo utilizador
 */
void ler(int v[N])
{
    //tirei a pergunta inicial para a funcao main para poder utilizar esta funcao na funcao de mistura de vetores (Gabriel)
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

/**
 * Função que permite ao utilizador visualizar o vetor que digitou.
 * @param v O vetor V é o vetor digitado
 */
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
}

/**
 * Função que ordena o vetor escolhido por ordem crescente.
 * Utiliza um ciclo for dentro de outro ciclo for para poder correr o vetor dado e poder ordenar noutro vetor "imaginário" o vetor principal.
 * @param aux variavel que vai funcionar como variavel auxiliar onde vai receber a v[i] e realizar os processos necessários para ordenar o vetor na ordem crescente
 
 
*/

void ordemcrescente(int v[N]) //ordenação do vetor por ordem crescente
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
 * Função que devolve o numero maior que 2 e divisivel por 5.
 * Com um ciclo for e dois ciclos if's, conseguimos correr o vetor de forma a verificarmos se eram maiores que 2 e divisiveis por 5.
 

 @param i variavel que vai tomar valores de 0 a 19, de forma a correr o vetor dado pelo utilizador à procura do que é pretendido
*/

void devolvenumero(int v[N]) //funcao que devolve numero maior que 2 e que seja divisivel por 5
{
    printf("Os números que são maiores que 2 e divisiveis por 5 são:");
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
 Função que revela qual é o valor minimo do vetor.
 Através da utilização de um ciclo for a correr por todos os membros do vetor e armazenar o valor minimo numa variavel.
 @param i variavel que vai correr o vetor dado pelo utilizador
 @param minimo variavel que armazena o menor valor existente no array 
*/
void minimodovetor(int v[N]) //funçao que revela o valor minimo do vetor
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

/**
 Função que calcula o seno de cada membro do vetor. Utiliza a biblioteca math.h.
 @param i Variavel que vai tomar valores de 0 a 19, de forma a correr o vetor dado pelo utilizador à procura do que é pretendido
*/
void vetorsin(int v[N])
{
    int i;
    for (i = 0; i < 20; i++)
    {
        printf("Posicao %d, valor %d: %f\n", (i + 1), v[i], sin((v[i])));
    }
}

/**
 Função que constroi uma nova matriz utilizando os valores digitados para a primeira matriz.
 Processamento da primeira linha através de um ciclo for. 
 O mesmo acontece para ser possivel processar as proximas linhas e as respetivas colunas, excepto que aqui é o utilizado o comando rand.
 @param  v Vetor que fica encarregue de armazenar os valores de forma a que seja possivel contruir a matriz
 @param  l Variavel que faz ler as linhas do vetor
 @param  c Variavel que permite armazenar as colunas criadas através do comando rand
*/
void matriz(int v[N])
{
    
    for (int i = 0; i < 20; i++)
    {
        printf("%i  ", v[i]);
        printf("\n");
    }
    
    for (int l = 1; l < 20; l++)
    {

        for (int c = 0; c < 20; c++)
        {
            printf("%i  ", v[rand() % 20]);
        }
        printf("\n");
    }
}

/**
 *  Função que está encarregue de criar uma matriz que mistura metade do primeiro vetor dado pelo utilizador com outra metade de um outro vetor pedido pelo utilizador
 *  O primeiro ciclo for tem o objetivo de usar o primeiro vetor no calculo da primeira metade da matriz vw.
 *  O segundo ciclo for é para completar o resto do vetor vw com a metade do vetor arr2. Por fim realizamos outro ciclo for, para permitir o utilizador ver a matriz vw completa.
 *  @param arr Variavel entregue à tarefa de armazenar o segundo vetor digitado pelo utilizador
 *  @param confirmaarray2 Váriavel que vai permitir a confirmação do segundo vetor para ser possivel seguir em frente
 *  @param vw Vetor que vai ter a tarefa de criar um vetor misturando metade do vetor original e metade do novo vetor
 *  @param p Variavel que vai correr as 10 primeiras posições para dar valores ao vetor vw, usando o primeiro vetor digitado
 *  @param s Variavel que vai correr as ultimas 10 primeiras posições para dar valores ao vetor vw, usando o segundo vetor digitado
 */ 

void mixvetor(int v[N])
{
    int arr2[N], confirmararray2;
    ler(arr2);
    //Processo de validação do vetor
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Tem a certeza que quer este vetor? \n1 - Sim\n2 - Não\n");
    printf("\n");
    scanf("%d", &confirmararray2);
    printf("\n");
    while (confirmararray2 == 0 || confirmararray2 > 2)
    {
        printf("Valor desconhecido, insira 1 para continuar ou 2 para escrever outro vetor!\n");
        printf("\n");
        scanf("%d", &confirmararray2);
        printf("\n");
    }
    if (confirmararray2 == 1)
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
            ler(arr2);
            printf("\n");
            escreve(arr2);
            printf("\n");
            printf("Tem a certeza que quer este vetor? \n1 - Sim\n2 - Não\n");
            printf("\n");
            scanf("%d", &confirmararray2);
            printf("\n");

        } while (confirmararray2 == 2);
    }
    escreve(arr2);
    int vw[20];
    //For com o objetivo de usar o primeiro vetor na primeira metade
    for (int p = 0; p < 10; p++)
    {
        vw[p] = v[p]; 
    }
    for (int s = 10; s < 20; s++) // Segundo for para completar o resto do vetor vw com a metade do vetor arr2
    {
        vw[s] = arr2[s];
    }
    //Segunda vetor na segunda metade
    printf("\nMistura dos vetores\n");
    for (int c = 0; c < 20; c++)
    {
        printf("posicao %i = %i\n", (c + 1), vw[c]); //Dar a conhecer ao utilizador o vetor que criou com os 2 vetores que digitou anteriormente
    }
}
/** 
 * Função com o objetivo de obter o minimo multiplo comum (mmc) de cada valor do vetor dado.
 * É necessário um ciclo for para correr o vetor incial, onde são escolhidos 2 valores seguidos (ex: Primeiro valor do vetor e segundo valor do vetor), e vai ser verificar se é possivel determinar o mmc.
 * @param nv Vetor que vai armazenar os minimos multiplos comuns dos 2 valores.
 * @param mmc Variavel que vai armazenar o valor do minimo multiplo comum dos 2 valores dados
 * @param a Variavel importante que vai permitir mostrar os valores dos quais foo calculado o minimo multiplo comum
 * @param c Variavel que vai correr no ciclo for para poder calcular o valor 
 * @param v1 Variavel que vai armazenar o primeiro valor necessário para o calculo do mmc
 * @param v1 Variavel que vai armazenar o segundo valor necessário para o calculo do mmc
*/

void minimomultiplo(int v[N])
{
    int nv[20];
    int a = 0;
    int mmc;
    int c;
    for (c = 0; c < 19; c++)
    {
        int v1 = v[c];
        int v2 = v[c + 1];
        if (v1 > v2)
            mmc = v1;
        else
            mmc = v2; //verificação qual é o maior valor para nao dar um valor menor que um na divisao
        while (1)
        { //while(1) vai ser sempre verdade, ou seja, vai fazer o loop ate a condicao seguinte do if ser verdade e seguir para o break
            if (mmc % v1 == 0 && mmc % v2 == 0)
            {
                nv[c] = mmc;
                break;
            }
            else
                mmc++; //adiciona um valor a mmc ate encontrar um valor que seja divisivel tanto por v1 tanto por v2
        }
        nv[c] = mmc;
    }
    for (int nc = 0; nc < 18; nc++)
    {
        printf("O minimo multiplo comum entre %d e %d vai ser %d.\n", v[a], v[a + 1], nv[nc]);
        a++;
    }
}
    /**
     * Função com o objetivo de calcular uma matriz 20x20 através do produto do vetor original com o vetor original na ordem crescente. 
     * Além disso pergunta ao utilizador se pretende ver a transposta do produto, juntando dois exercicios em um só.
     * Para isso usamos a função "ordemcrescente", para facilitar o calculo da matriz e simplificar o código.
     * Primeiro, foi necessário criar um ciclo for para duplicar o vetor orginal, sendo que o segundo foi logo de seguida colocado na ordem crescente.
     * Após isso, foi calculado o produto e pedido ser pretendia ver a transposta da matriz do produto.
     * @param m Matriz que vai armazenar a matriz transposta e permitir com que seja possivel imprimir no ecrã para o utilizador.
     * @param cres Vetor que vai servir de "clone" para ser possivel obter um vetor na ordem crescente
     * @param check Variavel para o utilizador poder confirmar se pretende ver a matriz transposta
     * 

    */

void matrizproduto(int v[N])
{
    int m[20][20];
    int cres[20];
    int check;
    for (int cond = 0; cond < 20; cond++)
    {
        cres[cond] = v[cond];
    } //cria o um novo vetor com os mesmos valores do vetor original, mais tarde vai ser usado para ficar na ordem crescente
    ordemcrescente(cres);
    printf ("\n");
    printf (" \n");
    for (int l = 0; l < 20; l++)
    {
        for (int c = 0; c < 20; c++)
        {
            m[l][c] = v[c] * cres[l];
            printf("%d ", m[l][c]);
        }
        printf("\n");
    }           

    //Verificar se quer ver a matriz transpopsta e mostrar a transposta caso ele confirme que isso                                                          
    printf("Quer ver a matriz transposta?\n 1 - Sim\n 2 - Voltar ao Menu\n");
    
    scanf("%d", &check);
    printf ("\n");
    while (check != 1 && check != 2)
    {
        printf("Opcao desconhecida, pressione 1 para ver a transposta ou 2 para voltar ao menu\n");
        scanf("%d", &check);
    }
    if (check == 1)
    {
        int nm[20][20];
        for (int l = 0; l < 20; l++)
        {
            for (int c = 0; c < 20; c++)
            {
                nm[c][l] = m[l][c]; //copia a matriz original para uma nova matriz com os valores das linhas e colunas trocadas
            }
        }
        int li, co;
        for (int li = 0; li < 20; li++)
        {
            for (int co = 0; co < 20; co++)
            {
                printf("%d ", nm[li][co]); //mostra a matriz transposta no ecra
            }
            printf("\n");
        }
    }
    else
    {
        printf("voltando ao menu");
    };
}
