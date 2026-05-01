#include <stdio.h>

typedef unsigned long long ULL;

ULL fib[91];

void initfib(ULL f[])
{
    f[1] = f[2] = 1;
    for (int i = 3; i < 91; ++i)
    {
        f[i] = f[i - 2] + f[i - 1];
    }
}

void find(ULL k, ULL p)
{
    if (k == 1)
    {
        printf("0\n");
        return;
    }
        
    if (k == 2)
    {
        printf("1\n");
        return;
    }
        

    if (p <= fib[k - 2])
    {
        find(k - 2, p);
    }
    else
    {
        find(k - 1, p - fib[k - 2]);
    }
}

int main()
{
    ULL q, k, p;

    initfib(fib);
    scanf("%llu", &q);

    for (int i = 0; i < q; ++i)
    {
        scanf("%llu %llu", &k, &p);
        find(k, p);
    }

    return 0;
}
