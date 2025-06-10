// Write your code here
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>g;
vector<int>subtreesz;


void dfs(int node , int parent )
{
    subtreesz[node]=1;
    for(auto v: g[node])
    {
        if(v!=parent)
        {
           dfs(v,node);
           subtreesz[node]+=subtreesz[v];        
           
           }
    }
}
int findcentroid(int node , int parent)
{
  
    // go to all child
    for(auto v:g[node])
    {
        if(v!=parent)
        {
        if(subtreesz[v]>n/2)
         {
             // go deeper
             return findcentroid(v,node);
           
         }
        }


    }

    // No child subtree has > n/2 nodes
    // Also check the "parent subtree" (everything above current node)
    int parentSubtreeSize = n - subtreesz[node];
    if(parentSubtreeSize > n/2)
    {
        // This shouldn't happen if we're moving correctly, but just in case
        return findcentroid(parent, node);
    }

    return node;
}
void solve()
{
cin>>n;

g.resize(n+1);
subtreesz.assign(n+1,0);

for(int i=0;i<n-1;i++)
{

    int a, b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(1,0);

int centroid=findcentroid(1,0);

cout<<centroid<<endl;

}
int main()
{



solve();

    return 0;
}