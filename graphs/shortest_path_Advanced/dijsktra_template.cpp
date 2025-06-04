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
#define F first
#define S second
vector<vector<array<int,2>>>g;  // initulized like this [[{1,0},{2,1}],[{3,1},{4,0}],....]
vector<int>dis;
int n, m;

//bool check // if any
//vector<state> neighbour if any                                                                

void dijsktra(int start)
{
   priority_queue<pair<int,int>>pq;
   pq.push({0,start});   // Push {-distance, node} but start distance is 0
   dis[start]=0;
   while(!dq.empty())
   {
       auto curr=pq.top(); //front element is the current // will explore the neighbours
       int curr_dist=-curr.F;  // storing the -ve , because by default pq is the max heap
       int curr_node=curr.S;

       pq.pop();//popping the elements from the front
         if(curr_dit> dis[curr_node]) continue;   // Skip if we've already found a better path to this node
       //let; sexplore the neighbours of curr
       for(auto v: g[curr_node])
       {
        // vist those neighbours who are not visited or those whose dist max still exsist
        // v[0] - 0th index gives node and v[1] - 1st index gives it's weight
         if(dis[v[0]]>dis[curr_node]+v[1])
         {
            dis[v[0]]=dis[curr_node]+v[1];

            pq.push({-dis[v[0]],v[0]});  // first position stores the distance of neighbour and second stores the neighbour
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
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});  // weight of the front edge as 0
        g[b].push_back({a,w}); // wr mark the weights of reverse edge as -1

        // take care in questinon whetehre directed graph is given or not
        // read the q properly ,especially the constriants , you missed the distance constriant .
    }
}

dijsktra(1);
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







