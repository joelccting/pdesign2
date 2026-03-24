// Alphabet Elimination Game

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN (1010)
#define dbg(s, b...) //printf(s, ##b)

int main()
{
    char s[LEN];
    char stack[LEN] = {0};
    int top = 0;
    scanf("%s", s);

    int len = strlen(s), i = 0;
    dbg("len=%d\n", len);
    // while (s[i])
    // {
    //     dbg("%d\n", s[i++]);
    // }

    for (i = 0; i < len; ++i)
    {
        if (top == 0)
        {
            stack[top++] = s[i];
            stack[top] = 0;
            continue;
        }

        if (tolower(s[i]) != tolower(stack[top - 1]))
        {
            dbg("push %c\n", s[i]);
            stack[top++] = s[i];
            stack[top] = 0;
        }
        else
        {
            dbg("pop %c\n", stack[top - 1]);
            stack[--top] = 0;
        }
    }

    printf("%s", stack);
    return 0;
}