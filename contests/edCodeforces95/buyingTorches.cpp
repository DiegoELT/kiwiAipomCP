#include <bits/stdc++.h>

using namespace std;

int testCases;
long long x, y, k;

// I can go up x - 1 torches at once.
// Basically the amount of trades to obtain k coal

long long howManyTrades()
{
  return (k * y + k - 1 + x - 2) / (x - 1) + k;
}

int main()
{
  cin >> testCases;
  while(testCases--)
  {
    cin >> x >> y >> k;
    cout << howManyTrades() << "\n";
  }
}