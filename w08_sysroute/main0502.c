/* System Route
 * stack
 */

#include <stdio.h>
#include <string.h>

#define SZ (105)
char stack[SZ][SZ];
int top = -1;

int main()
{
    int n;
    char b[SZ];
    scanf("%d", &n);
    strcpy(stack[0], "~");
    top = 0;
    while (n--)
    {
        scanf("%s%*[^\r\n]", b);
        b[strcspn(b, "\n")] = 0;
        if (!strcmp(b, ".."))
        {
            if (top > 0)
                top--;
        }
        else
        {
            strcpy(stack[++top], b);
        }
    }

    for (int i = 0; i <= top; ++i)
    {
        printf("%s%s", stack[i], (i != top) ? "/" : "");
    }
    return 0;
}