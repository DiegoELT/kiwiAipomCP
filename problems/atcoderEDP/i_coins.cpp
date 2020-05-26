#include <iostream>
#include <iomanip>
#include <math.h> 

#define MAX_TOSSES 3000

using namespace std;

double dp[MAX_TOSSES];
double probabilities[MAX_TOSSES-1];

int main()
{
    int nTosses;
    double probability, ans = 0;
    cin >> nTosses;
    dp[0] = 1; 
    for (int i = 0; i < nTosses; i++)
    {
        cin >> probability;
        probabilities[i] = probability;
        for(int j = i + 1; j >= 0; j--)
        {
            if(!j)
                dp[j] = dp[j] * (1-probability);
            else
                dp[j] = dp[j-1] * probability + dp[j] * (1-probability);
        }
    }
    for(int i = 0; i <= nTosses; i++) 
    {
        int tails = nTosses - i;
        if(i > tails) {
            ans += dp[i];
        }
    }
    cout << setprecision(10);
    cout << ans;
}