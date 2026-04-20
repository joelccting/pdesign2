#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i)
    {
        scanf(" %d", &n);
        int *a = (int *)malloc(sizeof(int) * n);
        memset(a, 0, sizeof(int) * n);

        for (int j = 0; j < n; ++j)
            scanf(" %d", a + j);


        free(a);
    }
    return 0;
}