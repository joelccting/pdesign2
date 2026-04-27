#include <stdio.h>
#include <stdlib.h>

void shift(int *a, int n)
{
    // printf("shift\n");
    int t = a[0];

    for (int i = 1; i <= n - 1; ++i)
    {
        a[i - 1] = a[i];
    }

    a[n - 1] = t;
    // for (int i = 0; i < n; ++i)
    //     printf("%d ", a[i]);
    // printf("\n");
}

void deque(int *a, int *len)
{
    // printf("deque\n");
    for (int i = 1; i <= *len - 1; ++i)
    {
        a[i - 1] = a[i];
    }

    *len -= 1;
}

int main()
{
    int n;
    int *a, *b;
    int top = 0, head = 0, qlen;

    scanf("%d", &n);
    qlen = n;

    a = (int *)calloc(n, sizeof(int)); // products,queue
    b = (int *)calloc(n, sizeof(int)); // toppings,stack

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", b + i);
    }

    int cnt = 0;
    while (qlen)
    {
        if (a[head] == b[top])
        {
            top++;
            deque(a, &qlen);
            cnt = 0;
        }
        else
        {
            shift(a, qlen);
            cnt++;
        }

        if (cnt > qlen) break;
    }

    printf("%d", qlen);

    return 0;
}