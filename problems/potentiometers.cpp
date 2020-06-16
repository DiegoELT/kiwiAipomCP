#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct FenwickTree 
{
  vector<int> bit;  // binary indexed tree
  int n;
  int LSO(int number)
  {
    return (number&(-number));
  }
  FenwickTree(int n) 
  {
    this->n = n;
    bit.assign(n+1, 0);
  }
  /*FenwickTree(vector<int> a) : FenwickTree(a.size()) 
  {
    for (size_t i = 0; i < a.size(); i++)
    add(i, a[i]);
  }*/
  int sum(int r) 
  {
    int ret = 0;
    for (; r; r -= LSO(r))
      ret += bit[r];
    return ret;
  }
  int sum(int l, int r) 
  {
    return sum(r) - sum(l - 1);
  }
  /*void add(int idx, int delta)
  {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }*/ // We don't need this function at the moment so I didn't put it in the template. 
  void update(int idx, int val) 
  {
    for(; idx < bit.size(); idx += LSO(idx))
      bit[idx] += val;
  }
};

int main()
{ 
  // These two are for faster I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> elements; 
  int n, left, right, testCase = 1; 
  string endString;
  while(cin >> n, n > 0)
  {
    if(testCase > 1) // Skip this since we need a breakline after each test case.
      cout << "\n";
    cout << "Case " << testCase++ << ":\n";
    elements.assign(n,0); // assigns 0 to all elements of the vector at first.
    FenwickTree potentiometer(n);
    for(int i=1; i <= n; i++)
    {
      cin >> elements[i];
      potentiometer.update(i, elements[i]);
    }
    while(cin >> endString, endString != "END") // Here we start receiving the queries themselves.
    {
      cin >> left >> right;
      if(endString == "S")
      {
        potentiometer.update(left, right-elements[left]);
        elements[left] = right;
      }
      else
        cout << potentiometer.sum(left,right) << "\n";
    }
  }
  return 0;
}