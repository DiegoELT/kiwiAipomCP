#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{
    int nT, nA, cV, nD, cD = 1000; // Number of tests, athletes, the current athlete to be added, new and current difference.
    vector<int> A; // Vector of athletes
    cin >> nT; 
    for (size_t i = 0; i < nT; i++)
    {
        cin >> nA; 
        for(size_t j = 0; j < nA; j++)
        {
            cin >> cV; 
            A.push_back(cV);
        }
        sort(A.begin(), A.end()); // We sort the vector of athletes
        for(size_t j = 1; j < nA; j++)
        {
            nD = abs(A[j] - A[j-1]); 
            if(nD < cD)
                cD = nD; // We obtain the smallest difference between two members of the vector.
        }
        cout << cD << "\n"; 
        cD = 1000; // Restart for next case.
        A.clear();
    }
}