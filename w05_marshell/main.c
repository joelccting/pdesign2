#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (80)
#define dbg(fmt, ...) printf("[%s:%d] " fmt, __func__, __LINE__, __VA_ARGS__)

typedef struct node
{
    int sn;
    struct node *prev;
    struct node *next;
} Node;

Node *find(Node *h, int val)
{
    Node *p = h->next;
    while (p)
    {
        if (p->sn == val) break;
        p = p->next;
    }

    return p;
}

void m2head(Node *h, int val)
{
    Node *p = find(h, val);
    
}

int main()
{
    int n, // the number of carriages
        q; // the number of operations

    int op[3];

    scanf("%d %d ", &n, &q);

    Node *head = (Node *)calloc(1, sizeof(Node)),
         *tail = (Node *)calloc(1, sizeof(Node));

    head->next = (Node *)calloc(n, sizeof(Node));
    tail->next = head->next + n - 1;
    Node *p = head->next;
    for (int i = 1; i <= n; ++i)
    {
        p->sn = i;
        if (i < n)
        {
            p->next = head->next + i;
            p = p->next;
        }
        else
        {
            p->next = NULL;
        }
    }

    // p = head->next;
    // while (p)
    // {
    //     dbg("%d,", p->sn);
    //     p = p->next;
    // }
    dbg("%d\n", tail->next->sn);

    for (int i = 0; i < q; ++i)
    {
        char buf[LEN] = "TEST";
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
    }

    switch (op[0])
    {
    case 'A':
        break;
    case 'B':
        break;
    case 'F':
    default:
        break;
    }

    free(head->next);
    free(head);
    free(tail);

    return 0;
}

#endif