#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (80)
#define SZ (200005)
typedef struct node
{
    int val;
    int prev;
    int next;
} Node;

Node train[SZ];
int head, tail;
void print(int n);
void f(int x)
{
    int prev = train[x].prev;
    int next = train[x].next;
    train[prev].next = next;
    train[next].prev = prev;

    next = train[0].next;
    train[x].prev = 0;
    train[x].next = train[0].next;
    train[0].next = x;
    train[next].prev = x;
}

void b(int x)
{
    int prev = train[x].prev;
    int next = train[x].next;
    train[prev].next = next;
    train[next].prev = prev;

    prev = train[tail].prev;
    next = tail;
    train[prev].next = x;
    train[x].prev = prev;
    train[x].next = next;
    train[tail].prev = x;
}

void a(int x, int y)
{
    int prev = train[x].prev;
    int next = train[x].next;
    train[prev].next = next;
    train[next].prev = prev;

    next = train[y].next;
    train[x].prev = y;
    train[x].next = next;
    train[y].next = x;
    train[next].prev = x;
}


void print(int n)
{
    for (int i = head; i <= tail; ++i)
    {
        printf("%d: %d %d %d\n", i, train[i].val, train[i].prev, train[i].next);
    }
}

int main()
{
    int n, q, arg1, arg2;
    char str[LEN + 5];
    char cmd;

    scanf("%d%d%*[^\r\n]", &n, &q);
    while (getchar() != '\n')
        ;

    /*init*/
    train[0].next = 1;
    train[n + 1].prev = n;
    train[0].prev = train[n + 1].next = -1;
    for (int i = 1; i <= n; ++i)
    {
        train[i].prev = i - 1;
        train[i].val = i;
        train[i].next = i + 1;
    }
    tail = n + 1;
    head = 0;
    // print(n);

    while (q--)
    {
        fgets(str, LEN, stdin);
        str[strcspn(str, "\n")] = 0;
        char *pch = strtok(str, " ");
        cmd = pch[0];
        pch = strtok(NULL, " ");
        arg1 = atoi(pch);

        if (cmd == 'A')
        {
            pch = strtok(NULL, " ");
            arg2 = atoi(pch);
        }

        // printf("%c %d %d\n", cmd, arg1, arg2);

        if (cmd == 'F')
        {
            f(arg1);
            // print(n);
        }
        else if (cmd == 'B')
        {
            b(arg1);
            // print(n);
        }
        else if (cmd == 'A')
        {
            a(arg1, arg2);
            // print(n);
        }

        // int curr = train[0].next;
        // for (int i = 0; i < n; ++i)
        // {
        //     printf("%d ", train[curr].val);
        //     curr = train[curr].next;
        // }
        // printf("\n");
        // print(n);
    }

    int curr = train[0].next;
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", train[curr].val);
        curr = train[curr].next;
    }
    printf("\n");
    return 0;
}
