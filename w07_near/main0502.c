/* Find the position of the nearest smaller value
 * by Monotonic Stack
 */
#include <stdio.h>
#include <string.h>

#define SZ (200005)

int a[SZ];
int stack[SZ];
int top = -1;
int ans[SZ];

void push(int v)
{
    // printf("push %d\n", a[v]);
    if (top > SZ - 1)
        return;
    stack[++top] = v;
}

int pop(int *r)
{
    if (top < 0)
        return -1;

    // printf("pop %d\n", a[stack[top]]);

    if (r)
        *r = stack[top--];
    else
        top--;

    return 0;
}

int peak()
{
    return stack[top];
}

void find(int n)
{
    push(1);
    ans[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        while (top > -1 && a[peak()] >= a[i])
            pop(NULL);

        if (top > -1)
            ans[i] = peak();
        else
            ans[i] = 0;
        push(i);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
    }

    find(n);

    for (int i = 1; i <= n; ++i)
    {
        printf("%d%s", ans[i], (i == n) ? "" : " ");
    }

    return 0;
}