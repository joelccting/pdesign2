#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dbg(fmt, ...) //printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)

typedef struct st
{
    int id;
    int ch;
    int en;
    int ma;
    int tot;
} St;

int cmp(const void *a, const void *b)
{
    St *sa = (St *)a,
       *sb = (St *)b;

    if (sa->tot != sb->tot)
    {
        return (sa->tot < sb->tot);
    }
    else
    {
        if (sa->ch != sb->ch)
        {
            return (sa->ch < sb->ch);
        }
        else
        {
            if (sa->en != sb->en)
            {
                return (sa->en < sb->en);
            }
            else
            {
                if (sa->ma != sb->ma)
                {
                    return (sa->ma < sb->ma);
                }

            }
        }
    }

    return (sa->id > sb->id);
}

int main()
{
    int N;

    scanf("%d", &N);

    St *s = (St *)malloc(sizeof(St) * N);
    memset(s, 0, sizeof(St) * N);
    for (int i = 0; i < N; ++i)
    {
        // scanf("%*[\r\n]");
        scanf(" %d %d %d %d", &s[i].id, &s[i].ch, &s[i].en, &s[i].ma);
        s[i].tot = s[i].ch + s[i].en + s[i].ma;
        dbg("%d, %d, %d, %d\n", s[i].id, s[i].ch, s[i].en, s[i].ma);
    }

    qsort(s, N, sizeof(St), cmp);
    for (int i = 0; i < N; ++i)
    {
        //printf("%d, %d, %d, %d\n", s[i].id, s[i].ch, s[i].en, s[i].ma);
        printf("%d\n", s[i].id);
    }
    free(s);
    return 0;
}