// here we will detect the cycle in the graph
// logic is if we find a node which is already visited and is not the parent of the current node then there is a cycle
// if there are just two nodes which are not connected then it is not a cycle
//there may be chances you may see the previous node and say it is visited  and say it is a cycle , so we need to handle this too

#include<bits/stdc++.h>
using namespace std;

    int n,m ;
    vector<vector<int>>g;
    vector<int>visited;
    bool is_cycle = false;
    void dfs(int node,int parent)
    {
        visited[node] = 1;  // every time mark the node as visited
        for(auto v:g[node])  // traverse all the neighbours of the node
        {
            if(!visited[v])  // if the neighbour is not visited then call the dfs for that neighbour
            {
                dfs(v,node) ; //the node is the parent of the current node
            }
            else if(v!=parent)
            {
                is_cycle=1; // if cout << num_comp << endl; //Q1 done

    vector<vector<int>>components;
    //visited array is used to store the component number of each node
    for(int i =0;i<n;i++)
    {
        components[visited[i]].push_back(i); // we get the component numbe
    }

    //we can print the components
    for(int i = 0; i < num_comp; i++)
    {
        for(auto v:components[i])
        {
            cout << v << " ";
        }
    }
    // we can also print the size of each component
    for(int i = 0; i < num_comp; i++)
    {
        cout << "size of component " << i << " is " << components[i].size() << endl;
    } the neighbour is visited and is not the parent of the current node then there is a cycle`
            }

        }
    
    }
 int main () {
    cin >> n >> m;//n is the number of nodes and m is the number of edges
    g.resize(n+1); // very important to resize the graph
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        // if undirected graph then uncomment this
        // g[b].push_back(a);
    }
    visited.assign(n+1,0);
    // dfs(1); // call the dfs for the starting node and the dfs will traverse the whole graph
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
  
    
    return 0;
}
