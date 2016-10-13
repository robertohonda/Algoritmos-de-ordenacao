#include<stdio.h>

int main()
{

    int num, prox, flag = 0, cont = 1;

    scanf("\n%d", &num);
    while(scanf("\n%d", &prox)!=EOF)
    {
        cont++;
        //printf("%d\n", prox);
        if(prox<num)
        {
            flag = 1;
            printf("Errado!! %d nao e maior que %d!\n", prox, num);
            break;
        }
        num = prox;
    }
    if(flag==0)
        printf("Correto para %d!!\n", cont);

    return 0;
}
