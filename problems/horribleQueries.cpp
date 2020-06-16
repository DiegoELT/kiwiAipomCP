#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

const int maxSize = 100002;

long long B1[maxSize];
long long B2[maxSize];

void update(long long bit[], int idx, long long value)
{
  for(int i = idx; i <  maxSize; i += i & -i)
    bit[i] += value;
}

long long query(long long bit[], int idx)
{
  long long answer = 0;
  for(int i = idx; i > 0; i -= i & -i)
    answer += bit[i];
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testCases;
  cin >> testCases;
  int N, commands, queries, left, right;
  long long value;
  for(int i = 0; i < testCases; i++)
  {
    cin >> N >> commands; 
    memset(B1,0,sizeof(B1));
    memset(B2,0,sizeof(B2));
    for(int j = 0; j < commands; j++)
    {
      cin >> queries >> left >> right;
      if(queries)
        cout << query(B1,right) * right + query(B2,right) - query(B1,left - 1) * (left - 1) - query(B2,left - 1) << "\n";
      else
      {
        cin >> value;
        update(B1,left,value);
        update(B1,right+1,-value);
        update(B2,left,-value*(left-1));
        update(B2,right+1,value*right);
      }
    }
  }
  return 0;
}