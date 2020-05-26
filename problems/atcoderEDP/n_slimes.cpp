#include <iostream>
#include <algorithm>
#include <limits>

#define MAX_ELEMENTS 400

using namespace std;

// I have to create a binary tree where each inner node has the value of its two sons, I want to minimize the value of the root.

long long dp[MAX_ELEMENTS][MAX_ELEMENTS]; // The weight of having to combine all elements between interval i and j. It has to be continuous since the slimes don't change positions
long long slimes[MAX_ELEMENTS]; // The slimes themselves
long long inf = 1e18L + 5;

long long arraySum(int L, int R)
{
    long long ans = 0;
    for(int i = L; i <= R; i++)
        ans += slimes[i];
    return ans;
}

int main()
{
    int nSlimes;
    long long slimeValue;
    cin >> nSlimes;
    for(int i = 0; i < nSlimes; i++)
    {
        cin >> slimeValue;
        slimes[i] = slimeValue;
    }
    for(int i = nSlimes - 1; i >= 0; i--)
    {
        for(int j = i; j < nSlimes; j++)
        {
            if(i == j)
                dp[i][j] = 0; // The cost to combine a slime to itself is none
            else
            {
                dp[i][j] = inf;
                for(int k = i; k < j;  k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arraySum(i,j));
            }
        }
    }
    cout << dp[0][nSlimes-1];
}