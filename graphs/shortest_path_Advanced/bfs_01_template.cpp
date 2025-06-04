// note bfs -01 is only done when there is possibilty of weighted graph which has weight of either 0 or 1
/*
  weight 1 push or initialize push
   back

  |    |
  |    |
  |    |        
  |    |
  ------
    weight 0 push and pop 
   front

*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<vector<array<int,2>>>g;  // initulized like this [[{1,0},{2,1}],[{3,1},{4,0}],....]
vector<int>dis;
int n, m;

//bool check // if any
//vector<state> neighbour if any                                                                

void bfs01(int node)
{
   deque<int>dq;
   dq.push_back(node);  // piche side dala taki pop hoke neighbours explore ho paye
   dis[node]=0;
   while(!dq.empty())
   {
       int curr=dq.front(); //front element is the current // will explore the neighbours
       dq.pop_front();//popping the elements from the front
       //let; sexplore the neighbours of curr
       for(auto v: g[curr])
       {
        // vist those neighbours who are not visited or those whose dist max still exsist
        // v[0] - 0th index gives node and v[1] - 1st index gives it's weight
         if(dis[v[0]]>dis[curr]+v[1])
         {
            dis[v[0]]=dis[curr]+v[1];

            // if weigh is 0 then push_front else push_back
            if(v[1]==0)
             {
                dq.push_front(v[0]); // push front what the current or the neighbours of curr, obviously the neighbours
             }

             else 
             {
                dq.push_back(v[0]);
             }
         }
       }
   }
   
}

void solve()
{
cin>>n>>m;
// note assign overwrites all the array when moving to next tc, when using resize it does not overwrites
// whenever use resize and there are multiple tc always do clear
g.clear();
g.resize(n+1); //never forget this 
dis.assign(n+1,INF);  // dis array with infinity initilization
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,0});  // weight of the front edge as 0
        g[b].push_back({a,1}); // wr mark the weights of reverse edge as -1
    }
}

bfs01(1);
if(dis[n]==INF) cout<<"-1\n";
else cout<<dis[n]<<endl;

}

int main()
{ 

    int t ;
    cin>>t;
    while(t--)
    {
        solve();
    }



    return 0;
}







