#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (80)
#define dbg(fmt, ...) //printf("[%s:%d] " fmt, __func__, __LINE__, __VA_ARGS__)

typedef struct node
{
    int val;
    int prev;
    int next;
} Node;

void print(Node *h, int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        dbg("%d: %d,%d\n", i, h[i].prev, h[i].next);
    }
}

void init(Node *h, int sz)
{
    int i;
    for (i = 0; i < sz - 1; ++i)
    {
        h[i].val = i;
        h[i].prev = i - 1;
        h[i].next = i + 1;
    }

    h[i].prev = i - 1;
    h[i].next = -1;

    // print(h, sz);
}

void front(Node *h, int n)
{
    int prev = h[n].prev;
    int next = h[n].next;
    h[prev].next = next;
    h[next].prev = prev;

    h[n].prev = 0;
    h[n].next = h[0].next;
    h[h[0].next].prev = n;
    h[0].next = n;
}

void tail(Node *h, int t, int n)
{
    int prev = h[n].prev;
    int next = h[n].next;
    h[prev].next = next;
    h[next].prev = prev;

    h[n].next = t;
    h[n].prev = h[t].prev;
    h[h[t].prev].next = n;
    h[t].prev = n;
}

void move(Node *h, int n, int at)
{
    int prev = h[n].prev;
    int next = h[n].next;
    h[prev].next = next;
    h[next].prev = prev;

    next = h[at].next;
    h[next].prev = n;
    h[at].next = n;
    h[n].prev = at;
    h[n].next = next;
    
}

void print2(Node *h, int sz)
{
    int p = h[0].next;

    // while (p != -1)
    while (p != sz)
    {
        printf("%d ", p, h[p].val);
        p = h[p].next;
    }
}

int main()
{
    int n, // the number of carriages
        q; // the number of operations

    int op[3];

    scanf("%d %d ", &n, &q);

    Node *table = (Node *)calloc(n + 2, sizeof(Node));
    init(table, n + 2);

    for (int i = 0; i < q; ++i)
    {
        char buf[LEN] = {0};
        fgets(buf, LEN - 1, stdin);
        buf[strcspn(buf, "\n")] = 0;
        // dbg("%s\n", buf);

        char *p = strtok(buf, " ");
        int pos = 0;
        while (p)
        {
            switch (pos)
            {
            case 0:
                op[pos] = *p;
                ++pos;
                break;
            case 1:
                op[pos] = atoi(p);
                ++pos;
                break;
            case 2:
            default:
                op[pos] = atoi(p);
                break;
            }
            p = strtok(NULL, " ");
        }
        dbg("%c %d %d\n", op[0], op[1], op[2]);

        switch (op[0])
        {
        case 'A':
            move(table, op[1], op[2]);
            break;
        case 'B':
            tail(table, n + 1, op[1]);
            break;
        case 'F':
        default:
            front(table, op[1]);
            break;
        }

        // print(table, n + 2);
    }

    print2(table, n + 1);

    free(table);

    return 0;
}