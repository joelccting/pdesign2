#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long long ULL;

int match(ULL *a, int s, int e)
{
    int r;

    if (abs(a[s] - a[e]) <= 100)
    {
        r = s;
        a[s] += a[e] + 50;
        a[e] = 0;
    }
    else
    {
        if (a[s] > a[e])
        {
            r = s;
            a[s] += a[e] / 2;
        }
        else
        {
            r = e;
            a[e] += a[s] / 2;
        }
    }

    // printf("a[%d]=%d,a[%d]=%d\n", s, a[s], e, a[e]);
    return r;
}

int go(ULL *a, int s, int e)
{
    // printf("%d,%d\n", s, e);
    if (e == s)
    {
        return e;
    }

    int m = s + (e - s) / 2;
    int le = go(a, s, m);
    int ri = go(a, m + 1, e);
    return match(a, le, ri);
}

int main()
{
    ULL N;
    scanf("%llu", &N);
    ULL *g = (ULL *)malloc(sizeof(ULL) * (N + 1));
    memset(g, 0, sizeof(ULL) * (N + 1));

    for (int i = 1; i <= N; ++i)
    {
        scanf(" %llu", g + i);
    }

    int w = go(g, 1, N);
    printf("%d", g[w]);
    free(g);
    return 0;
}