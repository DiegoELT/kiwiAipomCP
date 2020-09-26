#include <bits/stdc++.h>

using namespace std;

long long t, n, cube;
vector<long long> cubes;
vector<long long> temp;

long long merge(long long left, long long mid, long long right)
{
  long long invCount = 0;
  long long i = left, k = left, j = mid; 
  while((i <= mid - 1) && (j <= right))
  {
    if (cubes[i] <= cubes[j]) temp[k++] = cubes[i++];
    else
    {
      temp[k++] = cubes[j++];
      invCount += mid - i;
    }
  }
  while (i <= mid - 1) 
    temp[k++] = cubes[i++]; 
  while (j <= right) 
    temp[k++] = cubes[j++]; 
  for (i=left; i <= right; i++) 
    cubes[i] = temp[i]; 
  return invCount;
}

long long countSwaps(long long left, long long right)
{
  long long mid, invCount = 0;
  if(right > left)
  {
    mid = (right+left)/2;
    invCount += countSwaps(left, mid);
    invCount += countSwaps(mid+1, right);
    invCount += merge(left, mid+1, right);
  }
  return invCount;
}

int main()
{
  cin >> t;
  while(t--)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> cube; 
      cubes.push_back(cube);
      temp.push_back(0); // I am pretty sure you can push anything you want here or just use an array.
    }
    if (countSwaps(0, n-1) > (n*(n-1))/2 - 1) cout << "NO\n";
    else cout << "YES\n"; 
    cubes.clear();
    temp.clear();
  }
}