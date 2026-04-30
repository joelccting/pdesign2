/* Horowitz Program 1.9
 * To maintain lexicographical order, the prefix must always be followed by the remaining characters in sorted order.
 */

#include <stdio.h>
#include <string.h>

void shift_rite(char *s, int i, int j)
{
    int k;
    char ch = s[j];

    for (k = j; k > i; --k)
    {
        s[k] = s[k - 1];
    }
    s[i] = ch;
}

void shift_left(char *s, int i, int j)
{
    int k;
    char ch = s[i];

    for (k = i + 1; k <= j; ++k)
    {
        s[k - 1] = s[k];
    }
    s[j] = ch;
}

void perm(char *s, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; ++i)
        {
            printf("%c", s[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end; ++i)
    {
        shift_rite(s, start, i);
        perm(s, start + 1, end);
        shift_left(s, start, i);
    }
}

int main()
{
    int n;
    char s[20] = {0};
    scanf("%d%*0[^\r\n]", &n);
    while (getchar() != '\n')
        ;
    scanf("%s", s);
    s[strcspn(s, "\n")] = 0;

    // printf("%s\n", s);

    perm(s, 0, n - 1);
    return 0;
}

#if 0
#include <stdio.h>
#include <string.h>

#define SWAP(x, y, t) \
    do                \
    {                 \
        (t) = (x);    \
        (x) = (y);    \
        (y) = (t);    \
    } while (0)

void sright(char *s, int i, int j)
{
    char t = s[j];
    int n;
    for (n = j - 1; n >= i; n--)
    {
        s[n + 1] = s[n];
    }
    s[i] = t;
}

void sleft(char *s, int i, int j)
{
    char t = s[i];
    int n;
    for (n = i; n <= j - 1; n++)
    {
        s[n] = s[n + 1];
    }
    s[j] = t;
}

void perm(char *s, int i, int n)
{
    int j;
    char t;

    if (i == n)
    {
        for (i = 0; i <= n; ++i)
        {
            printf("%c ", s[i]);
        }
        printf("\n");
    }

    for (j = i; j <= n; ++j)
    {
        // printf("i=%d,j=%d\n", i, j);
        // SWAP(s[i], s[j], t);
        sright(s, i, j);
        perm(s, i + 1, n);
        // SWAP(s[i], s[j], t);
        sleft(s, i, j);
    }
}

int main()
{
    int n;
    char s[11];

    scanf("%d%*[^\n]", &n);
    while (getchar() != '\n')
        ;
    scanf("%s[^\n]", s);
    s[strcspn(s, "\n")] = 0;

    perm(s, 0, n - 1);

    return 0;
}

#endif