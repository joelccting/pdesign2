#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define msg(fmt, ...) printf("" fmt, ##__VA_ARGS__)

int main()
{
    int N, Q, *a, i, len, num, L, R;

    scanf("%d %d", &N, &Q);

    a = (int *)malloc(sizeof(int) * (N + 1));
    memset(a, 0, sizeof(int) * (N + 1));

    a[0] = 0;
    i = 1;
    while (N--)
    {
        scanf("%d", &num);
        if (1 == i)
            a[i] = num;
        else
            a[i] = num + a[i - 1];
        i++;
    }

    // len = i;
    // for (i = 1; i < len; ++i)
    //     msg("%d ", a[i]);

    while (Q--)
    {
        scanf("%d %d", &L, &R);
        msg("%d\n", a[R] - a[L-1]);
    }

    free(a);
    return 0;
}