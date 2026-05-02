/* Tako Factory
 * circular queue
 */

#include <stdio.h>

#define SZ (105)
// int a[SZ];   // products
int b[SZ];   // toppings
int que[SZ]; // products
int rear, front;
int len;

void print(char *s)
{
    printf("%s:", s);

    for (int i = 0; i < len; ++i)
        printf("%d%s%s ", que[i], (i == front) ? "F" : "", (i == rear) ? "R" : "");

    printf("\n");
}

int isempty()
{
    return front == rear;
}

int isfull()
{
    return (rear + 1) % len == front;
}

int enque(int n)
{
    if (isfull()) /*full*/
    {
        return -1;
    }

    rear = (rear + 1) % len;
    que[rear] = n;

    // printf("enque at %d: %d\n", rear, n);
    // print("enque");
    return 0;
}

int deque(int *r)
{
    if (isempty()) /*empty*/
        return -1;

    front = (front + 1) % len;
    // printf("deque at %d\n", f);
    if (r)
        *r = que[front];
    // print("deque");
    return 0;
}

int getcnt()
{
    return (rear + len - front) % len;
}

int tako(int n)
{
    int idx = 0;
    int cnt = 0;
    while (1)
    {
        int val = 0;
        deque(&val);

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

        if (cnt >= getcnt())
            break;

        if (isempty())
        {
            cnt = 0;
            break;
        }
    }

    return cnt;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    len = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &m);
        enque(m);
    }
    // front = 0;
    // rear = n;
    // len = n + 1;

    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
    printf("%d", tako(n));

    // int new;
    // if (!deque(&new))
    //     enque(new);
    // deque(&new);
    // deque(&new);
    // if (!deque(&new))
    //     enque(new);
    return 0;
}