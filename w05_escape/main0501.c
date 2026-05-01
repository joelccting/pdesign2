#include <stdio.h>
#include <string.h>

#define SZ (105)

char c[SZ][SZ];
typedef struct point
{
    int x;
    int y;
} Point;

int m, n;

int ispath(int x, int y)
{
    // printf("%d,%d\n", p.x, p.y);
    if ((-1 < x && x < m) && (-1 < y && y < n) && c[x][y] == '.')
        return 1;
    return 0;
}

int btrace(Point s, Point e)
{
    Point nxt;

    if (s.x == e.x && s.y == e.y)
    {
        return 1;
    }

    c[s.x][s.y] = 'w';

    if (ispath(s.x + 1, s.y))
    {
        nxt.x = s.x + 1;
        nxt.y = s.y;
        if (btrace(nxt, e))
            return 1;
    }

    if (ispath(s.x - 1, s.y))
    {
        nxt.x = s.x - 1;
        nxt.y = s.y;
        if (btrace(nxt, e))
            return 1;
    }

    if (ispath(s.x, s.y + 1))
    {
        nxt.x = s.x;
        nxt.y = s.y + 1;
        if (btrace(nxt, e))
            return 1;
    }

    if (ispath(s.x, s.y - 1))
    {
        nxt.x = s.x;
        nxt.y = s.y - 1;
        if (btrace(nxt, e))
            return 1;
    }

    // c[s.x][s.y] = '.';

    return 0;
}

int main()
{

    Point start, end;

    scanf("%d%d", &m, &n);
    scanf("%d%d%d%d", &(start.x), &(start.y), &(end.x), &(end.y));

    for (int i = 0; i < m; ++i)
    {
        scanf("%s", c[i]);
        c[i][strcspn(c[i], "\n")] = 0;
    }

#if 0
    for (int i = 0; i < m; ++i)
    {
        printf("%s\n", c[i]);
    }
#endif

    if (start.x == end.x && start.y == end.y)
    {
        printf("YES");
        return 0;
    }

    if (btrace(start, end))
        printf("YES");
    else
        printf("NO");

    return 0;
}
