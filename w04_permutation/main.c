//#define USE_RECURSION
#ifdef USE_RECURSION

#define dbg(s, b...) printf("[%s] " s, __func__, ##b)

#include <stdio.h>

int n;

void swap(char *a, char *b)
{
    dbg("%c and %c\n", *a, *b);
    char t = *a;
    *a = *b;
    *b = t;
}

// Moves the character at 'target' to 'start' and shifts
// everything in between to maintain sorted order.
void shiftRight(char *str, int start, int target)
{
    char temp = str[target];
    dbg("Move %d to %d\n", start, target);
    for (int i = target; i > start; i--)
    {
        str[i] = str[i - 1];
    }
    str[start] = temp;
}

// Reverses the shift to restore the original order for the next loop
void shiftLeft(char *str, int start, int target)
{
    char temp = str[start];
    dbg("Move %d to %d\n", start, target);
    for (int i = start; i < target; i++)
    {
        str[i] = str[i + 1];
    }
    str[target] = temp;
}

void perm(char *str, int start, int end)
{
    // Base Case: If the starting index reaches the end, we found a permutation
    if (start == end)
    {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i < end; ++i)
    {
        dbg("---  i=%d  ---\n", i);
        // 1. To keep order, we pull the i-th element to the current index
        shiftRight(str, start, i);

        // 2. Recurse for the next position
        perm(str, start + 1, n);

        // 3. Backtrack: Shift back to restore original sorted state
        shiftLeft(str, start, i);
    }
}

int main()
{
    // int n;
    char s[n + 1];

    scanf("%d", &n);
    scanf("%s", s);

    perm(s, 0, n);

    return 0;
}

#endif