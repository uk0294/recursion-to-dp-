#include<bits/stdc++.h>
using namespace std ;


int dep[10001];
int par[10001];
int subtreesz[10001];
bool isLeaf[10001];
int numChild[10001];
vector<int>g[10001];
int n, m;


void dfs(int node, int parent , int depth )
{

dep[node]=depth;
par[node]=parent;
numChild[node]=0;
subtreesz[node]=1; // initally the size of the subtree is for that node is 1 

for (auto v:g[node])
{

    // if the neighbour is not parent then it is in the subtree or it is a child 
    if(v!=parent)
    {
        numChild[v]++;
        dfs(v,node,depth+1); // depth inc by 1 and the node becomes the parent 
        subtreesz[node]+=subtreesz[v];  // increase the subtree size by addign the child size  
    }
     
}

// if after the above traversal we can't find any , child then it is a leaf  

if(numChild[node]==0)
{
    isLeaf[node]=1; 
}



}


void solve()
{
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {

    int a , b ;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a); // tree is always undriected
   }
   dfs(1,0,0) ; //0 depth and 0 parent 
  

}


int main()
{


    return 0;
}