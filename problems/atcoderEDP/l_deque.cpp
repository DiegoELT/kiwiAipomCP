#include <iostream>
#include <algorithm>

#define MAX_ELEMENTS 3000

using namespace std;

long long dp[MAX_ELEMENTS][MAX_ELEMENTS]; // I thought dp could be X - Y after N turns have passed, but then (After the editorial) I noticed it could be X - Y based on the current positions of L and R; 
long long elementValues[MAX_ELEMENTS];

int main()
{
    int nElements;
    unsigned long long eValue;
    cin >> nElements;
    for(int i = 0; i < nElements; i++)
    {
        cin >> eValue;
        elementValues[i] = eValue;
    } 
    for(int i = nElements - 1; i >= 0; i--)
    {
        for(int j = i; j < nElements; j++)
        {
            if (i == j)
                dp[i][j] = elementValues[i];  // Basically when they have only one option
            else
                dp[i][j] = max(elementValues[i] - dp[i+1][j], elementValues[j] - dp[i][j-1]);
        }
    }
    cout << dp[0][nElements-1];
}