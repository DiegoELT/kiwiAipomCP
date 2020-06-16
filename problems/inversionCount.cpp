#include <iostream>
#include <string>
#include <vector>

#define MAX_NUMBERS 1e7

using namespace std;

struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int _n) {
        this->n = _n + 1;
        bit.assign(_n + 1, 0);
    }

    /*FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }*/

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int testCases, arrayLength, value;
  long long ans = 0;

  cin >> testCases;
  for(int i = 0; i < testCases; i++)
  {
    cin >> arrayLength;
    FenwickTreeOneBasedIndexing inversions(MAX_NUMBERS + 1);
    ans = 0;

    for (int j = 0; j < arrayLength; ++j)
    {
      cin >> value;
      inversions.add(value, 1);
      ans += inversions.sum(value + 1, MAX_NUMBERS);
    }
    cout << ans << "\n";
  }
    return 0;
}