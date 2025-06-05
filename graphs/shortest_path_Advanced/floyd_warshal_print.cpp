#include <bits/stdc++.h> 
using namespace std;
#define INF 1e9
//floyd warshal is like dp 
int dist[404][404];
int par[404][404];
int n , m ;

void print_path(int i, int j)
{
    if(i!=j) print_path(i,par[i][j]);
    cout<<j<<endl;
}

void solve()
{

    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         if(i!=j) dist[i][j]=INF;
    }

    for(int  i=0;i<m;i++)
      {
        int a , b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c); // min because let's say if multiple paths from a to b then always take the minimum wt
      }


       for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         if(i!=j) par[i][j]=i;
    }

      for(int k=0;k<n;k++)
      {
        for(int i=0;i<n;i++)
        { 
          for(int j=0;j<n;j++)
          {
            if(dis[i][j]>dis[i][k]+dis[k][j])
            {
                dis[i][j]>dis[i][k]+dis[k][j]
                par[i][j]=par[k][j]; 
            }
              
          }

        }
      }

      // dist[a][b]  // gives distance from a to b 

}
int main()
{

solve(); 
return 0;
}