#include <stdio.h>
#include <string.h>

#define LEN (100000)

int top = -1;
char stack[LEN];

void push(char c)
{
    if (top < LEN - 1)
    {
        stack[top++] = c;
    }
}

char pop(void)
{
    char r = -1;

    if (top > -1)
    {
        r = stack[top--];
    }

    return r;
}

int main()
{
    char buf[LEN], out[LEN] = {0};
    int left = 0, right = 0, len, i, idx = 0;

    scanf("%s", buf);
    buf[strcspn(buf, "\n")] = 0;
    printf("%s\n", buf);
    len = strlen(buf);
    for (i = 0; i < len; ++i)
    {
        if (buf[i] == '(')
        {
            push(buf[i]);

            if (top > 0)
            {
                out[idx] = buf[i];
                // printf("(%d: %c\n", idx, out[idx]);
                ++idx;
            }
        }
        else if (buf[i] == ')')
        {
            if (top > 0)
            {
                out[idx] = buf[i];
                // printf(")%d: %c\n", idx, out[idx]);
                ++idx;
            }

            pop();
        }
    }

    printf("%s", out);

    return 0;
}