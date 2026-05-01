#include <stdio.h>
#include <string.h>

#define SZ (1005)
int mood[SZ];
int nu_mood[SZ];
int max_mood[SZ];

int goleft(int idx)
{
    int ret = 0;
    if (idx == 0)
        return 0;

    for (int i = idx - 1; i > -1; --i)
    {
        nu_mood[i] = ((nu_mood[i + 1] >= mood[i]) ? mood[i] : nu_mood[i + 1]);
        ret += nu_mood[i];
    }
    return ret;
}

int gorite(int idx, int n)
{
    int ret = 0;
    if (idx == n - 1)
        return 0;

    for (int i = idx + 1; i < n; ++i)
    {
        nu_mood[i] = ((nu_mood[i - 1] >= mood[i]) ? mood[i] : nu_mood[i - 1]);
        ret += nu_mood[i];
    }
    return ret;
}

void dbg(int n)
{
    printf("---\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", mood[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", nu_mood[i]);
    }
    printf("\n---\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", mood + i);
    }

    // dbg(n);

    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        nu_mood[i] = mood[i];
        int sum = nu_mood[i];
        sum += goleft(i);
        sum += gorite(i, n);
        // dbg(n);
        if (sum > max)
        {
            memcpy(max_mood, nu_mood, SZ * sizeof(int));
            max = sum;
        }
    }

    printf("%d\n", max);
    for (int i = 0; i < n; ++i)
        printf("%d%s", max_mood[i], (i == n - 1) ? "" : " ");

    return 0;
}