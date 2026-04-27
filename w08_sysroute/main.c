#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (105)

int top = -1;
char stack[LEN][LEN];

void prt(void)
{
    for (int i = 0; i <= top; ++i)
    {
        printf("%s", stack[i]);
        if (i < top)
        {
            printf("/");
        }
    }
    printf("\n");
}

int main()
{
    int n;
    char buf[LEN];

    scanf("%d", &n);
    top = 0;
    strcpy(stack[top], "~");
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", buf);
        buf[strcspn(buf, "\n")] = 0;

        if (!strcmp(buf, ".."))
        {
            // printf("--debug--\n");
            if (top > 0)
            {
                top--;
            }
        }
        else
        {
            strcpy(stack[++top], buf);
        }
    }
    prt();
    return 0;
}