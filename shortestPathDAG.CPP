#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u,int v,int weight)
    {
        adj[u].push_back(make_pair(v,weight));
    }

    void createGraph()
    {
        int V,E;

        cout<<"Enter the number of vertices : ";
        cin>>V;
        cout<<"Enter the number of edges : ";
        cin>>E;

        int u,v,weight;
        for(int i=0;i < E;i++)
        {
            cout<<"Enter the pair of vertex(u,v) and weight : ";
            cin>>u>>v>>weight;
            addEdge(u,v,weight);
        }
    }

    void showAdj(int vertices)
    {
        for(auto i:adj)
        {
            cout<<i.first<<" --> ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }
}g;

void topoSort(int node,unordered_map<int,bool> &visited,stack<int> &st)
{
    visited[node] = true;
    for(auto i:g.adj[node])
    {
        if(!visited[i.first])
        {
            topoSort(i.first,visited,st);
        }
    }
    st.push(node);
}

void shortestPath(unordered_map<int,int> &dist,stack<int> &st)
{
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();

        if(dist[temp] != INT_MAX)
        {
            for(auto i:g.adj[temp])
            if(dist[temp] + i.second < dist[i.first])
            {
                dist[i.first] = dist[temp] + i.second;
            }
        }
    }
}

int main(){
    g.createGraph();
    g.showAdj(6);

    unordered_map<int,bool> visited;
    stack<int> st;
    for(int i=0;i<6;i++)
    {
        if(!visited[i])
        {
            topoSort(i,visited,st);
        }
    }

    unordered_map<int,int> dist;
    for(int i=0;i<6;i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    shortestPath(dist,st);

    for(auto i:dist)
    {
        cout<<i.second<<" ";
    }

    return 0;
}


// 0 2 4
// 1 0 3
// 1 2 2
// 2 4 2
// 2 3 -3
// 4 3 2
// 1 3 5

// 0 1 2
// 0 4 1
// 4 5 4 
// 4 2 2
// 1 2 3
// 2 3 6
// 5 3 1