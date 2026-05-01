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
