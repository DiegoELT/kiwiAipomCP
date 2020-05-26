#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_FLOWERS 200001

using namespace std;

long long beauties[MAX_FLOWERS];
long long heights[MAX_FLOWERS];
long long dp[MAX_FLOWERS + 1]; // The dp in this case corresponds to the maximum beauty so far if the last taken flower has height i.

int main()
{
    long long nFlowers, pretty, height, ans = 0, base  = 1;
    cin >> nFlowers;

    while(base <= nFlowers)
        base *= 2; 

    vector<long long> tree(2 * base);

    for (long long i = 0; i < nFlowers; i++)
    {
        cin >> height;
        heights[i] = height;
    }

    for (long long i = 0; i < nFlowers; i++)
    {
        cin >> pretty;
        beauties[i] = pretty;
    }

    for(long long i = 0; i < nFlowers; i++)
    {   
        long long x = heights[i] + base;
        long long bestSoFar = 0;
        while(x > 1)
        {
            if(x % 2)
                bestSoFar = max(bestSoFar, tree[x-1]);
            x /= 2;
        }

        dp[heights[i]] = bestSoFar + beauties[i];

        for(long long j = base + heights[i]; j >= 1; j /= 2)
            tree[j] = max(tree[j], dp[heights[i]]);
    }

    for(long long i = 0; i <= nFlowers; i++)
    {
        if (dp[i] > ans)
            ans = dp[i];
    }
    cout << ans;
}