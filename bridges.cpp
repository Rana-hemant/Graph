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


void findBridge(int V,vector<int> &discoveryTime,vector<int> &lowestTime,vector<int> &parent,vector<bool> &visited,int &time,int node)
{
    time++;
    discoveryTime[node] = time;
    lowestTime[node] = time;
    visited[node] = true;
    for(auto neighbour : g.adj[node])
    {
        if(neighbour == parent[node])
        {
           continue;
        }
        if(!visited[neighbour])
        {
            findBridge(V,discoveryTime,lowestTime,parent,visited,time,neighbour);
            lowestTime[node] = min(lowestTime[node],lowestTime[neighbour]);
            if(lowestTime[neighbour] > discoveryTime[node])
            {
                cout<<node<<" --- "<<neighbour;
                cout<<endl;
            }
        }
        else
        {
            lowestTime[node] = min(lowestTime[node],discoveryTime[neighbour]);
        }
    }   
}

int main()
{
    int V=5,E=5,time = 0;
    g.createGraph();
    vector<int> discoveryTime(V,-1);
    vector<int> lowestTime(V,-1);
    vector<int> parent(V,-1);
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            findBridge(V,discoveryTime,lowestTime,parent,visited,time,i);
        }
    }
    return 0;
}



// 1 2
// 1 0
// 2 0
// 0 3
// 3 4