#include <iostream>
#include <vector>

#define MAX_ELEMENTS 100

using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int main()
{
    int n, W, w, v;
    vector< vector<long long int> > dp;
    vector<long long int> wW;
    int weights[MAX_ELEMENTS];
    long long int values[MAX_ELEMENTS];

    cin >> n >> W; 

    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        weights[i] = w; values[i] = v;
    }

    for(int i = 0; i <= n; i++)
    {   
        for (int j = 0; j <= W; j++)
            wW.push_back(0);
        dp.push_back(wW);
        wW.clear();
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (weights[i-1] <= j)
                    dp[i][j] = max(values[i-1] + dp[i-1][j - weights[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][W];
}