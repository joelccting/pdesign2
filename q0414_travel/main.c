#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
    char name[105];
    int price;
} Record;

Record r[100];

int cmp(const void *a, const void *b)
{
    Record *aa = (Record *)a,
           *bb = (Record *)b;
    return (aa->price < bb->price);
}

int main()
{
    int N, price;
    char buf[105], *pch;

    scanf("%d%*[^\r\n]", &N);
    getchar();

    for (int i = 0; i < N; ++i)
    {
        fgets(buf, 104, stdin);
        buf[strcspn(buf, "\n")] = 0;

        pch = strtok(buf, " ");
        strncpy(r[i].name, pch, 104);
        pch = strtok(NULL, " ");
        price = atoi(pch);
        if (5000 <= price && price < 10000)
        {
            price = price * 9 / 10;
        }
        else if (10000 <= price)
        {
            price = price * 83 / 100;
        }
        r[i].price = price;
    }

#if 0
    for (int i = 0; i < N; ++i)
    {
        printf("%s %d\n", r[i].name, r[i].price);
    }
#endif

    qsort(r, N, sizeof(Record), cmp);

    for (int i = 0; i < N; ++i)
    {
        printf("%s %d\n", r[i].name, r[i].price);
    }

    return 0;
}