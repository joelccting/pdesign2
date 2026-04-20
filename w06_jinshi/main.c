#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 5#define DEBUG

#ifdef DEBUG
#define msg(fmt, ...) printf("L%03d " fmt, __LINE__, ##__VA_ARGS__)
#else
#define msg(fmt, ...)
#endif

int left(int *a, int *b, int s, int p)
{
    if (s >= p)
        return 0;

    int ret = 0;
    for (int i = p - 1; i > -1; i--)
    {
        b[i] = (b[i + 1] > a[i]) ? a[i] : b[i + 1];
        ret += b[i];
    }

    return ret;
}

int right(int *a, int *b, int p, int e)
{
    msg("p=%d,e=%d\n", p, e);
    if (e <= p)
        return 0;

    int ret = 0;
    for (int i = p + 1; i <= e; i++)
    {
        b[i] = (b[i - 1] >= a[i]) ? a[i] : b[i - 1];
        ret += b[i];
        msg("b[%d]=%d, ret=%d\n", i, b[i], ret);
    }

    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    memset(a, 0, sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);
    memset(b, 0, sizeof(int) * n);
    int max = 0, imax;
    for (int i = 0; i < n; ++i)
    {
        scanf(" %d", a + i);
    }

#ifdef DEBUG
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\npeak:%d\n", ipeak);
#endif

    for (int i = 0; i < n; ++i)
    {
        b[i] = a[i];
        int L = left(a, b, 0, i);
        int R = right(a, b, i, n - 1);
        int sum = L + R + b[i];
        if (sum > max)
        {
            max = sum;
            imax = i;
        }
    }

    printf("%d\n", max);
    b[imax] = a[imax];
    int L = left(a, b, 0, imax);
    int R = right(a, b, imax, n - 1);
    for (int i = 0; i < n; ++i)
    {
        if (i != n - 1)
            printf("%d ", b[i]);
        else
            printf("%d", b[i]);
    }

    return 0;
}