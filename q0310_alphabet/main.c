// Alphabet Elimination Game

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN (1010)
#define dbg(s, b...) // printf(s, ##b)

int main()
{
    char s[LEN];
    char stack[LEN] = {0};
    int top = -1;
    scanf("%s", s);
    s[strcspn(s, "\n")] = 0;

    int len = strlen(s), i = 0;
    dbg("len=%d\n", len);
    // while (s[i])
    // {
    //     dbg("%d\n", s[i++]);
    // }

    stack[0] = s[0];
    top = 0;
    for (i = 1; i < len; ++i)
    {
        if (top > -1 && tolower(s[i]) == tolower(stack[top]))
        {
            --top;
        }
        else
        {
            stack[++top] = s[i];
        }
    }
    stack[top + 1] = 0;
    printf("%s", stack);
    return 0;
}