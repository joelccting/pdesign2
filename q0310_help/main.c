#include <stdio.h>

int main()
{
    int y, m, d;
    int mm[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};
    int err = 1;

    scanf("%d/%d/%d", &y, &m, &d);
    // printf("%d.%d.%d\n", y, m, d);
    do
    {
        if ((y < 2) || (y > 99))
            break;

        if ((m < 1) || (m > 12))
            break;

        //if (y % 4 == 0) mm[1] = 29;

        if ((d < 1) || (d > mm[m - 1]))
            break;

        err = 0;
    } while (0);

    if (err)
        printf("Not a Valid Date");
    else
        printf("%d/%d/%d", y + 1911, m, d);
    return 0;
}