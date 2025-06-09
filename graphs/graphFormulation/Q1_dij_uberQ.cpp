#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using MP=make_pair;
#define F first ;
#define S second;
vector<vector<pair<int,ii>>g;
int n,m,k;
int cost[1001];  // the cost of refuling 
int dist[1001][1001];  // i index the node no. , j index the petrol in liters ramaining corresponding to that i
int vis[1001][10001];

using state =pair<int,int>;

void dijkstra(state st)
{
    priority_queue<pair<int,ii>>  pq;//{-distance,{node_no.,fuel}}// first  int stores the distance - always keep in mind ,second stores the node info , in that{node_no. , fuel used}
   pq.push(MP(0,st));
   dis[st.F][st.S]=0;  // st.S is the fuel consumption 
   while(!pq.empty())
   {
       auto curr=pq.top();
       int curr_dist=-pq.F:
       auto curr_state=pq.S;  
      // curr_state.F = curr node , curr_State.S=current fuel 
       pq.pop();

       //imp dijkstra codition
       if(vis[curr_state.F][curr_state.S]==1) continue;  
       vis[curr_state.F][curr_state.S]==1;
     //
       //now we have two cases , either go to next node with 0 cost - in that case the petrol will dec - so need to refuel to the nest 
       // another case can be donot move to the next wecause petrol can't be completed when move to next , so stay at the same and take the fuel from it and with the first condition when have suffiecnt fuel then with the first condition will move to next
      //let's explore the neignbours
      for(auto v: g[curr_state.F ])
      {
        //v.F gives the node no.
        //v.S.F gives the litres of petrol required for the city 
        //v.S.S gives the diatance required to reach the city 
        // check 1 if(amount of petrol req by next node or the neighbour <= petrol currently having )  move to the next with 0 cost 

        if(curr_state.S>=v.S.F)
        {

            // just relax the dijkstra- by jis node pe pahuch gaye ,uska dist jada hona chaiye the distance + weight of rthe edge correspodding to that node 
       // future nod epe pahuche to uska fuel req jo hoga wo curr wale se minus
        if(!vis[v.F][curr_state.S-v.S.F] && dist[v.F][curr_state.S-v.S.F]>curr_dist+0)  // current_distance +edge wieght , but this edge will incur 0 cost 
          {
            dist[v.F][curr_state.S-v.S.F]>=curr_dist+0;
            pq.push(MP(-dist[v.F][curr_state.S-v.S.F],MP(v.F,curr_state.S-v.S.F));   // in th e second store  {node,fuel left}
          } 

        }


      }


      // now outside the loop will give the condition that will stay at the same node 
      // refill
         // relax me fuel cost ek badha ke check karoge na
         if(!vis[curr_state.F][curr_state.S+1] && dist[curr_state.F][curr_state.S+1]>curr_dist+c[curr_state.F])  // current distance + the cost of the refuling of the current nod e
          {
            dist[curr_state.F][curr_state.S+1]=curr_dist+c[curr_state.F] 
            pq.push(MP(-dist[curr_state.F][curr_state.S+1],MP(curr_state.F,curr_state.S+1)))// in th e second store  {node,fuel left}
          } 

        }

   }
}   

void solve()
{
    cin>>n>>m>>k;  // the initial petrol in the car 
    g.resize(n+1);
    c.resize(n+1);
     dis.assign(n+1,INF);
     vis.assign(n+1,0);
    
    int st_node=1, en_node=n;
    for(int i=1;i<=n;i++)
      cin>>c[i];
    for(int i=0;i<m;i++)
    {
        int a, b;  // the graph nodes or the cities
        itn p, d; //  petrol cost and the distance to reach that city 

        g[a].push_back(MP(b,MP(p,d)));
        g[b].push_back(MP(a,MP(p,d)));
    }


    state st={st_node,0}  ;  // second one represents the fuel amount , initiall the fuel amount =0;
    dijsktra(st);
    cout<<dist[en_node][0]<<endl;
}



int main()
{

int n , m 


    return 0;
}