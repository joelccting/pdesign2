#include <stdio.h>

long long len[100];

int fib(int level, long long bit)
{
    if (level == 1)
        return 0;
    if (level == 2)
        return 1;

    if (bit <= len[level - 2])
        return fib(level - 2, bit);

    return fib(level - 1, bit - len[level - 2]);
}

int main()
{
    int q, k;
    long long p;

    len[1] = 1;
    len[2] = 1;
    for (int i = 3; i < 91; ++i)
        len[i] = len[i - 2] + len[i - 1];

    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%lld", &k, &p);
        printf("%d\n", fib(k, p));
    }
    return 0;
}
