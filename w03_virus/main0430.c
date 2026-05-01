#include <stdio.h>

typedef long long LL;

int main()
{
    int a, b, N;
    LL newborn[30], active[30] = {0};
    scanf("%d%d%d", &a, &b, &N);

    newborn[1] = newborn[2] = 0;
    newborn[3] = 0;
    active[1] = active[2] = 0;
    active[3] = a;
    for (int i = 4; i <= N; ++i)
    {
        newborn[i] = active[i - 1] * b;
        active[i] = active[i - 1] + newborn[i - 2];
    }

    // for (int i = 1; i <= N; ++i)
    //     printf("%d: n:%d a:%d\n", i, newborn[i], active[i]);

    printf("%d", active[N]);

    return 0;
}
