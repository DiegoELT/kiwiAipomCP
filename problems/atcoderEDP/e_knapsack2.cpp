#include <iostream> 
#include <vector>
#include <algorithm>

#define MAX_ITEMS 100

using namespace std;

long long infinity = 1e18 + 5;
long long values[MAX_ITEMS];
long long weights[MAX_ITEMS];

int main()
{
    int numberOfItems;
    long long maximumWeight, aValue, aWeight, sumOfValues = 0, answer = 0;
    cin >> numberOfItems >> maximumWeight;
    for(int i = 0; i < numberOfItems; i++)
    {
        cin >> aWeight >> aValue;
        weights[i] = aWeight;
        values[i] = aValue;
        sumOfValues += aValue;
    }

    vector<long long> dp(sumOfValues + 1, infinity); // Another way to create DPs (thanks to Errichto), this one is the minimum weightof items with value i
    dp[0] = 0;
    for(int i = 0; i < numberOfItems; i++)
    {
        for(int j = sumOfValues - values[i]; j >= 0;  j--)
            dp[j+values[i]] = min(dp[j+values[i]], dp[j] + weights[i]);
    }
    for(int i = 0; i <= sumOfValues; i++)
    {
        if(dp[i] <= maximumWeight)
            answer = max(answer, (long long) i);
    }   
    cout << answer;
}