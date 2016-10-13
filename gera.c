#include "gera.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char** argv)
{
    int vet[TAM], tam, flag=0;


    if(argc==3)
    {
        tam = atoi(argv[2]);

        switch(argv[1][1])
        {
            case 'a':
                aleatorio(vet, tam);
                flag=1;
                break;
            case 'c':
                crescente(vet, tam);
                flag=1;
                break;
            case 'd':
                decrescente(vet, tam);
                flag = 1;
                break;
            default:
                printf("Erro de comando!\n");
                printf("-d Descrecente\n");
                printf("-c Crescente\n");
                printf("-a Aleatorio\n");
                printf("Voce deve digitar o nome do programa seguido da opcao e do tamanho do vetor! (Ex: ./gera -c 5)\n");
        }
        if(flag)
            imprime(vet, tam);
    }
    else
    {
        printf("Erro de comando!\n");
        printf("-d Descrecente\n");
        printf("-c Crescente\n");
        printf("-a Aleatorio\n");
        printf("Voce deve digitar o nome do programa seguido da opcao e do tamanho do vetor! (Ex: ./gera -c 5)\n");
    }


    return 0;
}

void aleatorio(int vet[], int tam)
{
    int i;
    srand(time(NULL));
    for(i=0;i<tam;i++)
        vet[i] = pow(-1, rand()%2)*(rand() % MAXIMO);
}

void crescente(int vet[], int tam)
{

    int i, aleatorio;

    srand(time(NULL));
    aleatorio = rand()%MAXIMO;
    for(i=0;i<tam;i++)
    {
        vet[i] = aleatorio;
        aleatorio++;
    }
}

void decrescente(int vet[], int tam)
{
    int i, aleatorio;

    srand(time(NULL));
    aleatorio = rand()%MAXIMO;
    for(i=0;i<tam;i++)
    {
        vet[i] = aleatorio;
        aleatorio--;
    }
}

void imprime(int vet[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
        printf("%d\n", vet[i]);
}
