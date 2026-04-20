#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    int prev, curr;

    printf("%c", s[0]);
    prev = 0;
    for (curr = 1; curr < n; ++curr)
    {
        if (s[prev] == s[curr])
        {
            // prev = curr;
            continue;
        }

        printf("%c", s[curr]);
        prev = curr;
    }

    return 0;
}