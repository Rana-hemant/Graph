#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findParent(int node,vector<int> &parent)
{
    if(parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node],parent);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank)
{
    int pu = findParent(u,parent);
    int pv = findParent(v,parent);
    if(rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else if(rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

void makeSet(vector<int> &parent,vector<int> &rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

void findMST(vector<vector<int>> edges,vector<int> parent,vector<int> rank)
{
    int minWeight = 0;
    for(int i=0;i<edges.size();i++)
    {
        int u = findParent(edges[i][0],parent);
        int v = findParent(edges[i][1],parent);
        int weight = edges[i][2];

        if(u != v)
        {
            minWeight += weight;
            unionSet(u,v,parent,rank);
        }
    }
    cout<<"The minimum weight sum is : "<<minWeight;
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    vector<vector<int>> edges;
    cout << "Enter the edges in the format u v weight:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    });

    findMST(edges,parent,rank);
}


// 1 4 1
// 1 2 2
// 2 3 3
// 2 4 3
// 1 5 4
// 3 4 5
// 2 6 7
// 3 6 8
// 4 5 9
