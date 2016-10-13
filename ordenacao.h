#define TAM 100000

#define MAXIMO 20000000

//void inicializacao(int vet[], *tam);

void troca(int *n1, int *n2);

void leitura(int vet[], int tam);

void imprime(int vet[], int tam);

void SelectionSort(int vet[],int tam);

void InsertionSort(int vet[], int tam);

void BubbleSort(int vet[],int tam);

void MergeSort(int vet[], int p, int r);

void Intercala(int vet[], int p, int q, int r);

void QuickSortFirst(int vet[], int p, int r);

int PartitionFirst(int vet[], int p, int r);

void QuickSortLast(int vet[], int p, int r);///p: posição inicial. r: ultima posição

int PartitionLast(int vet[], int p, int r);///p: posição inicial. r: ultima posição

void QuickSortMediana(int vet[], int p, int r);

int CalculaMediana(int vet[], int p, int r);

int PartitionMediana(int vet[], int p, int r);


void HeapMaxDescer(int vet[], int i, int n);

void HeapMaxConstrucao(int vet[], int n);

int HeapMaxRemocao(int vet[], int *n);

void HeapMaxImpressao(int vet[], int tam);


void HeapMinDescer(int vet[], int i, int n);

void HeapMinConstrucao(int vet[], int n);

int HeapMinRemocao(int vet[], int *n);

void HeapMinImpressao(int vet[], int tam);
