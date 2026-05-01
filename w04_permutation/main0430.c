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