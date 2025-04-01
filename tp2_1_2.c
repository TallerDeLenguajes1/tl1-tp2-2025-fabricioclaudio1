#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{

    // codigo a completar

    int i;
    double vt[N];
    double *pVt = vt;

    for (i = 0; i < N; i++)
    {
        *vt = 1 + rand() % 100;
        printf("%f", *vt);
        pVt++;
    }

    return 0;
}
