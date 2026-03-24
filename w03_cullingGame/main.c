#include <stdio.h>

void generate(int n, int k, int start, int depth, int c[])
{
    if (depth == k)
    {
        for (int i = 0; i < k; i++)
        {
            printf("%d ", c[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= n; i++)
    {
        c[depth] = i;
        generate(n, k, i + 1, depth + 1, c);
    }
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int c[k];
    generate(n, k, 1, 0, c);

    return 0;
}