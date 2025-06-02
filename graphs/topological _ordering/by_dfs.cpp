#include<bits/stdc++.h>
using namespace std;

    int n,m ;
    vector<vector<int>>g;
    vector<int>visited;
    vector<int>topo;
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
        topo.push_back(node);
    }

    // finding the longest path of graph , not related to graph , it can be done by dp , without topological ordering 
    int dp[10001];
    int rec(int node)
    {
        if(dp[node]!=-1) return dp[node];
        int ans=1;
        for(auto v:g[node]) // check all the neighbours
        {
         ans=max(ans,1+rec(v));  // think like this - lets say you are at node a so count =1 , and after the node a you have n options to choose so you will chosse max of the n paths
        }
        return dp[node]=ans;
    }
 int main () {
    cin >> n >> m;//n is the number of nodes and m is the number of edges
    g.resize(n+1); // very important to resize the graph
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
       
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
    //priting the longest path , the rec givest the max of a particular node so loop over all the nodes and get the max
    int ans =0;
    for (int i=1;i<=n;i++)
 {
    ans=max(ans,rec(i));
    
 }

 cout <<ans<<endl;

    reverse(topo.begin(),topo.end());
    for(auto v:topo)
    {
        cout<<v<<" ";
    }
    cout<<endl;


    //we can do the above int the tabulation approach 
    // in this case you need to again reverse the topo , we will be loooping over topo and as it bottom up
        reverse(topo.begin(),topo.end());
int final =0;
    for(auto node:topo)
    {    
        int ans=1;
        for(auto v:g[node])
        {
            ans=max(ans,1+dp[v]);
        }

        dp[node]=ans;
        final=max(final,dp[node]);
        
    }
    cout<<final<<endl;
    // cout << num_comp << endl; //Q1 done

    // vector<vector<int>>components;
    // //visited array is used to store the component number of each node
    // for(int i =0;i<n;i++)
    // {
    //     components[visited[i]].push_back(i); // we get the component numbe
    // }

    // //we can print the components
    // for(int i = 0; i < num_comp; i++)
    // {
    //     for(auto v:components[i])
    //     {
    //         cout << v << " ";
    //     }
    // }
    // // we can also print the size of each component
    // for(int i = 0; i < num_comp; i++)
    // {
    //     cout << "size of component " << i << " is " << components[i].size() << endl;
    // }
    // we can also answer the queries given in the question.
    
    return 0;
}
