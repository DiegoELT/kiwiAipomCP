#include <iostream>

#define MAX_STONES 100000
#define MAX_INTEGERS 100

using namespace std;

// Starting from this problem I discovered it is useful to write down the definition of the DP

bool dp[MAX_STONES + 1];  // It is TRUE if first player wins with that many stones available. We don't care what the optimal steps were.
int removeChances[MAX_INTEGERS];

int main()
{
    int nIntegers, nStones, removeValue;
    cin >> nIntegers >> nStones;
    for (int i = 0; i < nIntegers; i++)
    {
        cin >> removeValue;
        removeChances[i] = removeValue;
    }
    dp[0] = false; // If there are no stones left, the first player loses
    for(int i = 0; i <= nStones; i++)
    {
        for(int j = 0; j < nIntegers; j++)
        {
            if(i >= removeChances[j]  && !dp[i - removeChances[j]])
                dp[i] = true;
        }
    }
    if(dp[nStones])
        cout << "First";
    else
        cout << "Second";
}