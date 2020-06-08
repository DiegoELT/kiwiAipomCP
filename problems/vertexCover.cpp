#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NODES 100000

using namespace std;

vector< vector <int> > adjacencyList; 
int dp[MAX_NODES][2]; // So this is the DP, the parameters would be the node itself, and if we pick it or not. 

void dfs(int node, int parentNode) // I am making this from the tutorial. 
{
    dp[node][1] = 1;
    for(int i = 0; i < adjacencyList[node].size(); i++)
    {
        int children = adjacencyList[node][i];
        if (children == parentNode)
            continue; // Since the parent is not a children of the node.
        dfs(children, node); // Now the node would be the parent and the children is the node in which we apply the DFS in.
        dp[node][1] += min(dp[children][0], dp[children][1]);
        dp[node][0] += dp[children][1]; // If you don't choose the parent, you have to choose the children.
    }
}

int main()
{
    int numberOfNodes, start, finish;
    
    cin >> numberOfNodes;

    for(int i = 0; i < numberOfNodes; i++)
    {
        vector<int> nodeList;
        adjacencyList.push_back(nodeList);
    }
    
    for(int i = 0; i < numberOfNodes - 1; i++)
    {
        cin >> start >> finish;
        adjacencyList[start-1].push_back(finish-1);
        adjacencyList[finish-1].push_back(start-1);
    }
    dfs(0,-1);
    int ans = min(dp[0][1], dp[0][0]);
    if (ans<1)
        cout << 1;
    else
        cout << ans;
    return 0;
}