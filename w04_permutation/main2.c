//#define USE_ITERATION

#ifdef USE_ITERATION

#include <stdio.h>
#include <string.h>

#define dbg(s, b...) printf(s, b)

// Helper function to swap two characters
void swap(char *a, char *b)
{
    printf("[%s] %c,%c\n", __func__, *a, *b);
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to reverse a segment of the string
void reverse(char *str, int start, int end)
{
    while (start < end)
    {
        printf("[%s] %d,%d\n", __func__, start, end);
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

int next_perm(char *s)
{
    int n = strlen(s);
    if (n <= 1)
        return 0;

    dbg("- %s ", s);

    int i = n - 2;
    // Step 1: Find the pivot, first decreasing element from right
    while (i >= 0 && s[i] >= s[i + 1])
    {
        i--;
    }

    // If no pivot is found, we are at the last permutation (e.g., "cba")
    if (i < 0)
        return 0;

    dbg("[p] %d:%c ", i, s[i]);

    // Step 2: Find the successor to the pivot from the right
    int j = n - 1;
    while (s[i] >= s[j])
    {
        j--;
    }

    dbg("[s] %d:%c\n", j, s[j]);

    // Step 3: Swap pivot and successor
    swap(&s[i], &s[j]);

    // Step 4: Reverse the suffix starting after the pivot
    reverse(s, i + 1, n - 1);

    return 1; // Success!
}

int main()
{
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    do
    {
        printf("%s\n", s);
    } while (next_perm(s));
    return 0;
}

#endif