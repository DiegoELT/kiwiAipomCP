#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int finish;
    int weight;
    int next; // This is something I still need to fully unde
};

vector<edge> listOfPaths;
vector<int> head;
int edgeNo = 0; 

void addEdge(int firstNode, int secondNode, int weight) // Since adding an edge can be basically considered adding to edges, backwards and forwards.
{
    listOfPaths[edgeNo].weight = weight; 
    listOfPaths[edgeNo].finish = secondNode;
    listOfPaths[edgeNo].next = head[firstNode];
    head[firstNode] = edgeNo++;

    listOfPaths[edgeNo].weight = weight;
    listOfPaths[edgeNo].finish = firstNode;
    listOfPaths[edgeNo].next = head[secondNode];
    head[secondNode] = edgeNo++;
}

long long dfs(int node, int parentNode, long long flow)
{
    long long pathSoFar = flow;
    int child, weight;
    for(int i = head[node]; i != -1; i = listOfPaths[i].next)
    {
        child = listOfPaths[i].finish;
        weight = listOfPaths[i].weight;
        if(child != parentNode)
            pathSoFar = max(pathSoFar, dfs(child, node, flow + weight));
    }
    return pathSoFar;
}

int main()
{
    int amountOfCities, start, finish, weight;
    long long ans = 0;

    cin >> amountOfCities;
    for(int i = 0; i < amountOfCities; i++)
    {
        edge emptyEdge;
        listOfPaths.push_back(emptyEdge); listOfPaths.push_back(emptyEdge);
        head.push_back(-1);
    }

    for(int i = 0; i < amountOfCities - 1; i++)
    {
        cin >> start >> finish >> weight; 
        addEdge(start - 1, finish - 1, weight);
        ans += weight*2; // Since you will go through the path twice.
    }

    long long pathToSubstract = dfs(0, -1, 0); 
    cout << ans - pathToSubstract;
    return 0;
}