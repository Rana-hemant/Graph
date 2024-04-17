#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool directed)
    {
        adj[u].push_back(v);
        if(directed)
        {
            adj[v].push_back(u);
        }
    }

    void createGraph()
    {
        int V,E;

        cout<<"Enter the number of vertices : ";
        cin>>V;
        cout<<"Enter the number of edges : ";
        cin>>E;

        int u,v;
        for(int i=0;i < E;i++)
        {
            cout<<"Enter the pair of vertex(u,v) : ";
            cin>>u>>v;
            addEdge(u,v,false);
        }
    }

    void showAdj(int vertices)
    {
        for(auto i:adj)
        {
            cout<<i.first<<" --> ";
            for(auto j:i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
}g;

void kahn_Dfs_topologySort(unordered_map<int,int> &indegree,int &count)
{
    queue<int> q;
    for(int i=0;i!=6;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        count++;
        for(auto j:g.adj[temp])
        {
            indegree[j]--;
            if(indegree[j] == 0)
            {
                q.push(j);
            }
        }
    }
}

int main()
{
    unordered_map<int,int> indegree;
    int count = 0;
    g.createGraph();
    g.showAdj(6);
    for(auto i:g.adj)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }
    
    kahn_Dfs_topologySort(indegree,count);

    if(count == 4)
    {
        cout<<"No cycle detected";
    }
    else{
        cout<<"Cycle found";
    }
    return 0;
}

// 5 0
// 4 0
// 5 2
// 4 1
// 2 3
// 3 1