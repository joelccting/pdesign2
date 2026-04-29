#include <stdio.h>

typedef long long LL;

#define LEN (100005)
int a[LEN];

LL calc(int n, LL k)
{
    int max_dq[LEN], min_dq[LEN];
    int max_head = 0, max_tail = 0,
        min_head = 0, min_tail = 0;
    LL total_count = 0;

    int right, left = 0;

    for (right = 0; right < n; ++right)
    {
        // Maintain max deque (decreasing order)
        while (max_head < max_tail && a[max_dq[max_tail - 1]] <= a[right])
            max_tail--;
        max_dq[max_tail++] = right;

        // Maintain min deque (increasing order)
        while (min_head < min_tail && a[min_dq[min_tail - 1]] >= a[right])
            min_tail--;
        min_dq[min_tail++] = right;

        // Shrink the window from the left if cost > k [cite: 6, 7]
        // cost = (max - min) * (length)
        while (left <= right)
        {
            long long current_max = a[max_dq[max_head]];
            long long current_min = a[min_dq[min_head]];
            long long length = (right - left + 1);

            if ((current_max - current_min) * length <= k)
            {
                break;
            }

            left++;
            // Remove indices from deques if they are outside the new window
            if (max_dq[max_head] < left)
                max_head++;
            if (min_dq[min_head] < left)
                min_head++;
        }

        // All subarrays starting from [left...right] and ending at right are valid
        total_count += (right - left + 1);
    }

    return total_count;
}

int main()
{
    int n;
    LL k;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }

#if 0
    printf("%d %lld\n", n, k);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
#endif

    printf("%lld", calc(n, k));

    return 0;
}