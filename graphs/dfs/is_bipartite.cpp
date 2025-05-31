//here we will find that if there is bipartatite or odd cycle exsis or not 
//not =e if odd cycles exsist then it means that the adjancent nodes are of same color and thus it is non bipartite

#include<bits/stdc++.h>
using namespace std;

    int n,m ;
    vector<vector<int>>g;
    vector<int>visited;
    bool is_bipartite = true;
    void dfs(int node,int color)
    {
        visited[node] = color;  // every time mark the node as visited
        for(auto v:g[node])  // traverse all the neighbours of the node
        {
            if(!visited[v])  // if the neighbour is not visited then call the dfs for that neighbour
            {
                dfs(v,3-color);  // mark with the opposite color
            }

            else if(visited[v] == color)  // if the neighbour is already visited and has the same color then it is not bipartite
            {
                is_bipartite = false;
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
       
            dfs(i,1); // start with 1 as the color
        }
    }
    cout << is_bipartite << endl;
    // we can also answer the queries given in the question.
    
    return 0;
}
