#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define F first
#define S second

struct Edge{
    int from,to;
    long long wt;
};

vector<Edge>edges;
int n , m,a;
vector<long long>dis;

void dijsktra(int start)
{
   priority_queue<pair<long long,int>>pq; // first indx wt , second node
   pq.push({0,start});
   dis[start]=0;
   while(!pq.empty())
   {
    auto curr=pq.top();
    pq.pop();
    int curr_node=curr.S;
    long long curr_dist=-curr.F;
    
    if(curr_dist>dis[curr_node])  continue;
    
    // Use edges vector instead of adjacency list
    for(Edge e : edges)
    {
        int neighbor = -1;
        long long weight = e.wt;
        
        // Check if current node is connected to this edge
        if(e.from == curr_node) {
            neighbor = e.to;
        } else if(e.to == curr_node) {
            neighbor = e.from;
        }
        
        // If neighbor found, try to relax the distance
        if(neighbor != -1 && dis[neighbor] > dis[curr_node] + weight)
        {
            dis[neighbor] = dis[curr_node] + weight;
            pq.push({-dis[neighbor], neighbor});
        }
    }
   }
}


void solve()
{
    cin>>n>>m;
    dis.assign(n+1,INF);
    edges.clear();

    for(int i=0;i<m;i++)
    {
        int u, v;
        long long w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w}); // Store edge info using struct
    }

    cin>>a;
    dijsktra(a);
    
    // Calculate burn time for each edge
    double maxBurnTime = 0;
    for(Edge edge : edges) {
        int u = edge.from, v = edge.to;
        long long w = edge.wt;
        double time_u = dis[u];
        double time_v = dis[v];
        
        double burnTime;
        double firstTime = min(time_u, time_v);
        double secondTime = max(time_u, time_v);
        
        if(secondTime - firstTime >= w) {
            // Edge is fully burned by the time fire reaches the second end
            burnTime = secondTime;
        } else {
            // Fire burns from both ends for the remaining distance
            double remainingDist = w - (secondTime - firstTime);
            burnTime = secondTime + remainingDist / 2.0;
        }
        
        maxBurnTime = max(maxBurnTime, burnTime);
    }
    
    cout << (long long)(maxBurnTime * 10) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   solve();

    return 0;
}