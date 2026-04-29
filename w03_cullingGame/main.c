#include <stdio.h>

#include <stdio.h>
/* @param arr    The input array (1, 2, 3, 4, 5)
 * @param data   Temporary array to store current combination
 * @param start  Starting index in arr[]
 * @param end    Ending index in arr[]
 * @param index  Current index in data[]
 * @param depth  Size of combination to be printed
 */
void selection(int *arr, int *data, int start, int end, int index, int depth)
{
    if (index == depth)
    {
        for (int i = 0; i < depth; ++i)
            printf("%d ", data[i]);
        printf("\n");
        return;
    }

    /* end - i + 1 >= depth - index
     * stops the loop if there aren't enough numbers left in the array to finish the combination
     */
    for (int i = start; i <= end && end - i + 1 >= depth - index; ++i)
    {
        // printf("index=%d, i=%d\n", index, i);
        data[index] = arr[i];
        selection(arr, data, i + 1, end, index + 1, depth);
    }
}

/*culling game*/
void culling(void)
{
    int n, k;
    int a[15], d[15];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }

    selection(a, d, 0, n - 1, 0, k);
}

int main()
{
    culling();
    return 0;
}

#if 0
void generate(int n, int k, int start, int depth, int c[])
{
    if (depth == k)
    {
        for (int i = 0; i < k; i++)
        {
            printf("%d ", c[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= n; i++)
    {
        c[depth] = i;
        generate(n, k, i + 1, depth + 1, c);
    }
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int c[k];
    generate(n, k, 1, 0, c);

    return 0;
}
#endif