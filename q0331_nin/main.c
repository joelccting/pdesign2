#include <stdio.h>
#include <string.h>

typedef unsigned long long ULL;
#define dbg(fmt, ...) // printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)
int isValid(char *s)
{
    // printf("%s\n", s);
    const int a[] = {
        10,
        11, 12, 13, 14, 15,
        16, 17, 34, 18, 19,
        20, 21, 22, 35, 23,
        24, 25, 26, 27, 28,
        29, 32, 30, 31, 33};
    int sum = 0;

    int aa = a[s[0] - 'A'];
    sum += aa / 10 + (aa % 10) * 9;
    for (int i = 1; i < 9; ++i)
    {
        sum += (s[i] - '0') * (9 - i);
    }

    sum += (s[9] - '0');

    return (0 == sum % 10);
}

ULL cnt = 0;

void count(char *id, int i)
{
    if (10 == i)
    {
        if (isValid(id))
            ++cnt;
        return;
    }

    if (id[i] != '#')
        return count(id, i + 1);

    if (i == 0)
    { // First character must be a letter
        for (char c = 'A'; c <= 'Z'; c++)
        {
            id[i] = c;
            count(id, i + 1);
        }
    }
    else if (i == 1)
    { // Second character must be '1' or '2'
        for (char c = '1'; c <= '2'; c++)
        {
            id[i] = c;
            count(id, i + 1);
        }
    }
    else
    { // All other positions are digits 0-9
        for (char c = '0'; c <= '9'; c++)
        {
            id[i] = c;
            count(id, i + 1);
        }
    }

    id[i] = '#';
}

int main()
{
    // int pos;
    // int p[30] = {
    //     26,
    //     2,
    //     10,
    //     10,
    //     10,
    //     10,
    //     10,
    //     10,
    //     10,
    //     1,
    // };
    char id[30] = {0};

    scanf("%s", id);
    id[strcspn(id, "\n")] = 0;
    dbg("%s\n", id);
    do
    {
        if (strlen(id) != 10)
        {
            dbg("\n");
            break;
        }

        if (id[0] != '#' && (id[0] < 'A' || 'Z' < id[0]))
        {
            dbg("\n");
            break;
        }

        if (id[1] != '#' && id[1] != '1' && id[1] != '2')
        {
            dbg("\n");
            break;
        }

        int flag = 0;
        for (int i = 2; i < 10; ++i)
        {
            if (id[i] != '#' && ('0' > id[i] || id[i] > '9'))
            {
                flag = 1;
                dbg("\n");
                break;
            }
        }

        if (1 == flag)
            break;

        // if (id[9] == '#')
        // {
        //     pos = 1;
        //     for (int i = 0; i < 10; ++i)
        //     {
        //         if (id[i] == '#')
        //             pos *= p[i];
        //     }
        // }
        // else
        // {

        // }
        count(id, 0);

    } while (0);

    // printf("%d", pos);
    printf("%llu", cnt);
    return 0;
}