// Write your code here
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
int ans[10001];
int val[10001];
int n ;



void dfs (int node , int parent, int maxval,int minval)
{
    
   ans[node]=max(abs(minval-val[node]),abs(maxval-val[node]));
    for(auto v:g[node])
    {
        if(v!=parent)
        {
            dfs(v,node,max(maxval,val[node]),min(minval,val[node]));
            
        }
      
    }
}
void solve()
{
     
    dfs(root,0,-1e9,1e9);

} 
int main()
{

    solve();

    return 0;
}
