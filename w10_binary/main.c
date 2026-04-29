#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2)
        return;

    int *a = (int *)malloc(n * sizeof(int));
    int *diff = (int *)calloc(n + 1, sizeof(int)); // Tracks where flips end
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int current_flips = 0;
    int possible = 1;

    for (int i = 0; i < n; i++)
    {
        // Update current_flips based on flips that expired at this index
        current_flips ^= diff[i];

        // Determine actual value of a[i] after active flips
        // If current_flips is odd (1), the bit is toggled
        int actual_val = a[i] ^ current_flips;

        if (actual_val == 1)
        {
            // If we are within the range to start a new flip
            if (i + k <= n)
            {
                current_flips ^= 1; // Start flip
                if (i + k < n)
                {
                    diff[i + k] ^= 1; // Mark where this flip ends
                }
            }
            else
            {
                // Not enough space for a k-sized window; cannot flip a[i] to 0
                possible = 0;
                break;
            }
        }
    }

    if (possible)
        printf("YES\n");
    else
        printf("NO\n");

    free(a);
    free(diff);
}

int main()
{
    int t;
    if (scanf("%d", &t) != 1)
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}