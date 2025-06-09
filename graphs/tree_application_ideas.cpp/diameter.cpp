// Write your code here
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>dep;
vector<int>par;
int n ;


void dfs (int node , int parent, int depth)
{
    dep[node]=depth;
    par[node]=parent;
    for(auto v:g[node])
    {
        if(v!=parent)
        {
            dfs(v,node,depth+1);
            
        }
      
    }
}
void solve()
{
     
    cin>>n;
    g.resize(n+1);
     dep.assign(n+1,0);
     par.assign(n+1,0);
     for(int i=0;i<n-1;i++ )
     {
        int a ,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
     }

     dfs(1,0,0);

     int max1=1;
     for(int i=2;i<=n;i++)
     {
        if(dep[i]>dep[max1])
        {
            max1=i;
        }
     }

     dfs(max1,0,0);
       int max2=1;
     for(int i=2;i<=n;i++)
     {
        if(dep[i]>dep[max2])
        {
            max2=i;
        }
     }
     

     cout<<dep[max2]<<endl;


} 
int main()
{

    solve();

    return 0;
}
