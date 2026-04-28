/* coloring: greedy
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[50];

int cmp(const void *a, const void *b)
{
    int *aa = (int *)a;
    int *bb = (int *)b;
    return (*aa > *bb);
}

int main()
{
    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i)
    {
        scanf("%d", &n);

        memset(a, 0, sizeof(int) * n);

        for (int j = 0; j < n; ++j)
            scanf("%d", a + j);

        qsort(a, n, sizeof(int), cmp);
#if 0
        for (int j = 0; j < n; ++j)
            printf("%d ", a[j]);
        printf("\n");
#endif
        int sum = 0, left = 0, right = n - 1;
        while (right > left)
        {
            sum += (a[right--] - a[left++]);
        }
        printf("%d\n", sum);
    }
    return 0;
}