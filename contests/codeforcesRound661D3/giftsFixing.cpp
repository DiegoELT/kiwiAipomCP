#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  long long testCases, gifts, candy, orange, minCandy, minOrange, minOfTheTwo, counter = 0;
  vector<int> candies;
  vector<int> oranges;

  cin >> testCases;

  while(testCases--){
    cin >> gifts;
    for (int i = 0; i < gifts; i++){
      cin >> candy;
      candies.push_back(candy);
    }
    for (int i = 0; i < gifts; i++){
      cin >> orange;
      oranges.push_back(orange);
    }
    minCandy = *min_element(candies.begin(), candies.end());
    minOrange = *min_element(oranges.begin(), oranges.end());
    for (int i = 0; i < gifts; i++){
      if(oranges[i] > minOrange && candies[i] > minCandy){
        minOfTheTwo = min(oranges[i] - minOrange, candies[i] - minCandy);
        oranges[i] -= minOfTheTwo;
        candies[i] -= minOfTheTwo;
        counter += minOfTheTwo;
      }
      counter += oranges[i] - minOrange;
      counter += candies[i] - minCandy;
    }
    cout << counter << "\n";
    counter = 0;
    candies.clear();
    oranges.clear();
  }
  return 0;
}