//different questions - 1. count the number of connected components in the graph
//2. print the connected components in the graph
//3.print the size of each connected component
//4.answer the queries given in the question.

#include<bits/stdc++.h>
using namespace std;

    int n,m ;
    vector<vector<int>>g;
    vector<int>visited;
    void dfs(int node,int num_comp)
    {
        visited[node] = num_comp;  // every time mark the node as visited
        for(auto v:g[node])  // traverse all the neighbours of the node
        {
            if(!visited[v])  // if the neighbour is not visited then call the dfs for that neighbour
            {
                dfs(v,num_comp);
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
    int num_comp=0
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            num_comp++;
            dfs(i,num_comp);
        }
    }
    cout << num_comp << endl; //Q1 done

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
    }
    // we can also answer the queries given in the question.
    
    return 0;
}
