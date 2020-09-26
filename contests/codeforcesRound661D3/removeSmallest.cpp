#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
  int testCases, amountOfElements, element;
  bool flag = true; 
  vector<int> values;
  cin >> testCases;
  while(testCases--){
    cin >> amountOfElements;
    while(amountOfElements--){
      cin >> element;
      values.push_back(element);
    }
    sort(values.begin(), values.end());
    for (int i = 0; i < values.size()-1; i++){
      if(abs(values[i]-values[i+1]) > 1){
        cout << "NO\n";
        flag = false;
        break;
      }
    }
    if(flag)
      cout << "YES\n";
    values.clear();
    flag = true;
  }
  return 0;
}