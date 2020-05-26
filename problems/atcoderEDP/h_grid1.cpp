#include <iostream>

#define MAX_HEIGHT 1000
#define MOD 1000000007

using namespace std;

char grid[MAX_HEIGHT][MAX_HEIGHT];
unsigned long long dp[MAX_HEIGHT][MAX_HEIGHT];

void addWithMod(unsigned long long &a, unsigned long long b)
{
    a += b;
    if(a >= MOD) 
        a -= MOD;
}

int main()
{
    int h, w;
    string line;
    cin >> h >> w;
    for(int i = 0; i < h; i++)
    {
        cin >> line;
        for(int j = 0; j < line.size(); j++)
            grid[i][j] = line[j];
    }
    dp[0][0] = 1;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            for(int i2 : {i, i + 1})
            {
                int j2 = j;
                if(i2 == i)
                    j2 = j+1;
                if(i2 < h && j2 < w && grid[i2][j2] == '.')
                    addWithMod(dp[i2][j2], dp[i][j]);
            }
        }
    }

    cout << dp[h-1][w-1] % MOD;
}