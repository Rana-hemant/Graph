#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
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

void topoSort(int node,unordered_map<int,bool> &visited,stack<int> &st)
{
    visited[node] = true;
    for(auto i:g.adj[node])
    {
        if(!visited[i])
        {
            topoSort(i,visited,st);
        }
    }
    st.push(node);
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
    cout<<"The topological sort order is : ";
    while(!st.empty())
    {
        cout<<st.top()<<", ";
        st.pop();
    }

    return 0;
}