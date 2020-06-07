#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int nT, a, b, m, M; // Number of tests, sides a and b, min and Max side
    cin >> nT;
    for (size_t i = 0; i < nT; i++)
    {
        cin >> a >> b; 
        m = min(a,b);
        M = max(a,b);
        if(m*2 >= M) // If the smallest side times 2 is big enough for the big side, the square needs to be 2 times the smallest side
            cout << m * m * 4 << "\n";
        else // Otherwise, the biggest side will be enough. 
            cout << M * M << "\n";
    }
}