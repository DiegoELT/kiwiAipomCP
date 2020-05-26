#include <iostream>

#define MAX_DAYS 100000

using namespace std;

int main()
{
    int n, a, b, c;
    int events[MAX_DAYS][3];
    int dp[MAX_DAYS][3];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        events[i][0] = dp[i][0] = a;
        events[i][1] = dp[i][1] = b;
        events[i][2] = dp[i][2] = c;
    }   

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i-1][1] + events[i][0], dp[i-1][2] + events[i][0]);
        dp[i][1] = max(dp[i-1][0] + events[i][1], dp[i-1][2] + events[i][1]);
        dp[i][2] = max(dp[i-1][0] + events[i][2], dp[i-1][1] + events[i][2]);
    }

    cout << max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}