#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second

// TO DO - maximum spanning tree - simply just push the negative cost and ans is -mst_cost
//TO DO - supernode concept , each node has also the cost , along with the weight
int n , m;
vector<pair<int,pair<int,int>>>edges; // cost , {x,y};
vector<int>parent;
vector<int>rankk;

vector<pair<int,int>>g; //this is for printing the graph 
//note everything is one indexed
void init()
{
   edges.resize(m);
   parent.resize(n+1);
   rankk.resize(n+1);
   g.resize(n+1);
   for(int i=1;i<=n;i++)
   {
    parent[i]=i;
    rankk[i]=0;
   }
}

int find(int x)
{
    if(parent[x]!=x)
    {

        parent[x]=find(parent[x]);
    }
    return parent[x];
}


bool unite(int x,int y)
{

    int xroot=find(x),yroot=find(y);
    if(xroot==yroot) return false;
    if(parent[xroot]<yroot)
    {
        parent[xroot]=yroot;
    }
       else if(parent[yroot]<xroot)
    {
        parent[yroot]=xroot;
    }

         else 
    {
        parent[yroot]=xroot;
        rankk[yroot]+=rankk[xroot];
    }


    // or can be done like below 
    //     if(rankk[xroot]<rankk[yroot])
    // {
    //     parent[xroot]=yroot;
    //      rankk[yroot]+=rankk[xroot];
    // }
    //    else 
    // {
    //     parent[yroot]=xroot;
    //      rankk[xroot]+=rankk[yroot];
    // }

   
   return true;


}

void solve()
{
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++)
{

    int a,b,c;
    cin>>a>>b>>c;
    edges.push_back(make_pair(c,make_pair(a,b)));
}

sort(edges.begin(),edges.end());
//mst algo 
int cnt=0;
int mst_cost=0;
for(auto v:edges)
{
    int cost=v.f;
    int x =v.s.f;
    int y=v.s.s;
    if(find(x)!=find(y))
    {
        cnt++;
        mst_cost+=cost;
        unite(x,y);
        // for printing the spanning tree 
        g[x].push_back({y,cost});
        g[y].push_back({x,cost});

    }
}

if(cnt!=n-1) // for the formation of tree minimum of the edge size of n-1
 cout<<"IMPOSSIBLE"<<endl;
 else
 {
    cout<<mst_cost<<endl;
 }
}


signed main()
{

solve();


    return 0;
}