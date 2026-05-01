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

#if 0 // 260501 TLE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (80)

int train[200000];

void f(int a)
{
    int idx = 0;
    while (train[idx] != a)
    {
        idx++;
    }

    while (idx > 0)
    {
        train[idx] = train[idx - 1];
        idx--;
    }
    train[0] = a;
}

void b(int a, int n)
{

    int idx = 0;
    while (train[idx] != a)
    {
        idx++;
    }
    int t = train[idx];
    while (idx < n - 1)
    {
        train[idx] = train[idx + 1];
        idx++;
    }
    train[n - 1] = t;
}

void a(int x, int y)
{
    int idxx = 0;
    while (train[idxx] != x)
    {
        idxx++;
    }
    // printf("%d at %d\n", x, idxx);
    int idxy = 0;
    while (train[idxy] != y)
    {
        idxy++;
    }
    // printf("%d at %d\n", y, idxy);

    if (idxx >= idxy)
    {
        // printf("[%d] %d %d\n", __LINE__, idxy, idxx);
        int t = train[idxx];
        int idx = idxx;
        while (idx > idxy + 1)
        {
            train[idx] = train[idx - 1];
            --idx;
        }
        train[idxy + 1] = t;
    }
    else // if (idxx < idxy)
    {
        // printf("[%d] %d %d\n", __LINE__, idxx, idxy);
        int t = train[idxx];
        int idx = idxx;
        while (idx < idxy)
        {
            train[idx] = train[idx + 1];
            ++idx;
        }
        train[idxy] = t;
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

    for (int i = 0; i < n; ++i)
    {
        train[i] = i + 1;
    }

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
        }
        else if (cmd == 'B')
        {
            b(arg1, n);
        }
        else if (cmd == 'A')
        {
            a(arg1, arg2);
        }

        // for (int i = 0; i < n; ++i)
        // {
        //     printf("%d ", train[i]);
        // }
        // printf("\n");
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", train[i]);
    }
    printf("\n");
    return 0;
}

#endif