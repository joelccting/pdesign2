#include <stdio.h>

int main()
{
    const int a[] = {
        10,
        11, 12, 13, 14, 15,
        16, 17, 34, 18, 19,
        20, 21, 22, 35, 23,
        24, 25, 26, 27, 28,
        29, 32, 30, 31, 33};

    char s[20] = {0};
    scanf("%s", s);

    if ((s[0] < 'A') || (s[0] > 'Z'))
    {
        printf("No");
        return 0;
    }

    if ((s[1] < '1') || (s[1] > '2'))
    {
        printf("No");
        return 0;
    }

    for (int i = 2; i < 10; ++i)
    {
        if ((s[i] < '0') || (s[i] > '9'))
        {
            printf("No");
            return 0;
        }
    }

    if (s[10] != 0)
    {
        printf("No");
        return 0;
    }
    
    int sum = 0;

    // for (int i = 0; i < 10; ++i) printf("%c-", s[i]);
    // printf("\n");

    int aa = a[s[0] - 'A'];
    sum += aa / 10 + (aa % 10) * 9;
    for (int i = 1; i < 9; ++i)
    {
        sum += (s[i] - '0') * (9 - i);
    }

    sum += (s[9] - '0');
    // printf("sum=%d\n", sum);

    if (0 == sum % 10)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}