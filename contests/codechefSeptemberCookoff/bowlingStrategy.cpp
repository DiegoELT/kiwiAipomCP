#include <bits/stdc++.h>

using namespace std;

int t;
long long n, k, l;

void generateCombo()
{
  if (k*l < n || (k == 1 && n != 1)) cout << -1 << "\n";
  else
  {
    while(n)
    {
      for(int i = 1; i <= k; i++)
      {
        cout << i << " "; 
        n--; 
        if(!n) break;
      }
    }
  }
  cout << "\n";
}

int main()
{
  cin >> t;
  for(int i = 0; i < t; i++)
  {
    cin >> n >> k >> l;
    generateCombo();
  }
}