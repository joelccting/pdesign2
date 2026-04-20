// #include <stdio.h>

// int main()
// {
//     int n, *a, i;

//     scanf("%d", &n);
//     a = (int *)malloc(sizeof(int) * (n + 1));
//     memset(a, 0, sizeof(int) * (n + 1));

//     a[0] = 0;
//     i = 1;
//     while (n--)
//     {
//         scanf("%d", a + i);
//     }

//     free(a);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * findNearestSmaller - 尋找左側第一個比自己小的數
 * @param nums: 輸入數組
 * @param n: 數組長度
 */
void findNearestSmaller(int nums[], int n)
{
    // 建立一個棧存放索引，最大長度為 n
    int *stack = (int *)malloc(sizeof(int) * n);
    int top = -1; // 棧頂指標，-1 表示空棧

    for (int i = 0; i < n; i++)
    {
        // 當棧不為空，且棧頂元素大於或等於當前元素時，彈出棧頂
        // 保持棧內元素是由底到頂「嚴格遞增」
        while (top >= 0 && nums[stack[top]] >= nums[i])
        {
            top--;
        }

        // 如果棧不為空，棧頂就是左側最近的小值
        if (top >= 0)
        {
            // printf("數字 %d 左側最近的小值是: %d\n", nums[i], nums[stack[top]]);
            printf("%d ", stack[top] + 1);
        }
        else
        {
            // printf("數字 %d 左側沒有更小的數\n", nums[i]);
            printf("0 ");
        }

        // 將當前索引壓入棧
        stack[++top] = i;

#if 0 /*DEBUG*/
        printf("i=%d: ", i);
        for (int j = 0; j <= top; ++j)
            printf("%d ", nums[stack[j]]);
        printf("\n");
#endif
    }

    free(stack);
}

int main()
{
    int i;
#if 0 /*DEBUG*/
    int arr[] = {2, 5, 1, 4, 8, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

#else
    int n, *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);

    for (i = 0; i < n; ++i)
    {
        scanf("%d", arr + i);
    }
#endif

    findNearestSmaller(arr, n);
#ifndef DEBUG
    free(arr);
#endif

    return 0;
}