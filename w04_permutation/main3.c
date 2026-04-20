//#define MY_PRACTICE_0321

#ifdef MY_PRACTICE_0321

#include <stdio.h>
#include <string.h>

void sright(char *s, int start, int idx)
{
    char t = s[idx];
    for (int i = idx; i > start; --i)
    {
        s[i] = s[i - 1];
    }

    s[start] = t;
}

void sleft(char *s, int start, int idx)
{
    char t = s[start];
    for (int i = start; i < idx; ++i)
    {
        s[i] = s[i + 1];
    }
    s[idx] = t;
}

void lexperm(char *s, int start, int end)
{
    if (start == end)
    {
        printf("%s\n", s);
    }

    for (int i = start; i < end; ++i)
    {
        sright(s, start, i);
        lexperm(s, start + 1, end);
        sleft(s, start, i);
    }
}

int main()
{
    int n;
    char s[10] = {0};
    scanf("%d", &n);
    scanf("%s", s);

    lexperm(s, 0, n);
    return 0;
}

#endif