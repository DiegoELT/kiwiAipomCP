#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, amount; // Amount of balloons and gas canisters, amount of helium
    double min = 1; // Minimum fraction possible
    cin >> n; 
    vector<double> helium;
    vector<double> balloons; 

    for (size_t i = 0; i < n; i++)
    {
        cin >> amount;
        helium.push_back(amount);
        balloons.push_back(i+1);
    }
    sort(helium.begin(), helium.end()); // I sort the canisters so each gets its correct balloon.
    for (size_t i = 0; i < n; i++)
    {
        if(helium[i] > balloons[i])
        {
            cout << "impossible"; // If a canister is bigger than the assigned ballon, it explodes
            return 0;
        }
        else
        {
            double frac = helium[i]/balloons[i];
            if(min > frac)
                min = frac; // We check how much of the balloon is filled, and save it if its the minimum.
        }
    }
    cout << min;
    return 0;
}