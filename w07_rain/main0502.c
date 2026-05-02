/* Prefix sum
 */

#include <stdio.h>

#define SZ (100005)
int acc[SZ];

int main()
{
    int N, Q, a, m, n;

    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &a);
        acc[i] = acc[i - 1] + a;
    }
    while (Q--)
    {

        scanf("%d%d", &m, &n);
        printf("%d\n", acc[n] - acc[m - 1]);
    }
    return 0;
}