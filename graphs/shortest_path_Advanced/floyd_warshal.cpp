#include <bits/stdc++.h> 
using namespace std;
#define INF 1e9
//floyd warshal is like dp 
int dist[404][404];
int par[404][404];
int n , m ;

void solve()
{

    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         if(i!=j) dist[i][j]=INF;
        //  dist[i][j]=INF;   for shortest cycle detection distance of i to i is marked as inf and if we come to the smae value i again then we get the cycle 
    }

    for(int  i=0;i<m;i++)
      {
        int a , b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c); // min because let's say if multiple paths from a to b then always take the minimum wt
      }

      for(int k=0;k<n;k++)
      {
        for(int i=0;i<n;i++)
        { 
          for(int j=0;j<n;j++)
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);

        }
      }

      // dist[a][b]  // gives distance from a to b 

      //for the shortest cycle 
    //   int ans=INF;
    //   for(int i=0;i<n;i++)
    //   {
    //     ans=min(ans,dist[i][i]);
    //   }

      // just took the minimum of the all the reachable distance 


      // negative cycle detection , 
    //   if(ans<0) then negative cycle exsist 


    // diameter of graph - longest shortest path 
    // just take the maximum of the i to j paths we have it in the matrix;
}
int main()
{

solve(); 
return 0;
}