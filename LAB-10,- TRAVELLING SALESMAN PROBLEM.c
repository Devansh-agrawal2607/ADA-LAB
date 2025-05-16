#include <stdio.h>
#include <limits.h>

#define N 4
#define VISITED_ALL ((1 << N) - 1)

int tsp(int mask, int pos, int cost[N][N], int dp[N][1 << N]) {
    if (mask == VISITED_ALL)
        return cost[pos][0];

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int minCost = INT_MAX;

    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = cost[pos][city] + tsp(mask | (1 << city), city, cost, dp);
            if (newCost < minCost)
                minCost = newCost;
        }
    }

    return dp[pos][mask] = minCost;
}

int main() {
    int cost[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[N][1 << N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < (1 << N); j++)
            dp[i][j] = -1;

    int result = tsp(1, 0, cost, dp);
    printf("Minimum tour cost: %d\n", result);

    return 0;
}
