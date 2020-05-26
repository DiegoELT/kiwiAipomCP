#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SOLIDITY 20123 // I checked this value from the editorial since you don't know what the max value is it going to be. 

using namespace std;

class Block
{
    public:
    int weight, solidity;
    long long value; 
    void read(int w, int s, long long v)
    {
        weight = w;
        solidity = s;
        value = v;
    }
    bool operator <(const Block& otherBlock) const
    {
        return weight + solidity < otherBlock.weight + otherBlock.solidity;
    }
};

long long dp[MAX_SOLIDITY+1]; // DDP in the case is the value of blocks with total weight i

int main()
{
    int nBlocks, maxSolidity = 20123; 
    int bW, bS; long long bV;
    long long answer = 0;
    cin >> nBlocks;
    vector<Block> bloques;
    for (int i = 0; i < nBlocks; i++)
    {
        Block happyBlock;
        cin >> bW >> bS >> bV;
        happyBlock.read(bW, bS, bV);
        bloques.push_back(happyBlock);
    }
    sort(bloques.begin(), bloques.end());
    for (int i = 0; i < nBlocks; i++)
    {
        for(int j = min(bloques[i].solidity, maxSolidity - bloques[i].weight); j >= 0; j--)
            dp[j + bloques[i].weight] = max(dp[j + bloques[i].weight], dp[j] + bloques[i].value);
    }
    for(int i = 0; i <= maxSolidity; i++)
    {
        if(dp[i] > answer)
            answer = dp[i];
    }
    cout << answer;
}