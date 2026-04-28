#include <stdio.h>

int main()
{
    int N, t, cnt2 = 0, cnt5 = 0;
    scanf("%d", &N);
    t = N;
    while (t)
    {
        t /= 2;
        cnt2 += t;
    }

    t = N;
    while (t)
    {
        t /= 5;
        cnt5 += t;
    }
    printf("%d", (cnt2 > cnt5) ? cnt5 : cnt2);
    return 0;
}