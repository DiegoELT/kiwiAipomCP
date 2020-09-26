#include <bits/stdc++.h>

using namespace std;

int n, sum, length;
char bit;
unordered_map<int, int> mapOfSums;


int main()
{
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> bit; 
    if(bit == '0') sum++;
    else sum--; 

    if(mapOfSums.count(sum)) length = max(length, i - mapOfSums[sum]);
    else mapOfSums[sum] = i; 
    
    if(!sum) length = max(length, i+1);
  }
  cout << length;
  return 0;
}