#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<set>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void createGraph(int u,int v,int weight,bool directed)
    {
        if(directed)
        {
           adj[u].push_back(make_pair(v,weight)); 
        }
    }

    void showAdj()
    {
        for(auto i : adj)
        {
            cout<<i.first<<" -> ";
            for(auto j : i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }

}g;

void primsAlgo()
{
    int V = 3;
    vector<int> key(V,INT_MAX);
    vector<bool> mst(V,false);
    vector<int> parent(V,-1);
    key[0] = 0;

    // pair(weight,node)
    set<pair<int,int>> st;
    st.insert(make_pair(0,0));
    
    while(!st.empty())
    {
        pair<int,int> p = *st.begin();
        st.erase(st.begin());
        mst[p.second] = true;

        for(auto i : g.adj[p.second])
        {
            if(!mst[i.first] && key[i.first] > i.second)
            {
                auto it = st.find({key[i.first],i.first});
                if(it != st.end())
                {
                    st.erase(it);
                }
                key[i.first] = i.second;
                st.insert({key[i.first],i.first});
                parent[i.first] = p.second;
            }
        }
    }

    for(auto i = 0; i<mst.size();i++)
    {
        if(parent[i] = -1)
        {
            cout<<i<<" , ";
        }
    }

}

int main()
{
    g.createGraph(0,1,2,true);
    g.createGraph(1,2,3,true);
    g.createGraph(2,0,10,true);
    g.showAdj();

    primsAlgo();
    return 0;
}




// #include<iostream>
// #include<unordered_map>
// #include<list>
// #include<vector>
// #include<set>
// #include<climits>
// using namespace std;

// class graph{
//     public:
//     unordered_map<int, list<pair<int, int>>> adj;

//     void createGraph(int u, int v, int weight, bool directed) {
//         if (directed) {
//             adj[u].push_back(make_pair(v, weight));
//         }
//     }

//     void showAdj() {
//         for (auto i : adj) {
//             cout << i.first << " -> ";
//             for (auto j : i.second) {
//                 cout << "(" << j.first << "," << j.second << ")";
//             }
//             cout << endl;
//         }
//     }
// } g;

// void primsAlgo() {
//     int V = 6; // Number of vertices
//     vector<int> key(V, INT_MAX);
//     vector<bool> mst(V, false);
//     vector<int> parent(V, -1);

//     // Starting from node 0
//     key[0] = 0;
//     set<pair<int, int>> st;
//     st.insert({0, 0}); // {weight, node}

//     while (!st.empty()) {
//         auto p = *st.begin();
//         st.erase(st.begin());
//         int u = p.second;
//         mst[u] = true;

//         for (auto i : g.adj[u]) {
//             int v = i.first;
//             int weight = i.second;

//             if (!mst[v] && weight < key[v]) {
//                 auto it = st.find({key[v], v});
//                 if (it != st.end()) {
//                     st.erase(it);
//                 }
//                 key[v] = weight;
//                 st.insert({key[v], v});
//                 parent[v] = u;
//             }
//         }
//     }

//     for (int i = 1; i < V; i++) {
//         if (parent[i] != -1) {
//             cout << "Edge: " << parent[i] << " - " << i << " with weight: " << key[i] << endl;
//         }
//     }
// }

// int main() {
//     g.createGraph(0, 1, 2, true);
//     g.createGraph(1, 2, 3, true);
//     g.createGraph(2, 0, 10, true);
//     g.showAdj();

//     primsAlgo();
//     return 0;
// }




// // 2 -> (3,2)
// // 4 -> (3,3)
// // 0 -> (1,3)(4,8)(3,7)
// // 1 -> (3,4)(2,1)

// 2 -> (0,10)
// 0 -> (1,2)
// 1 -> (2,3)