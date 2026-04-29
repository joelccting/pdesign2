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

#if 0
int main()
{
    int a, b, N, i;
    scanf("%d %d %d", &a, &b, &N);
    int ac[N + 1], uac[N + 1];

    for (i = 1; i <= N + 1; ++i)
    {
        ac[i] = uac[i] = 0;
    }

    ac[1] = ac[2] = 0;
    uac[1] = a;
    uac[2] = 0;
    ac[3] = uac[1];
    for (i = 4; i <= N; ++i)
    {
        uac[i] = ac[i - 1] * b;
        ac[i] = uac[i - 2] + ac[i - 1];
    }

 /*    int sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        sum += ac[i];
    } */
/*     for (i = 1; i <= N; ++i)
    {
        printf("%d: %d %d\n", i, uac[i], ac[i]);
    } */
    
    printf("%d", ac[N]);

    return 0;
}
#endif