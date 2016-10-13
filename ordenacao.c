#include "ordenacao.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>


int main(int argc, char**argv)
{
    int tam, vet[TAM], flag=0;
    float tempo = 0;
    clock_t inicio;

    if(argc==3)
    {
        tam = atoi(argv[2]);

        leitura(vet, tam);

        if(strcmp(argv[1], "-bubble")==0)
        {
            flag = 1;
            inicio = clock();
            BubbleSort(vet, tam);
            tempo = (float)clock()-(float)inicio;
            imprime(vet, tam);
        }
        else if(strcmp(argv[1], "-insertion")==0)
        {
            flag = 1;
            inicio = clock();
            InsertionSort(vet, tam);
            tempo = (float)clock()-(float)inicio;
            imprime(vet, tam);
        }
        else if(strcmp(argv[1], "-selection")==0)
        {
            flag = 1;
            inicio = clock();
            SelectionSort(vet, tam);
            tempo = (float)clock()-(float)inicio;
            imprime(vet, tam);
        }
        else if(strcmp(argv[1], "-merge")==0)
        {
            flag = 1;
            inicio = clock();
            MergeSort(vet, 0, tam-1);
            tempo = (float)clock()-(float)inicio;
            imprime(vet, tam);
        }
        else if(strcmp(argv[1], "-quickp")==0)
        {
            flag = 1;
            inicio = clock();
            QuickSortFirst(vet, 0, tam-1);
            tempo = (float)clock()-(float)inicio;
            imprime(vet, tam);
        }
        else if(strcmp(argv[1], "-quicku")==0)
        {
            flag = 1;
            inicio = clock();
            QuickSortLast(vet, 0, tam-1);
            tempo = (float)clock()-(float)inicio;
            imprime(vet, tam);
        }
        else if(strcmp(argv[1], "-quickmediana")==0)
        {
            flag = 1;
            inicio = clock();
            QuickSortMediana(vet, 0, tam-1);
            tempo = (float)clock()-(float)inicio;
            imprime(vet, tam);
        }
        else if(strcmp(argv[1], "-heapmin")==0)
        {
            flag = 1;
            inicio = clock();
            HeapMinConstrucao(vet, tam-1);
            tempo = (float)clock()-(float)inicio;
            HeapMinImpressao(vet, tam);
        }
        else if(strcmp(argv[1], "-heapmax")==0)
        {
            flag = 1;
            inicio = clock();
            HeapMaxConstrucao(vet, tam-1);
            tempo = (float)clock()-(float)inicio;
            HeapMaxImpressao(vet, tam);
        }
        else
        {
            printf("Comando incorreto!\n");
            printf("Voce deve digitar o nome do programa, o algoritmo, o numero de elemento do vetor e o arquivo do vetor!\n");
            printf("ex: ./ordenacao -bubble 20 < vetor.txt\n");
        }
        if(flag)
            printf("\nTempo: %f milissegundos\n", tempo);
    }
    else
    {
        printf("Comando incorreto!\n");
        printf("Voce deve digitar o nome do programa, o algoritmo, o numero de elemento do vetor e o arquivo do vetor!\n");
        printf("ex: ./ordenacao -bubble 20 < vetor.txt\n");
    }
    return 0;
}

void troca(int *n1, int *n2)
{
    int aux;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void leitura(int vet[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
        scanf("\n%d", &vet[i]);
}
void imprime(int vet[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
        printf("%d\n", vet[i]);
}

void SelectionSort(int vet[],int tam)
{
    int i, j, menor;
    for(i=0;i<tam-1;i++)
    {
        menor = i;
        for(j=i+1;j<tam;j++)
        {
            if(vet[j]<vet[menor])
                menor = j;
        }
        if(menor!=i)
            troca(&vet[i], &vet[menor]);
    }
}
void InsertionSort(int vet[], int tam)
{
    int i, j, chave;

    for(i=1;i<tam;i++)
    {
        chave = vet[i];
        j = i-1;
        while(j>=0&&vet[j]>chave)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = chave;
    }

}

void BubbleSort(int vet[],int tam)
{
    int i, j;

    for(i=0;i<tam-1;i++)
    {
        for(j=0;j<tam-1-i;j++)
            if(vet[j]>vet[j+1])
                troca(&vet[j], &vet[j+1]);
    }
}
void MergeSort(int vet[], int p, int r)
{
    int q;

    if(p<r)
    {
        q = (p+r) / 2;
        MergeSort(vet, p, q);
        MergeSort(vet, q+1, r);
        Intercala(vet, p, q, r);
        //system("pause");
    }
}

void Intercala(int vet[], int p, int q, int r)
{
    int n1, n2, i, j, k;
    int L[TAM], R[TAM];

    n1 = q-p+1;
    n2 = r-q;
    for(i=0;i<n1;i++)
        L[i] = vet[p+i];

    for(j=0;j<n2;j++)
        R[j] = vet[q+j+1];

    L[i] = R[j] = MAXIMO;
    i = j = 0;

    for(k=p;k<=r;k++)
    {
        if(L[i] <= R[j])
        {
            vet[k] = L[i];
            i++;
        }
        else
        {
            vet[k] = R[j];
            j++;
        }
    }
}

void QuickSortFirst(int vet[], int p, int r)
{
    int q;

    if(p<r)
    {
        q = PartitionFirst(vet, p, r);
        QuickSortFirst(vet, p, q-1);///ordenar a parta de baixo
        QuickSortFirst(vet, q+1, r);///ordenar a parte de cima
    }
}

int PartitionFirst(int vet[], int p, int r)
{
    int x, i, j;

    x = vet[p];
    i = p;

    for(j=p+1;j<=r;j++)
    {
        if(vet[j] <= x)
        {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }
    troca(&vet[i], &vet[p]);
    return i;
}
void QuickSortLast(int vet[], int p, int r)
{
    int q;

    if(p<r)
    {
        q = PartitionLast(vet, p, r);
        QuickSortLast(vet, p, q-1);///ordenar a parta de baixo
        QuickSortLast(vet, q+1, r);///ordenar a parte de cima
    }
}

int PartitionLast(int vet[], int p, int r)
{
    int x, i, j;

    x = vet[r];
    i = p-1;
    for(j=p;j<r;j++)
    {
        if(vet[j] <= x)
        {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }
    troca(&vet[i+1], &vet[r]);
    return i+1;
}

void QuickSortMediana(int vet[], int p, int r)
{
    int q;

    if(p<r)
    {
        q = PartitionMediana(vet, p, r);
        QuickSortMediana(vet, p, q-1);///ordenar a parta de baixo
        QuickSortMediana(vet, q+1, r);///ordenar a parte de cima
    }
}

int CalculaMediana(int vet[], int p, int r)
{
    int a, b, c, tam = r-p, mediana;

    srand(time(NULL));
    a = rand()%tam;
    b = rand()%tam;
    c = rand()%tam;
    if(vet[a]>=vet[b]&&vet[a]<=vet[c]||vet[a]<=vet[b]&&vet[a]>=vet[c])
        mediana = a;
    else if(vet[b]>=vet[a]&&vet[b]<=vet[c]||vet[b]<=vet[a]&&vet[b]>=vet[c])
        mediana = b;
    else
        mediana = c;

    return p+mediana;
}

int PartitionMediana(int vet[], int p, int r)
{
    int x, i, j, pivo;

    pivo = CalculaMediana(vet, p, r);
    x = vet[pivo];
    i = p;
    troca(&vet[p], &vet[pivo]);
    for(j=p+1;j<=r;j++)
    {
        if(vet[j] <= x)
        {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }
    troca(&vet[i], &vet[p]);

    return i;
}

void HeapMaxDescer(int vet[], int i, int n)
{
    int j;

    j = 2*i;
    if(j<=n)
    {
        if(j<n)
            if(vet[j+1]>vet[j])
                j++;
        if(vet[i]<vet[j])
        {
            troca(&vet[i], &vet[j]);
            HeapMaxDescer(vet, j, n);
        }
    }
}

int HeapMaxRemocao(int vet[], int *n)
{
    int aux;

    if((*n)!=-1)
    {
        aux = vet[0];
        vet[0] = vet[*n];
        (*n)--;
        HeapMaxDescer(vet, 0, *n);
    }
    return aux;
}

void HeapMaxConstrucao(int vet[], int n)
{
    int i;

    for(i=n/2;i>=0;i--)
        HeapMaxDescer(vet, i, n);
}

void HeapMaxImpressao(int vet[], int tam)
{
    int i, n=tam-1;

    for(i=0;i<tam;i++)
        printf("%d\n", HeapMaxRemocao(vet, &n));


}

void HeapMinDescer(int vet[], int i, int n)
{
    int j;

    j = 2*i;
    if(j<=n)
    {
        if(j<n)
            if(vet[j]>vet[j+1])
                j++;
        if(vet[i]>vet[j])
        {
            troca(&vet[i], &vet[j]);
            HeapMinDescer(vet, j, n);
        }
    }
}

int HeapMinRemocao(int vet[], int *n)
{
    int aux;

    if((*n)!=-1)
    {
        aux = vet[0];
        vet[0] = vet[*n];
        (*n)--;
        HeapMinDescer(vet, 0, *n);
    }
    return aux;
}

void HeapMinConstrucao(int vet[], int n)
{
    int i;

    for(i=n/2;i>=0;i--)
        HeapMinDescer(vet, i, n);
}

void HeapMinImpressao(int vet[], int tam)
{
    int i, n=tam-1;

    for(i=0;i<tam;i++)
        printf("%d\n", HeapMinRemocao(vet, &n));
}



