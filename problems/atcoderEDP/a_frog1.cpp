#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX_HEIGHT 10000
#define MAX_ROCKS 100000


using namespace std;

int main()
{
    int nR, rV, dJ;
    int distances[MAX_ROCKS];
    int rocks[MAX_ROCKS]; 
    cin >> nR;
    for(int i = nR-1; i >= 0; i--)
    {   
        cin >> rV; 
        rocks[i] = rV;
        distances[i] = MAX_HEIGHT; 
    }
    distances[nR-1] = 0;
    distances[nR-2] = abs(rocks[nR-1] - rocks[nR-2]);
    for(int i = nR - 3; i >= 0; i--)
        distances[i] = min(abs(rocks[i+1]-rocks[i]) + distances[i+1], abs(rocks[i+2]-rocks[i]) + distances[i+2]);
    cout << distances[0];
}