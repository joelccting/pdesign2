#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (10001)
typedef long long LL;
int exists[LEN];

/* sliding window */
LL swin(int a[], int sz)
{
    LL curr_sum = 0, max_score = 0;
    int left = 0;
    memset(exists, 0, LEN * sizeof(int));

    for (int right = 0; right < sz; ++right)
    {
        while (exists[a[right]])
        {
            exists[a[left]] = 0;
            curr_sum -= a[left];
            left++;
        }

        exists[a[right]] = 1;
        curr_sum += a[right];

        // printf("l=%d, r=%d\n", left, right);
        if (max_score < curr_sum)
            max_score = curr_sum;
    }

    return max_score;
}

int main()
{
    int t, n, *nums;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i)
    {
        scanf("%d", &n);
        nums = (int *)calloc(n, sizeof(int));

        for (int j = 0; j < n; ++j)
            scanf("%d", nums + j);

        printf("%lld\n", swin(nums, n));

        free(nums);
    }

    return 0;
}
