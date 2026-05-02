/* Tako Factory
 * queue
 */

#include <stdio.h>
#define SZ (105)
// int a[SZ];   // products
int b[SZ];   // toppings
int que[SZ]; // products
int rear;

void enque(int n)
{
    if (rear < SZ - 1)
        que[++rear] = n;

    // printf("que: ");
    // for (int i = 0; i <= rear; ++i)
    //     printf("%d ", que[i]);
    // printf("\n");
}

int deque()
{
    int r;
    if (rear > -1)
    {
        r = que[0];
    }

    for (int i = 1; i <= rear; ++i)
        que[i - 1] = que[i];

    --rear;
    return r;
}

int peak()
{
    return que[0];
}

int tako(int n)
{
    int idx = 0;
    int cnt = 0;
    while (rear > -1)
    {
        int val = deque();
        ;
        if (b[idx] == val)
        {
            ++idx;
            cnt = 0;
        }
        else
        {
            enque(val);
            cnt++;
        }

        if (cnt > rear)
            break;
    }

    return cnt;
}

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", que + i);
    rear = n - 1;
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
    printf("%d", tako(n));
    return 0;
}