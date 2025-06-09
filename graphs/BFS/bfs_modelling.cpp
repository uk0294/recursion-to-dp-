#include<bits/stdc++.h>
using namespace std;
#define INF 1e9


int n,m;

int dist[101];
int go_to[101];
bool check(int node )
{
    if(node<101 && node>=1) return 1;

    else return 0;
     
}



int bfs(int node )
{
    for(int i=1;i<=100;i++)
     dist[i]=INF;

   dist[node]=0;
   queue<int>q;
   q.push(node);
   while(!q.empty())
    {
        int current_node=q.front();
        q.pop();
        // for(auto v : g[curr])
        // {
        //     // exploring the neighbours of current node , we have 6 options to go
        //     //go_to[i] tells where you will go  
        // }

        // the above code is for exploring the neighbours , i will explore the neighbout in following way 
        // we 6 ways to go right ?? becausae we can get from 1-6 in dice 
        for(int i=1;i<=6;i++)
        {
            int next_node=current_node+i;  // current se i aage jao wo check karo 

            // if snake or laader then do the below
             if(go_to[next_node]!=next_node)
               next_node=go_to[next_node];
            if(check(next_node)&&dist[next_node]==INF)
            {
                q.push(next_node);
                dist[next_node]=dist[current_node]+1;
            }

        }
    }
    if(dist[100]==INF)
     return -1;
     else 
      return dist[100];

}


void solve ()
{


    for(int i=1;i<=100;i++)
    {
        go_to[i]=i;
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a ,b;
        cin>>a>>b;
        go_to[a]=b;
    }
    cin>>m;
    for(int i=0;i<m;i++)
     {
        int a,b ;
        cin>>a>>b;
        go_to[a]=b;
     }

    cout<<bfs(1)<<endl;

}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    solve();
   }


    return 0;
}