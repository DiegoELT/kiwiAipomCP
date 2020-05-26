#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

#define MAX_PAIRS 100005

using namespace std;

vector<int> edges[MAX_PAIRS];
bool visited[MAX_PAIRS];
int dp[MAX_PAIRS];
int in[MAX_PAIRS];

void depthSearch(int vertex)
{   
    assert(!visited[vertex]);
    visited[vertex] = true;
    for(int i: edges[vertex])
    {
        dp[i] = max(dp[i], dp[vertex] + 1);
        in[i]--;
        if(!in[i])
            depthSearch(i);
    }
}

int main()
{
    int n, m, start, end, maximum = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> start >> end;
        edges[start].push_back(end);
        in[end]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i] && !in[i])
            depthSearch(i);
    }
    for(int i = 1; i <=n; i++)
    {
        if(dp[i] > maximum)
            maximum = dp[i];
    }
    cout << maximum;
}